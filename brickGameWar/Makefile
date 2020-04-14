game.o: game.cpp
	g++ -c -Wall game.cpp

soldier.o: soldier.cpp
	g++ -c -Wall soldier.cpp

soldier: soldier.o game.o
	g++ soldier.o game.o -o soldier -lsfml-graphics -lsfml-window -lsfml-system