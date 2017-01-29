CC = g++
FLAGS = -Wall -Wextra -Werror -std=gnu++14 -Ilib
SRCS = $(shell find contest/* -name "*.cpp")
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
DEPS = $(patsubst %.cpp,%.d,$(SRCS))
TESTSRCS = $(shell find test/* -name "*.cpp")
TESTEXES = $(patsubst %.cpp,%.exe,$(TESTSRCS))
TESTDEPS = $(patsubst %.cpp,%.d,$(TESTSRCS))

all: $(OBJS)

test: $(TESTEXES)

.cpp.o:
	$(CC) $< $(FLAGS) -O0 -c -MMD -MP -o $@

%.exe: %.cpp
	$(CC) $< $(FLAGS) -O2 -MMD -MP -lboost_unit_test_framework -o $@ && $@

clean:
	rm -f $(shell find * -name "*.o")
	rm -f $(shell find * -name "*.d")
	rm -f $(shell find * -name "*.exe")

-include $(DEPS)
-include $(TESTDEPS)
