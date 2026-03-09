#include <gtest/gtest.h>

#include "tool.h"

TEST(TestBlah, OutputTest)
{
	EXPECT_EQ(1, Return_Num(1));
}