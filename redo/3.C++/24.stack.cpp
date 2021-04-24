/*************************************************************************
	> File Name: 24.stack.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月20日 星期二 09时36分30秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

enum class open_modes{input, output = 2, append};

#define func(x) __func(x, #x)

template<typename T>
void __func(T &x, const char *str) {
    cout << __PRETTY_FUNCTION__ << endl;
    cout << str << " : " << x << " is left value" << endl;

}

template<typename T>
void __func(T &&x, const char *str) {
    cout << __PRETTY_FUNCTION__ << endl;
    cout << str << " : " << x << " is right value" << endl;
}

template <typename T>
void test_func(std::initializer_list<T> arg) {
}

int main() {




    using type = map<string, int>;
    typedef map<string, int>  type1;
    typedef pair<int, int> PII;
    //cout << PII(1, 2) << endl;

    cout << endl;
    enum color {red, yellow, green};
    cout << red << yellow << endl;
    cout << color(2) << endl;
    cout << typeid(color(2)).name() << endl;
    func(color(2));
    cout << typeid(open_modes::input).name() << endl;
    open_modes x = open_modes::append;
    cout << static_cast<int>(x) << endl;
    int a = 1;
    int b = 2;
    int c[10] = {0};
    printf("a = %p, b = %p\n", &a, &b);
    for (int i = 0; i < 10; i++) {
        i == 0 && printf("i = %p\n", &i);
        printf("%p\n", c + i);
    }

    return 0;
}
