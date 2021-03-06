/*****************************************
Entity class declaration. describes the master entity class.
******************************************/
#ifndef ENTITY_HEADER_H
#define ENTITY_HEADER_H

#include <stdint.h>
#include "SDLheaders.h"
#include "all_header.h"

class map;

class base_entity
{
    boost::mutex locationXmtx;
    boost::mutex locationYmtx;
    boost::mutex colourmtx;
    
    public:
        virtual void do_logic(); //function to run this entities logic. takes an int as the current tick in order to calculate how much time it needs to do something.
        virtual void render(); //renders current object.
        virtual void handle_collision(int, int); //collision handler, takes ints to show what direction something hit it at.
        virtual void handle_keys(int, map*); //key handling function. Every object has one, this way we can make multiple entities act as one player.
        virtual bool return_solid(); //returns if the entity is solid or transparent.
        virtual GLfloat return_locationX(); //returns the entities X co-ordinate. used in collsion checking.
        virtual GLfloat return_locationY();
    private:
        bool solid; //tru if entity is collidable/solid, false if things can go through this entity. default to solid(true).
        GLfloat colour4f[4]; //array of four bytes for storing object's colours;Red,Green, Blue and Alpha.
        GLfloat colour3f[3]; //array of three bytes for storing object's colours;Red,Green and blue.
        GLfloat locationX; //the X and Y coords of the entity.
        GLfloat locationY;
};

#endif
