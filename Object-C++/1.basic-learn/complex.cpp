/*************************************************************************
	> File Name: complex.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月28日 星期日 17时57分54秒
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
#include <iostream>
using namespace std;
class Complex
{
private:
  	double real;
  	double image;
public:
  	Complex(const Complex& complex) :real{ complex.real }, image{ complex.image } {

  	}
  	Complex(double Real=0, double Image=0) :real{ Real }, image{ Image } {

  	}
  	//TODO
    Complex operator+(Complex &obj) {
        double x = this->real + obj.real;
        double y = this->image + obj.image;
        return Complex(x, y); 
    }
    Complex operator-(Complex &obj) {
        double x = this->real - obj.real;
        double y = this->image - obj.image;
        return Complex(x, y); 
    }

    Complex operator*(Complex &obj) {
        double a = this->real, b = this->image;
        double c = obj.real, d = obj.image;
        return Complex(a * c - b * d, b * c + a * d); 
    }

    Complex operator/(Complex &obj) {
        double a = this->real, b = this->image;
        double c = obj.real, d = obj.image;
        return Complex((a * c + b * d) / (c * c + d * d), (b * c - a * d) / (c * c + d * d)); 
    }

    friend istream &operator>>(istream &input, Complex &obj);
    friend ostream &operator<<(ostream &output, const Complex &obj);
};

istream &operator>>(istream &input, Complex &obj){
    input >> obj.real >> obj.image;
    return input;
}
ostream &operator<<(ostream &out, const Complex &obj) {
    out << "(" << obj.real;
    if (obj.image > 0) out << "+";
    out << obj.image << "i" << ")";
    return out;
}



int main() {
  	Complex z1, z2;
  	cin >> z1;
  	cin >> z2;
  	cout << z1 << " " << z2 << endl;
  	cout << z1 + z2 << endl;
  	cout << z1 - z2 << endl;
  	cout << z1*z2 << endl;
  	cout << z1 / z2 << endl;
  	return 0;
}
