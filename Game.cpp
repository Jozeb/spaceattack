
#include "Game.h"



Game::Game(){
	
	GAMEOVER = false;
	active_enemies =3;
	
	Hero_Ship = new Hero;
	Game::buffer=create_bitmap(800,600);

	Game::background= create_bitmap(800,600);
	Game::temp1 = create_bitmap(800,600);
	
	for (int a=0; a<3; a++){
		Enemy_Ship[a] = new Enemy;
	}
}




void Game::Level_cleared(){
	

	temp1 = load_bitmap("images/splash/levelclear.bmp", NULL);
	
	masked_blit(temp1,buffer,0,0,80,300,648,78);
	
	destroy_bitmap(temp1);
}



void Game::Set_Screen(char *filename){
	
	Game::temp1 = load_bitmap(filename,NULL);
	
	blit(temp1,screen, 0,0,0,0,800,600);
	
	destroy_bitmap(temp1);

	
}



void Game::buffer_screen(){
	
	blit(buffer,screen,0,0,0,0,800,600);

	
}


void Game::Set_buffer(char *filename){
	
	Game::buffer = load_bitmap(filename,NULL);
	
}

void Game::Set_background(char *filename){
	
	Game::temp1 = load_bitmap(filename,NULL);
	blit(temp1,background,0,0,0,0,800,600);
	
}

void Game::Put_background(){
	blit (background,buffer,0,0,0,0,800,600);
}
	
void Game::move_hero(){
	

	Game::Hero_Ship->Move(Game::buffer);

	
}

void Game::move_enemy(int move_type){
	
	if (move_type ==0)
	for (int a=0; a<active_enemies; a++){
	if(Enemy_Ship[a]->isalive() )	
	Game::Enemy_Ship[a]->Move_horizontal(Game::buffer);
}

	else if (move_type ==1)
	for (int a=0; a<active_enemies; a++){
	if(Enemy_Ship[a]->isalive() )	
	Game::Enemy_Ship[a]->Move(Game::buffer);
}


//textprintf_ex(Game::buffer, font, 0, 0, makecol(255, 0, 0),-1,"x: %d", x_ofenemy()  );
//textprintf_ex(Game::buffer, font, 0, 20, makecol(255, 0, 0),-1,"y: %d", y_ofenemy()  );	
//textprintf_ex(Game::buffer, font, 0, 40, makecol(255, 0, 0),-1,"HEALTH: %d", Hero_Ship->life()  );	

}


void Game::fire_hero(){
	
	Game::Hero_Ship->Fire(Game::buffer );
	
	
}

void Game::fire_enemy(){
	for(int a=0; a<active_enemies; a++)
	if(Enemy_Ship[a]->isalive() )
	Game::Enemy_Ship[a]->Fire(Game::buffer);
}

int Game::x_ofenemy(){
	
	for(int a=0; a<active_enemies; a++){
		
	if(Enemy_Ship[a]->isalive() )
	return Enemy_Ship[a]->give_x();
}
	
	
}

int Game::y_ofenemy(){
	
	for(int a=0; a<active_enemies; a++){
		
	if(Enemy_Ship[a]->isalive() )
	return Enemy_Ship[a]->give_y();
}
	
}

void Game::check_firecollision(){
	
	for(int a=0; a<active_enemies; a++)
	if(Hero_Ship->x() > Enemy_Ship[a]->give_x() -20 && Hero_Ship->x() < Enemy_Ship[a]->give_x() +30 && Hero_Ship->y() > Enemy_Ship[a]->give_y() )
		if(Enemy_Ship[a]->isalive())
		Enemy_Ship[a]->destroy_ship();
		
}

void Game::check_damageintake(int amount){
	
	for(int a=0; a<active_enemies; a++)
	if(Enemy_Ship[a]->give_x()> Hero_Ship->x() -14 && Enemy_Ship[a]->give_x() < Hero_Ship->x() +14 && Enemy_Ship[a]->give_y() < Hero_Ship->y() ) {
	
	if(amount ==0)
	Hero_Ship->take_Ldamage();
	else if (amount ==1)
	Hero_Ship->take_Mdamage();
	else if (amount ==2)
	Hero_Ship->take_Hdamage();

}
}


bool Game::isGAMEOVER(){
	if(!Hero_Ship->isalive()){
	GAMEOVER = true;
	return true;
}
	
	for(int a=0; a<active_enemies; a++){
		if(Enemy_Ship[a]->isalive() ){
		
		GAMEOVER= false;
		return GAMEOVER;
	}
	}
	
	
	
	return true;
}

bool Game::isHero_alive(){
	
	if (Hero_Ship->isalive())
	return true;
	
	else
	Hero_Ship->destroy_ship();
	return false;
		
	
}

void Game::change_enemyno(int ok){
	active_enemies = ok;
	
}

void Game::Reset(int enemyno, bool speedup){
	
	Set_Screen("images/splash/loading.bmp");

	GAMEOVER= false;
	for(int a=0; a<active_enemies; a++)
	delete Enemy_Ship[a];
	
	active_enemies = enemyno;
	

	
	for(int a=0; a<active_enemies; a++){
	Enemy_Ship[a] = new Enemy;
	if(speedup)
	Enemy_Ship[a]->speed_UP();	
}
	rest(70);
	
	
	
}
