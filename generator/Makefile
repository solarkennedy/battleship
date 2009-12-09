all: generate6x6 generate8x8

generate8x8: generate8x8.c
# Add a -pg to do profileing
	gcc -O3 -o $@ $< -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient -lpthread

generate6x6: generate6x6.c
# Add a -pg to do profileing
	gcc -O3 -o $@ $< -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient -lpthread
 
.PHONY: clean
 
clean:
	rm -f generate8x8 generate8x8.o generate6x6 generate6x6.o

