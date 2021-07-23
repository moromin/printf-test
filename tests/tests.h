#ifndef TESTS_H
#define TESTS_H

#include "gtest/gtest.h"

extern "C" {
#include "../../includes/ft_printf.h"
#include "../../includes/ft_printf_utils.h"
#include <climits>
}

#define STRSIZE 42

#define JUDGE_EQ(op, val) \
    testing::internal::CaptureStdout(); \
    EXPECT_EQ(printf("%"# op"\n", val), ft_printf("%"# op"\n", val)); \
    testing::internal::GetCapturedStdout(); \
    testing::internal::CaptureStdout(); \
    printf("%"# op"\n", val); \
    lib = testing::internal::GetCapturedStdout().c_str(); \
    testing::internal::CaptureStdout(); \
    ft_printf("%"# op"\n", val); \
    ft = testing::internal::GetCapturedStdout().c_str(); \
    EXPECT_STREQ(lib, ft); \

    // backup = dup(1); \
    // dup2(fd1, 1); \
    // printf("%"# op"\n", val); \
    // dup2(fd2, 1); \
    // ft_printf("%"# op"\n", val); \
    // dup2(backup, 1); \
    // close(backup); \
    // system("diff output1 output2");

#define JUDGE_EQ_NO_ARGS(op) \
    testing::internal::CaptureStdout(); \
    EXPECT_EQ(printf("%"# op"\n"), ft_printf("%"# op"\n")); \
    testing::internal::GetCapturedStdout(); \
    testing::internal::CaptureStdout(); \
    printf("%"# op"\n"); \
    lib = testing::internal::GetCapturedStdout().c_str(); \
    testing::internal::CaptureStdout(); \
    ft_printf("%"# op"\n"); \
    ft = testing::internal::GetCapturedStdout().c_str(); \
    EXPECT_STREQ(lib, ft); \

#define LEAKS_CONFIRM \
    testing::internal::CaptureStdout(); \
	system("leaks a.out"); \
	EXPECT_NE(std::string::npos, testing::internal::GetCapturedStdout().find(" 0 leaks for 0 total leaked bytes")); \

#endif //TESTS_H
