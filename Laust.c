#include <gb/gb.h>
#include <stdio.h>
#include <stdlib.h>
#include <gb/console.h>
#include "Map_Tile/TitleScreenTiles.c"
#include "Map_Tile/TitleScreenMap.c"
#include "Map_Tile/PressStart.c"
#include "Map_Tile/By.c"
#include "Map_Tile/textIcon.c"
#include "IncludeCustom/MessageIntro.c"
#include "Map_Tile/MapTownTile.c"
#include "Map_Tile/MapTownMap.c"
#include "Map_Tile/Robot.c"
#include "Map_Tile/HomeTile.c"
#include "Map_Tile/Home.c"
#include "Map_Tile/HomeRoom.c"

#define S_PALETTE    0x10U




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

void textNext(){

    int A_PressedA = 0;
    int delayVerifA = 0;
    while(A_PressedA == 0){

        move_sprite(0, 155, 142);
        while(delayVerifA != 4000){
            delayVerifA++;
            if(joypad() == J_A){
                A_PressedA = 1;
                delayVerifA = 4000;
                NR52_REG = 0x80;
                NR51_REG = 0x11;
                NR50_REG = 0x55;

                NR10_REG = 0x09;
                NR11_REG = 0x5A;
                NR12_REG = 0x41;
                NR13_REG = 0x00;
                NR14_REG = 0x8A;
            }
        }
        delayVerifA = 0;
        move_sprite(0, 200, 200);
        while(delayVerifA != 4000){
            delayVerifA++;
            if(joypad() == J_A){
                A_PressedA = 1;
                delayVerifA = 4000;
                NR52_REG = 0x80;
                NR51_REG = 0x11;
                NR50_REG = 0x55;

                NR10_REG = 0x09;
                NR11_REG = 0x09;
                NR12_REG = 0x41;
                NR13_REG = 0x00;
                NR14_REG = 0x8A;
            }
        }
        delayVerifA = 0;

    }

}

void Intro(){

    //INTRO//

    /*
       wait_vbl_done();
       DISPLAY_OFF;
       set_bkg_data(0, 219, TitleScreenTiles);
       set_bkg_tiles(0,0,20,18,TitleScreenMap);
       SHOW_BKG;

       SPRITES_8x8;
       set_sprite_data(0, 10, PressStart);

       for(tileInc = 0; tileInc <= 9; tileInc++){
       set_sprite_tile(tileInc, tileInc);
       }

       move_sprite(0, 45, 110);
       move_sprite(1, 45 + 8, 110);
       move_sprite(2, 45 + 16, 110);
       move_sprite(3, 45 + 24, 110);
       move_sprite(4, 45 + 32, 110);
       move_sprite(5, 45 + 48, 110);
       move_sprite(6, 45 + 56, 110);
       move_sprite(7, 45 + 64, 110);
       move_sprite(8, 45 + 72, 110);
       move_sprite(9, 45 + 80, 110);

       set_sprite_data(10, 16, By);

       for(tileInc = 10; tileInc <= 25; tileInc++){
       set_sprite_tile(tileInc, tileInc);
       }

       move_sprite(10, 8, 144);
       move_sprite(11, 8 + 8, 144);
       move_sprite(12, 8 + 16, 144);
       move_sprite(13, 8 + 24, 144);
       move_sprite(20, 168 - 48, 144);
       move_sprite(21, 168 - 40, 144);
       move_sprite(22, 168 - 32, 144);
       move_sprite(23, 168 - 24, 144);
       move_sprite(24, 168 - 16, 144);
       move_sprite(25, 168 - 8, 144);

       SHOW_SPRITES;
       wait_vbl_done();
       DISPLAY_ON;

       while(StartPressed == 0){

       move_sprite(0, 45, 220);
       move_sprite(1, 45 + 8, 220);
       move_sprite(2, 45 + 16, 220);
       move_sprite(3, 45 + 24, 220);
       move_sprite(4, 45 + 32, 220);
       move_sprite(5, 45 + 48, 220);
       move_sprite(6, 45 + 56, 220);
       move_sprite(7, 45 + 64, 220);
       move_sprite(8, 45 + 72, 220);
       move_sprite(9, 45 + 80, 220);
       while(delayVerif != 4000){
       delayVerif++;
       if(joypad() == J_START){
       StartPressed = 1;
       delayVerif = 4000;

       NR52_REG = 0x80;
       NR51_REG = 0x11;
       NR50_REG = 0x77;

       NR10_REG = 0x40;
       NR11_REG = 0x9A;
       NR12_REG = 0x41;
    NR13_REG = 0x9A;
    NR14_REG = 0x98;

}
}
delayVerif = 0;

move_sprite(0, 45, 110);
move_sprite(1, 45 + 8, 110);
move_sprite(2, 45 + 16, 110);
move_sprite(3, 45 + 24, 110);
move_sprite(4, 45 + 32, 110);
move_sprite(5, 45 + 48, 110);
move_sprite(6, 45 + 56, 110);
move_sprite(7, 45 + 64, 110);
move_sprite(8, 45 + 72, 110);
move_sprite(9, 45 + 80, 110);
while(delayVerif != 4000){
    delayVerif++;
    if(joypad() == J_START){
        StartPressed = 1;
        delayVerif = 4000;

        NR52_REG = 0x80;
        NR51_REG = 0x11;
        NR50_REG = 0x77;

        NR10_REG = 0x40;
        NR11_REG = 0x9A;
        NR12_REG = 0x41;
        NR13_REG = 0x9A;
        NR14_REG = 0x98;

    }
}
delayVerif = 0;
}

if(StartPressed == 1){
    HIDE_SPRITES;

    for(tileInc = 1; tileInc <= 25; tileInc++){
        move_sprite(tileInc, 200, 200);
    }

    delay(10);
    clearScreenLetter();
}
messageIntroPart1();
SPRITES_8x8;
set_sprite_data(0, 1, textIcon);
set_sprite_tile(0, 0);
move_sprite(0, 155, 142);
SHOW_SPRITES;
textNext();
clearScreenLetter();
HIDE_SPRITES;
delay(200);

messageIntroPart2();
SHOW_SPRITES;
textNext();
clearScreenLetter();
HIDE_SPRITES;
printf("\n\n Ton nom: ");
for(delayVerif = 0; delayVerif < 6; delayVerif++){

    nomPlayer[delayVerif] = getchar();
    printf("%c", nomPlayer[delayVerif]);

}
clearScreenLetter();
HIDE_SPRITES;
delay(200);

messageIntroPart3(nomPlayer);
SHOW_SPRITES;
textNext();
clearScreenLetter();
HIDE_BKG;

*/
getchar(); //ligne pour changer de Palette
IDMap = 1;
//INTRO//
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
    }
    OffUp = 0;
    OffDown = 0;
    OffLeft = 0;
    OffRight = 0;

    //COLLISION ET MOUVEMENT//
}

