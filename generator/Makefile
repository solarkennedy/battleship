all: generate6x6 generate8x8 generate10x10
6: generate6x6
8: generate8x8
10: generate10x10

generate10x10: generate10x10.c
# Add a -pg to do profileing
	gcc -O3 -o $@ $<

generate8x8: generate8x8.c
# Add a -pg to do profileing
	gcc -O3 -o $@ $< 

generate6x6: generate6x6.c
# Add a -pg to do profileing
	gcc -O3 -o $@ $<
 
.PHONY: clean
 
clean:
	rm -f generate8x8 generate8x8.o generate6x6 generate6x6.o generate10x10 generate10x10.o

