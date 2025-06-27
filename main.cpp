#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


int main(int argc, char *args[])
{

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("DropSIM",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        650, 600, SDL_WINDOW_SHOWN);
        
        SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        
        
        
       


     bool running = true;
    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;

            if (event.type == SDL_MOUSEMOTION) {
            std::cout << "Mouse Motion Detected - "
            << "x: " << event.motion.x
            << ", y: " << event.motion.y << '\n';
            }

            if (event.type == SDL_MOUSEBUTTONDOWN){
            if (event.button.button == SDL_BUTTON_LEFT)
            {
            std::cout << "left mouse button pressed" << std::endl;
            } 
            else if (event.button.button == SDL_BUTTON_RIGHT) 
            {
            std::cout << "Right mouse button pressed" << std::endl;
            }
            }
            
           
        }
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        
        SDL_RenderClear(renderer);
        
        SDL_RenderPresent(renderer);
        
    }
        
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();

    return 0;
}