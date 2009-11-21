all: generate6x6 generate8x8

generate8x8: generate8x8.c
	gcc -O3 -pg -o $@ $< -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient

generate6x6: generate6x6.c
	gcc -O3 -pg -o $@ $< -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient
 
.PHONY: clean
 
clean:
	rm -f generate8x8 generate8x8.o generate6x6 generate6x6.o

