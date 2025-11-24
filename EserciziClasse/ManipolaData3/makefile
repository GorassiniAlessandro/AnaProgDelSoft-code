OPZIONI = -Wall -Wfatal-errors -O3

ClasseData.exe: ClasseData.o DriverData.o
	g++ -o ClasseData.exe ClasseData.o DriverData.o

ClasseData.o: ClasseData.cpp ClasseData.hpp
	g++ -c $(OPZIONI) ClasseData.cpp

DriverData.o: DriverData.cpp ClasseData.hpp
	g++ -c $(OPZIONI) DriverData.cpp

clean:
	rm -f ClasseData.exe ClasseData.o DriverData.o