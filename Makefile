CC = g++
FLAGS = -O0 -Wall -Wextra -Werror -std=gnu++14 -I$(LIB_PATH)
SRCS = $(shell find * -name "*.cpp")
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
DEPS = $(patsubst %.cpp,%.d,$(SRCS))

all: $(OBJS);

.cpp.o:
	$(CC) $< $(FLAGS) -c -MMD -MP -o $@

clean:
	rm -f $(shell find * -name "*.o")
	rm -f $(shell find * -name "*.d")

-include $(DEPS)
