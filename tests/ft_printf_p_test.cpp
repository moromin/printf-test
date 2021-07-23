#include "tests.h"

class p_class : public ::testing::Test {
protected:
	char    str[STRSIZE];
	const char  *lib;
    const char  *ft;
	virtual void SetUp(){
		strcpy(str, "test");
	}
	virtual void TearDown(){
	}
};

TEST_F(p_class, p) {
	JUDGE_EQ(p, str);
    JUDGE_EQ(p, (void *)NULL);
	LEAKS_CONFIRM
}