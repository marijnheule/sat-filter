all: sat-filter

sat-filter: sat-filter.c
	gcc sat-filter.c -std=c99 -O2 -o sat-filter

clean:
	rm sat-filter
