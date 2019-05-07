SRCS = $(shell find * -name "*.hpp" | sort)
DIFF = $(patsubst %.hpp,%.diff,$(SRCS))

format: $(DIFF)

%.diff: %.hpp
	clang-format $< | diff - $<
	! clang-format $< -output-replacements-xml | grep -q "<replacement "
	touch $@

clean:
	rm -f $(shell find * -name "*.diff")
