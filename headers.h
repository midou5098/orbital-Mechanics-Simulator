#ifndef HEADERS_H
#define HEADERS_H
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfxPrimitives.h>
//using 1 for earth
//2 for mars , 3 for jupiter and 4 for ur anus :)
struct planet {
    int id;
    std::string name;
    std::string species;
    int size;
    int pop;
    std::string desc;
    float ang;
    void add(int ide,int sizee,const std::string& namee,const std::string& speciese ,int pope,const std::string& desce,float ange){
        id=ide;
        size=sizee;
        name=namee;
        species=speciese;
        pop=pope;
        desc=desce;
        ang=ange;}
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
    public:
        int t_alpha,t_mode,fade_speed;
        bool out=true,trans=false;// #trans are wasting oxygene

        std::string s1="",s2="",s3="",message="";
        int focused=-1,splt=0;
        float a1=0,a2=0,a3=0,a4=0;
        SDLinit& sdl;
        SDL_Texture* tex;
        SDL_Texture* anim;
        SDL_Texture* venus;
        SDL_Texture* uranus;
        SDL_Texture* mars;
        SDL_Texture* sun;

        
        std::vector<planet> planets;
        int ROWS=6,COLS=6;
        int current_frame=0;
        Uint32 lframe_time;
        Uint32 current_time;
        double frame_delay=100;


        uinter(SDLinit &sdlo);
        ~uinter();
        void handle(int* mode,SDL_Event event);
        std::vector<planet>& getvect(void){return planets;}
        void addPlanet(const planet& p) { planets.push_back(p); }
        void animate(int mode,SDL_Texture* seleanim,int px,int py);
        bool checkmouse(int posx,int posy, int x,int y,int w,int h);
        void draworbit(int n,float* angle,int size);
        void layout(int mode);

};
uinter::uinter(SDLinit &osdl) : sdl(osdl),tex(nullptr),anim(nullptr) {
    SDL_Renderer *renderer=sdl.getrender();
    SDL_Surface *surf=IMG_Load("space.png");
    tex = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    SDL_Surface *anims=IMG_Load("earth.png");
    anim = SDL_CreateTextureFromSurface(renderer, anims);
    SDL_FreeSurface(anims);
    SDL_Surface *venuss=IMG_Load("venus.png");
    venus = SDL_CreateTextureFromSurface(renderer, venuss);
    SDL_FreeSurface(venuss);
    SDL_Surface *marss=IMG_Load("mars.png");
    mars = SDL_CreateTextureFromSurface(renderer, marss);
    SDL_FreeSurface(marss);
    SDL_Surface *uranuss=IMG_Load("saturn.png");
    uranus = SDL_CreateTextureFromSurface(renderer, uranuss);
    SDL_FreeSurface(uranuss);
    SDL_Surface *sunss=IMG_Load("sun.png");
    sun = SDL_CreateTextureFromSurface(renderer, sunss);
    SDL_FreeSurface(sunss);
    t_alpha=0;
    t_mode=2;
    fade_speed =15;








}
void uinter::layout(int mode){
    SDL_Renderer *renderer=sdl.getrender();
    switch(mode){
        case 1:
            SDL_SetRenderDrawColor(renderer,60,60,60,255);
            SDL_RenderClear(renderer);
            sdl.drawtext( 110,75 ,"planet name :" );
            sdl.drawtextarea( 300, 70, 200, 50, 0, 0, 0);
            sdl.drawtext( 80,140 , "Orbital Distance : "); // was going to use planet size as input , but it doesnt add anything , so using the semi-major axis 
            sdl.drawtextarea( 300, 135, 200, 50, 0, 0, 0);
            sdl.drawtext( 80,205 , "species names : ");
            sdl.drawtextarea( 300, 200, 200, 50, 0, 0, 0);
            sdl.drawbut( 300,450 ,200 ,100 ,150 ,150 ,150,"deploy");
            if(!s1.empty()){
                sdl.drawtext( 320,80 ,s1.c_str());
            }if(!s2.empty()){
                sdl.drawtext( 320,145 ,s2.c_str());
            }if(!s3.empty()){
                sdl.drawtext( 320,210 ,s3.c_str());
            }if(!message.empty()){
                sdl.drawtext( 20,650 ,message.c_str());
            }
            
            switch(splt){
                case 1:
                    sdl.drawtext( 330,365 ,"planet : earth");
                    break;
                case 2:
                    sdl.drawtext( 330,365 ,"planet : venus");
                    break;
                case 3:
                    sdl.drawtext( 330,365 ,"planet : saturn");
                    break;
                case 4:
                    sdl.drawtext( 330,365 ,"planet : mars");
                    break;
                default:
                    sdl.drawtext( 330,365 ,"planet : none");
                    break;
            }
            animate(1,anim,1090,20);
            animate(1,venus,1090,178);
            animate(1,uranus,1060,346);
            animate(1,mars,1090,514);
            if (trans){
                SDL_Rect rect={0,0,1280,720};
                SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
                SDL_SetRenderDrawColor(renderer,0,0,0,t_alpha);
                SDL_RenderFillRect(renderer,&rect);
            }

            break;
        case 2:
            SDL_Rect rect={0,0,1280,720};
            SDL_RenderCopy(renderer,tex,NULL,&rect);
            

            animate(2,sun,515,235);
            for(auto& planet : planets){
                draworbit(planet.id,&planet.ang,planet.size);
            }
            




            if (trans){
                SDL_Rect rect={0,0,1280,720};
                SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
                SDL_SetRenderDrawColor(renderer,0,0,0,t_alpha);
                SDL_RenderFillRect(renderer,&rect);
            }











            break;
    }
}

