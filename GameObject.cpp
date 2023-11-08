#include"GameObject.h"

GameObject::GameObject(){

    m_type = GameObjectType_None;

    m_x = 0.0;
    m_y = 0.0;

    m_xSpead = 0.0;
    m_ySpead = 0.0;

    m_symbol = '?';
    m_symbolcolor = ConsoleColor_White;
    m_backgroundcolor = ConsoleColor_Black; 
}


void GameObject::render(RenderSystem *rs){


   int row = int(m_y);
   int column = int(m_x);

   rs->drawChar(row,column,m_symbol,m_symbolcolor,m_backgroundcolor);

}

void GameObject::update(float dt){

   m_y += m_ySpead * dt;
   m_x += m_xSpead * dt;


}

bool GameObject::intersect(GameObject *object){

  if(   int(m_y)  ==  int(object->m_y)
     && int(m_x) ==  int(object->m_x))

    return true;    

 
 return false;
}
