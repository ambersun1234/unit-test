#include "mytest.h"
#include <string>

using namespace std;

int factorial( int input ) {
	if ( input <= 1 ) return 1;
	return input * factorial( input - 1 );
}

mystring::mystring() {
	this->content = "";
}

mystring::mystring( const string input ) {
	this->content = input;
}

string mystring::getContent() {
	return this->content;
}

string mystring::set() {
	return this->content.length() > 4 ? this->content.substr( 4 ) + ".done" : "no need to set";
}
