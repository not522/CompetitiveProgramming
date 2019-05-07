SRCS = $(shell find * -name "*.cpp" | sort)
DIFF = $(patsubst %.cpp,%.diff,$(SRCS))

all:
	rime test

format: $(DIFF)

%.diff: %.cpp
	clang-format $< | diff - $<
	! clang-format $< -output-replacements-xml | grep -q "<replacement "
	touch $@

clean:
	rime clean
	rm -f $(shell find * -name "*.diff")
