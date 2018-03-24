vpath %.h ../include

test-101: test-101.c
	clang $^ -o $@

test-div: test-div.c
	clang $^ -o $@

all: test-div test-101
	./test-div
	./test-101
