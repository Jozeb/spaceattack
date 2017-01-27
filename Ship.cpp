#include "Ship.h"


		Ship:: Ship() : pos_x(400), pos_y(400), health(100){}
		
		Ship::Ship(int x, int y) : pos_x (x), pos_y(y) {}
		
		Ship::Ship (int x, int y, int h) : pos_x (x), pos_y(y), health(h) {}
	
	int Ship::x(){
		return pos_x;
	}
	
	int Ship::y(){
		return pos_y;
	}
	int Ship::life(){
		return health;
	}
	
	void Ship::take_damage(int amount){
		
		health -=  amount;
	
		
	}
	
	int Ship::change_x(int ok){
		pos_x = ok;
	}
	
	int Ship::change_y(int ok){
		pos_y = ok;
	}
