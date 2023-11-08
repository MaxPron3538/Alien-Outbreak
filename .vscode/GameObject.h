#pragma once

#include"RenderSystem.h"

enum GameObjectType
{

GameObjectType_None,
GameObjectType_Ship,
GameObjectType_Bulet,
GameObjectType_Alien,
GameObjectType_Bulet_Alien

};


class GameObject
{

public:

  GameObject();

  void render(RenderSystem *rs);

  void update(float dt);

  bool intersect(GameObject *Object);



  void setType(GameObjectType type){  m_type = type; }
  GameObjectType getType(){ return m_type; }


  void setX(float x){  m_x = x; }
  float getX(){  return m_x;  }


  void setY(float y){  m_y = y; }
  float getY(){  return m_y;  }


  void setXspead(float speadX){  m_xSpead = speadX; }
  float getXspead(){  return m_xSpead; }


  void setYspead(float speady){  m_ySpead = speady; }
  float getYspead(){  return m_ySpead;  }
  
  void setSymbol(char symbol){  m_symbol = symbol; }
  char getSymbol(){ return m_symbol; }

  void setColor(ConsoleColor symbolColor){  m_symbolcolor = symbolColor; }
  ConsoleColor getColor(){  return m_symbolcolor; }

  void setBackground(ConsoleColor backroundcolor){  m_backgroundcolor = backroundcolor; }
  ConsoleColor getBackground(){  return m_backgroundcolor; }

private:

  GameObjectType m_type;

  float m_x;
  float m_y;
  float m_xSpead;
  float m_ySpead;

  char m_symbol;
  ConsoleColor m_symbolcolor;
  ConsoleColor m_backgroundcolor;


};
