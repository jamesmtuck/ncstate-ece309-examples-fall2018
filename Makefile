
DIRS = Lecture02 Lecture03 Lecture04 Lecture05 Lecture06 Lecture07 Lecture08 Lecture09 Lecture10 Lecture11


.PHONY = $(addsuffix -all,$(DIRS)) $(addsuffix -test,$(DIRS)) $(addsuffix -test,$(DIRS))

all: $(addsuffix -all,$(DIRS))
	$(CXX) -o hello hello.cpp -Wall -Werror

test: all $(addsuffix -test,$(DIRS))
	./hello
	make -C Lecture02 test

clean: $(addsuffix -clean,$(DIRS))
	rm -f hello *~

$(addsuffix -all,$(DIRS)):
	make -k -C $(subst -all,,$@) all

$(addsuffix -test,$(DIRS)):
	make -k -C $(subst -test,,$@) test

$(addsuffix -clean,$(DIRS)):
	make -k -C $(subst -clean,,$@) clean
