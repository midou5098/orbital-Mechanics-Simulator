#ifndef HEADERS_H
#define HEADERS_H


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
        TTF_Font* getFont() { return font; }
        void clear();
        void present();
        bool handel_event();
        
};
SDLinit::SDLinit(const std::string &title,int w,int h):window(nullptr),renderer(nullptr){
    SDL_Init(SDL_INIT_VIDEO);
    window=SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w,h,SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);         
    TTF_Init();
    font = TTF_OpenFont("font.ttf",20);    
}



SDLinit::~SDLinit(){
    if(window){
        SDL_DestroyWindow(window);}
    if(renderer){
        SDL_DestroyRenderer(renderer);
    }
    TTF_CloseFont(font);
    TTF_Quit();
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
bool SDLinit::handel_event(){
    SDL_Event event;
    std::string s;
    while(SDL_PollEvent(&event)){
        if(event.type==SDL_QUIT){
            return false;
        }
        return true;
    }
    return false;
    }
















#endif