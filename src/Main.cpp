#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#include "Projectile.cpp"
#include "Utils.cpp"
#include "global.h"

int main(int argc, char* argv[]) {
    // error checking in init
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    // creates a window
    SDL_Window* win = SDL_CreateWindow("SIMULATION",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       CANVAS_WIDTH, CANVAS_HEIGHT, 0);
    // SDL_WINDOW_FULLSCREEN
    // Set up render with acc flag and set color
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    // Projectile
    Projectile player1(ORIGIN_X, ORIGIN_Y, 50, 1.57079632679);
    Projectile player2(ORIGIN_X, ORIGIN_Y, 50, 0.3);

    // animation loop
    bool open = true;
    while (open) {
        SDL_Event event;

        // Events management
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    // handling of close button
                    open = false;
                    break;
            }
        }

        player1.move((double)1 / 60);
        player2.move((double)1 / 60);

        // clears the screen
        drawBackground(rend);

        SDL_SetRenderDrawColor(rend, 200, 0, 0, 255);
        drawCircle(rend, player1.x, player1.y, STROKE_SIZE);

        SDL_SetRenderDrawColor(rend, 0, 200, 0, 255);
        drawCircle(rend, player2.x, player2.y, STROKE_SIZE);

        SDL_RenderPresent(rend);

        // // triggers the double buffers
        // // for multiple rendering
        // SDL_RenderPresent(rend);

        // Delay for 60 fps
        SDL_Delay(1000 / 60);
    }

    // Clean up
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
