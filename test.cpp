#include <gtest/gtest.h>
#include "mytest.h"

// test case name , test name
TEST( factorial , negative ) {
	EXPECT_EQ( 1 , factorial( -5 ) );
	EXPECT_GT( 2 , factorial( -99 ) );
	EXPECT_GT( factorial( -3 ) , 0 );
}

using namespace std;

GTEST_API_ int main( int argc , char **argv ) {
	cout << "google test began soon..." << endl;
	testing::InitGoogleTest( &argc , argv );
	return RUN_ALL_TESTS();
}
