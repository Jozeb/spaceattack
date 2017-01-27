#include <allegro.h>
#include "Ship.h"
#ifndef ENEMY_H
#define ENEMY_H





class Enemy : public Ship{
	
	private:
		BITMAP *image;
		BITMAP *weapon;
		BITMAP *impact;
		
		int horizontal_movement;
		int vertical_movement;
		
		bool alive;
		
	public:
		Enemy();
		
		bool isalive();
		
		void Move(BITMAP *okay);
		void Move_horizontal(BITMAP *okay);
		void Fire(BITMAP *okay);
		int give_x();
		int give_y();
		
		void change_ship();
		
		void destroy_ship();
		void speed_UP();
};

#endif
