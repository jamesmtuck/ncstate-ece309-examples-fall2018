
all:
	$(CXX) -o hello hello.cpp -Wall -Werror

test: all
	./hello

clean:
	rm hello *~