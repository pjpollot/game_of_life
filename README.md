# The Conway's game of life

**author:** Pierre-Jean Pollot.

## Language

C - compiler gcc

## Installation and run

In the document root, enter in the command line:

```{sh}
make
```

Then run the program by typing:

```{sh}
./golife.run [number of iterations] [time in milliseconds]
```

none of these parameters is set, then the program **by default** will iterate `20 times` and change state each `500ms`.

## Description

This is a terminal-based program, so the printing is still quite simple.

## TODO

- Saving new seeds.
