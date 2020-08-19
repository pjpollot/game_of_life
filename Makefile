CC = gcc
CFLAG = -O2 -std=c11
LINK = -lSDL2

.PHONY: compile clean

compile: golife

clean:
	rm golife src/*.o

golife: src/*.o
	gcc $(CFLAG) src/*.o -o golife $(LINK)

src/*.o: src/*.c
	cd src && gcc $(CFLAG) *.c -c && cd ..
