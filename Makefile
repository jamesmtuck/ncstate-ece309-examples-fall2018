all:
	$(CC) -o hello hello.cpp -Wall -Werror

test: all
	./hello