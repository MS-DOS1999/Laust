
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


extern char nomPlayer[6];
extern int IDMap;
extern int OutCheck;
extern int tileInc;
extern int tileNumber;
extern int StartPressed;
extern int A_Pressed;
extern int delayVerif;
extern void clearScreenLetter();


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



void Intro() BANKED{

    //INTRO//

      /* wait_vbl_done();
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

}*/
}

void Intro2() BANKED{
	
/*messageIntroPart1();
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
OutCheck = 1;
//INTRO//*/

}



