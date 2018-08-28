
EXE = lec02-ex1 lec02-ex2 lec02-log lec02-superhero

all: $(EXE)

test: all

clean:
	rm -f $(EXE) *~ logfile.txt

%: %.cpp
	$(CXX) -o $@ $< 
