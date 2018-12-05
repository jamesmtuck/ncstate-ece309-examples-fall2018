
EXE = stl list vector set graph age

all:  $(EXE)

test: all

clean:
	rm -f $(EXE) *~ logfile.txt *.o

stl: stl.o
	$(CXX) -o $@ $^ -Wall -std=c++11 -g

list: list.o
	$(CXX) -o $@ $^ -Wall -std=c++11 -g

vector: vector.o
	$(CXX) -o $@ $^ -Wall -std=c++11 -g

set: set.o
	$(CXX) -o $@ $^ -Wall -std=c++11 -g

graph: graph.o
	$(CXX) -o $@ $^ -Wall -std=c++11 -g

age: age.o
	$(CXX) -o $@ $^ -Wall -std=c++11 -g

%.o: %.cpp
	$(CXX) -c -o $@ $< -Wall -std=c++11 -g
