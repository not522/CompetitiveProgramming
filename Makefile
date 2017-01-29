CC = g++
FLAGS = -Wall -Wextra -Werror -std=gnu++14 -Ilib
SRCS = $(shell find contest/* -name "*.cpp")
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
DEPS = $(patsubst %.cpp,%.d,$(SRCS))
TESTSRCS = $(shell find test/* -name "*.cpp")
TESTEXES = $(patsubst %.cpp,%_test,$(TESTSRCS))
TESTDEPS = $(patsubst %.cpp,%.d,$(TESTSRCS))

all: $(OBJS)

test: $(TESTEXES)

.cpp.o:
	$(CC) $< $(FLAGS) -O0 -c -MMD -MP -o $@

%_test: %.cpp
	$(CC) $< $(FLAGS) -O2 -MMD -MP -lboost_unit_test_framework -o $@.exe
	$@.exe
	mv $@.exe $@

clean:
	rm -f $(shell find * -name "*.o")
	rm -f $(shell find * -name "*.d")
	rm -f $(shell find * -name "*.exe")
	rm -f $(shell find * -name "*_test")

-include $(DEPS)
-include $(TESTDEPS)
