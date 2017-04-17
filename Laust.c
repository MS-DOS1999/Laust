#include <gb/gb.h>
#include <stdio.h>
#include <stdlib.h>
#include <gb/console.h>




#include "Map_Tile/Robot.c"




// VARIABLE MAIN//


int IDMap = 0;

int i;

int xMove = 0;
int yMove = 0;

long xCounter = 0;
long yCounter = 0;

long xCounterForSpawn = 0;
long yCounterForSpawn = 0;

long WalkCounter = 0;
long TabCollide[40];
int TabDirection[40];
int arrayLength = 0;
int sizeOfTab;
int OffRight;
int OffLeft;
int OffUp;
int OffDown;

int Direction = 0;

int OffMove = 0;

int OutCheck = 0;

int incMove = 0;

int switchMove = 0;

char nomPlayer[6];
int tileInc = 0;
int tileNumber = 0;
int StartPressed = 0;
int A_Pressed = 0;
int delayVerif = 0;
//VARIABLE MAIN//





//PROTOTYPE//


extern void Intro();
extern void Intro2();
extern void Spawn();
extern void Black_Clear();


void clearScreenLetter(){

    int x, y;

    for(y=0; y<20; y++){
        for(x=0; x<30; x++){
            gotoxy(x, y);
            setchar(' ');
        }
    }

    gotoxy(0, 0);

}


void MoveAndColl(){

    //COLLISION ET MOUVEMENT//

    WalkCounter = xCounter + yCounter;

    for(i = 0; i < arrayLength; i++ ){
        if(TabCollide[i] == WalkCounter){
            switch(TabDirection[i]){

                case 1:
                    OffUp = 1;
                    OffDown = 0;
                    OffRight = 0;
                    OffLeft = 0;
                    break;
                case 2:
                    OffDown = 1;
                    OffUp = 0;
                    OffLeft = 0;
                    OffRight = 0;
                    break;
                case 3:
                    OffLeft = 1;
                    OffRight = 0;
                    OffUp = 0;
                    OffDown = 0;
                    break;
                case 4:
                    OffRight = 1;
                    OffLeft = 0;
                    OffUp = 0;
                    OffDown = 0;
                    break;
                case 5:
                    OffUp = 1;
                    OffLeft = 1;
                    OffRight = 0;
                    OffDown = 0;
                    break;
                case 6:
                    OffUp = 1;
                    OffRight = 1;
                    OffLeft = 0;
                    OffDown = 0;
                    break;
                case 7:
                    OffDown = 1;
                    OffLeft = 1;
                    OffRight = 0;
                    OffUp = 0;
                    break;
                case 8:
                    OffDown = 1;
                    OffRight = 1;
                    OffLeft = 0;
                    OffUp = 0;
                    break;
                case 9:
                    OffLeft = 1;
                    OffUp = 1;
                    OffRight = 1;
                    OffDown = 0;
                    break;
                case 10:
                    OffUp = 1;
                    OffRight = 1;
                    OffDown = 1;
                    OffLeft = 0;
                    break;
                case 11:
                    OffRight = 1;
                    OffDown = 1;
                    OffLeft = 1;
                    OffUp = 0;
                    break;
                case 12:
                    OffDown = 1;
                    OffLeft = 1;
                    OffUp = 1;
                    OffRight = 0;
                    break;
                case 13:
                    OffDown = 0;
                    OffUp = 0;
                    OffLeft = 1;
                    OffRight = 1;
                    break;
                case 14:
                    OffDown = 1;
                    OffUp = 1;
                    OffLeft = 0;
                    OffRight = 0;
                    break;
                default:
                    OffDown = 0;
                    OffUp = 0;
                    OffLeft = 0;
                    OffRight = 0;
                    break;
            }
        }
    }

    if(joypad() == J_DOWN){

        for(incMove = 0; incMove <= 7; incMove++){

            if(incMove <= 5 && !switchMove){
                set_sprite_tile(0, 2);
            }
            else if(incMove <= 5 && switchMove){
                set_sprite_tile(0, 4);
            }
            else{
                set_sprite_tile(0, 0);
            }
            if(OffDown != 1){
                yMove++;
            }
            delay(25);
            move_sprite(0, xMove, yMove);
            if(incMove == 7){
                if(!switchMove){
                    switchMove = 1;
                }
                else{
                    switchMove = 0;
                }
            }
        }
        if(OffDown != 1){
            yCounter = yCounter + 1;
        }

        Direction = 1;

    }


    else if(joypad() == J_RIGHT){

        for(incMove = 0; incMove <= 7; incMove++){

            if(incMove <= 5 && !switchMove){
                set_sprite_tile(0, 8);
            }
            else if(incMove <= 5 && switchMove){
                set_sprite_tile(0, 6);
            }
            else{
                set_sprite_tile(0, 6);
            }
            if(OffRight != 1){
                xMove++;
            }
            delay(25);
            move_sprite(0, xMove, yMove);
            if(incMove == 7){
                if(!switchMove){
                    switchMove = 1;
                }
                else{
                    switchMove = 0;
                }
            }
        }
        if(OffRight != 1){
            xCounter = xCounter + 21;
        }

        Direction = 2;

    }


    else if(joypad() == J_LEFT){
        for(incMove = 0; incMove <= 7; incMove++){

            if(incMove <= 5 && !switchMove){
                set_sprite_tile(0, 12);
            }
            else if(incMove <= 5 && switchMove){
                set_sprite_tile(0, 10);
            }
            else{
                set_sprite_tile(0, 10);
            }
            if(OffLeft != 1){
                xMove--;
            }
            delay(25);
            move_sprite(0, xMove, yMove);
            if(incMove == 7){
                if(!switchMove){
                    switchMove = 1;
                }
                else{
                    switchMove = 0;
                }
            }
        }
        if(OffLeft != 1){
            xCounter = xCounter - 21;
        }

        Direction = 3;

    }


    else if(joypad() == J_UP){
        for(incMove = 0; incMove <= 7; incMove++){

            if(incMove <= 5 && !switchMove){
                set_sprite_tile(0, 16);
            }
            else if(incMove <= 5 && switchMove){
                set_sprite_tile(0, 18);
            }
            else{
                set_sprite_tile(0, 14);
            }
            if(OffUp != 1){
                yMove--;
            }
            delay(25);
            move_sprite(0, xMove, yMove);
            if(incMove == 7){
                if(!switchMove){
                    switchMove = 1;
                }
                else{
                    switchMove = 0;
                }
            }
        }
        if(OffUp != 1){
            yCounter = yCounter - 1;
        }

        Direction = 4;

    }
    OffUp = 0;
    OffDown = 0;
    OffLeft = 0;
    OffRight = 0;

    //COLLISION ET MOUVEMENT//
}


