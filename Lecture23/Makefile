
EXE = namespace namespace2 refcount core files

all:  $(EXE)

test: all

clean:
	rm -f $(EXE) *~ logfile.txt *.o

files: file1.o file2.o
	$(CXX) -o $@ $^ -Wall -std=c++11 -g

namespace:  namespace.o
	$(CXX) -o $@ $^ -Wall -std=c++11 -g

namespace2:  namespace2.o
	$(CXX) -o $@ $^ -Wall -std=c++11 -g

refcount: RefCount.o
	$(CXX) -o $@ $^ -Wall -std=c++11 -g

core: Core.o
	$(CXX) -o $@ $^ -Wall -std=c++11 -g

%.o: %.cpp
	$(CXX) -c -o $@ $< -Wall -std=c++11 -g
