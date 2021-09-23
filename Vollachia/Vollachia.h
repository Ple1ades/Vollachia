#pragma once

#include "../src/include/SDL.h"
#include <algorithm>
#include <iostream>
#include <map>
#include "math.h"
#include <vector>
#include <utility>
namespace Vollachia {
	class Object;
	class Renderer;
	class Physics;
	//struct Vector2;
	class Pixel;
};
class Vollachia::Renderer {
public:
	Vollachia::Renderer* init(const char* title, Uint32 renderer, Uint32 flags);
	int getEntity(Renderer* renderer, const char* name);
	void destroy(Renderer* renderer, int entity);
	void create(Renderer* renderer, const char* name);
	void updateWorld(Renderer* renderer);
	std::map<std::pair<int, int>, int> world;
	std::map<int, Vollachia::Pixel> pixelTypes;
	std::map<int, const char*> layers{};
	int renderWidth;
	int renderHeight;
private:

	SDL_Renderer* renderer;
	SDL_Window* window;
	std::map<const char*, Vollachia::Object> entities;
	std::map<int, const char*> entityTag{};

};
class Vollachia::Object {
public:
	void setFunction(Object* object, char name, void* (*functions)(void));
	std::vector<std::pair<int, int>> touchingPoints(Object* object);
	float x{}, y{};
	int objectNum{};
	bool enabled{};
	std::map<char, void* (*)()> functions;
	float radius{};
	int w{}, h{};
	enum types { Rect = 0, Circle = 1 } objType;
	std::vector<std::pair<int,int>> points{};
	std::vector<int> yValues;
};
class Vollachia::Pixel {
public:
	int placeHolder;
	std::map<char, void (*)()> functions;
};
class Vollachia::Physics {
public:
	static bool intersect(Vollachia::Object* obj1, Vollachia::Object* obj2);
};
//struct Vollachia::Vector2 {
//public:
//	int x;
//	int y;
//	Vector2(int x, int y) { this->x = x; this->y = y; };
//	Vector2 operator+(const Vector2 *v2) {
//		Vector2 vector2 = Vector2(0,0);
//		vector2.x = this->x + v2->x;
//		vector2.y = this->y + v2->y;
//		return vector2;
//	}
//	Vector2 operator*(const Vector2* v2) {
//		Vector2 vector2 = Vector2(0, 0);
//		vector2.x = this->x * v2->x;
//		vector2.y = this->y * v2->y;
//		return vector2;
//	}
//	Vector2 operator/(const Vector2* v2) {
//		Vector2 vector2 = Vector2(0, 0);
//		vector2.x = this->x / v2->x;
//		vector2.y = this->y / v2->y;
//		return vector2;
//	}
//	Vector2 operator%(const Vector2* v2) {
//		Vector2 vector2 = Vector2(0, 0);
//		vector2.x = this->x % v2->x;
//		vector2.y = this->y % v2->y;
//		return vector2;
//	}
//	bool operator>(const Vector2* v2) {
//		bool larger;
//		larger = this->x > v2->x;
//		larger = larger && this->y > v2->y;
//		return larger;
//	}
//	bool operator<(const Vector2* v2) {
//		bool larger;
//		larger = this->x < v2->x;
//		larger = larger && this->y < v2->y;
//		return larger;
//	}
//};