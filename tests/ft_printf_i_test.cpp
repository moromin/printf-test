#include "tests.h"

class i_class : public ::testing::Test {
protected:
	const char  *lib;
    const char  *ft;
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(i_class, i) {
	JUDGE_EQ(i, 2147483647);
    // JUDGE_EQ(i, -2147483648);
    JUDGE_EQ(i, 0);
    JUDGE_EQ(i, -134);
    JUDGE_EQ(i, 5234);
	LEAKS_CONFIRM
}