
EXE = lec07

all: $(EXE)

test: all

clean:
	rm -f $(EXE) *~ logfile.txt

%: %.cpp
	$(CXX) -o $@ $< -Wall
