
EXE = IntArray lec08

all: $(EXE)

test: all

clean:
	rm -f $(EXE) *~

%: %.cpp
	$(CXX) -o $@ $< -Wall
