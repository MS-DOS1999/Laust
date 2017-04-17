#include <gb/gb.h>
#include <stdio.h>
#include <stdlib.h>
#include <gb/console.h>

#include "Map_Tile/HomeTile.c"
#include "Map_Tile/Home.c"
#include "Map_Tile/HomeRoom.c"
#include "Map_Tile/HomeChest.c"
#include "Map_Tile/Alphabet.c"
#include "Map_Tile/textNES.c"
#include "Map_Tile/textNES1.c"
#include "Map_Tile/textORDI.c"
#include "Map_Tile/textORDI1.c"
#include "Map_Tile/TownTile.c"
#include "Map_Tile/TownMap.c"


extern int IDMap;

extern int i;

extern int xMove;
extern int yMove;

extern long xCounter;
extern long yCounter;

extern long xCounterForSpawn;
extern long yCounterForSpawn;

extern long WalkCounter;
extern long TabCollide[40];
extern int TabDirection[40];
extern int arrayLength;
extern int sizeOfTab;
extern int OffRight;
extern int OffLeft;
extern int OffUp;
extern int OffDown;

extern int Direction;

extern int OffMove;

extern int OutCheck;

extern int tileInc;




void Load_Home() BANKED{

    HIDE_BKG;
    wait_vbl_done();
    set_bkg_data(0,41, HomeTile);
    set_bkg_tiles(0,0,20,18,Home);
    SHOW_BKG;
    HIDE_SPRITES;
    //SPAWN//
    if(WalkCounter == 320){
    xCounter = 294;
    yCounter = 5;
    }
    else if(WalkCounter == 67){
      xCounter = 189;
      yCounter = 10;
    }
    else{
      xCounter = 294;
      yCounter = 5;
    }

    //SPAWN//

    OutCheck = 1;

}

void Out_Home() BANKED{
    if(WalkCounter == 320){
        IDMap = 2;
    }
    else if(WalkCounter == 200 || WalkCounter == 179){
        IDMap = 3;
    }


    if(WalkCounter == 304 && joypad() == J_A && Direction == 4 || WalkCounter == 325 && joypad() == J_A && Direction == 4){
        OffMove = 1;
        HIDE_WIN;
        tileInc = 0;
        set_win_data(128, 122, Alphabet);
        set_win_tiles(0, 0, 20, 5, textORDI);
        move_win(8, 104);
        SHOW_WIN;
        delay(1000);

        waitpad(J_A);


        HIDE_WIN;
        tileInc = 0;
        set_win_data(128, 122, Alphabet);
        set_win_tiles(0, 0, 20, 5, textORDI1);
        move_win(8, 104);
        SHOW_WIN;
        delay(1000);

        waitpad(J_A);

        HIDE_WIN;
        OffMove = 0;
        delay(500);

    }
}

