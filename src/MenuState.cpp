#include "../include/MenuState.h"
#include "../include/Texture.h"
#include "../include/Button.h"

//Método que establece el estado del menú del juego
MenuState::MenuState(){
    BUTTON_WIDTH = 346;
    BUTTON_HEIGHT = 40;
    currentStateEnum = MENU_STATE;
    nextStateEnum = MENU_STATE;
    boardButtons = new Button[FULL_MENU];
    userQuit = false;

}

//Constructor de la clase
MenuState::~MenuState(){
    delete [] boardButtons;
    boardButtons = NULL;
    spriteSheetTexture.free();
    spriteClips.clear();
}

//Método que establece el estado del menú del juego
void MenuState::stateEnter(){
    if (!loadMedia()) {
        cout<<"Could not load media"<<endl;
    }
}

//Método que establece el estado de los eventos del juego
void MenuState::stateEvent(){
    SDL_Event event;

    // Event loop //
    while(SDL_PollEvent(&event)!=0){

        // Quits game //
        if(event.type==SDL_QUIT)
        {
            userQuit=true;
        }

        if (event.type == SDL_MOUSEMOTION) {
            // Checks if mouse is hovering over a button
            for (int index = 0; index < 3; index ++) {
                if (boardButtons[index].insideButton(346, 40)) {
                    hover[index] = true;
                }
                else {
                    hover[index] = false;
                }
            }
        }

        // Chequea si un botón fue clickeado
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            for (int index = 0; index < 3; index++) {
                if (hover[index]) {
                    nextStateEnum = GAME_STATE;
                    GAMEMODE = index;
                }
            }
        }
    }
}

//Método que actializa el estado del juego
StateEnum MenuState::stateUpdate(){
    if (currentStateEnum != nextStateEnum) {
        return nextStateEnum;
    }
    return currentStateEnum;
}

//Método que renderiza el juego
void MenuState::stateRender(){
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);
    drawMenu();
    for (int index = 0; index < 3; index++) {
        currentSprite = index;
        if (hover[index]) {
            currentSprite += 3;
        }
        boardButtons[index].render(currentSprite);
    }
}

//Método que cierra el juego
bool MenuState::stateExit(){
    return userQuit;
}

//Método que carga la media del juego
bool MenuState::loadMedia(){
    bool initSuccessfulful = true;

    if (!spriteSheetTexture.loadFromFile("data/MenuState.png")) {
        printf("Could not load sprite");
        initSuccessfulful = false;
    }


    //Clips Sprite
    //Clips Estándar
    SDL_Rect localMultiplayer = {0, 0, 346, 40};
    spriteClips.push_back(localMultiplayer);
    SDL_Rect singlePlayer = {0, 40, 346, 40};
    spriteClips.push_back(singlePlayer);
    SDL_Rect aI = {0, 80, 346, 40};
    spriteClips.push_back(aI);
    //Clips Hover
    SDL_Rect localMultiplayerHover = {346, 0, 346, 40};
    spriteClips.push_back(localMultiplayerHover);
    SDL_Rect singlePlayerHover = {346, 40, 346, 40};
    spriteClips.push_back(singlePlayerHover);
    SDL_Rect aIHover = {346, 80, 346, 40};
    spriteClips.push_back(aIHover);
    // Full Menu
    SDL_Rect fullMenu = {0, 120, 640, 640};
    spriteClips.push_back(fullMenu);

    boardButtons[LOCAL_MULTIPLAYER].setPoint(148, 210);
    boardButtons[SINGLEPLAYER].setPoint(148, 280);
    boardButtons[AI_VS_AI].setPoint(148, 350);

    return initSuccessfulful;
}

//Método que dibuja el menu del juego
void MenuState::drawMenu() {
    spriteSheetTexture.render(0, 0, &spriteClips[FULL_MENU]);
}