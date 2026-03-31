#ifndef HEADERS_H
#define HEADERS_H
#include <iostream>
#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
//using 1 for earth
//2 for mars , 3 for jupiter and 4 for kepler 
struct planet {
    int id;
    std::string name;
    std::string species;
    int size;
    int pop;
    std::string desc;
    void add(int ide,int sizee,const std::string& namee,const std::string& speciese ,int pope,const std::string& desce){
        id=ide;
        size=sizee;
        name=namee;
        species=speciese;
        pop=pope;
        desc=desce;}
};

    class SDLinit{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        TTF_Font* font;
    public:
        SDLinit(const std::string &title,int w,int h);
        ~SDLinit();
        std::string message="";
        TTF_Font* getfont(){return font;}
        SDL_Renderer* getrender(){return renderer;}
        void drawtextarea(int x,int y,int w,int h,int r,int g,int b);
        void drawbut(int x,int y,int w,int h,int r,int g,int b,const std::string &text);
        void drawtext(int x,int y,const std::string &text);
        void clear();
        void present();

};
SDLinit::SDLinit(const std::string &title,int w,int h):window(nullptr),renderer(nullptr){
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    font=TTF_OpenFont("font.ttf",30);
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

void SDLinit::drawtext(int x,int y,const std::string &text){
    SDL_Color black = {0,0,0,255};
    SDL_Surface* surf=TTF_RenderText_Solid(font,text.c_str(),black);
    int tw = surf->w;
    int th = surf->h;
    SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
    SDL_Rect rect={x,y,tw,th};
    SDL_RenderCopy(renderer,tex,NULL,&rect);
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
    
    IMG_Quit();
    SDL_Quit();
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
void SDLinit::drawtextarea(int x,int y,int w,int h,int r,int g,int b){
    SDL_SetRenderDrawColor(renderer,r,g,b,255);
    SDL_Rect rect4={x,y,w,h};
    SDL_RenderDrawRect(renderer,&rect4);
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderFillRect(renderer,&rect4);
}
class uinter{
    private:
        std::string s1="",s2="",s3="";
        int focused=-1;
        SDLinit& sdl;
        SDL_Texture* tex;
        SDL_Texture* anim;
        
        std::vector<planet> planets;
        int ROWS=6,COLS=6;
        int current_frame=0;
        Uint32 lframe_time;
        Uint32 current_time;
        double frame_delay=100;

    public:
        uinter(SDLinit &sdlo);
        ~uinter();
        void handle(int* mode,SDL_Event event);
        std::vector<planet>& getvect(void){return planets;}
        void addPlanet(const planet& p) { planets.push_back(p); }
        void animate(int mode,SDL_Texture* seleanim,int px,int py);
        void drawplt(int n);
        void layout(int mode);

};
uinter::uinter(SDLinit &osdl) : sdl(osdl),tex(nullptr),anim(nullptr) {
    SDL_Renderer *renderer=sdl.getrender();
    SDL_Surface *surf=IMG_Load("space.png");
    SDL_Surface *anims=IMG_Load("sun.png");
    anim = SDL_CreateTextureFromSurface(renderer, anims);
    SDL_FreeSurface(anims);
    tex=SDL_CreateTextureFromSurface(renderer,surf);
    SDL_FreeSurface(surf);
}
void uinter::layout(int mode){
    SDL_Renderer *renderer=sdl.getrender();
    switch(mode){
        case 1:
            SDL_SetRenderDrawColor(renderer,60,60,60,255);
            SDL_RenderClear(renderer);
            sdl.drawtext( 110,75 ,"planet name :" );
            sdl.drawtextarea( 300, 70, 200, 50, 0, 0, 0);
            sdl.drawtext( 110,140 , "planet size : ");
            sdl.drawtextarea( 300, 135, 200, 50, 0, 0, 0);
            sdl.drawtext( 80,205 , "species names : ");
            sdl.drawtextarea( 300, 200, 200, 50, 0, 0, 0);
            sdl.drawbut( 540,600 ,200 ,100 ,150 ,150 ,150,"deploy");
            if(!s1.empty()){
                sdl.drawtext( 320,80 ,s1.c_str());
            }if(!s2.empty()){
                sdl.drawtext( 320,145 ,s2.c_str());
            }if(!s3.empty()){
                sdl.drawtext( 320,210 ,s3.c_str());
            }
            animate(mofde,anim,400,250);
            break;
        case 2:
            SDL_Rect rect={0,0,1280,720};
            SDL_RenderCopy(renderer,tex,NULL,&rect);
            break;
    }
}



void uinter::animate(int mode,SDL_Texture* seleanim,int px,int py){
    if (mode==1){
        int W,H;
        SDL_QueryTexture(seleanim,NULL,NULL,&W,&H);
        int framewidth=W/6;
        int frameheight=H/6;
        SDL_Rect rect;
        rect.w=framewidth;
        rect.h=frameheight;
        int framex=current_frame%6;
        int framey=current_frame/6;
        rect.x=framex*framewidth;
        rect.y=framey*frameheight;
        SDL_Rect dst;
        dst.x=px;
        dst.y=py;
        dst.w=framewidth;
        dst.h=frameheight;
        current_time = SDL_GetTicks();
        if (current_time > lframe_time + frame_delay) {
            current_frame = (current_frame + 1) % 36; 
            lframe_time = current_time;
        }
        SDL_RenderCopy(sdl.getrender(), anim, &rect, &dst);

    }
}






































void uinter::handle(int* mode,SDL_Event event){
    if (*mode==1){
            if (event.type==SDL_MOUSEBUTTONDOWN){
                int x=event.button.x;
                int y=event.button.y;
                if(540<x && x<740 && 600<y && y<700){
                    if(!s1.empty() && !s2.empty() && !s3.empty()){
                            planet prot;
                            prot.add(1,std::stoi(s2),s1,s3,1,"nigga");
                            addPlanet(prot);

                        }
                    *mode=2;
                }
                if (300<x && x<500){
                        if(70<y && y<120){
                            focused=1;
                        }else if(135<y && y<185){
                            focused=2;
                        }else if(200<y && y<250){
                            focused=3;
                    }
                }
            }else{
                if(event.type==SDL_KEYDOWN){
                    SDL_Keycode key=event.key.keysym.sym;
                    if(key==SDLK_ESCAPE){
                        *mode=1;
                    }
                    if (key>=32 && key<=126) {  
                            char c=(char)key;
                            bool shift=(event.key.keysym.mod & KMOD_SHIFT);
                            if (shift && c>='a' && c<= 'z') {
                                c=toupper(c);
                            }
                            if(focused==1 && s1.length()<15) s1+=c;
                            else if(focused==2 && s2.length()<15) s2+=c;
                            else if(focused==3 && s3.length()<15) s3+=c;
                    }
                }
            }
    }
}

uinter::~uinter(){
    SDL_DestroyTexture(tex);
    if (anim) SDL_DestroyTexture(anim);
    }
































#endif