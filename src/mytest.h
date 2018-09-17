#include <string>

using namespace std;

int factorial( int input );

class mystring {
    private:
        string content;

    public:
        mystring();
        mystring( const string input );
        string getContent();
        string set();
};

template< typename itemType >
class mytemplate {
    private:
        itemType data;

	public:
		mytemplate();
		mytemplate( const itemType input );
		itemType getData();
        void setData( const itemType input );
};
//---------------------------------------------------------------------
template< typename itemType >
mytemplate< itemType >::mytemplate() {
    this->data = 0;
}

template< typename itemType >
mytemplate< itemType >::mytemplate( const itemType input ) {
    this->data = input;
}

template< typename itemType >
itemType mytemplate< itemType >::getData() {
    return this->data;
}

template< typename itemType >
void mytemplate< itemType >::setData( const itemType input ) {
    this->data = input;
    return;
}