void Spawn(){
    xMove = 8;
    yMove = 4;

    xCounterForSpawn = xCounter;
    yCounterForSpawn = yCounter;

    while(xCounterForSpawn != 0){
        xMove = xMove + 8;
        xCounterForSpawn = xCounterForSpawn - 21;
    }
    while(yCounterForSpawn != 0){
        yMove = yMove + 8;
        yCounterForSpawn = yCounterForSpawn - 1;
    }


    SPRITES_8x16;
    set_sprite_data(0, 20, Robot);
    for(tileInc = 0; tileInc <= 9; tileInc++){
        set_sprite_tile(tileInc, tileNumber);
        tileNumber = tileNumber + 2;
    }

    move_sprite(0, xMove, yMove);
    SHOW_SPRITES;
}


void Load_Home(){

    HIDE_BKG;
    wait_vbl_done();
    set_bkg_data(0,19, HomeTile);
    set_bkg_tiles(0,0,20,18,Home);
    SHOW_BKG;
    HIDE_SPRITES;
    //SPAWN//
    xCounter = 168;
    yCounter = 10;
    //SPAWN//

}

void Col_Home(){


    TabCollide[0] = 73;
    TabCollide[1] = 94;
    TabCollide[2] = 115;
    TabCollide[3] = 136;
    TabCollide[4] = 157;
    TabCollide[5] = 178; //SPAWN Home
    TabCollide[6] = 199;
    TabCollide[7] = 220;
    TabCollide[8] = 241;
    TabCollide[9] = 262;
    TabCollide[10] = 283;
    TabCollide[11] = 304;
    TabCollide[12] = 325;
    TabCollide[13] = 324;
    TabCollide[14] = 323;
    TabCollide[15] = 322;
    TabCollide[16] = 321;
    TabCollide[17] = 320;
    TabCollide[18] = 299;
    TabCollide[19] = 278;
    TabCollide[20] = 257;
    TabCollide[21] = 236;
    TabCollide[22] = 216;
    TabCollide[23] = 195;
    TabCollide[24] = 174;
    TabCollide[25] = 152;
    TabCollide[26] = 131;
    TabCollide[27] = 110;
    TabCollide[28] = 89;
    TabCollide[29] = 68;
    TabCollide[30] = 69;
    TabCollide[31] = 70;
    TabCollide[32] = 71;
    TabCollide[33] = 93;





    TabDirection[0] = 12;
    TabDirection[1] = 2;
    TabDirection[2] = 2;
    TabDirection[3] = 2;
    TabDirection[4] = 2;
    TabDirection[5] = 2;
    TabDirection[6] = 2;
    TabDirection[7] = 2;
    TabDirection[8] = 2;
    TabDirection[9] = 2;
    TabDirection[10] = 2;
    TabDirection[11] = 2;
    TabDirection[12] = 8;
    TabDirection[13] = 4;
    TabDirection[14] = 4;
    TabDirection[15] = 4;
    TabDirection[16] = 4;
    TabDirection[17] = 6;
    TabDirection[18] = 1;
    TabDirection[19] = 1;
    TabDirection[20] = 1;
    TabDirection[21] = 5;
    TabDirection[22] = 1;
    TabDirection[23] = 1;
    TabDirection[24] = 1;
    TabDirection[25] = 6;
    TabDirection[26] = 1;
    TabDirection[27] = 1;
    TabDirection[28] = 1;
    TabDirection[29] = 5;
    TabDirection[30] = 3;
    TabDirection[31] = 3;
    TabDirection[32] = 7;
    TabDirection[33] = 3;




    arrayLength = 34;



}


void MapChanger(){

    //CHANGEMENT DE MAP//

    switch(IDMap){
        case 0:
            break;
        case 1:
            Load_Home();
            Spawn();
            Col_Home();
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

    Intro();

    //BOUCLE PRINCIPALE//
    while(1){


        MapChanger();
        MoveAndColl();

    }
    //BOUCLE PRINCIPALE//

}




