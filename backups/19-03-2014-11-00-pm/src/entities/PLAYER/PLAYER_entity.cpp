/************************
Class methods for PLAYER class.
************************/

#include "all_entities.h"
#include "all_header.h"



GLfloat PLAYER::return_locationX()
{
    locationXmtx.lock();
    GLfloat tmp = locationX;
    locationXmtx.unlock();
    return tmp;
}

GLfloat PLAYER::return_locationY()
{
    locationYmtx.lock();
    GLfloat tmp = locationY;
    locationYmtx.unlock();
    return tmp;

}


void PLAYER::render()
{
        GLfloat pointTL[2] = {(this->locationX), (this->locationY + 0.0f)};
        GLfloat pointTR[2] = {(this->locationX + 0.1f), (this->locationY)};
        GLfloat pointBR[2] = {(this->locationX + 0.1f), (this->locationY - 0.1f)};
        GLfloat pointBL[2] = {(this->locationX), (this->locationY - 0.1f)};
        
        std::cout << "colours: " << colour4f[0] << " " << colour4f[1] << " " << colour4f[2] << " " << colour4f[3] << "\n";
        
        
                
        glLoadIdentity(); //load ID
        glBegin(GL_QUADS); //draw quad.
            glColor3f(1.0f,0.0f,0.0f);
            //glColor3f(SQUARE::colour4f[0],SQUARE::colour4f[1],SQUARE::colour4f[2]);
            glColor4f(this->colour4f[0],this->colour4f[1],this->colour4f[2],this->colour4f[3]);
            glVertex2f(pointTL[0],pointTL[1]);
            glVertex2f(pointTR[0],pointTR[1]);
            glVertex2f(pointBR[0],pointBR[1]);
            glVertex2f(pointBL[0],pointBL[1]);
        glEnd();

return;

}


void PLAYER::handle_keys(int key, map* mapptr)
{
    if (key == 119)
    {
            int entities = mapptr->return_number_of_entities();
            for (int i=0; i<entities; ++i)
            {
                if (mapptr->entityStack[i]->return_locationX() == (this->locationY + 0.1f)); //if there is an entity in the location we want to move to...
                {
                    mapptr->entityStack[i]->handle_collision(0,0); //then call that entities cikkision function. with n o collision parameters.
                    if (mapptr->entityStack[i]->return_solid() == true) //if the entity in the way is solid then just dont move.
                    {
                    return;
                    }
                    else if (mapptr->entityStack[i]->return_solid() == false) //is there isnt a solid entity in the place we want to move to, then move!
                    {
                    this->locationY = locationY + 0.1f; //if the key = W then move one up
                    return;
                    }
                }
            }
            
    }
    
    return;
}

void PLAYER::handle_collision(int x, int y)
{
    return;
}

void PLAYER::do_logic()
{
return;
}



PLAYER::PLAYER (GLfloat x, GLfloat y, GLfloat R, GLfloat G, GLfloat B, GLfloat A)
{
    std::cout << "new PLAYER entity created!\n\n";

    std::cout << "X = " << x << "\nY = " << y << "\n\n";
    this->locationX = x; //add the x and y to this entity.
    this->locationY = y; 
    std::cout << "location: " << this->locationX << "  " << this->locationY << "\n\n";
    this->colour4f[0] = 0.0f; //assign colours.
    this->colour4f[1] = 1.0f;
    this->colour4f[2] = 0.0f;
    this->colour4f[3] = 1.0f;
    
    return;
}
