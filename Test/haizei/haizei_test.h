/*************************************************************************
	> File Name: test.h
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月13日 星期六 19时07分16秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H


#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[1;" #b "m" a"\033[0m"


#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a, 34)
#define YELLOW(a) COLOR(a, 33)

#define GREEN_HL(a) COLOR_HL(a, 32)
#define RED_HL(a) COLOR_HL(a, 31)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define YELLOW_HL(a) COLOR_HL(a, 33)

#define EXPECT(a, b, comp) {\
    printf(GREEN("[-----------]") " "#a " "#comp" " #b);\
    printf(" %s\n", (a) comp (b) ? GREEN("True") : RED("False"));\
}


#define TEST(a, b) \
    void a##_haizei_##b(); \
    __attribute__((constructor)) \
    void add##__haizei__##a##__haizei__##b() {\
        add_function(a##_haizei_##b, #a "_haizei_" #b); \
    } \
    void a##_haizei_##b()

typedef void (*TestFuncT)();


typedef struct function {
    TestFuncT func;
    const char *str;
} Function;


int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);

#define EXPECT_EQ(a, b) {\
    EXPECT(a, b, ==)\
    }
#endif

#define EXPECT_NE(a, b) {\
    EXPECT(a, b, !=)\
    }

#define EXPECT_LT(a, b) {\
    EXPECT(a, b, <)\
    }

#define EXPECT_GT(a, b) {\
    EXPECT(a, b, >)\
    }

#define EXPECT_LE(a, b) {\
    EXPECT(a, b, <=)\
    }

#define EXPECT_GE(a, b) {\
    EXPECT(a, b, >=)\
    }
