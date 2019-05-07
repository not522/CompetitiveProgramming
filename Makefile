.PHONY: all test clean

all:
	$(MAKE)	-C ./contest

test:
	$(MAKE)	-C ./tests

format:
	$(MAKE)	format -C ./contest
	$(MAKE)	format -C ./include
	$(MAKE)	format -C ./tests

clean:
	$(MAKE)	clean -C ./contest
	$(MAKE)	clean -C ./include
	$(MAKE)	clean -C ./tests
