echo compiling
gcc -c Menu.c -o Menu.o
gcc -c MaquinaEstados.h -o MaquinaEstados.o

gcc -o MaquinaEstados.exe Menu.o MaquinaEstados.o
.\MaquinaEstados.exe

pause