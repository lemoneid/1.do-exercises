/*************************************************************************
	> File Name: test.h
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月09日 星期二 08时32分19秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

extern struct FunctionInfo info;

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[" #b ";1m" a "\033[0m"

#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a, 34)
#define YELLOW(a) COLOR(a, 33)
#define GREEN_HL(a) COLOR_HL(a, 32)
#define RED_HL(a) COLOR_HL(a, 31)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define YELLOW_HL(a) COLOR_HL(a, 33)

#define Name(a, b) a##_test_##b
#define Str(a, b) #a "." #b

#define TEST(a, b) \
void a##_test_##b();\
__attribute__((constructor)) \
void add_test_functon_##a##_test_##b() {\
    add_function(Name(a, b), Str(a, b));\
}\
void a##_test_##b()\

#define TYPE_STR(a) _Generic((a),\
    int : "%d", \
    double : "%lf", \
    float : "%f", \
    long long : "%ld", \
    const char * : "%s", \
    char * : "%s" \
)


#define P(a, color) {\
    char frm[100];\
    sprintf(frm, color("%s"), TYPE_STR(a));\
    printf(frm, a);\
}


#define EXPECT(a, b, cmp) {\
    __typeof(a) __a = (a);\
    __typeof(b) __b = (b);\
    info.total++;\
    if (__a cmp __b) info.success++;\
    else {\
        printf("\n");\
        printf(YELLOW_HL("\t%s:%d: Failure\n"), __FILE__, __LINE__);\
        printf(YELLOW_HL("\t\texpect" #a " "  #cmp " " #b "\n\t\tactual : "));\
        P(__a, YELLOW_HL);\
        P(" vs ", YELLOW_HL);\
        P(__b, YELLOW_HL);\
        printf("\n\n");\
    }\
    printf(GREEN("[-----------]") #a #cmp #b);\
    printf(" %s\n", __a cmp __b ? GREEN_HL("TRUE") : RED_HL("FALSE"));\
}

#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)

typedef void (*TestFuncT)();
struct Function {
    TestFuncT func;
    const char *str;
};

struct FunctionInfo {
    int total, success;
};

int RUN_ALL_TESTS();
void add_function(TestFuncT , const char *);
#endif