extern void Load_Home();
extern void Out_Home();
extern void Col_Home();
extern void Load_HomeRoom();
extern void Out_HomeRoom();
extern void Col_HomeRoom();
extern void Load_Town1();
extern void Col1_Town1();
extern void Col2_Town1();
extern void Out_Town1();


void OutMatrix(){

    switch(OutCheck){

        case 1:
		SWITCH_ROM_MBC1(4);
            Out_Home();
            break;
        case 2:
		SWITCH_ROM_MBC1(4);
            Out_HomeRoom();
            break;
        case 3:
		SWITCH_ROM_MBC1(4);
            Out_Town1();
            break;
        default:
            break;


    }

}

void MapChanger(){

    //CHANGEMENT DE MAP//


    switch(IDMap){
        case 0:
            break;
        case 1:
            OffMove = 1;
	    SWITCH_ROM_MBC1(4);
            Col_Home();
	    SWITCH_ROM_MBC1(3);
            Black_Clear();
	SWITCH_ROM_MBC1(4);
            Load_Home();
	    SWITCH_ROM_MBC1(3);
            Spawn();
            OffMove = 0;
            break;
        case 2:
            OffMove = 1;
	SWITCH_ROM_MBC1(4);
            Col_HomeRoom();
	    SWITCH_ROM_MBC1(3);
            Black_Clear();
	SWITCH_ROM_MBC1(4);
            Load_HomeRoom();
	    SWITCH_ROM_MBC1(3);
            Spawn();
            OffMove = 0;
            break;
        case 3:
            OffMove = 1;
	    SWITCH_ROM_MBC1(3);
            Black_Clear();
	SWITCH_ROM_MBC1(4);
            Load_Town1();
	    SWITCH_ROM_MBC1(3);
            Spawn();
            OffMove = 0;
            break;
        default:
            break;
    }
    IDMap = 0;

    //FIN CHANGEMENT DE MAP//
}


//PROTOTYPE//




// MAIN //



void main(){
	
	SWITCH_ROM_MBC1(2);
	Intro();
	clearScreenLetter();
	SWITCH_ROM_MBC1(2);
	Intro2();

    //BOUCLE PRINCIPALE//
    while(1){


        MapChanger();
        if(!OffMove){
            MoveAndColl();
        }
        OutMatrix();
    }
    //BOUCLE PRINCIPALE//

}




