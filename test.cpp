#include <gtest/gtest.h>
#include "mytest.h"

template< typename itemType >
class mytemplateTest : public ::testing::Test {

};
using itemType_test = ::testing::Types< int , double , unsigned >;
TYPED_TEST_CASE( mytemplateTest , itemType_test );

TYPED_TEST( mytemplateTest , constructor ) {
	mytemplate< TypeParam > obj;
	mytemplate< TypeParam > obj1( 104 );
	EXPECT_EQ( 0 , obj.getData() );
	EXPECT_EQ( 104 , obj1.getData() );
}

TYPED_TEST( mytemplateTest , setData ) {
	mytemplate< TypeParam > obj;
	EXPECT_EQ( 0 , obj.getData() );
	obj.setData( 554 );
	EXPECT_EQ( 554 , obj.getData() );
}

TEST( mystring , constructor ) {
	mystring s1;
	mystring s2( "helloworld" );
	EXPECT_EQ( "" , s1.getContent() );
	EXPECT_EQ( "helloworld" , s2.getContent() );
}

TEST( mystring , set ) {
	mystring s1;
	mystring s2( "pigggg" );
	EXPECT_EQ( "no need to set" , s1.set() );
	EXPECT_EQ( "gg.done" , s2.set() );
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
