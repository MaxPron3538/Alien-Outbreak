#pragma once

#include<ctime>
#include"RenderSystem.h"
#include"GameObject.h"
#include"ConsoleColor.h"

const int gameobjectCountMax = 512;

class Game
{

public:

Game();

void SetupSystem();
void Initialize();
bool frame();
void ShutDown();

private:

void Render();
void Update(float dt);

GameObject *CreateObject(GameObjectType type,float x,float y,char symbol,ConsoleColor color,ConsoleColor backgcolor);
void destroyObject(GameObject *object);

private:

  bool m_IsGameActive;
  clock_t m_clockLastFrame; 
  RenderSystem m_rendersystem;

  GameObject *m_object[gameobjectCountMax];

  float m_shipFireCooldownTime;
  float m_alienFireCooldownTime;
  float m_alienAmplitudeTime;


};
