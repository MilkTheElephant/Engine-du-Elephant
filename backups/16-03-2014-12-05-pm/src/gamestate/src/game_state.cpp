#include "all_header.h"
#include "game_state_header.h"

bool game_state::quit_state;

bool game_state::return_quit_state()
{
    quitmtx.lock(); //lock mutex
    bool temp = game_state::quit_state; //temp var to store real var.
    quitmtx.unlock(); //unlock mutex.
    
    return temp; //return value.    
}

void game_state::change_quit_state (bool state)
{
    quitmtx.lock(); //lock mutex
    game_state::quit_state = state; // change state.
    quitmtx.unlock();
    return;
}



