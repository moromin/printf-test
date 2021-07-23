#include "tests.h"

class d_class : public ::testing::Test {
protected:
	const char  *lib;
    const char  *ft;
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(d_class, d) {
	JUDGE_EQ(d, 2147483647);
    // JUDGE_EQ(d, -2147483648);
    JUDGE_EQ(d, 0);
    JUDGE_EQ(d, -134);
    JUDGE_EQ(d, 5234);
	LEAKS_CONFIRM
}