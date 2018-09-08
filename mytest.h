#include <string>

using namespace std;

int factorial( int input );

class mystring {
    private:
        string content;

    public:
        mystring() : content( "" ) {

        }
        mystring( const string input ) : content(  input  ) {

        }
        string getContent();
        string set();
};
