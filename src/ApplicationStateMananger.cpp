#include "../include/ApplicationStateManager.h"
#include "../include/MenuState.h"
#include "../include/GameState.h"
#include "../include/GameOverState.h"

//Método que envía el estado del menu aplicación
ApplicationStateManager::ApplicationStateManager(){
    currentState = new MenuState();
    currentState->stateEnter();
}

//Método que setea los eventos de la aplicación
void ApplicationStateManager::stateEvent(){
    currentState->stateEvent();
}