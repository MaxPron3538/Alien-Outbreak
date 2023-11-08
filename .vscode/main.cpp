#include"game.h"

using namespace std;

int main(){

Game game;

game.SetupSystem();
game.Initialize();

while(game.frame());

game.ShutDown();

return 0;
}