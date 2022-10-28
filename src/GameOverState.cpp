#include <stdio.h>
#include "../include/GameOverState.h"
#include "../include/Texture.h"

//Método que setea el final del juego
GameOverState::GameOverState(){
    currentStateEnum = GAME_OVER_STATE;
    nextStateEnum = GAME_OVER_STATE;
    userQuit = false;
}

//Constructor de la clase
GameOverState::~GameOverState(){

}

//Método que setea la entrada del juego
void GameOverState::stateEnter(){
    printf("GAME OVER");
}

//Método que setea el evento del juego
void GameOverState::stateEvent(){
    SDL_Event event;
    // Loop del evento //
    while(SDL_PollEvent(&event)!=0){

        // Termina el juego //
        if(event.type==SDL_QUIT)
        {
            userQuit=true;
        }
    }
}

//Método que actualiza los eventos del juego
StateEnum GameOverState::stateUpdate(){
    if (currentStateEnum != nextStateEnum) {
        return nextStateEnum;
    }
    return currentStateEnum;
}

//Método que renderiza el juego
void GameOverState::stateRender(){
    // Color madera claro //
    SDL_SetRenderDrawColor(gRenderer, 0xD4, 0x9A, 0x6A, 0xFF);
    // Refresca la pantalla //
    SDL_RenderClear(gRenderer);
}

//Método que establece el cierre del juego
bool GameOverState::stateExit(){
    return userQuit;
}

//Método que carga los medios del juego
bool GameOverState::loadMedia(){
    return false;
}