CC = g++
FLAGS = -Wall -Wextra -Werror -Wold-style-cast -std=gnu++14 -I../include
SRCS = $(shell find * -name "*.cpp" | sort)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
DEPS = $(patsubst %.cpp,%.d,$(SRCS))
DIFF = $(patsubst %.cpp,%.diff,$(SRCS))

all: $(OBJS)

.cpp.o:
	$(CC) $< $(FLAGS) -O0 -c -MMD -MP -o $@

format: $(DIFF)

%.diff: %.cpp
	clang-format $< | diff - $<
	! clang-format $< -output-replacements-xml | grep -q "<replacement "
	touch $@

clean:
	rm -f $(shell find * -name "*.o")
	rm -f $(shell find * -name "*.d")
	rm -f $(shell find * -name "*.diff")

-include $(DEPS)
