CC = gcc
OBJ = command.o game.o game_loop.o graphic_engine.o space.o
all: ejecutar clean
ejecutar: $(OBJ) libscreen.a libscreen.h
	$(CC) -o juego $(OBJ) -L/home/kitos/pp/seed-src -lscreen

command.o: command.h command.c
	$(CC) -c command.c 
game.o: game.h game.c
	$(CC) -c game.c
game_loop.o: game_loop.c
	$(CC) -c game_loop.c
graphic_engine.o: graphic_engine.h graphic_engine.c
	$(CC) -c graphic_engine.c
space.o: space.h space.c
	$(CC) -c space.c
clean:
	rm -rf *.o
start: hormiguero.dat
	./juego hormiguero.dat
