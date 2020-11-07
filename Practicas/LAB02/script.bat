echo compiling
gcc -c Mines.c -o Mines.o
gcc -c Mines.h -o Mines2.o
gcc -o Mines.exe Mines.o Mines2.o
.\Mines.exe
pause