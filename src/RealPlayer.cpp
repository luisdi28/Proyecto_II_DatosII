#include "../include/RealPlayer.h"
#include "../include/GameState.h"

//Método que identifica que quien está jugando es el usuario
RealPlayer::RealPlayer(bool topSideOfBoard, CheckersBoard *board, Button *buttons): Player(topSideOfBoard, board, buttons){
    selectingState = false;
}

//Constructor de la clase
RealPlayer::~RealPlayer(){
    delete Board;
    Board = NULL;
    delete boardButtons;
    boardButtons = NULL;
}

//Método que permite al jugador escoger el movimiento que tendrán las fichas
bool RealPlayer::makeMove(SDL_Event* event){

    if (event->type == SDL_MOUSEBUTTONDOWN) {

        // Selecciona el estado para la pieza inicial //
        if (!selectingState) {
            killWasMade = false;
            for (int index=0; index<TOTAL_BUTTONS; index++) {
                if (boardButtons[index].insideButton(BUTTON_WIDTH, BUTTON_HEIGHT)) {
                    // El jugador selecciona una pieza a mover //
                    selectPiece(boardButtons[index].getButtonPointX()/80, boardButtons[index].getButtonPointY()/80);
                    break;
                }
            }
        }
            // Seleccionar una pieza para ser movida //
        else{
            for (int index=0; index<TOTAL_BUTTONS; index++) {
                if (boardButtons[index].insideButton(BUTTON_WIDTH,BUTTON_HEIGHT)) {
                    // El jugador selecciona donde debería ser movida la pieza//

                    if (selectedLocationIsValid(currentIndex,boardButtons[index].getButtonPointX()/80, boardButtons[index].getButtonPointY()/80, false)) {
                        movePiece(Board->virtualBoard, team, currentIndex, boardButtons[index].getButtonPointX()/80, boardButtons[index].getButtonPointY()/80);
                        Board->turnHighLightOff();

                        if (killWasMade) {
                            selectPiece(team[killerPeiceIndex].x, team[killerPeiceIndex].y);
                            if (Board->validLocations.size() == 0) {
                                selectingState = false;
                                Board->turnHighLightOff();
                                return true;
                            }
                        }
                        if (!killWasMade) {
                            return true;
                        }
                    }
                    else {
                        return false;
                    }
                }
            }
        }
    }
    return false;
}

//Método que permite al jugador escoger la ficha que moverá
void RealPlayer::selectPiece(int x, int y){
    // Seleccionar la pieza//
    // Cuando una pieza no ha sido seleccionada aún y el botón actualmente seleccionado no tiene una pieza adentro //
    if(sameTeam(Board->virtualBoard[x][y], TEAM_NUMBER)){
        currentIndex = pieceTeamIndexByXY(x, y);
        Board->turnHighLightOn(x, y);
        highlightValidMoves();
        selectingState = true;
        cout << "Selected piece is:\t(" << x << ", " << y << ")" <<endl;
    }
    else{
        cout<<"Piece isn't apart of your team"<<endl;
    }
}

//Método que valida si la casilla sellecionada por el usuario es valida
bool RealPlayer::selectedLocationIsValid(int currentIndex, int x, int y, bool forHighlight) {
    bool locationIsValid = false;
    if (Board->virtualBoard[x][y] == EMPTY_PIECE) {

        // caso 1: mover en un cuadrdo centrado de 3x3 en el origen //
        if (abs(x - team[currentIndex].x) == 1 && abs(y - team[currentIndex].y) == 1 && !killWasMade) {

            // case 1.1: piece is a king //
            if (team[currentIndex].isKing()) {
                locationIsValid = true;
            }

                // caso 1.2: la pieza no es una Reina //
            else if (y - team[currentIndex].y == ONE) {
                locationIsValid = true;
            }
        }

            // caso 2: mover en un cuadrado centrado de 5x5 en el origen para matar una pieza //
        else if (abs(x - team[currentIndex].x) == 2 && abs(y - team[currentIndex].y) == 2 && sameTeam(Board->virtualBoard[(x + team[currentIndex].x)/2][(y + team[currentIndex].y)/2],ENEMY_TEAM_NUMBER)) {

            // caso 2.1: la pieza es una reina //
            if (team[currentIndex].isKing()) {
                locationIsValid = true;
            }

                // caso 2.2: la pieza no es una reina //
            else if (y - team[currentIndex].y == 2*ONE) {
                locationIsValid = true;
            }
        }
    }
        // caso 3: selección de pieza propia para cambiar la selección //
    else if(sameTeam(Board->virtualBoard[x][y],TEAM_NUMBER) && !forHighlight && !killWasMade){
        Board->turnHighLightOff();
        selectPiece(x, y);
        locationIsValid = false;
    }
    if (!locationIsValid && !forHighlight) {
        cout<<"cant move here"<<endl;
    }
    else if(!killWasMade){
        selectingState = false;
    }
    return locationIsValid;
}

//Método que imprime un registro de los movimiento validos realizados en la partida
void RealPlayer::highlightValidMoves() {
    int x, y;
    for (int i = -2; i <=2; i++){
        x = team[currentIndex].x + i;
        for (int j = -2; j <=2; j++){
            y = team[currentIndex].y + j;

            if (x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (selectedLocationIsValid(currentIndex,x, y, true)) {
                    pointXY pointToHighlight = {x,y};
                    Board->validLocations.push_back(pointToHighlight);
                }
            }
        }
    }
}