#include <SDL2/SDL.h>
#include <stdio.h>

//Dimensões constantes da Tela
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main( int argc, char* args[] )
{
    //A janela que estará sendo renderizada
    SDL_Window* window = NULL;
    
    //A render contida pela janela
    SDL_Surface* screenSurface = NULL;

    //Inicializando o SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        printf( "SDL não conseguiu inicializar! SDL_Error: %s\n", SDL_GetError() );
    }
    else{
        //Cria a Janela
        window = SDL_CreateWindow( "Tutorial de SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL ){
            printf( "A janela não pode ser criada! SDL_Error: %s\n", SDL_GetError() );
        }
         else
        {
            //Criando uma render para janela
            screenSurface = SDL_GetWindowSurface( window );

            //Preenchendo a render com branco
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            
            //Atualizando a render
            SDL_UpdateWindowSurface( window );

            //Esperando 2 segundos
            SDL_Delay( 2000 );
        }
    }
    //Destruindo a janela
    SDL_DestroyWindow( window );

    //Fechando o SDL
    SDL_Quit();

    return 0;
}