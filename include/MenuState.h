#ifndef MenuState_h
#define MenuState_h

#ifdef __linux
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif

#include "ApplicationState.h"
#include "Application.h"

class Button;

enum MenuSpriteEnum {
    LOCAL_MULTIPLAYER,
    SINGLEPLAYER,
    AI_VS_AI,
    LOCAL_MULTIPLAYER_HOVER,
    SINGLEPLAYER_HOVER,
    AI_VS_AI_HOVER,
    FULL_MENU
};


class MenuState: public ApplicationState{
public:
    MenuState();
    ~MenuState();
    void stateEnter();
    void stateEvent();
    StateEnum stateUpdate();
    void stateRender();
    bool stateExit();
private:
    bool hover[3] = {false, false, false};
    Button *boardButtons;
    void drawMenu();
    bool loadMedia();
    bool userQuit;
};


#endif /* MenuState_h */
