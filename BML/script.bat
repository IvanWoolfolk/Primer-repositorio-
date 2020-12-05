echo compiling
gcc -c Main.c -o Main.o
gcc -c BML.c -o BML.o
gcc -c BOMBAS.c -o BOMBAS.o

gcc -o BOMBAS.exe Main.o BML.o BOMBAS.o

BOMBAS.exe

pause