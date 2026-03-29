#ifndef HEADERS_H
#define HEADERS_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
class SDLinit{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
    public:
        SDLinit(const std::string &title,int w,int h);
        ~SDLinit();
        std::string message="";
        SDL_Renderer* getrender(){return renderer;}
        void clear();
        void present();

};
SDLinit::SDLinit(const std::string &title,int w,int h):window(nullptr),renderer(nullptr){
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    window=SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w,h,SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
}



SDLinit::~SDLinit(){
    if(window){
        SDL_DestroyWindow(window);}
    if(renderer){
        SDL_DestroyRenderer(renderer);
    }
}
void SDLinit::clear(){
    if(renderer){
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_RenderClear(renderer);
    }
}
void SDLinit::present(){
    if(renderer){
        SDL_RenderPresent(renderer);
    }
}

class uinter{
    private:
        SDLinit& sdl;
        SDL_Texture* tex;
    public:
        uinter(SDLinit &sdlo);
        ~uinter();
        void drawbg();

};
uinter::uinter(SDLinit &osdl) : sdl(osdl),tex(nullptr) {
    SDL_Renderer *renderer=sdl.getrender();
    SDL_Surface *surf=IMG_Load("space.png");
    tex=SDL_CreateTextureFromSurface(renderer,surf);
    SDL_FreeSurface(surf);

}





void uinter::drawbg(){
    SDL_Renderer *renderer=sdl.getrender();
    SDL_Rect rect={0,0,1280,720};
    SDL_RenderCopy(renderer,tex,NULL,&rect);

}

uinter::~uinter(){
    SDL_DestroyTexture(tex);
}
































#endif