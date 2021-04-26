
# A help function from https://marmelab.com/blog/2016/02/29/auto-documented-makefile.html
.DEFAULT_GOAL := help

.PHONY: help
help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

src = $(wildcard *.c)
obj = $(src:.c=.o)

CC=gcc
CFLAGS=-Wall -std=c99 -pthread

resources: $(obj)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: run
run: 
	./resources

.PHONY: clean
clean:
	rm -f $(obj) myprog

