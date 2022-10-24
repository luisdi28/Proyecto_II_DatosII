#ifndef Button_h
#define Button_h

#ifdef __linux
#include <SDL2/SDL.h>
#endif

class Texture;

class Button{
public:
    Button();
    ~Button();
    void setPoint(int,int);
    bool insideButton(int,int);
    void render(int);
    int getButtonPointX();
    int getButtonPointY();
private:
    SDL_Point buttonPoint;
};

#endif /* Button_h */
