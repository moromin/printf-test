#include "tests.h"

class c_class : public ::testing::Test {
protected:
	const char  *lib;
    const char  *ft;
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(c_class, c) {
	JUDGE_EQ(c, 'a');
	LEAKS_CONFIRM
}