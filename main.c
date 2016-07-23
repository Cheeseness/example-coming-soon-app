/**
 * EXAMPLE SDL2 "COMING SOON" APPLICATION
 * 
 * Originally created for the Linux port of Day of the Tentacle.
 * See README.md for more information.
 * 
 * Copyright (c) 2016 Josh "Cheeseness" Bush
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 **/

#include "SDL2/SDL.h"

//Declare the window and SDL renderer that we'll be using
SDL_Window *w;
SDL_Renderer *r;

int main(int argc, char* argv[])
{
	//Init us some SDL
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Failed to initialise SDL: %s\n", SDL_GetError());
	}
	else
	{
		//Create the surface before the window - Ubuntu's Unity gets funny
		#include "icon_image.c"
		SDL_Surface *s = SDL_CreateRGBSurfaceFrom(
								ICON_IMAGE_PIXEL_DATA,
								ICON_IMAGE_WIDTH,
								ICON_IMAGE_HEIGHT,
								ICON_IMAGE_BYTES_PER_PIXEL * 8,
								ICON_IMAGE_BYTES_PER_PIXEL * ICON_IMAGE_WIDTH,
								0x000000ff,
								0x0000ff00,
								0x00ff0000,
								0xff000000);

		//Make a window and attached renderer
		SDL_CreateWindowAndRenderer(800, 600, 0, &w, &r);
		SDL_SetWindowTitle(w, "A Cool Game - Coming soon...");

		if (!w)
		{
			printf("Failed to create SDL window: %s\n", SDL_GetError());
		}
		else
		{
			//Set the window icon and free the surface we were using
			SDL_SetWindowIcon(w, s);
			SDL_FreeSurface(s);

			//Clear the window
			SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
			SDL_RenderClear(r);

			//Create a new surface for the splash image
			#include "splash_image.c"
			s = SDL_CreateRGBSurfaceFrom(
								SPLASH_IMAGE_PIXEL_DATA,
								SPLASH_IMAGE_WIDTH,
								SPLASH_IMAGE_HEIGHT,
								SPLASH_IMAGE_BYTES_PER_PIXEL * 8,
								SPLASH_IMAGE_BYTES_PER_PIXEL * SPLASH_IMAGE_WIDTH,
								0x000000ff,
								0x0000ff00,
								0x00ff0000,
								0xff000000);

			//Make an SDL texture from that surface
			SDL_Texture *t = SDL_CreateTextureFromSurface(r, s);

			//Copy from the texter into the renderer
			SDL_Rect rect;
			rect.x = 0;
			rect.y = 0;
			rect.w = 800;
			rect.h = 600;
			SDL_RenderCopyEx(r, t, NULL, &rect, 0, 0, 0);

			//Shove it onto the window
			SDL_RenderPresent(r);

			//Loop until the user wants to quit
			int running = 1;
			while (running)
			{
				SDL_Event e;
				while (SDL_PollEvent(&e))
				{
					//Check for a mouseclick or quit event and quit
					if (e.type == SDL_QUIT || e.type == SDL_MOUSEBUTTONUP)
					{
						running = 0;
						break;
					}
				}
			}

			//Free up all that lovely stuff we made
			SDL_DestroyTexture(t);
			SDL_FreeSurface(s);
			SDL_DestroyRenderer(r);
			SDL_DestroyWindow(w);
		}
		SDL_Quit();
	}

	//Goodbye, friends <3
	return 0;
}

