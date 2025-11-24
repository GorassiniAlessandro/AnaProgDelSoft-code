OPZIONI = -Wall -Wfatal-errors -O3

Pila.exe: Pila.o DriverPila.o
	g++ -o Pila.exe Pila.o DriverPila.o

Pila.o: Pila.cpp Pila.hpp
	g++ -c $(OPZIONI) Pila.cpp

DriverPila.o: DriverPila.cpp Pila.hpp
	g++ -c $(OPZIONI) DriverPila.cpp

clean:
	rm -f Pila.exe Pila.o DriverPila.o