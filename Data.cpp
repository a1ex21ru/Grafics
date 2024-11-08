#include "Data.h"
// используемые пространства имен
using namespace glm;
using namespace std;

// список графических объектов
vector<GraphicObjects> graphicObjects;

// используемая камера
Camera camera(15, 20, 25);

LARGE_INTEGER frequency;
LARGE_INTEGER start;
LARGE_INTEGER tend;
int fps = 0.0f;
int framecount = 0;

vector <GraphicObjects> models;
vector <vec3> colors;

void init() {
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
}

POINT prev_cursor_pos;
bool first_mouse_movement = 1;
float rotateUDSens = 0.3;
float rotateLRSens = 0.3;

float wheel_sensitive = 0.5;

// функция для инициализации всех общих данных (камера, объекты и т.д.)
void initData()
{
	//// инициализация графических объектов 
	//GraphicObjects tempGraphicObject;
	//// 1 -----------------------------------------
	//tempGraphicObject.setPosition(vec3(5, 0, 0));
	//tempGraphicObject.setAngle(180);
	//tempGraphicObject.setColor(vec3(0, 0, 1));
	//tempGraphicObject.setScale(vec3(1, 1, 1));
	////tempGraphicObject.draw();
	//graphicObjects.push_back(tempGraphicObject);

	//GraphicObjects tempGraphicObject1;
	//// 2 -----------------------------------------
	//tempGraphicObject1.setPosition(vec3(0, 0, 5));
	//tempGraphicObject1.setAngle(90);
	//tempGraphicObject1.setColor(vec3(0, 1, 0));
	//tempGraphicObject1.setScale(vec3(1, 1, 1));
	////tempGraphicObject1.draw();
	//graphicObjects.push_back(tempGraphicObject1);

	//GraphicObjects tempGraphicObject2;
	//// 3 -----------------------------------------
	//tempGraphicObject2.setPosition(vec3(-5, 0, 0));
	//tempGraphicObject2.setAngle(0);
	//tempGraphicObject2.setColor(vec3(1, 1, 0));
	//tempGraphicObject2.setScale(vec3(1, 1, 1));
	////tempGraphicObject2.draw();
	//graphicObjects.push_back(tempGraphicObject2);

	//GraphicObjects tempGraphicObject3;
	//// 4 -----------------------------------------
	//tempGraphicObject3.setPosition(vec3(0, 0, 0));
	//tempGraphicObject3.setAngle(270);
	//tempGraphicObject3.setColor(vec3(1, 0, 0));
	//tempGraphicObject3.setScale(vec3(1, 1, 1));
	////tempGraphicObject3.draw();
	//graphicObjects.push_back(tempGraphicObject3);


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

	GraphicObjects temp[SIZE];

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
