.PHONY: all test clean

all:
	$(MAKE)	-C ./contest

test:
	$(MAKE)	-C ./test

clean:
	$(MAKE)	clean -C ./contest
	$(MAKE)	clean -C ./test
