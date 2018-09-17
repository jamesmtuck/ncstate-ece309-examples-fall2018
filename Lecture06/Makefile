
EXE = stack-test queue-test

all: $(EXE)

test: all

clean:
	rm -f $(EXE) *~ logfile.txt

stack-test: stack-test.o List.o Stack.o
	$(CXX) -o $@ stack-test.o List.o Stack.o

queue-test: queue-test.o List.o Queue.o
		$(CXX) -o $@ queue-test.o List.o Queue.o

%.o: %.cpp
	$(CXX) -c -o $@ $< -Wall
