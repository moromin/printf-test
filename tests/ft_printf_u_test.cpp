#include "tests.h"

class u_class : public ::testing::Test {
protected:
	const char  *lib;
    const char  *ft;
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(u_class, u) {
	JUDGE_EQ(u, 2147483647);
    // JUDGE_EQ(u, 4294967294);
    JUDGE_EQ(u, 0);
    JUDGE_EQ(u, -1);
    JUDGE_EQ(u, 5234);
	LEAKS_CONFIRM
}