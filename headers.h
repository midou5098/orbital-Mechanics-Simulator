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
        TTF_Font* font;
    public:
        SDLinit(const std::string &title,int w,int h);
        ~SDLinit();
        std::string message="";
        SDL_Renderer* getrender(){return renderer;}
        void drawbut(int x,int y,int w,int h,int r,int g,int b,const std::string &text);
        void clear();
        void present();

};
SDLinit::SDLinit(const std::string &title,int w,int h):window(nullptr),renderer(nullptr){
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    font=TTF_OpenFont("font.ttf",15);
    window=SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w,h,SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
}
void SDLinit::drawbut(int x,int y,int w,int h,int r,int g,int b,const std::string &text){
    SDL_SetRenderDrawColor(renderer,r,g,b,255);
    SDL_Rect rect6={x,y,w,h};
    SDL_RenderFillRect(renderer,&rect6);
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderDrawRect(renderer,&rect6);
    SDL_Color white = {120,120,120,255};
    SDL_Surface* surf=TTF_RenderText_Solid(font,text.c_str(),white);
    SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
    SDL_Rect rect5={x+27,y+10,w-50,h-30};
    SDL_RenderCopy(renderer,tex,NULL,&rect5);
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(tex);
    
}


SDLinit::~SDLinit(){
    if(window){
        SDL_DestroyWindow(window);}
    if(renderer){
        SDL_DestroyRenderer(renderer);
    }
    TTF_Quit();
    SDL_Quit();
    IMG_Quit();
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
        void drawplt(int n);
        void layout(int mode);

};
uinter::uinter(SDLinit &osdl) : sdl(osdl),tex(nullptr) {
    SDL_Renderer *renderer=sdl.getrender();
    SDL_Surface *surf=IMG_Load("space.png");
    tex=SDL_CreateTextureFromSurface(renderer,surf);
    SDL_FreeSurface(surf);




}
void uinter::layout(int mode){
    SDL_Renderer *renderer=sdl.getrender();
    switch(mode){
        case 1:
            SDL_SetRenderDrawColor(renderer,60,60,60,255);
            SDL_RenderClear(renderer);
            sdl.drawbut( 540,600 ,200 ,100 ,20 ,150 ,150,"deploy");
            break;
        case 2:
            SDL_Rect rect={0,0,1280,720};
            SDL_RenderCopy(renderer,tex,NULL,&rect);
            break;
    }
}




uinter::~uinter(){
    SDL_DestroyTexture(tex);
    }
































#endif