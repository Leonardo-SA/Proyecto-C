p3: proyecto3.c
  gcc proyecto3.c -o exe

run: p3
  ./exe

clean:
  rm -f exe
