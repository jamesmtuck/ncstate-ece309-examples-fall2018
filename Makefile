
all:
	$(CXX) -o hello hello.cpp -Wall -Werror
	make -C Lecture02 all

test: all
	./hello
	make -C Lecture02 test

clean:
	rm hello *~
