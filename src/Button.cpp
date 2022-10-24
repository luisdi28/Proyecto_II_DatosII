#include "../include/Button.h"
#include "../include/GameState.h"
#include "../include/Texture.h"
#include "../include/Application.h"

//Método que crea lel botón
Button::Button(){
    buttonPoint.x = 0;
    buttonPoint.y = 0;
}

//Constructor de la clase
Button::~Button(){
    buttonPoint.x = NULL;
    buttonPoint.y = NULL;
}

//Método que setea un punto
void Button::setPoint(int x, int y){
    buttonPoint.x = x;
    buttonPoint.y = y;
}

//Método que renderiza el botón
void Button::render(int sprite){
    //Render button with spritesheet
    spriteSheetTexture.render(buttonPoint.x, buttonPoint.y, &spriteClips[sprite]);
}

//Método que setea las caraterísticas del botón
bool Button::insideButton(int buttonWidth, int buttonHeight){

    int x,y;
    bool insideButton = true;
    SDL_GetMouseState(&x,&y);
    
    // Arriba del botón button //
    if(y < buttonPoint.y){
        insideButton = false;
    }
    // Debajo del botón //
    else if (y > buttonPoint.y + buttonHeight){
        insideButton = false;
    }
    // Izquierda del botón button //
    else if (x < buttonPoint.x) {
        insideButton = false;
    }
    // Derecha del botón button  //
    else if (x > buttonPoint.x + buttonWidth){
        insideButton = false;
    }

    return insideButton;
}

//-- que obtiene el punto "x" del botón
int Button::getButtonPointX(){
    return buttonPoint.x;
}

//-- que obtiene el punto "y" del botón
int Button::getButtonPointY(){
    return buttonPoint.y;
}