Tycoon: main.o Game.o Player.o House.o Business.o Apt.o Property.o Tenant.o
	g++  -std=c++0x main.o Game.o Player.o House.o Business.o Apt.o Property.o Tenant.o -o Tycoon

main.o: main.cpp Game.cpp Game.h
	g++ -std=c++0x -c main.cpp

Game.o: Game.cpp Game.h Player.cpp Player.h House.h Business.h Apt.h Property.h
	g++ -std=c++0x -c Game.cpp

Player.o: House.cpp House.h Business.cpp Business.h Apt.cpp Apt.h
	g++ -std=c++0x -c Player.cpp

House.o: House.cpp House.h Property.cpp Property.h
	g++ -std=c++0x -c House.cpp

Business.o: Business.cpp Business.h Property.cpp Property.h
	g++ -std=c++0x -c Business.cpp

Apt.o: Apt.cpp Apt.h Property.cpp Property.h
	g++ -std=c++0x -c Apt.cpp

Property.o: Property.cpp Property.h Tenant.cpp Tenant.o
	g++ -std=c++0x -c Property.cpp

Tenant.o: Tenant.cpp Tenant.h
	g++ -std=c++0x -c Tenant.cpp

clean:
	del *.o Tycoon