bool uinter::checkmouse(int posx,int posy, int x,int y,int w,int h){
    if(x<posx && posx<x+w && y<posy && posy<y+h){
        return true;
    }
    return false;
}

void uinter::animate(int mode,SDL_Texture* seleanim,int px,int py){
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
        if(mode==1){
            dst.w=140;
            dst.h=140;
        }else if (mode==2) {
            dst.w=90;
            dst.h=90;
        }
        if(seleanim==uranus){
            dst.w=170;
            dst.h=110;
        }else if (seleanim==sun){
            dst.w=250;
            dst.h=250;
        }
        current_time = SDL_GetTicks();
        if (current_time > lframe_time + frame_delay) {
            current_frame = (current_frame + 1) % 36; 
            lframe_time = current_time;
        }
        SDL_RenderCopy(sdl.getrender(), seleanim, &rect, &dst);

}


void uinter::draworbit(int  n ,float* angle, int size){  
    int sunx=640; //at this point i hitted a wall , i had limited choices for drawing the orbit ,and all are ineffisicent , with a O(n²) at least , so i m addign the sdl gfx library(feels like summoning a boos lol)
    int suny=360;
    circleRGBA(sdl.getrender(), sunx, suny, size, 255, 255, 255, 120);
    int x= sunx + (int)(size*cos(*angle))-45;
    int y= suny + (int)(size*sin(*angle))-45;
    
    *angle+=0.0035f;
    if(*angle>2*M_PI) *angle-=2*M_PI;
    switch(n){
        case 1:
            animate(2,anim,x,y);
            *angle+=0.0035f;
            break;
        case 2:
            animate(2,venus,x,y);
            *angle+=0.00315f;
            break;
        case 3:
            animate(2,uranus,x-55,y-25);
            *angle+=0.0031f;
            break;
        case 4:
            animate(2,mars,x,y);
            *angle+=0.00361f;
            break;
        
        
        
        
        }
    
    if(*angle>2*M_PI) *angle-=2*M_PI;


    
}



































void uinter::handle(int* mode,SDL_Event event){
    if (*mode==1){
            if (event.type==SDL_MOUSEBUTTONDOWN){
                int x=event.button.x;
                int y=event.button.y;
                if(300<x && x<500 && 450<y && y<550){
                    if(!s1.empty() && !s2.empty() && !s3.empty()){
                            planet prot;
                            switch(planets.size()){
                                case 0:
                                    prot.add(splt,std::stoi(s2),s1,s3,1,"nigga",a1);
                                    break;
                            
                                case 1:
                                    prot.add(splt,std::stoi(s2),s1,s3,1,"nigga",a2);
                                    break;
                                case 2:
                                    prot.add(splt,std::stoi(s2),s1,s3,1,"nigga",a3);
                                    break;
                                case 3:
                                    prot.add(splt,std::stoi(s2),s1,s3,1,"nigga",a4);
                                    break;
                            
                                }
                            
                            addPlanet(prot);
                            t_mode=2;
                            trans=true;
                            t_alpha=0;

                    }else{
                        message="nah u fucked up somehting , press escape if u wanna just go back to space";
                    }
                    
                }
                if (checkmouse(x,y,1090,20,140,140)){splt=1;}
                if (checkmouse(x,y,1090,178,140,140)){splt=2;}
                if (checkmouse(x,y,1090,346,200,140)){splt=3;}
                if (checkmouse(x,y,1090,514,140,140)){splt=4;}
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
                        *mode=2;
                    }
                    if(key == SDLK_BACKSPACE) {
                        if(focused == 1 && !s1.empty()) {
                            s1.pop_back();  // Remove last character
                        }
                        else if(focused == 2 && !s2.empty()) {
                            s2.pop_back();
                        }
                        else if(focused == 3 && !s3.empty()) {
                            s3.pop_back();
                        }
                    }
                    if (key>=32 && key<=126) {  
                            char c=(char)key;
                            bool shift=(event.key.keysym.mod & KMOD_SHIFT);
                            if (shift && c>='a' && c<= 'z') {
                                c=toupper(c);
                            }
                            if(focused==1 && s1.length()<15) s1+=c;
                            else if(focused==2 && s2.length()<15 && isdigit(c)) s2+=c;
                            else if(focused==3 && s3.length()<15) s3+=c;
                    }
                }
            }
    }else if (*mode==2){
        if(event.type==SDL_KEYDOWN){
                    SDL_Keycode key=event.key.keysym.sym;
                    if(key==SDLK_ESCAPE){
                        t_mode=1;
                        trans=true;
                    }
                }
    }
}

uinter::~uinter(){
    SDL_DestroyTexture(tex);
    if (anim) SDL_DestroyTexture(anim);
    }
































#endif