#include <allegro.h>
#include "Ship.h"
#include "Hero.h"
#include "Enemy.h"
#ifndef GAME_H
#define GAME_H




class Game{
	
	private:
		
		
		
		BITMAP *buffer;
		BITMAP *temp1;
		BITMAP *background;
		BITMAP *levelclear;
		
		
		
		bool GAMEOVER;
		int active_enemies;
	
	public:
		
		Hero *Hero_Ship;
		Enemy *Enemy_Ship[10];
		
		Game();
		
		void Level_cleared();
		void Set_Screen(char *filename);
		void buffer_screen();
		void Set_buffer(char *filename);
		void Set_background	(char *filename);
		void Put_background ();
		
		void move_hero();
		void move_enemy(int move_type);
		void fire_hero();
		void fire_enemy();
		
		
		int x_ofenemy();
		int y_ofenemy();
		
		
		void check_firecollision();
		void check_damageintake(int amount);
		
		void change_enemyno(int ok);
		
		bool isGAMEOVER();
		bool isHero_alive();
		
		void Reset(int enemyno, bool speedup);
		
	
};

#endif
