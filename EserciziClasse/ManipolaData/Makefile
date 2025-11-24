ManipolaDate.exe: ManipolaDate.o MainDate.o
	g++ -o ManipolaDate.exe ManipolaDate.o MainDate.o

ManipolaDate.o: ManipolaDate.cpp ManipolaDate.hpp
	g++ -c -Wall ManipolaDate.cpp

MainDate.o: MainDate.cpp ManipolaDate.hpp
	g++ -c -Wall MainDate.cpp