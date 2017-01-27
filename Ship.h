
#ifndef SHIP_H
#define SHIP_H


class Ship{
	
	protected:
		int pos_x;
		int pos_y;
		int health;
		
		
	public:
		Ship();
		Ship(int x, int y);
		Ship (int x, int y, int h);
	
	int x();
	int y();
	int life();
	
	int change_x(int ok);
	int change_y(int ok);
	
	void take_damage(int amount);

	
};

#endif
