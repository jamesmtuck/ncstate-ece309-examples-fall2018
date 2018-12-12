
EXE = ex1

all:  $(EXE)

test: all

clean:
	rm -f $(EXE) *~ logfile.txt *.o

ex1: ex1.o
	$(CXX) -o $@ $^ -Wall -std=c++11 -g

%.o: %.cpp
	$(CXX) -c -o $@ $< -Wall -std=c++11 -g
