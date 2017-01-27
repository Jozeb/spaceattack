/*****************************************************************************************************************************************************************
							************************************ 		PROJECT: SPACE ATTACK 		*************************************





******************************************************************************************************************************************************************/

#include <allegro.h>
#include<stdio.h>

#include "Game.h"
#include "Ship.h"
#include "Hero.h"
#include "Enemy.h"



/*****************************************************************************************************************************************************************
					************************************ 		DEFINING PROTOTYPES AND GLOBAL VARIABLES 		**************************************/

void init();
void deinit();
void intro();
int menu();
int choose_player();



BITMAP *buffer;



/******************************************************************************************************************************************************************/





int main() {
	init();
	buffer = create_bitmap(800,600);
	BITMAP *temp;
	
	intro();
	
	SAMPLE *sound_fire1= load_wav("audio/laser1.wav");
	SAMPLE *sound_fire2= load_wav("audio/laser2.wav");
	SAMPLE *music;
	char s[18];
	
	


	Game *G = new Game;



 rest(60);
	
int option_selected;
do
{

option_selected = menu();





if (option_selected == 0){
if (choose_player() ==1)	
G->Hero_Ship->change_ship();
else if (choose_player() ==-1)	
continue;
			///////////////////////////////////// LEVEL 1		/////////////////////////////////////
G->Reset(3, true);
G->Set_background ( "images/space/space2.bmp");

G->Enemy_Ship[1]->change_y(100);
G->Enemy_Ship[2]->change_y(200);

while( !G->isGAMEOVER() ){
 
 G->Put_background();
 
 if(key[KEY_SPACE]){
 G->fire_hero();
 G->check_firecollision();
 play_sample(sound_fire1 , 500 , 125 , 1000 , false);
}
 
 G->move_hero();
 rest(15);
 if( G->x_ofenemy() >200 && G->x_ofenemy() <400 ){
 G->check_damageintake(0);
 G->fire_enemy();
play_sample(sound_fire2 , 500 , 125 , 1000 , false);
 G->isHero_alive();
 
}  

G->move_enemy(0);
 
G->buffer_screen();

if(key[KEY_ESC])
exit(1);

if(key[KEY_P]){
	while(!key[KEY_SPACE]){}
	
}
	
}// LEVEL 1 OVER!

if(G->isHero_alive()){     			// IF HERO IS ALIVE  CONTINUE TO NEXT STAGE //

G->Level_cleared();
while(!key[KEY_ENTER]){			// Wait for the user to press ENTER TO CONTINUE
G->buffer_screen();
}

}


				///////////////////////////////////// LEVEL 2		/////////////////////////////////////

G->Reset(5, true);
G->Set_background ( "images/space/space4.bmp");

G->Enemy_Ship[1]->change_y(100);
G->Enemy_Ship[2]->change_y(200);
G->Enemy_Ship[3]->change_y(300);
G->Enemy_Ship[4]->change_y(400);



while( !G->isGAMEOVER() ){
 
 G->Put_background();
 
 if(key[KEY_SPACE]){
 G->fire_hero();
 G->check_firecollision();
  play_sample(sound_fire1 , 500 , 125 , 1000 , false);
}
 
 G->move_hero();
 rest(15);
 if( G->x_ofenemy() >200 && G->x_ofenemy() <300 || G->x_ofenemy() >500 && G->x_ofenemy() <700 ){
 G->check_damageintake(0);
 G->fire_enemy();
 play_sample(sound_fire2 , 500 , 125 , 1000 , false);
 G->isHero_alive();
 
}  

G->move_enemy(0);
 
G->buffer_screen();

if(key[KEY_ESC])
exit(1);

if(key[KEY_P]){
	while(!key[KEY_SPACE]){}
	
}
 
}






if(G->isHero_alive()){     			// IF HERO IS ALIVE  CONTINUE TO NEXT STAGE //

G->Level_cleared();
while(!key[KEY_ENTER]){			// Wait for the user to press ENTER TO CONTINUE
G->buffer_screen();
}

}
			///////////////////////////////////// LEVEL 3		/////////////////////////////////////

G->Reset(5, false);
G->Set_background ( "images/space/space3.bmp");

for(int a=0; a<5; a++){

G->Enemy_Ship[a]->change_y(a*100);
G->Enemy_Ship[a]->change_ship();

}


while( !G->isGAMEOVER() ){
 
 G->Put_background();
 
 if(key[KEY_SPACE]){
 G->fire_hero();
 G->check_firecollision();
  play_sample(sound_fire1 , 500 , 125 , 1000 , false);
}
 
 G->move_hero();
 rest(15);
 if( G->x_ofenemy() >200 && G->x_ofenemy() <300 || G->x_ofenemy() >500 && G->x_ofenemy() <700 ){
 G->check_damageintake(1);
 G->fire_enemy();
 play_sample(sound_fire2 , 500 , 125 , 1000 , false);
 G->isHero_alive();
 
}  

G->move_enemy(1);
 
G->buffer_screen();

if(key[KEY_ESC])
exit(1);

if(key[KEY_P]){
	while(!key[KEY_SPACE]){}
	
}
 
}


// while the hero is still hanging


if(G->isHero_alive()){     			// IF HERO IS ALIVE  CONTINUE TO NEXT STAGE //

G->Level_cleared();
while(!key[KEY_ENTER]){			// Wait for the user to press ENTER TO CONTINUE
G->buffer_screen();
}
}


//////////////////////////////  LEVEL 4		////////////////////////////// 


G->Reset(10, true);
G->Set_background ( "images/space/space1.bmp");

for(int a=0; a<10; a++){

G->Enemy_Ship[a]->change_y(a*100 %570);
G->Enemy_Ship[a]->change_ship();

}

while( !G->isGAMEOVER() ){
 
 G->Put_background();
 
 if(key[KEY_SPACE]){
 G->fire_hero();
 G->check_firecollision();
  play_sample(sound_fire1 , 250 , 125 , 1000 , false);
}
 
 G->move_hero();
 rest(15);
 if( G->x_ofenemy() >200 && G->x_ofenemy() <300 || G->x_ofenemy() >500 && G->x_ofenemy() <700 ){
 G->check_damageintake(0);
 G->fire_enemy();
 play_sample(sound_fire2 , 250 , 125 , 1000 , false);
 G->isHero_alive();
 
}  

G->move_enemy(0);
 
G->buffer_screen();

if(key[KEY_ESC])
exit(1);

if(key[KEY_P]){
	while(!key[KEY_SPACE]){}
	
}
 
}















if(G->isHero_alive()){     			// IF HERO IS ALIVE  CONTINUE TO NEXT STAGE //

G->Level_cleared();
while(!key[KEY_ENTER]){			// Wait for the user to press ENTER TO CONTINUE
G->buffer_screen();
}
}

else
G->Set_Screen("images/splash/gameover.bmp");
delete G->Hero_Ship;
G->Hero_Ship = new Hero;
while(!key[KEY_ENTER])
{
}

















}						/// if the player wanted to play the game


/////////////////////			OPTION 					///////////////////////////
else if(option_selected ==1){		
	
	temp = load_bitmap("images/splash/option.bmp",NULL);
	BITMAP *cursor;
	int *a = new int;
	int *b = new int;
	*a = 324;
	*b =240;
	cursor = load_bitmap("images/ships/hero1.bmp",NULL);
	
	blit(temp,buffer,0,0,0,0,800,600);
	draw_sprite(buffer,cursor,*a,*b);
	blit(buffer, screen,0,0,0,0,800,600);
	option_selected=0;
	do{
	
	if(key[KEY_DOWN] || key[KEY_LEFT]){	
	
	option_selected++;
	*b+=66;
		if(option_selected>3){
		option_selected=0;
		*b = 248; 
	}
	blit(temp,buffer,0,0,0,0,800,600);
	draw_sprite(buffer,cursor,*a,*b);
}
	
	if(key[KEY_UP] || key[KEY_RIGHT] ){
	
	option_selected--;
	*b-= 66;
		if(option_selected<0){
		option_selected =3;	
		*b=476;
	}
	blit(temp,buffer,0,0,0,0,800,600);
	draw_sprite(buffer,cursor,*a,*b);
	}


	blit(buffer, screen,0,0,0,0,800,600);
	rest(100);
		
		if(key[KEY_ENTER]){
	if(option_selected!=3){
	
	stop_sample(music);
	sprintf(s,"audio/music%d.wav",option_selected+1);
	music= load_wav(s);
	play_sample(music , 500 , 125 , 1000 , true);
	}
	else
	stop_sample(music);
}

	
	
		
		
		
	}while(!key[KEY_BACKSPACE]);
	
	
	option_selected =7;
	
}					// if the player wants open options


else if (option_selected ==2){
	
	temp = load_bitmap("images/splash/extra.bmp",NULL);
	
	blit(temp,screen,0,0,0,0,800,600);
	
	while(!key[KEY_ENTER]){}
	
	
	
	
	
}







}while(option_selected !=3);


	deinit();
	return 0;

}
END_OF_MAIN()








