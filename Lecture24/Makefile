
EXE = max list swap tarray

all:  $(EXE)

test: all

clean:
	rm -f $(EXE) *~ logfile.txt *.o

list: list.o
	$(CXX) -o $@ $^ -Wall -std=c++11 -g

swap: swap.o
	$(CXX) -o $@ $^ -Wall -std=c++11 -g

tarray: tarray.o
	$(CXX) -o $@ $^ -Wall -std=c++11 -g

max: max.o
	$(CXX) -o $@ $^ -Wall -std=c++11 -g

%.o: %.cpp
	$(CXX) -c -o $@ $< -Wall -std=c++11 -g
