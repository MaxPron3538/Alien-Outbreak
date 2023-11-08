#include<cstdlib>
#include<cstdio>
#include<cmath>
#include"game.h"
#include"input.h"
#include"level.h"


Game::Game(){

    m_IsGameActive = true;

    m_clockLastFrame = 0;

    for(int i = 0;i < gameobjectCountMax;i++){

        m_object[i] = 0;

     m_shipFireCooldownTime =  0.0;
     m_alienFireCooldownTime = 0,0;
     m_alienAmplitudeTime  =   0.0;

    }
}

void Game::SetupSystem(){

    srand(time(0));

    m_rendersystem.initialize();
}

void Game::Initialize(){

 m_shipFireCooldownTime = 0.0;
 m_alienFireCooldownTime = 0,0;
 m_alienAmplitudeTime = 0.0;

 for(int r = 0;r < levelRows;r++){

     for(int c = 0;c < levelColumns;c++){
                                                      
     unsigned char CellSymboll = levelData0[r][c];

     switch(CellSymboll){

         case CellSymboll_Ship:
        {
        
           CreateObject(GameObjectType_Ship,(c + 0.5),r,GetRenderCellSymboll(CellSymboll),
                                GetRenderCellSymbollColor(CellSymboll),
                                GetRenderCellSymbollBackgroundColor(CellSymboll));
                                   
        break;
        }

        case CellSymboll_Alien:
        {
          
            GameObject *alien =  CreateObject(GameObjectType_Alien,(c + 0.5),r,GetRenderCellSymboll(CellSymboll),
                                 GetRenderCellSymbollColor(CellSymboll),
                                 GetRenderCellSymbollBackgroundColor(CellSymboll));


             alien->setXspead(alienAmplitude * cos(m_alienAmplitudeTime));
             alien->setYspead(alienSpeed);
             break;
                 
        }

     }

   }

 }

}

bool Game::frame(){

clock_t clockNow = clock();

clock_t deltaClock = clockNow - m_clockLastFrame;

float deltaTime = float(deltaClock) / CLOCKS_PER_SEC;

m_clockLastFrame = clockNow;

Render();

Update(deltaTime);

return m_IsGameActive;
}

void Game::ShutDown(){

  for(int i = 0;i < gameobjectCountMax;i++){

    if(m_object[i] != 0){
      
      delete m_object[i];

      m_object[i] = 0;

    }
  }

}


void Game::Render(){

  m_rendersystem.clear();

  int objectCount = 0;

  for(int i = 0;i < gameobjectCountMax;i++){
      if(m_object[i] != 0)
      {
        m_object[i]->render( &m_rendersystem );
        objectCount++;
    }
  }

 char buffer[64];
 sprintf(buffer,"Obj : %d",objectCount);
 m_rendersystem.drawText(0,0,buffer,ConsoleColor_Gray,ConsoleColor_Black);


 m_rendersystem.flush();

}

GameObject *Game::CreateObject(GameObjectType type,float x,float y,char symbol,ConsoleColor color,ConsoleColor backgcolor){
     
     for(int i = 0;i < gameobjectCountMax;i++){

         if( m_object[i] == 0){
            
         GameObject *object = new GameObject();

         object->setType(type);
         object->setX(x);
         object->setY(y);
         object->setSymbol(symbol);
         object->setColor(color);
         object->setBackground(backgcolor);

         m_object[i] = object;
         return object;

        }
    }
    return 0;
}

void Game::destroyObject(GameObject *object){

    for(int i = 0;i < gameobjectCountMax;i++){

        if(m_object[i] == object){

            delete m_object[i];

            m_object[i] = 0;

            return;
        }
    }

}


void Game::Update(float dt)
{

  bool haveAliveAliens = false;

  for(int i = 0;i < gameobjectCountMax;i++){

    GameObject *object = m_object[i];

    if(object != 0){
   
       object->update(dt);

       switch(object->getType())
       {

            case GameObjectType_Ship:
            {   
                if(object->getX() < 0)

                  object->setX(0);

                else
            
                if(object->getX() > screenColumns - 1)

                   object->setX(screenColumns - 1 );
                

              if(IsKeyDown(VK_LEFT))

                  object->setXspead(-shipSpeed);

              else    
               
              if(IsKeyDown(VK_RIGHT))
              
                  object->setXspead(shipSpeed);

              else
              
                  object->setXspead(0.0);
              
              if(IsKeyDown(VK_SPACE)){

              if( m_shipFireCooldownTime <= 0.0){


                  m_shipFireCooldownTime = shipFireCooldown;

               GameObject *bulet = CreateObject(GameObjectType_Bulet,object->getX(),object->getY() - 1,GetRenderCellSymboll(CellSymboll_Bullet),

               GetRenderCellSymbollColor(CellSymboll_Bullet),GetRenderCellSymbollBackgroundColor(CellSymboll_Bullet));

              
               bulet->setYspead(-bulletSpeed);
                           
                 }

              }  

            }
                        
            case GameObjectType_Bulet:
            {
              if(object->getY() < 0)
              {

                destroyObject(object);

              }
              else
              {
                for(int e = 0;e < gameobjectCountMax;e++)
                {

                  GameObject *anotherobject = m_object[e];

                  if(anotherobject != 0)
                  {
                    if(anotherobject->getType() == GameObjectType_Alien)
                    {
                       if(anotherobject->intersect(object))
                       {
                          destroyObject(anotherobject);
                          destroyObject(object);
                         
                         break;
                       }
                    }
                  } 
                }
              }              
              break;

            }

            case GameObjectType_Alien:
            {

             haveAliveAliens = true;

             if( m_alienFireCooldownTime <= 0.0){

             m_alienFireCooldownTime = alienFireCooldown;

             GameObject *alienbullet = CreateObject(GameObjectType_Bulet_Alien,object->getX() + 32,object->getY() + 8,
             GetRenderCellSymboll(CellSymboll_Bullet_Alien),GetRenderCellSymbollColor(CellSymboll_Bullet_Alien),
             GetRenderCellSymbollBackgroundColor(CellSymboll_Bullet_Alien));

             alienbullet->setYspead(bulletSpeedalien);

             }

             if(object->getY() >= screenRows){

                m_IsGameActive = false;

             }
             else
             {

                 object->setXspead(alienAmplitude * cos(m_alienAmplitudeTime));

             }

             break;
            }

             case GameObjectType_Bulet_Alien:
             {
              

              break;  
             }




         }

      }

  }

  if(m_shipFireCooldownTime > 0.0 )
    
    m_shipFireCooldownTime -= dt;

  if(m_alienFireCooldownTime > 0.0 )

    m_alienFireCooldownTime -= dt;
    
  m_alienAmplitudeTime += dt;

  if(!haveAliveAliens)

    m_IsGameActive = false;

}
