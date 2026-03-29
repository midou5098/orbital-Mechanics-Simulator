#include "headers.h"




int main(void){
    SDLinit sdl("fuckass orbital",1920,1080);

    SDL_Event event;
    while(running){
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT){
                running=false
            }
        }
    }
    return 0







}







