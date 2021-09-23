#include "Vollachia.h"

using namespace Vollachia;

Renderer* Renderer::init(const char* title, Uint32 renderer, Uint32 flags) {
	SDL_Init(SDL_INIT_EVERYTHING);
	Renderer::window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, renderer);
	Renderer::renderer = SDL_CreateRenderer(window, -1, flags);
	return this;
}

int Renderer::getEntity(Renderer* renderer, const char* name) {
	return (renderer->entities.find(name)->second).objectNum;
}

void Renderer::destroy(Renderer* renderer, int entity) {
	renderer->entityTag.erase(renderer->entityTag.find(entity));
	renderer->entities.erase(renderer->entities.find(renderer->entityTag.find(entity)->second));
}

void Renderer::create(Renderer* renderer, const char* name) {
	Object entity;
	renderer->entityTag.insert(std::pair<int, const char*>(renderer->entities.size(), name));
	entity.objectNum = entities.size();
	renderer->entities.insert(std::pair<const char*, Vollachia::Object>(name, entity));

}

void Renderer::updateWorld(Renderer* renderer) {
	for (int x = 0; x < renderer->renderWidth; x++) {
		for (int y = 0; y < renderer->renderHeight; y++) {
			std::map<char, void (*)()> funct = (renderer->pixelTypes.find(renderer->world.find(std::pair<int, int>(x, y))->second)->second).functions;
			for (auto iter = funct.begin(); iter != funct.end(); iter++) {
				void (*function)() = iter->second;
			}
		}
	}
}