CC=gcc
CFLAGS=-Wall -std=c99 -pthread
PROGS=zombies statistics
SOURCES = $(patsubst %,%.c,$(PROGS))


# A help function from https://marmelab.com/blog/2016/02/29/auto-documented-makefile.html
.DEFAULT_GOAL := help

.PHONY: help
help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'


all: $(PROGS)

$(PROGS):
	$(CC) $(CFLAGS) -o $@ $@.c

zip: u1.zip

u1.zip: all
	zip u1.zip $(SOURCES) Makefile

# zombies: # compiles zombie process
# 	gcc -Wall -std=c99 ./zombies.c -o zombies
#
# statistics: # compiles zombie process
# 	gcc -Wall -std=c99 -pthread ./statistics.c -o statistics

clean: 
	rm $(PROGS)
