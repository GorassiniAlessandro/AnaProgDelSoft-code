OPZIONI = -Wall -Wfatal-errors

TestVettorePile.exe: VettorePile.o Pila.o
	g++ -o TestVettorePile.exe VettorePile.o Pila.o

VettorePile.o: VettorePile.cpp Pila.hpp
	g++ $(OPZIONI) -c VettorePile.cpp

Pila.o: Pila.cpp Pila.hpp
	g++ $(OPZIONI) -c Pila.cpp

clean:
	rm -f TestVettorePile.exe VettorePile.o Pila.o