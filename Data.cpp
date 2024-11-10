#include "Data.h"
// используемые пространства имен
using namespace glm;
using namespace std;

// список графических объектов
vector<GraphicObject> graphicObjects;

// используемая камера
Camera camera(15, 20, 25);

LARGE_INTEGER frequency;
LARGE_INTEGER start;
LARGE_INTEGER end;
int fps = 0.0f;
int framecount = 0;

vector <GraphicObject> models;
vector <vec3> colors;

void init() {
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
}

float wheel_sensitive = 0.5;

// функция для инициализации всех общих данных (камера, объекты и т.д.)
void initData()
{
	const int SIZE = 4;
	int offset = 6;

	colors = {
		{ 1.0, 0.0, 0.0 },  // красный
		{ 0.0, 1.0, 0.0 },  // зеленый
		{ 0.0, 0.0, 1.0 },  // синий
		{ 1.0, 0.0, 1.0 },  // фиолетовый
		{ 1.0, 1.0, 0.0 },  // желтый
		{ 0.0, 1.0, 1.0 },  // голубой
	};

	GraphicObject temp[SIZE];

	vec3 pos[SIZE]{};
	pos[0].x = float(-offset); pos[1].z = offset; pos[2].x = offset; pos[3].z = -offset;

	for (size_t i = 0; i < SIZE; i++)
	{
		temp[i].setAngle(i * 90.f);
		temp[i].setColor(colors[i]);
		temp[i].setPosition(pos[i]);
		temp[i].setScale(vec3(1.f, 1.f, 1.f));

		models.push_back(temp[i]);
	}

}
