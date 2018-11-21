
DIRS = Lecture02 Lecture03 Lecture04 Lecture05 Lecture06 Lecture07 Lecture08 \
       Lecture09 Lecture10 Lecture11 Lecture12 Lecture13 Lecture14 Lecture15 \
			 Lecture16 Lecture17 Lecture18 Lecture19 Lecture20 Lecture21 Lecture22


.PHONY = $(addsuffix -all,$(DIRS)) $(addsuffix -test,$(DIRS)) $(addsuffix -test,$(DIRS))

all: $(addsuffix -all,$(DIRS))
	$(CXX) -o hello hello.cpp -Wall -Werror

test: all $(addsuffix -test,$(DIRS))
	./hello
	make -C Lecture02 test

clean: $(addsuffix -clean,$(DIRS))
	rm -f hello *~

$(addsuffix -all,$(DIRS)):
	make -C $(subst -all,,$@) all

$(addsuffix -test,$(DIRS)):
	make -C $(subst -test,,$@) test

$(addsuffix -clean,$(DIRS)):
	make -C $(subst -clean,,$@) clean
