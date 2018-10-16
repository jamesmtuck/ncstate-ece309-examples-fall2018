
EXE = IntegerSet

all: $(EXE)

test: all

clean:
	rm -f $(EXE) *~ logfile.txt *.o

IntegerSet: IntegerSet.o List.o
	$(CXX) -o $@ $^ -Wall -std=c++11

%.o: %.cpp
	$(CXX) -c -o $@ $< -Wall -std=c++11 -g

IntegerSet.o:IntegerSet.h List.h
List.o:List.h
