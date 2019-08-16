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
	
	SDL_Rect *rect = (SDL_Rect *) malloc(sizeof(SDL_Rect));
	rect->y = 0;
	rect->x = 0;
	rect->w = WINDOW_WIDTH;
	rect->h = WINDOW_HEIGHT;

	int run = 1;
	int x, y;
	int i, j;
	int nvertices = 0;
	int verts_x[4];
	int verts_y[4];
	SDL_Event sdlEvent;
	while (run) {
		while (SDL_PollEvent(&sdlEvent)) {	
			if (sdlEvent.type == SDL_QUIT) {
				run = 0;
			}
			if (sdlEvent.type == SDL_MOUSEBUTTONDOWN) {
				SDL_GetMouseState( &x, &y);
				if (sdlEvent.button.button == SDL_BUTTON_LEFT) {
					if (nvertices != 4) {
						verts_x[nvertices] = x;
						verts_y[nvertices] = y;
						nvertices++;
					}
					printf("Added vertex x: %d y: %d\n", x, y);
				} else if (sdlEvent.button.button == SDL_BUTTON_RIGHT) {
					for (i = 0; i < nvertices; i++) {
						verts_x[i] = -1;
						verts_y[i] = -1;
					}
					nvertices = 0;
					printf("Wiped vertices\n");
				}
			}
		}
		// Background
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(renderer, rect);

		// Vertices
		if (nvertices == 4) {
			SDL_SetRenderDrawColor(renderer, 130, 130, 130, 255);
			for (i = 1; i < nvertices; i++) {
				SDL_RenderDrawLine(renderer, verts_x[i-1], verts_y[i-1], verts_x[i], verts_y[i]);
			}
			SDL_RenderDrawLine(renderer, verts_x[0], verts_y[0], verts_x[nvertices-1], verts_y[nvertices-1]);

		}
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}


