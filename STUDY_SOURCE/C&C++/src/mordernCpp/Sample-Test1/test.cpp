#include "pch.h"
#include "..\mordernCpp\GoogleTestDemo.h"


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(SUM_TEST_CASE, SumTest) {
	EXPECT_EQ(3, sumForUnitTest(1, 2));
	ASSERT_EQ(5, sumForUnitTest(3, 2));
}


int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}