void Col_Home() BANKED{


    TabCollide[0] = 299;
    TabCollide[1] = 278;
    TabCollide[2] = 257;
    TabCollide[3] = 236;
    TabCollide[4] = 216;
    TabCollide[5] = 195;
    TabCollide[6] = 174;
    TabCollide[7] = 152;
    TabCollide[8] = 131;
    TabCollide[9] = 110;
    TabCollide[10] = 90;
    TabCollide[11] = 69;
    TabCollide[12] = 70;
    TabCollide[13] = 91;
    TabCollide[14] = 113;
    TabCollide[15] = 114;
    TabCollide[16] = 115;
    TabCollide[17] = 136;
    TabCollide[18] = 157;
    TabCollide[19] = 178;
    TabCollide[20] = 199;
    TabCollide[21] = 220;
    TabCollide[22] = 241;
    TabCollide[23] = 262;
    TabCollide[24] = 283;
    TabCollide[25] = 304;
    TabCollide[26] = 325;
    TabCollide[27] = 282;
    TabCollide[28] = 281;
    TabCollide[29] = 301;
    TabCollide[30] = 322;
    TabCollide[31] = 321;
    TabCollide[32] = 320;
    TabCollide[33] = NULL;
    TabCollide[34] = NULL;
    TabCollide[35] = NULL;
    TabCollide[36] = NULL;
    TabCollide[37] = NULL;
    TabCollide[38] = NULL;
    TabCollide[39] = NULL;




    TabDirection[0] = 1;
    TabDirection[1] = 1;
    TabDirection[2] = 1;
    TabDirection[3] = 5;
    TabDirection[4] = 1;
    TabDirection[5] = 1;
    TabDirection[6] = 1;
    TabDirection[7] = 6;
    TabDirection[8] = 1;
    TabDirection[9] = 5;
    TabDirection[10] = 1;
    TabDirection[11] = 5;
    TabDirection[12] = 7;
    TabDirection[13] = 2;
    TabDirection[14] = 3;
    TabDirection[15] = 3;
    TabDirection[16] = 7;
    TabDirection[17] = 2;
    TabDirection[18] = 2;
    TabDirection[19] = NULL;
    TabDirection[20] = NULL;
    TabDirection[21] = 2;
    TabDirection[22] = 2;
    TabDirection[23] = 2;
    TabDirection[24] = 2;
    TabDirection[25] = 14;
    TabDirection[26] = 10;
    TabDirection[27] = 4;
    TabDirection[28] = 4;
    TabDirection[29] = 2;
    TabDirection[30] = 8;
    TabDirection[31] = 4;
    TabDirection[32] = 6;
    TabDirection[33] = NULL;
    TabDirection[34] = NULL;
    TabDirection[35] = NULL;
    TabDirection[36] = NULL;
    TabDirection[37] = NULL;
    TabDirection[38] = NULL;
    TabDirection[39] = NULL;



    arrayLength = 40;



}

void Load_HomeRoom() BANKED{


    HIDE_BKG;
    wait_vbl_done();
    set_bkg_data(0,40, HomeTile);
    set_bkg_tiles(0,0,20,18,HomeRoom);
    SHOW_BKG;

    HIDE_SPRITES;
    //SPAWN//
    xCounter = 294;
    yCounter = 5;
    //SPAWN//

    OutCheck = 2;


}

void Out_HomeRoom() BANKED{
    if(WalkCounter == 320){
        IDMap = 1;
    }

    if(WalkCounter == 176 && joypad() == J_A && Direction == 1 || WalkCounter == 198 && joypad() == J_A && Direction == 3 || WalkCounter == 178 && joypad() == J_A && Direction == 4){

        set_bkg_tiles(8, 8, 1, 2, HomeChest);
    }

    if(WalkCounter == 260 && joypad() == J_A && Direction == 3 || WalkCounter == 218 && joypad() == J_A && Direction == 2){
        OffMove = 1;
        HIDE_WIN;
        tileInc = 0;
        set_win_data(128, 122, Alphabet);
        set_win_tiles(0, 0, 20, 5, textNES);
        move_win(8, 104);
        SHOW_WIN;
        delay(1000);

        waitpad(J_A);


        HIDE_WIN;
        tileInc = 0;
        set_win_data(128, 122, Alphabet);
        set_win_tiles(0, 0, 20, 5, textNES1);
        move_win(8, 104);
        SHOW_WIN;
        delay(1000);

        waitpad(J_A);

        HIDE_WIN;
        OffMove = 0;
        delay(500);

    }

}

