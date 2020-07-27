CC = gcc
EXE = golife.run

compile: 
	$(CC) src/*.c -o $(EXE)

clean:
	rm $(EXE)