void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 24;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}
	
	set_volume(255, 255);
	install_sound(DIGI_AUTODETECT , MIDI_AUTODETECT , NULL);

	install_timer();
	install_keyboard();
//	install_mouse();
	/* add other initializations here */
}

void deinit() {
	clear_keybuf();
	/* add other deinitializations here */
}

					///////////////////////////////				MENU				///////////////////////////////
int menu(){
	
	
	BITMAP *menu[4];
	int option_selected=0;
	char s[30];
	
	for (int n=0; n<4; n++){
	sprintf(s,"images/splash/menu/menu%d.bmp",n+1);
	menu[n] = load_bitmap(s, NULL);
	}
	
	blit(menu[option_selected], buffer,0,0,0,0,800,600);
	
	do{
	

	if(key[KEY_DOWN] || key[KEY_LEFT]){	
	
	option_selected++;
	
		if(option_selected>3)
		option_selected=0;

	blit(menu[option_selected], buffer,0,0,0,0,800,600);
}
	
	if(key[KEY_UP] || key[KEY_RIGHT] ){
	
	option_selected--;
		
		if(option_selected<0)
		option_selected=3;
	
	blit(menu[option_selected], buffer,0,0,0,0,800,600);
	}


	blit(buffer, screen,0,0,0,0,800,600);
	rest(100);

}while(!key[KEY_ENTER]);
	for(int a=0; a<4; a++){			// DESTROY BITMAPS AND FREE SPACE
		destroy_bitmap(menu[a]);
	}
	
	return option_selected;
}


					///////////////////////////////				CHOOSE PLAYER FUNCTION				///////////////////////////////