void Col_HomeRoom() BANKED{


    TabCollide[0] = 299;
    TabCollide[1] = 278;
    TabCollide[2] = 257;
    TabCollide[3] = 258;
    TabCollide[4] = 259;
    TabCollide[5] = 260;
    TabCollide[6] = 240;
    TabCollide[7] = 218;
    TabCollide[8] = 217;
    TabCollide[9] = 216;
    TabCollide[10] = 236;
    TabCollide[11] = 215;
    TabCollide[12] = 195;
    TabCollide[13] = 174;
    TabCollide[14] = NULL;
    TabCollide[15] = 175;
    TabCollide[16] = 176;
    TabCollide[17] = 198;
    TabCollide[18] = 178;
    TabCollide[19] = 199;
    TabCollide[20] = 220;
    TabCollide[21] = 241;
    TabCollide[22] = 262;
    TabCollide[23] = 283;
    TabCollide[24] = 304;
    TabCollide[25] = 325;
    TabCollide[26] = 324;
    TabCollide[27] = 323;
    TabCollide[28] = 322;
    TabCollide[29] = 321;
    TabCollide[30] = 320;
    TabCollide[31] = NULL;
    TabCollide[32] = NULL;
    TabCollide[33] = NULL;
    TabCollide[34] = NULL;
    TabCollide[35] = NULL;
    TabCollide[36] = NULL;
    TabCollide[37] = NULL;
    TabCollide[38] = NULL;
    TabCollide[39] = NULL;




    TabDirection[0] = 1;
    TabDirection[1] = 1;
    TabDirection[2] = 1;
    TabDirection[3] = 3;
    TabDirection[4] = 3;
    TabDirection[5] = 3;
    TabDirection[6] = 1;
    TabDirection[7] = 4;
    TabDirection[8] = 4;
    TabDirection[9] = 4;
    TabDirection[10] = 14;
    TabDirection[11] = 5;
    TabDirection[12] = 1;
    TabDirection[13] = 5;
    TabDirection[14] = NULL;
    TabDirection[15] = 3;
    TabDirection[16] = 7;
    TabDirection[17] = 3;
    TabDirection[18] = 12;
    TabDirection[19] = 2;
    TabDirection[20] = 2;
    TabDirection[21] = 2;
    TabDirection[22] = 2;
    TabDirection[23] = 2;
    TabDirection[24] = 2;
    TabDirection[25] = 8;
    TabDirection[26] = 4;
    TabDirection[27] = 4;
    TabDirection[28] = 4;
    TabDirection[29] = 4;
    TabDirection[30] = 6;
    TabDirection[31] = NULL;
    TabDirection[32] = NULL;
    TabDirection[33] = NULL;
    TabDirection[34] = NULL;
    TabDirection[35] = NULL;
    TabDirection[36] = NULL;
    TabDirection[37] = NULL;
    TabDirection[38] = NULL;
    TabDirection[39] = NULL;



    arrayLength = 40;



}

void Load_Town1() BANKED{


    HIDE_BKG;
    wait_vbl_done();
    set_bkg_data(0,80, TownTile);
    set_bkg_tiles(0,0,20,18,TownMap);
    SHOW_BKG;

    HIDE_SPRITES;
    //SPAWN//
    xCounter = 63;
    yCounter = 5;
    //SPAWN//

    OutCheck = 3;


}

void Col1_Town1(){

    TabCollide[0] = 164;
    TabCollide[1] = 163;
    TabCollide[2] = 162;
    TabCollide[3] = 140;
    TabCollide[4] = NULL;
    TabCollide[5] = 118;
    TabCollide[6] = 97;
    TabCollide[7] = 77;
    TabCollide[8] = 57;
    TabCollide[9] = 58;
    TabCollide[10] = 37;
    TabCollide[11] = 36;
    TabCollide[12] = 35;
    TabCollide[13] = 34;
    TabCollide[14] = 33;
    TabCollide[15] = 32;
    TabCollide[16] = 31;
    TabCollide[17] = 30;
    TabCollide[18] = 50;
    TabCollide[19] = 28;
    TabCollide[20] = 27;
    TabCollide[21] = 26;
    TabCollide[22] = 47;
    TabCollide[23] = 67;
    TabCollide[24] = 89;
    TabCollide[25] = 110;
    TabCollide[26] = 131;
    TabCollide[27] = 153;
    TabCollide[28] = NULL;
    TabCollide[29] = NULL;
    TabCollide[30] = NULL;
    TabCollide[31] = NULL;
    TabCollide[32] = NULL;
    TabCollide[33] = NULL;
    TabCollide[34] = NULL;
    TabCollide[35] = NULL;
    TabCollide[36] = NULL;
    TabCollide[37] = NULL;
    TabCollide[38] = NULL;
    TabCollide[39] = NULL;

    TabDirection[0] = 3;
    TabDirection[1] = 3;
    TabDirection[2] = 3;
    TabDirection[3] = 7;
    TabDirection[4] = NULL;
    TabDirection[5] = 2;
    TabDirection[6] = 2;
    TabDirection[7] = 8;
    TabDirection[8] = 4;
    TabDirection[9] = 8;
    TabDirection[10] = 7;
    TabDirection[11] = 3;
    TabDirection[12] = 3;
    TabDirection[13] = 3;
    TabDirection[14] = 3;
    TabDirection[15] = 3;
    TabDirection[16] = 3;
    TabDirection[17] = 5;
    TabDirection[18] = 3;
    TabDirection[19] = 7;
    TabDirection[20] = 3;
    TabDirection[21] = 5;
    TabDirection[22] = 1;
    TabDirection[23] = 9;
    TabDirection[24] = 1;
    TabDirection[25] = 1;
    TabDirection[26] = 6;
    TabDirection[27] = 1;
    TabDirection[28] = NULL;
    TabDirection[29] = NULL;
    TabDirection[30] = NULL;
    TabDirection[31] = NULL;
    TabDirection[32] = NULL;
    TabDirection[33] = NULL;
    TabDirection[34] = NULL;
    TabDirection[35] = NULL;
    TabDirection[36] = NULL;
    TabDirection[37] = NULL;
    TabDirection[38] = NULL;
    TabDirection[39] = NULL;


}

