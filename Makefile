GTESTLIB=gtest
GTESTINCLUDE=/usr/local/include
CXX=g++
CXXFLAGS=-Wall -std=c++1y -I $(GTESTINCLUDE) -c
GTESTFLAGS=-L /usr/local/lib -l $(GTESTLIB) -l pthread

all: result

result: mytest.o test.o
	$(CXX) -o result $^ $(GTESTFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf *.o *.gch

test: 
	./result

.PHONY: all clean test
