#include "../include/Texture.h"

Texture::Texture(){
    currentTexture = NULL;
    width = 0;
    height = 0;
}

//Constructor de la clase
Texture::~Texture(){
    free();
}

//Método que carga los datos del archivo
bool Texture::loadFromFile(std::string path){

    // Libera la textura actual //
    free();

    SDL_Texture *newTexture;
    // Carga la imágen desde la ruta//
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());

    if(loadedSurface == NULL){
        printf("Unable to load img from %s! SDL Error: %s\n",path.c_str(),IMG_GetError());
    }
    else{
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n",path.c_str(), SDL_GetError());
        }
        else{
            // Obtiene las dimensiones de la imágen //
            width = loadedSurface->w;
            height = loadedSurface->h;
        }
        SDL_FreeSurface(loadedSurface);
    }
        currentTexture = newTexture;
        return currentTexture != NULL;
}

//Método que renderiza los elementos
void Texture::render(int x, int y, SDL_Rect *clip){

    // Setea un espacio para renderizar en la pantalla //
    SDL_Rect renderSpace = {x, y, width, height};

    // Setea un espacio para rendarizar las dimensiones de los clips dimensionales //
    if(clip != NULL){
        renderSpace.w = clip->w;
        renderSpace.h = clip->h;
    }

    // Renderiza a la pantalla//
    SDL_RenderCopy(gRenderer, currentTexture, clip, &renderSpace);
}

<<<<<<< HEAD
//Método que libera las texturas
=======
//Método que --
>>>>>>> origin/master
void Texture::free(){
    if(currentTexture!=NULL){
        SDL_DestroyTexture(currentTexture);
        currentTexture = NULL;
        width = 0;
        height = 0;
    }
}

//Método que obtiene el ancho
int Texture::getWidth(){
    return width;
}

//Método que obtiene la altura
int Texture::getHeight(){
    return height;
}