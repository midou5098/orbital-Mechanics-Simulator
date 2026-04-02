#include "headers.h"




int main(void){
    SDLinit sdl("fuckass orbital",1280,720);
    uinter uic(sdl);
    int mode=1;
    SDL_Event event;
    int running=true;
    while(running){
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT){
                running=false;
            }
            uic.handle(&mode,event);
            
        }
        if(uic.trans){
                if(uic.out){
                    
                    uic.t_alpha+=uic.fade_speed;
                    if(uic.t_alpha>=255){
                        mode=uic.t_mode;
                        uic.t_alpha=255;
                        uic.out=false;
                    }
                }else{
                    uic.t_alpha-=uic.fade_speed;
                    if(uic.t_alpha<=0){
                        uic.t_alpha=0;
                        uic.trans=false;
                        uic.out=true;
                    }
                }
                SDL_Delay(8);
            }
        sdl.clear();
        
        uic.layout(mode);
        
        sdl.present();
        SDL_Delay(16);
    };
    return 0;







}







