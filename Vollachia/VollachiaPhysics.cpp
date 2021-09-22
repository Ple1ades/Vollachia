#include "VollachiaMain.h"

using namespace Vollachia;

bool Physics::intersect(Object* obj1, Object* obj2) {
	if (obj1->objType == 0 && obj2->objType == 0) return (
		obj1->x < obj2->x + obj2->w &&
		obj1->x + obj1->w > obj2->x &&
		obj1->y < obj2->y + obj2->h &&
		obj1->y + obj1->h > obj2->y);
	if (obj1->objType == 0) {
		float Xn = std::max(obj1->x, std::min(obj2->x, obj1->x + obj1->w));
		float Yn = std::max(obj1->y, std::min(obj2->y, obj1->y + obj1->h));
		return (Xn - obj2->x) * (Xn - obj2->x) + (Yn - obj2->y) * (Yn - obj2->y) <= obj2->radius;
	}
	if (obj2->objType == 0) {
		float Xn = std::max(obj2->x, std::min(obj1->x, obj2->x + obj2->w));
		float Yn = std::max(obj2->y, std::min(obj1->y, obj2->y + obj2->h));
		return (Xn - obj1->x) * (Xn - obj1->x) + (Yn - obj1->y) * (Yn - obj1->y) <= obj1->radius;
	}
	float dist = (obj1->x - obj2->x) * (obj1->x - obj2->x) + (obj1->y - obj2->y) * (obj1->y - obj2->y);
	float rad = (obj1->radius + obj2->radius) * (obj1->radius + obj2->radius);
	return dist < rad;
}