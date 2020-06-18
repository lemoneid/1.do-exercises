/*************************************************************************
	> File Name: test.h
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月13日 星期六 19时07分16秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#define RESET "\033[0m"
#define BLACK "\033[30m" /* Black */
#define RED "\033[31m" /* Red */
#define GREEN "\033[32m" /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define BLUE "\033[34m" /* Blue */
#define MAGENTA "\033[35m" /* Magenta */
#define CYAN "\033[36m" /* Cyan */
#define WHITE "\033[37m" /* White */

#define TEST(a, b) \
    void a##_haizei_##b(int *, int *); \
    __attribute__((constructor)) \
    void add##__haizei__##a##__haizei__##b() {\
        add_function(a##_haizei_##b, #a "_haizei_" #b); \
    } \
    void a##_haizei_##b(int *total, int *success)

typedef void (*TestFuncT)(int *, int *);


typedef struct function {
    TestFuncT func;
    const char *str;
} Function;


int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);
void print_false(const char *, int , int, const char * ,int);

#define EXPECT_EQ(a, b) {\
    int flag = ((a) == (b));\
    if (!flag) print_false(#a "==" #b, (a), (b), __func__,__LINE__);\
    *total += 1;\
    *success += flag;\
    cout << GREEN << "[-----------]" << RESET; \
    printf(" %s == %s ", #a, #b);\
    if (flag) cout << GREEN << "True" << RESET << endl;\
    else cout << RED << "False" << RESET << endl;\
    }
#endif

#define EXPECT_NE(a, b) {\
    int flag = ((a) != (b));\
    if (!flag) print_false(#a "!=" #b, (a), (b), __func__, __LINE__);\
    *total += 1;\
    *success += (a) != (b);\
    cout << GREEN << "[-----------]" << RESET; \
    printf(" %s != %s ", #a, #b);\
    if ((a) != (b)) cout << GREEN << "True" << RESET << endl;\
    else cout << RED << "False" << RESET << endl;\
    }

#define EXPECT_LT(a, b) {\
    int flag = ((a) < (b));\
    if (!flag) print_false(#a "<" #b, (a), (b), __func__, __LINE__);\
    *total += 1;\
    *success += (a) < (b);\
    cout << GREEN << "[-----------]" << RESET; \
    printf(" %s < %s ", #a, #b);\
    if ((a) < (b)) cout << GREEN << "True" << RESET << endl;\
    else cout << RED << "False" << RESET << endl;\
    }

#define EXPECT_GT(a, b) {\
    int flag = ((a) > (b));\
    if (!flag) print_false(#a ">" #b, (a), (b), __func__, __LINE__);\
    *total += 1;\
    *success += flag;\
    cout << GREEN << "[-----------]" << RESET; \
    printf(" %s > %s ", #a, #b);\
    if ((a) > (b)) cout << GREEN << "True" << RESET << endl;\
    else cout << RED << "False" << RESET << endl;\
    }

#define EXPECT_LE(a, b) {\
    int flag = ((a) <= (b));\
    if (!flag) print_false(#a "<=" #b, (a), (b), __func__, __LINE__);\
    *total += 1;\
    *success += (a) <= (b);\
    cout << GREEN << "[-----------]" << RESET; \
    printf(" %s <= %s ", #a, #b);\
    if ((a) <= (b)) cout << GREEN << "True" << RESET << endl;\
    else cout << RED << "False" << RESET << endl;\
    }

#define EXPECT_GE(a, b) {\
    int flag = ((a) >= (b));\
    if (!flag) print_false(#a ">=" #b, (a), (b), __func__, __LINE__);\
    *total += 1;\
    *success += (a) >= (b);\
    cout << GREEN << "[-----------]" << RESET; \
    printf(" %s >= %s ", #a, #b);\
    if ((a) >= (b)) cout << GREEN << "True" << RESET << endl;\
    else cout << RED << "False" << RESET << endl;\
    }