int choose_player(){
	buffer = create_bitmap(800,600);
	
	BITMAP *menu[2];
	int option_selected=0;
	
	char s[34];
	
	for (int n=0; n<2; n++){
	sprintf(s,"images/splash/choose/select%d.bmp",n+1);
	menu[n] = load_bitmap(s, NULL);
	}
	
	blit(menu[option_selected], buffer,0,0,0,0,800,600);
	
do{
	
	

	if(key[KEY_DOWN] || key[KEY_LEFT]){	
	
	option_selected++;
	
		if(option_selected>1)
		option_selected=0;

	blit(menu[option_selected], buffer,0,0,0,0,800,600);
}
	
	if(key[KEY_UP] || key[KEY_RIGHT] ){
	
	option_selected--;
		
		if(option_selected<0)
		option_selected=1;
	
	blit(menu[option_selected], buffer,0,0,0,0,800,600);
	}
	
	if(key[KEY_BACKSPACE])
	return -1;

	
	blit(buffer, screen,0,0,0,0,800,600);
	rest(100);
}while(!key[KEY_ENTER]);
	for(int a=0; a<2; a++){			// DESTROY BITMAPS AND FREE SPACE
	destroy_bitmap(menu[a]);
	}
	
	return option_selected;
	
}


void intro(){
	
	BITMAP *temp[3];		
	temp[0]= load_bitmap("images/splash/menu/menu1.bmp", NULL);
	temp[1]= load_bitmap("images/splash/title2.bmp", NULL);
	temp[2]= load_bitmap("images/splash/title.bmp", NULL);
	
	
	for(int a=0; a<3; a++)
	masked_blit(temp[a], buffer, 0,0,0,0,800,600);
	blit(buffer,screen,0,0,0,0,800,600);
	while(!key[KEY_ENTER]) {}  // wait for user input
	
	for(int a=0; a<800; a+=5){
	
	blit(temp[0], buffer, 0,0,0,0,800,600);
	draw_sprite(buffer,temp[2],-a,0);
	masked_blit(temp[1], buffer,0,0,a,0,800,600);
	
	blit(buffer,screen,0,0,0,0,800,600);
	
}
	for(int a=0; a<3; a++)
	destroy_bitmap(temp[a]);
	
}
