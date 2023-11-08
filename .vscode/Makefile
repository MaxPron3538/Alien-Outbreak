CCX=g++


GAME3.o:  RenderSystem.o  GameObject.o  game.o  main.o 
	$(CCX) -o game03.exe  RenderSystem.o GameObject.o game.o main.o

RenderSystem.o: RenderSystem.cpp
	$(CCX) -o RenderSystem.o -c RenderSystem.cpp

GameObject.o: GameObject.cpp
	$(CCX) -o GameObject.o -c GameObject.cpp

game.o: game.cpp
	$(CCX) -o game.o -c game.cpp


main.o: main.cpp
	$(CCX) -o main.o -c main.cpp