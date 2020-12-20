/*************************************************************************
	> File Name: 20.rvalue.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月19日 星期六 20时06分04秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;

void judge2(int &x) {
    cout << " int function 2 " << x << " is left value" << endl;
    return ;
}

void judge2(int &&x) {
    cout << " int function 2 " << x << " is right value" << endl;
    return ;
}

void judge(int &x) {
    cout << x << " is left value" << endl;
    //judge2(x); // x是左值
    judge2(move(x));
    return ;
}

void judge(int &&x) {
    cout << x << " is right value" << endl;
   // judge2(x); // x是左值
    judge2(forward<int &&>(x));
    return ;
}

class A {
public :
    A(int n  = 10) : n(n) {
        arr = new int[n];
        for (int i = 0; i < n; ++i) arr[i] = i;
        cout << "constructor" << endl;
    }
    A(const A &obj) : n(obj.n) { //拷贝构造:左值引用
        this->arr = new int[n];
        for (int i = 0; i < n; ++i) this->arr[i] = obj.arr[i];
        cout << "copy constructor" << endl;
    }
    A(A &&obj) : n(obj.n), arr(obj.arr) { //移动构造:右值引用
        cout << "move constructor" << endl;
        obj.arr = nullptr;
    }
    A operator+(const A &obj) {
        A temp(this->n + obj.n);
        for (int i = 0; i < this->n; ++i) temp.arr[i] = this->arr[i];
        for (int i = 0; i < obj.n; ++i) temp.arr[i + this->n] = obj.arr[i];
        return temp;
    }
    void output() {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return ;
    }
    ~A() {
        cout << "destructor" << endl;
        delete[] arr;
    }

private:
    int *arr, n;
};

int main() {
    int n = 123;
    //越过该行代码,还能否相关的值,能左值,不能右值
    cout << (n++) << endl; //右值,简单理解:临时的变量,不可以修改的
    cout << (++n) << endl; //左值,简单理解:可以操作的变量,可引用
    //结合重载++运算符理解
    cout << (++n)++ << endl;
    //cout << (n++)++ << endl;
    cout << "++n ";
    judge(++n);
    cout << "n++ ";
    judge(n++);
    /*
     * ++n 128 is left value
     * int function 2 128 is left value
     * n++ 128 is right value
     * int function 2 128 is left value 
    */
    //move强制变右值
    //forward变成任意类型的值
    //为了解决完美传值过程
    
    A *p = new A();
    A a = move(*p); //节约开辟对象空间,深拷贝,直接移动相关存储区的指向 O(n)->O(1)
    delete p;
    a.output();
    return 0;
}
