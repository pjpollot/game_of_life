CC = gcc
EXE = golife.run
LINK = -lSDL2

compile: 
	$(CC) src/*.c -o $(EXE) $(LINK)

clean:
	rm $(EXE)