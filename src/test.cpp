#include "gtest/gtest.h"
#include "mytest.h"

// test fixure
class mystringTest : public testing::Test {
	protected:
		virtual void SetUp() {
			s1 = new mystring();
			s2 = new mystring( "helloworld" );
		}
		virtual void TearDown() {
			delete s1;
			delete s2;
		}
		mystring *s1;
		mystring *s2;
};

TEST_F( mystringTest , constructor ) {
	EXPECT_EQ( s1->getContent() , "" );
	EXPECT_EQ( s2->getContent() , "helloworld" );
}

TEST_F( mystringTest , set ) {
	s1->set();
	EXPECT_EQ( s1->getContent() , "no need to set" );
	s2->set();
	EXPECT_EQ( s2->getContent() , "oworld.done" );
}

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
