#pragma once

#include<windows.h>
#include"ConsoleColor.h"

const unsigned int screenRows = 25;
const unsigned int screenColumns = 90;

struct ConsoleSymbolData
{

char symbol;
ConsoleColor symbolColor;
ConsoleColor backgraundcolor;

};


class RenderSystem
{

public:

   RenderSystem();

   void initialize();
   void clear();
   void drawChar(int r,int c,char symbol,ConsoleColor symbolColor,ConsoleColor backgraundcolor);
   void drawText(int r,int c,const char *Text,ConsoleColor symbolColor,ConsoleColor backgraundcolor);
   void flush();

private:

   void SetConsoleCursor(int r,int c);
   void SetConsoleColor(ConsoleColor symbolColor,ConsoleColor backgraundcolor);

private:

   HANDLE m_consolehandle;

   ConsoleSymbolData m_backbuffer[screenRows][screenColumns];
   ConsoleSymbolData m_screanbuffer[screenRows][screenColumns];

};