#include "tests.h"

class pct_class : public ::testing::Test {
protected:
	const char  *lib;
    const char  *ft;
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(pct_class, pct) {
	JUDGE_EQ_NO_ARGS(%);
    JUDGE_EQ_NO_ARGS( %);
	LEAKS_CONFIRM
}