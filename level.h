#pragma once
#include"ConsoleColor.h"
#include"RenderSystem.h"

const unsigned int levelRows = screenRows;
const unsigned int levelColumns = screenColumns;

const float shipSpeed = 35.0;
const float shipFireCooldown = 0.2;

const float bulletSpeed = 40.0;
const float bulletSpeedalien = 10.0;

const float alienAmplitude = 11.0;
const float alienSpeed = 0.23;
const float alienFireCooldown = 2.0;


const unsigned char	CellSymboll_Ship          = 'S';
const unsigned char	CellSymboll_Bullet	      = '|';
const unsigned char	CellSymboll_Alien	      = 'X';
const unsigned char	CellSymboll_Bullet_Alien  = 'p';

const unsigned char levelData0[levelRows][levelColumns + 1] =		
{
	"                                                                                         ",
	"            XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX           ",
	"                XXXX XX XXXXXXX  XXXXXXXXXXXXXXXXXXXXXX  XXXXXXX XX XXXX  X              ",
	"            XXXXXXXXX    X  X  X  X  XXX  XXXXXX  XXX  X  X  X  X    XXXXXXXXX           ",
	"                 XXXX    X  X  X  XXXXXXX  XXXX  XXXXXXX  X  X  X    XXXX                ",
	"                 XXXX             X   XXXXXXXXXXXXXX   X             XXXX                ",
	"                 X  X                  XXXXXXXXXXXX                  X  X                ",
	"                                       XX  XXXX  XX                                      ",
	"                                       XX  X  X  XX                                      ",
	"                                       X          X                                      ",
	"                                                                                         ",
	"                                                                                         ",
	"                                                                                         ",
	"                                                                                         ",
	"                                                                                         ",
	"                                                                                         ",
	"                                                                                         ",
	"                                                                                         ",
	"                                                                                         ",
	"                                                                                         ",
	"                                                                                         ",
	"                                                                                         ",
    "                                                                                         ",
	"                                             S                                           ",
	"                                            SSS                                          ",

};


unsigned char GetRenderCellSymboll(unsigned char CellSymboll){

    switch(CellSymboll){

     case CellSymboll_Ship:          return  202;
     case CellSymboll_Bullet:        return 179;
	 case CellSymboll_Bullet_Alien:  return 178;
     case CellSymboll_Alien:         return 2;

    }
    return '?';

}

ConsoleColor GetRenderCellSymbollColor(unsigned char CellSymboll){

	switch(CellSymboll){

     case CellSymboll_Ship:          return ConsoleColor_Blue;
     case CellSymboll_Bullet:        return ConsoleColor_Red;
	 case CellSymboll_Bullet_Alien:  return ConsoleColor_DarkRed;
     case CellSymboll_Alien:         return ConsoleColor_Green;

    }
    return ConsoleColor_Gray;

}

ConsoleColor GetRenderCellSymbollBackgroundColor(unsigned char cellSymboll){

     
	 switch(cellSymboll){


		case CellSymboll_Ship:        return ConsoleColor_DarkGray;

	 }
	 return ConsoleColor_Black;

}

