#include "../include/Piece.h"

Directions kingMoves[4] = {LEFT, RIGHT, BACK_LEFT, BACK_RIGHT};
Directions pieceMoves[2] = {LEFT, RIGHT};

//Método que se encarga del manejo de las piezas
Piece::Piece() {
    x = 0;
    y = 0;
    potential = -99999999;
    king = false;
}

//Método que se encarga de localizar los puntos
void Piece::setPoint (int xLocation, int yLocation) {
    x = xLocation;
    y = yLocation;
}

//Método que se encarga de decir si una pieza es Reina
bool Piece::isKing() {
    return king;
}

//Método que se encarga de convertir una pieza a Reina
void Piece::makeKing() {
    king = true;
}

//Método que se encarga de encontar el potencial más largo
void Piece::findLargestPotenial(){
    int largest = directionValues[0];
    
    for (int i=1; i<4; i++) {
        if (largest < directionValues[i]) {
            largest = directionValues[i];
        }
    }
    potential = largest;
}

//Método que se encarga de encontar la mejor dirección
void Piece::findBestDirection(){
    
    int largest = directionValues[0];
    vector<int> largestVector;
    
    for (int i=1; i<4; i++) {
        if (largest < directionValues[i]) {
            largest = directionValues[i];
        }
    }
    
    for(int j=0; j<4; j++){
        if (largest <= directionValues[j]) {
            largestVector.push_back(j);
        }
    }
    
    srand(static_cast<unsigned int>(time(NULL)));
    int bestIndex = rand() % largestVector.size();
    
    for(int k=0; k<4; k++){
        if (kingMoves[k] == largestVector[bestIndex]) {
            bestDirection = kingMoves[k];
        }
    }
}