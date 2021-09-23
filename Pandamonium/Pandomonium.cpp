#include "../Vollachia/Vollachia.h"


using namespace Vollachia;

Renderer mainRenderer;

int init(){
    mainRenderer = *mainRenderer.init("Pandamonium", SDL_RENDERER_ACCELERATED, SDL_WINDOW_OPENGL);
}