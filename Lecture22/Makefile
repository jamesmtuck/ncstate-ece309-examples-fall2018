
EXE = btree

all: $(EXE)

test: all
	./$(EXE)

clean:
	rm -f $(EXE) *~ logfile.txt *.o

btree:  BTree.o
	$(CXX) -o $@ $^ -Wall -std=c++11

%.o: %.cpp
	$(CXX) -c -o $@ $< -Wall -std=c++11 -g
