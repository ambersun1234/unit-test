#include "gtest/gtest.h"
#include "mytest.h"

// test case name , test name
TEST( factorial , negative ) {
	EXPECT_EQ( 1 , factorial( -5 ) );
	EXPECT_LT( -3 , factorial( -99 ) );
	EXPECT_GT( factorial( -3 ) , 0 );
}

TEST( factorial , zero ) {
	EXPECT_EQ( factorial( -10 ) , 1 );
}

TEST( factorial , positive ) {
	EXPECT_EQ( 120 , factorial( 5 ) );
	EXPECT_LT( 5 , factorial( 3 ) );
	EXPECT_GT( factorial( 10 ) , 5050 );
}

GTEST_API_ int main( int argc , char **argv ) {
	testing::InitGoogleTest( &argc , argv );
	return RUN_ALL_TESTS();
}
