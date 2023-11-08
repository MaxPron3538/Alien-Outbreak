#include"RenderSystem.h"
#include<stdio.h>

RenderSystem::RenderSystem(){

m_consolehandle = 0;

for(int r = 0;r < screenRows;r++){

    for(int c = 0;c < screenColumns;c++){

        m_backbuffer[r][c].symbol = 0;
        m_backbuffer[r][c].symbolColor = ConsoleColor_Gray;
        m_backbuffer[r][c].backgraundcolor = ConsoleColor_Black;

        m_screanbuffer[r][c] = m_backbuffer[r][c]; 
    }

}

}

void RenderSystem::initialize(){

m_consolehandle = GetStdHandle(STD_OUTPUT_HANDLE);

CONSOLE_CURSOR_INFO cursorinfo;

cursorinfo.dwSize = 1;
cursorinfo.bVisible = 0;
SetConsoleCursorInfo(m_consolehandle,&cursorinfo);

}

void RenderSystem::clear(){

for(int r = 0;r < screenRows;r++){

    for(int c = 0;c < screenColumns;c++){

     m_backbuffer[r][c].symbol = 0;
     m_backbuffer[r][c].backgraundcolor = ConsoleColor_Black;

    }
 }

}

void RenderSystem::drawChar(int r,int c,char symbol,ConsoleColor symbolColor,ConsoleColor backgraundcolor){

 if(r < 0 || c < 0 || r >= screenRows || c >= screenColumns) 
   return;

    m_backbuffer[r][c].symbol = symbol;
    m_backbuffer[r][c].symbolColor = symbolColor;
    m_backbuffer[r][c].backgraundcolor = backgraundcolor;

}

void RenderSystem::drawText(int r,int c,const char *Text,ConsoleColor symbolColor,ConsoleColor backgraundcolor){

  int column = c;
  char symbol = *Text;

  while(symbol != 0){

    drawChar(r,column,symbol,symbolColor,backgraundcolor);
  
    Text++;
    column++;
    symbol = *Text;
  }

}

void RenderSystem::flush(){

 bool screanbuffermodifieid = false;

 for(int r = 0;r < screenRows;r++){

    for(int c = 0;c < screenColumns;c++){
  
  if( (m_backbuffer[r][c].symbol          != m_screanbuffer[r][c].symbol) ||
      (m_backbuffer[r][c].symbolColor     != m_screanbuffer[r][c].symbolColor) ||
      (m_backbuffer[r][c].backgraundcolor != m_screanbuffer[r][c].backgraundcolor))

      {

       m_screanbuffer[r][c] = m_backbuffer[r][c];

       SetConsoleCursor(r,c);
       SetConsoleColor(m_screanbuffer[r][c].symbolColor,m_screanbuffer[r][c].backgraundcolor);
       printf("%c",m_screanbuffer[r][c]);

       screanbuffermodifieid = true;

      }

    }

 }

if(screanbuffermodifieid)

   SetConsoleCursor(0,0);

}

void RenderSystem::SetConsoleCursor(int r,int c){

  COORD cursorcoord;

  cursorcoord.X = c;
  cursorcoord.Y = r;
  SetConsoleCursorPosition(m_consolehandle,cursorcoord);

}

void RenderSystem::SetConsoleColor(ConsoleColor symbolColor,ConsoleColor backgraundcolor){

  unsigned char consolecolor = symbolColor | (backgraundcolor << 4);
  SetConsoleTextAttribute(m_consolehandle,consolecolor);

}