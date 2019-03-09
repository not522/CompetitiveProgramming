.PHONY: all test clean

all:
	$(MAKE)	-C ./contest

test:
	$(MAKE)	-C ./tests

format:
	$(MAKE)	format -C ./contest

clean:
	$(MAKE)	clean -C ./contest
	$(MAKE)	clean -C ./tests
