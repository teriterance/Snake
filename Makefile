game.o: game.cpp
	gcc -c -wall game.c

snake.o: snake.cpp
	gcc -c -wall snake.c

snake: snake.o game.o
	g++ -o snake snake.o game.o