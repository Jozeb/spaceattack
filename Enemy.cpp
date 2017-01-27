#include "Enemy.h"



	Enemy::Enemy() : Ship(rand()%700+50,11){
		
		if (pos_x>650) 	// if out of boundries
			Ship::pos_x-=100;
			
			image = load_bitmap ("images/Ships/Enemy1.bmp", NULL);
			weapon = load_bitmap ("images/weapon/fire2.bmp", NULL);
			impact = load_bitmap ("images/ships/impact.bmp", NULL);
			horizontal_movement = 4;
			vertical_movement = 5;
			alive = true;
		}
		
		
		
	bool Enemy::isalive(){
		return alive;
	}	
		
	void Enemy::Move(BITMAP *okay){
			
			
			
			pos_y+= vertical_movement;
			pos_x += Enemy::horizontal_movement;
			if(pos_x<-1 || pos_x>700)
			Enemy::horizontal_movement *= -1;
			if(pos_y <10 || pos_y >500 )
			vertical_movement *= -1;
		
			
			draw_sprite(okay,image, pos_x,pos_y);
			
		}
		
	void Enemy::Move_horizontal(BITMAP *okay){
			
		if(pos_x<50 || pos_x>650)
		Enemy::horizontal_movement *= -1;
		
		pos_x += horizontal_movement;
		
		draw_sprite(okay,image, pos_x,pos_y);
		
	}	
		
		
	void Enemy::Fire(BITMAP *okay){
			
			for(int a=pos_y+50; a< 590; a++ )
			draw_sprite(okay, Enemy::weapon, Enemy::pos_x+30, a );
					
		}
		
	int Enemy::give_x(){
		int ok =Ship::x();
		return ok;
	}
	
	int Enemy::give_y(){
		return Ship::y();
	}
	
	void Enemy::destroy_ship(){
		draw_sprite(screen, impact, pos_x, pos_y );
		rest(2);
		clear_bitmap(image);
		alive = false;
	}	
	
	void Enemy::speed_UP(){
		
		horizontal_movement += 1;
		vertical_movement	+= 1;
	}
	
	void Enemy::change_ship(){
		
		image = load_bitmap ("images/Ships/Enemy2.bmp", NULL);
		
	}
