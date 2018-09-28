CFLAGS = -Wall -std=c99 -g

all: clear main
	./main
clear:
	rm -rf main