/*************************************************************************
	> File Name: 5.cout.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月15日 星期二 18时02分56秒
 ************************************************************************/

#include <iostream>
#include <string>

namespace worst {
    class ostream {
    public :
        ostream &operator<<(int x) {
            printf("%d", x);
            return *this;
        }
        ostream &operator<<(const std::string &str) {
            printf("%s", str.c_str());
            return *this;
        }   
        ostream &operator<<(const char &ch) {
            printf("%c", ch);
            return *this;
        }
        ostream &operator<<(const double &a) {
            char e_str[20];
            int e_num, temp;
            sprintf(e_str, "%.5e", a);
            scanf(e_str, "%d.%de%d", &temp, &temp, &e_num);
            if (e_num >= 6 || e_num <= -5) {
                printf("%s", e_str);
            } else {
                temp = 5 - e_num;
                sprintf(e_str, "%%.%dlf", temp);
                printf(e_str, a);
            }
            return *this;
        }
    };
    char endl = '\n';
    ostream cout;
}

int main() {
    worst::cout << "hello world" << worst::endl;
    worst::cout << 123 << worst::endl;
    worst::cout << 12.3 << worst::endl;
    worst::cout << 'a' << worst::endl;

    return 0;
}
