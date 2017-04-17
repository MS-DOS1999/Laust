#include <gb/gb.h>
#include <stdio.h>
#include <stdlib.h>
#include <gb/console.h>

#include "Map_Tile/BlackClear.c"
#include "Map_Tile/BlackClearMap.c"

extern int xMove;
extern int yMove;


extern long xCounter;
extern long yCounter;

extern long xCounterForSpawn;
extern long yCounterForSpawn;


extern int tileInc;
extern int tileNumber;

extern const unsigned char Robot[];


void Spawn() BANKED{
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

    tileNumber = 0;

    for(tileInc = 0; tileInc <= 9; tileInc++){
        set_sprite_tile(tileInc, tileNumber);
        tileNumber = tileNumber + 2;
    }

    move_sprite(0, xMove, yMove);
    set_sprite_tile(0,0);
    SHOW_SPRITES;
}

void Black_Clear() BANKED{

    int x, y;

    set_bkg_data(0, 1, BlackClear);
    wait_vbl_done();
    for(y=0; y<=17; y++){
        if(y == 7){
            HIDE_SPRITES;
        }
        for(x=0; x<=19; x++){
            set_bkg_tiles(x, y, 1, 1, BlackClearMap);
            delay(1);
        }
    }



}

