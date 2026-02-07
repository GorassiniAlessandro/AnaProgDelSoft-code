OPZIONI = -Wall -Wfatal-errors

CambiaData.exe: Data.o CambiaData.o
	g++ -o CambiaData.exe Data.o CambiaData.o

Data.o: Data.cpp Data.hpp
	g++ -c $(OPZIONI) Data.cpp

CambiaData.o: CambiaData.cpp Data.hpp
	g++ -c $(OPZIONI) CambiaData.cpp

clean:
	rm -f CambiaData.exe Data.o CambiaData.o