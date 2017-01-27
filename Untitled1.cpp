#include "Game.h"

Game::Game(){
	
	Hero_Ship = new Hero;
	
	for (int a=0; a<5; a++){
		Enemy_Ship[a] = new Enemy;
	}
}
Game::Game(int x){
	
	Hero_Ship = new Hero(x);
	
	for (int a=0; a<5; a++){
		Enemy_Ship[a] = new Enemy;
	}
	
	
}

Game::Set_Screen(char *filename){
	
	Game::temp1 = load_png(filename);
	
	blit(temp1,screen, 0,0,0,0,800,600);
	
}
	


