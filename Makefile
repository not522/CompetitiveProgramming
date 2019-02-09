.PHONY: all test clean

all:
	$(MAKE)	-C ./contest

test:
	$(MAKE)	-C ./tests

clean:
	$(MAKE)	clean -C ./contest
	$(MAKE)	clean -C ./tests
