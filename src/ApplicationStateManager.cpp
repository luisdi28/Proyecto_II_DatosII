#include "../include/ApplicationStateManager.h"
#include "../include/MenuState.h"
#include "../include/GameState.h"
#include "../include/GameOverState.h"

//Método que envía el estado del menu aplicación
ApplicationStateManager::ApplicationStateManager(){
    currentState = new MenuState();
    currentState->stateEnter();
}
//Constructor de la clase
ApplicationStateManager::~ApplicationStateManager(){
    delete currentState;
    currentState = NULL;
}

//Método que setea los eventos de la aplicación
void ApplicationStateManager::stateEvent(){
    currentState->stateEvent();
}

//Método que actualiza los eventos de la aplicación
StateEnum ApplicationStateManager::stateUpdate(){
    return currentState->stateUpdate();
}

//Método que renderiza los eventos de la aplicación
void ApplicationStateManager::stateRender(){
    currentState->stateRender();
}

//Método que setea el cierre los eventos y de la aplicación
bool ApplicationStateManager::stateExit(){
    return currentState->stateExit();
}

//Método que setea el estado de los eventos de la aplicación
void ApplicationStateManager::setCurrentStateEnum(StateEnum current){
    currentStateEnum = current;
}

//Método que obtiene el estado de los eventos de la aplicación
StateEnum ApplicationStateManager::getCurrentStateEnum(){
    return currentStateEnum;
}

//Método que cambia el estado de los eventos de la aplicación
void ApplicationStateManager::changeStates(){
    
    delete currentState;
    currentState = NULL;
    
    switch (currentStateEnum) {
        case MENU_STATE:
            currentState = new MenuState;
            break;
        case GAME_STATE:
            currentState = new GameState;
            break;
        case GAME_OVER_STATE:
            currentState = new GameOverState;
            break;
        default:
            break;
    }
    currentState->stateEnter();
}