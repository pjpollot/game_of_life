CC = gcc
EXE = golife

compile: 
	$(CC) src/*.c -o $(EXE)

clean:
	rm $(EXE)