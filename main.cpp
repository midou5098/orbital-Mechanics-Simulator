#include "headers.h"




int main(void){
    SDLinit sdl("fuckass orbital",1280,720);
    uinter uic(sdl);

    SDL_Event event;
    int running=true;
    while(running){
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT){
                running=false;
            }
        }
        sdl.clear();
        uic.layout(1);
        sdl.present();
    };
    return 0;







}







