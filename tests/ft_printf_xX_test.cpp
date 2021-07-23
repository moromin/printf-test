#include "tests.h"

class xX_class : public ::testing::Test {
protected:
	const char  *lib;
    const char  *ft;
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(xX_class, x) {
	JUDGE_EQ(x, 0);
    // JUDGE_EQ(x, 4294967294);
    JUDGE_EQ(x, -1);;
    JUDGE_EQ(x, 5234);
	LEAKS_CONFIRM
}

TEST_F(xX_class, X) {
	JUDGE_EQ(X, 0);
    // JUDGE_EQ(X, 4294967294);
    JUDGE_EQ(X, -1);;
    JUDGE_EQ(X, 5234);
	LEAKS_CONFIRM
}