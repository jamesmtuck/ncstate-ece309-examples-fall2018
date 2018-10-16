
EXE = bt

all: $(EXE)

test: all

clean:
	rm -f $(EXE) *~ logfile.txt *.o

bt: bt.o BinarySearchTree.o
	$(CXX) -o $@ $^ -Wall -std=c++11

%.o: %.cpp
	$(CXX) -c -o $@ $< -Wall -std=c++11 -g
