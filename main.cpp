#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int GrainW = 2;
int GrainH = 2;

struct FallingRect
{
    SDL_Rect rect;
    float V_velocity; // vertical velocity
};

int main(int argc, char *args[])
{

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("DropSIM",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          650, 600, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    std::vector<FallingRect> fallingRects;
    const float gravity = 0.5f;

    bool running = true;
    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;

            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {

                    int spawnCount = 50; 
                    for (int i = 0; i < spawnCount; ++i)
                    {
                        FallingRect Fr;
                        
                        Fr.rect = {
                            event.button.x + (rand() % 61 - 30), 
                            event.button.y + (rand() % 61 - 30), 
                            GrainW,
                            GrainH};
                        Fr.V_velocity = 0;
                        fallingRects.push_back(Fr);
                    }
                }
            }
        }

            for (auto &r : fallingRects)
            {
                r.V_velocity += gravity;
                r.rect.y += static_cast<int>(r.V_velocity);

                if (r.rect.y + r.rect.h > 600)
                {
                    r.rect.y = 600 - r.rect.h;
                    r.V_velocity = 0;
                }
            }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        for (const auto &r : fallingRects)
        {
            SDL_RenderFillRect(renderer, &r.rect);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
