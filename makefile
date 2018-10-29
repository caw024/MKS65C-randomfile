all: file.o
	gcc file.o
run:
	./a.out
clean:
	rm -rf a.out file.txt file.o
file.o: file.c
	gcc -c file.c
