#ifndef Texture_h
#define Texture_h

#ifdef __linux
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#include "Application.h"

class Texture{
public:
    Texture();
    ~Texture();
    bool loadFromFile(std::string);
    void render(int,int,SDL_Rect*);
    void free();
    int getWidth();
    int getHeight();
private:
    SDL_Texture *currentTexture;
    int width;
    int height;
};

#endif /* Texture_h */