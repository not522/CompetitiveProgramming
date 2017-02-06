CC = g++
FLAGS = -Wall -Wextra -Werror -Wold-style-cast -std=gnu++14 -I../include
SRCS = $(shell find * -name "*.cpp" | sort)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
DEPS = $(patsubst %.cpp,%.d,$(SRCS))

all: $(OBJS)

.cpp.o:
	$(CC) $< $(FLAGS) -O0 -c -MMD -MP -o $@

clean:
	rm -f $(shell find * -name "*.o")
	rm -f $(shell find * -name "*.d")

-include $(DEPS)
