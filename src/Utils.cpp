#include <SDL2/SDL.h>

#include "global.h"

void drawEmptyCircle(SDL_Renderer* renderer, int x0, int y0, int radius) {
    int x = radius;
    int y = 0;
    int decisionOver2 = 1 - x;  // Decision criterion divided by 2 evaluated at x=r, y=0

    while (y <= x) {
        SDL_RenderDrawPoint(renderer, x + x0, y + y0);    // Octant 1
        SDL_RenderDrawPoint(renderer, y + x0, x + y0);    // Octant 2
        SDL_RenderDrawPoint(renderer, -x + x0, y + y0);   // Octant 3
        SDL_RenderDrawPoint(renderer, -y + x0, x + y0);   // Octant 4
        SDL_RenderDrawPoint(renderer, -x + x0, -y + y0);  // Octant 5
        SDL_RenderDrawPoint(renderer, -y + x0, -x + y0);  // Octant 6
        SDL_RenderDrawPoint(renderer, x + x0, -y + y0);   // Octant 7
        SDL_RenderDrawPoint(renderer, y + x0, -x + y0);   // Octant 8
        y++;
        if (decisionOver2 <= 0) {
            decisionOver2 += 2 * y + 1;
        } else {
            x--;
            decisionOver2 += 2 * (y - x) + 1;
        }
    }
}

void drawCircle(SDL_Renderer* renderer, int x0, int y0, int radius) {
    int x = radius;
    int y = 0;
    int decisionOver2 = 1 - x;  // Decision criterion divided by 2 evaluated at x=r, y=0

    while (y <= x) {
        // Draw horizontal lines across the circle
        SDL_RenderDrawLine(renderer, x0 - x, y0 - y, x0 + x, y0 - y);
        SDL_RenderDrawLine(renderer, x0 - x, y0 + y, x0 + x, y0 + y);
        SDL_RenderDrawLine(renderer, x0 - y, y0 - x, x0 + y, y0 - x);
        SDL_RenderDrawLine(renderer, x0 - y, y0 + x, x0 + y, y0 + x);
        y++;
        if (decisionOver2 <= 0) {
            decisionOver2 += 2 * y + 1;
        } else {
            x--;
            decisionOver2 += 2 * (y - x) + 1;
        }
    }
}

void drawBackground(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, ORIGIN_X, 0, ORIGIN_X, CANVAS_HEIGHT);
    SDL_RenderDrawLine(renderer, 0, ORIGIN_Y, CANVAS_WIDTH, ORIGIN_Y);
}
