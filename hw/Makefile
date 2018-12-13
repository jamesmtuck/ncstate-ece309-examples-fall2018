all: IntArray_test IntegerSet avl IntInf

IntArray_test: IntArray.o IntArray_test.o
	$(CXX) -o $@ $^ -std=c++11 -Wall -Werror -g

IntegerSet: IntegerSet.o
	$(CXX) -o $@ $^ -std=c++11 -Wall -Werror -g

avl: AVLTree.o BinarySearchTree.o
	$(CXX) -o $@ $^ -std=c++11 -Wall -Werror -g

IntInf: IntInf.o
	$(CXX) -o $@ $^ -std=c++11 -Wall -Werror -g

%.o : %.cpp
	$(CXX) -c -o $@ $< -std=c++11 -Wall -Werror -g

IntegerSet.o:IntegerSet.h

files: file1.o file2.o
	$(CXX) -o $@ $^ -std=c++11 -Wall -Werror -g
