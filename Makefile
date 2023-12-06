p2: proyecto2.c
  gcc proyecto2.c -o exe lm

p3: proyecto3.c
  gcc proyecto3.c -o exe

run: p3
  ./exe

clean:
  rm -f exe
