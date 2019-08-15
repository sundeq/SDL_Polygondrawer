#include <SDL2/SDL.h>


int main() {

	SDL_Window *window;
	SDL_Renderer *renderer;

	if(SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_Log("Could not initialize SDL: %s", SDL_GetError());
		return 1;
	}
	
	int WINDOW_WIDTH = 1920;
	int WINDOW_HEIGHT = 1080;
	window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Rect *rect = (SDL_Rect *) malloc(sizeof(SDL_Rect));
	rect->y = 0;
	rect->x = 0;
	rect->w = WINDOW_WIDTH;
	rect->h = WINDOW_HEIGHT;
	SDL_RenderFillRect(renderer, rect);

	SDL_SetRenderDrawColor(renderer, 200, 120, 120, 255);
	int x1 = 500, x2 = 1000, y1 = 400, y2 = 600;
	int x, y;
	for (x = x1; x < x2; x++) {
		for (y = y1; y < y2; y++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}

	SDL_RenderPresent(renderer);
	
	SDL_Delay(3000);

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
