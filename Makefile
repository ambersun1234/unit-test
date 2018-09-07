GTESTLIB=gtest
GTESTINCLUDE=/usr/local/include
CXX=g++
CXXFLAGS=-Wall -std=c++1y -I $(GTESTINCLUDE) -c
GTESTFLAGS=-L /usr/local/lib -l $(GTESTLIB) -l pthread

all: result

result: mytest.o test.o
	$(CXX) -o result $^ $(GTESTFLAGS)

mytest.o: mytest.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

test.o: test.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf *.o *.gch

test: result
	./result

.PHONY: all clean
