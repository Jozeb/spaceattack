#include <allegro.h>
#include <stdio.h>
#include "Ship.h"
#ifndef HERO_H
#define HERO_H





class Hero : public Ship {
	
	private:
		BITMAP *image;
		BITMAP *weapon;
		BITMAP *healthbar[7];
		BITMAP *explosion[16];
		SAMPLE *sound= load_wav("audio/explosion.wav");
		
		bool alive;	
	public:
		Hero();
		
		bool isalive();
		
		void Move(BITMAP *okay);
		void Fire(BITMAP *okay);
		
		void change_ship();
		void take_Ldamage();
		void take_Mdamage();
		void take_Hdamage();
		
		void destroy_ship();
			
	
};

#endif
