
#include "Hero.h"




		Hero::Hero(){
			image = load_bitmap ("images/ships/Hero1.bmp", NULL);
			weapon = load_bitmap ("images/weapon/fire1.bmp", NULL);
			alive = true;
		
					/*			///    INTIALIZING EXPLOSION 		/// 				*/
			BITMAP *temporary; 
			int count =0;
			temporary = load_bitmap("images/ships/explode.bmp", NULL);
				
			
			
				for(int a=0; a<16; a++)
				explosion[a]= create_bitmap(64,64);
		
				for(int a=0; a<256; a+=64){
				for(int b=0; b<256; b+= 64){
				blit (temporary,explosion[count], b,a,0,0,64,64);
				count++;
			}
			}
			destroy_bitmap(temporary);
		
					/*			/// 	INITIAZLING HEALTHBAR		///					*/	
			
	char s[27];	
	
	for (int n=0; n<7; n++)
	healthbar[n]= create_bitmap(209,64);	
	for (int n=0; n<7; n++){
	sprintf(s,"images/Health/health%d.bmp",n);
	healthbar[n] = load_bitmap(s, NULL);
	}
			
			
}

		bool Hero::isalive(){
			if(life() <0)
			alive =false;
		return alive;
	}
		
		void Hero::Move(BITMAP *okay){
			
			
			if(key[KEY_LEFT])
			pos_x-=5;
			
			if (key[KEY_UP])			
			pos_y-=5;
			
			if (key[KEY_RIGHT])
			pos_x+= 5;
			
			if(key[KEY_DOWN])
			pos_y+= 5;
			
			if(pos_x <0)
			pos_x=0;
			if(pos_y <0)
			pos_y=0;
			
			if(pos_x>760)
			pos_x=760;
			if(pos_y>560)
			pos_y=560;
			
			 
		draw_sprite(okay, Hero::image, Hero::pos_x, Hero::pos_y);
		
		if(life()==100)
		draw_sprite(okay, healthbar[6], 0, 536);
		else if (life() >80)
		draw_sprite(okay, healthbar[5], 0, 536);
		else if (life() >60)
		draw_sprite(okay, healthbar[4], 0, 536);
		else if (life() >40)
		draw_sprite(okay, healthbar[3], 0, 536);
		else if (life() >20)
		draw_sprite(okay, healthbar[2], 0, 536);
		else 
		draw_sprite(okay, healthbar[1], 0, 536);
		}
		
		void Hero::Fire(BITMAP *okay){
			
			for(int a=pos_y+15; a> 0; a-- )
			draw_sprite(okay, Hero::weapon, Hero::pos_x+20, a );
					
		}
		
		void Hero::destroy_ship(){
		
		if ( life() <0 )
		alive = false;
		draw_sprite(screen, healthbar[0], 0, 536);
		for(int a=0; a<16; a++){
			draw_sprite(screen,explosion[a],pos_x,pos_y);
			rest(100);	
		}
		play_sample(sound , 500 , 125 , 1000 , false);
		
		
		
		clear_bitmap(image);
	}	
	
	
	void Hero::take_Ldamage(){
		
		Ship::take_damage(1);
		
	}
	
	void Hero::take_Mdamage(){
		
		Ship::take_damage(2);
		
	}
	
	void Hero::take_Hdamage(){
		
		Ship::take_damage(3);
		
	}
	
	void Hero::change_ship(){
		
	
	
		image = load_bitmap ("images/Ships/hero2.bmp", NULL);
		
	}
