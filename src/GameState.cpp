#include "../include/ApplicationStateManager.h"
#include "../include/GameState.h"
#include "../include/CheckersBoard.h"
#include "../include/Player.h"
#include "../include/AI.h"
#include "../include/RealPlayer.h"
#include "../include/Button.h"
#include "../include/Texture.h"

int TOTAL_BUTTONS = 32;

//Método que establece el estado del juego
GameState::GameState(){
    BUTTON_WIDTH = 80;
    BUTTON_HEIGHT = 80;

    currentStateEnum = GAME_STATE;
    nextStateEnum = GAME_STATE;

    Board = new CheckersBoard;
    boardButtons = new Button[TOTAL_BUTTONS];

    userQuit = false;
    switch (GAMEMODE) {
        case 0:
            Player1 = new RealPlayer(true, Board, boardButtons);
            Player2 = new RealPlayer(false, Board, boardButtons);
            break;
        case 1:
            Player1 = new AI(true, Board, boardButtons);
            Player2 = new RealPlayer(false, Board, boardButtons);
            break;
        case 2:
            Player1 = new AI(true, Board, boardButtons);
            Player2 = new AI(false, Board, boardButtons);
            break;
        default:
            userQuit = true;
            break;
    }

}

//Constructor de la clase
GameState::~GameState(){
    delete Board;
    Board = NULL;
    delete [] boardButtons;
    boardButtons = NULL;
    delete Player1;
    Player1 = NULL;
    delete Player2;
    Player2 = NULL;
    spriteClips.clear();
}

//Método que establece el estado de entrada del juego
void GameState::stateEnter(){
    if (!loadMedia()) {
        cout<<"Could not load media"<<endl;
    }
}

//Método que establece el estado de los eventos del juego
void GameState::stateEvent(){
    SDL_Event event;

    // Loop (Ciclo) del evento //
    while(SDL_PollEvent(&event)!=0){

        // TERMINA EL JUEGO //
        if(event.type==SDL_QUIT)
        {
            userQuit=true;
        }

        if (!gameOver()) {
            // Turno del jugador 1 //
            if (Player1->turn) {
                if(Player1->makeMove(&event)){
                    Player1->updateKings();
                    Player1->turn = false;
                    Player2->turn = true;
                    Player2->updateTeam();
                    cout<<*Board<<endl;
                    // Breaks para continuar en el loop principal //
                    break;
                }
            }
                // Turno del jugador 2 //
            else{
                if(Player2->makeMove(&event)){
                    Player2->updateKings();
                    Player2->turn = false;
                    Player1->turn = true;
                    Player1->updateTeam();
                    cout<<*Board<<endl;
                    // Breaks para continuar en el loop principal //
                    break;
                }
            }
        }
        else{
            nextStateEnum = GAME_OVER_STATE;
        }
    }
}

//Método que carga la media del juego
bool GameState::loadMedia(){
    bool initSuccessfulful = true;

    if (!spriteSheetTexture.loadFromFile("data/CheckerSprites.png")) {
        printf("Could not load sprite");
        initSuccessfulful = false;
    }
    // Inicializa las piezas del juego de Damas //

    // Pieza Dama Roja //
    SDL_Rect redPeice = {0,0,BUTTON_WIDTH,BUTTON_HEIGHT};
    spriteClips.push_back(redPeice);
    // Pieza Dama Negra //
    SDL_Rect blackPeice = {BUTTON_WIDTH,0,BUTTON_WIDTH,BUTTON_HEIGHT};
    spriteClips.push_back(blackPeice);
    // Pieza Reina Roja //
    SDL_Rect redKing = {BUTTON_WIDTH * 2, 0, BUTTON_WIDTH, BUTTON_HEIGHT};
    spriteClips.push_back(redKing);
    // Pieza Reina Negra //
    SDL_Rect blackKing = {BUTTON_WIDTH * 3, 0, BUTTON_WIDTH, BUTTON_HEIGHT};
    spriteClips.push_back(blackKing);

    int index = 0;
    bool indent = true;
    int xStart;

    //Setea puntos para el botón (arriba a la izquierda del botón)
    for(int y=0;y<SCREEN_HEIGHT;y+=BUTTON_HEIGHT){
        if (indent) {
            xStart = BUTTON_WIDTH;
            indent = false;
        }
        else{
            xStart = 0;
            indent = true;
        }
        for(int x=xStart;x<SCREEN_WIDTH;x+=2*BUTTON_WIDTH){
            boardButtons[index].setPoint(x, y);
            index++;
        }
    }
    return initSuccessfulful;
}

//**//
//Método que establece el fin del juego
bool GameState::gameOver(){
    if (Player1->team.size() == 0 || Player2->team.size() == 0) {
        return true;
    }
    return false;
}

//Método que actualiza el estado del juego
StateEnum GameState::stateUpdate(){
    if (currentStateEnum != nextStateEnum) {
        return nextStateEnum;
    }
    return currentStateEnum;
}

//Método que renderiza el juego
void GameState::stateRender(){
    // Renderiza informacón aquí //
    // Color madera claro //
    SDL_SetRenderDrawColor(gRenderer, 0xD4, 0x9A, 0x6A, 0xFF);
    // Refresca la pantalla //
    SDL_RenderClear(gRenderer);

    Board->drawBoard();

    // Renderiza el equipo completo //
    int index = 0;
    for (int y=0; y<8; y++) {
        for (int x=0; x<8; x++) {
            if((y+x)%2 == 1){
                Board->drawBoardPeices(x,y,&boardButtons[index]);
                index++;
            }
        }
    }
}

//Método que cierra el juego
bool GameState::stateExit(){
    return userQuit;
}