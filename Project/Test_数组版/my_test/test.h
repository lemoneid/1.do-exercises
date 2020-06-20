/*************************************************************************
	> File Name: test.h
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月13日 星期六 15时26分16秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H
#include <iostream>
using namespace std;

#define RESET "\033[0m"
#define BLACK "\033[30m" /* Black */
#define RED "\033[31m" /* Red */
#define GREEN "\033[32m" /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define BLUE "\033[34m" /* Blue */
#define MAGENTA "\033[35m" /* Magenta */
#define CYAN "\033[36m" /* Cyan */
#define WHITE "\033[37m" /* White */

#define TEST(test_name, func_name)  \
    void test_name##_##func_name(); \
    __attribute__((constructor)) \
    void register_##test_name##_##func_name() { \
        test_function_arr[test_function_cnt] = test_name##_##func_name; \
        test_function_cnt++; \
    } \
    void test_name##_##func_name() 


typedef void (*test_function_t) ();

test_function_t test_function_arr[100];
int test_function_cnt = 0;

int RUN_ALL_TESTS() {
    
    for (int i = 0; i < test_function_cnt; ++i) {
        printf("RUN TEST : %d\n", i + 1);
        test_function_arr[i](); 
        printf("RUN TEST DONE\n\n");
    }
    return 0;
}

#define EXPECT_EQ(m, n) \
        if (m != n) { \
            cout << "Expect: " << #m << " Actuall: " << n << " " << RED << "False" << RESET << endl; \
        } else { \
            cout << "Expect: " << #m << " Actuall: " << n << " " << GREEN << "True" << RESET << endl; \
        }
#endif
