CC = gcc
CFLAG = -O2 -std=c11
LINK = -lSDL2

compile: 
	$(CC) $(CFLAG) src/*.c -o golife $(LINK)

clean:
	rm golife