
EXE = graph

all: $(EXE)

test: all

clean:
	rm -f $(EXE) *~ logfile.txt *.o

graph:  Stack.o Queue.o IntegerSet.o Graph.o List.o 
	$(CXX) -o $@ $^ -Wall -std=c++11

%.o: %.cpp
	$(CXX) -c -o $@ $< -Wall -std=c++11 -g
