#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    // Create a window
    SDL_Window* window = SDL_CreateWindow("Point", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // Set the render color to red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    // Render a single point at the coordinates (10, 10)
    SDL_RenderDrawPoint(renderer, 10, 10);
    // Update the screen
    SDL_RenderPresent(renderer);

    SDL_Delay(2000);
    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
