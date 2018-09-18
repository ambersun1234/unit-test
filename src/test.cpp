#include "gtest/gtest.h"
#include "mytest.h"

// template test fixure
class mytemplateTest : public testing::Test {
	protected:
		virtual void SetUp() {
			t1 = new mytemplate< int >();
			t2 = new mytemplate< int >( 101 );
		}
		virtual void TearDown() {
			delete t1;
			delete t2;
		}
		mytemplate< int > *t1;
		mytemplate< int > *t2;
};

TEST_F( mytemplateTest , constructor ) {
	EXPECT_EQ( t1->getData() , 0 );
	EXPECT_EQ( t2->getData() , 101 );
}

TEST_F( mytemplateTest , setData ) {
	t1->setData( 112 );
	EXPECT_EQ( t1->getData() , 112 );
	t2->setData( 404 );
	EXPECT_LT( 401 , t2->getData() );
}

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
			s1 = nullptr;
			s2 = nullptr;
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
