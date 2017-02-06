CC = g++
FLAGS = -Wall -Wextra -Werror -Wold-style-cast -std=gnu++14 -I../include
SRCS = $(shell find * -name "*.cpp" | sort)
EXES = $(patsubst %.cpp,%_test,$(SRCS))
DEPS = $(patsubst %.cpp,%_test.d,$(SRCS))

all: $(EXES)

%_test: %.cpp
	$(CC) $< $(FLAGS) -O2 -MMD -MP -lboost_unit_test_framework -o $@
	mv $@ $@.exe
	./$@.exe
	mv $@.exe $@

clean:
	rm -f $(shell find * -name "*.d")
	rm -f $(shell find * -name "*.exe")
	rm -f $(shell find * -name "*_test")

-include $(DEPS)
