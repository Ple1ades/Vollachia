#include "VollachiaMain.h"

using namespace Vollachia;

void Object::setFunction(Object* object, char name, void* (*function)(void)) {
	object->functions.insert(std::pair<char, void* (*)()>(name, function));
}
std::vector<std::pair<int, int>> Object::touchingPoints(Object* object) {
	for (int y = 0; y < h; y++) {
		object->yValues.insert(object->yValues.end(), y + floor(object->y));
	}
	switch ((int)object->objType) {
	case 0:
		for (int x = -1; x < w + 1; x++) {
			for (int y = -1; y < h + 1; y++) {
				object->points.insert(object->points.end(), std::pair<int, int>(x + floor(object->x), y + floor(object->y)));
			}
		}
		break;
	case 1:
		for (int x = -1; x < 2 * object->radius + 1; x++) {
			for (int y = -1; y < 2 * object->radius + 1; y++) {
				if (x * x + y * y < object->radius * object->radius) {
					object->points.insert(object->points.end(), std::pair<int, int>(x + floor(object->x), y + floor(object->y)));
				}
			}
		}
		break;
	}
	return object->points;
}
