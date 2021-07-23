#include "tests.h"

class s_class : public ::testing::Test {
protected:
	const char  *lib;
    const char  *ft;
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(s_class, s) {
	JUDGE_EQ(s, "kkonishi\n");
    JUDGE_EQ(s, (char *)NULL);
    JUDGE_EQ(s, "    ");
	LEAKS_CONFIRM
}