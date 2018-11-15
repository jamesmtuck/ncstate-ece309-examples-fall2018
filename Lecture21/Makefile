
EXE = graph

all: $(EXE)

test: all
	./graph

clean:
	rm -f $(EXE) *~ logfile.txt *.o

graph:  Stack.o Queue.o IntegerSet.o Graph.o List.o DList.o EdgeList.o
	$(CXX) -o $@ $^ -Wall -std=c++11

%.o: %.cpp
	$(CXX) -c -o $@ $< -Wall -std=c++11 -g

Stack.o:Stack.h List.h
Queue.o:Queue.h List.h
Graph.o:Graph.h List.h DList.h
List.o:List.h
IntegerSet.o:IntegerSet.h
DList.o:DList.h
EdgeList.o:EdgeList.h