void Col2_Town1() BANKED{

TabCollide[0] = 174;
TabCollide[1] = 194;
TabCollide[2] = 214;
TabCollide[3] = 213;
TabCollide[4] = 212;
TabCollide[5] = 233;
TabCollide[6] = 254;
TabCollide[7] = 275;
TabCollide[8] = 296;
TabCollide[9] = 297;
TabCollide[10] = 303;
TabCollide[11] = 282;
TabCollide[12] = 262;
TabCollide[13] = 263;
TabCollide[14] = 264;
TabCollide[15] = 265;
TabCollide[16] = 308;
TabCollide[17] = 288;
TabCollide[18] = 310;
TabCollide[19] = 289;
TabCollide[20] = 268;
TabCollide[21] = 248;
TabCollide[22] = NULL;
TabCollide[23] = NULL;
TabCollide[24] = NULL;
TabCollide[25] = NULL;
TabCollide[26] = NULL;
TabCollide[27] = NULL;
TabCollide[28] = NULL;
TabCollide[29] = NULL;
TabCollide[30] = NULL;
TabCollide[31] = NULL;
TabCollide[32] = NULL;
TabCollide[33] = NULL;
TabCollide[34] = NULL;
TabCollide[35] = NULL;
TabCollide[36] = NULL;
TabCollide[37] = NULL;
TabCollide[38] = NULL;
TabCollide[39] = NULL;

TabDirection[0] = 1;
TabDirection[1] = 5;
TabDirection[2] = 3;
TabDirection[3] = 3;
TabDirection[4] = 5;
TabDirection[5] = 1;
TabDirection[6] = 1;
TabDirection[7] = 1;
TabDirection[8] = 1;
TabDirection[9] = 4;
TabDirection[10] = 2;
TabDirection[11] = 2;
TabDirection[12] = 4;
TabDirection[13] = 4;
TabDirection[14] = 4;
TabDirection[15] = 4;
TabDirection[16] = 9;
TabDirection[17] = 1;
TabDirection[18] = 2;
TabDirection[19] = 2;
TabDirection[20] = 2;
TabDirection[21] = 4;
TabDirection[22] = NULL;
TabDirection[23] = NULL;
TabDirection[24] = NULL;
TabDirection[25] = NULL;
TabDirection[26] = NULL;
TabDirection[27] = NULL;
TabDirection[28] = NULL;
TabDirection[29] = NULL;
TabDirection[30] = NULL;
TabDirection[31] = NULL;
TabDirection[32] = NULL;
TabDirection[33] = NULL;
TabDirection[34] = NULL;
TabDirection[35] = NULL;
TabDirection[36] = NULL;
TabDirection[37] = NULL;
TabDirection[38] = NULL;
TabDirection[39] = NULL;

}


void Out_Town1() BANKED{
    if(WalkCounter == 67){
        IDMap = 1;
    }

}

