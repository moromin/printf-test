#include "tests.h"

class p_class : public ::testing::Test {
protected:
	const char  *lib;
    const char  *ft;
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(p_class, p) {
	JUDGE_EQ(p, lib);
    JUDGE_EQ(p, (void *)NULL);
	LEAKS_CONFIRM
}