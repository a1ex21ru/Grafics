#include "Data.h"
#define SHPH shared_ptr<PhongMaterial>

// используемые пространства имен
using namespace glm;
using namespace std;

LARGE_INTEGER frequency;
LARGE_INTEGER start;
LARGE_INTEGER tend;
int fps = 0.0f;
int framecount = 0;

double degreees = 0.5;

// список графических объектов
vector <GraphicObject> models;
vector <vec3> colors;

// используемая камера
Camera camera(15, 20, 25);

// Объект света
Light light(20, 20, 15);

shared_ptr<PhongMaterial> m1 = make_shared<PhongMaterial>();
shared_ptr<PhongMaterial> m2 = make_shared<PhongMaterial>();
shared_ptr<PhongMaterial> m3 = make_shared<PhongMaterial>();
shared_ptr<PhongMaterial> m4 = make_shared<PhongMaterial>();

void init() 
{
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
}

float wheel_sensitive = 0.5;

void initData()
{
	const int SIZE = 4;
	int offset = 4;

	vector<SHPH> materials{ m1, m2, m3, m4 };

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
		temp[i].setAngle(i * 60.f);
		temp[i].setColor(colors[i]);
		temp[i].setPosition(pos[i]);
		temp[i].setMaterial(materials[i], i);
		models.push_back(temp[i]);
	}
	/*models[0].setMaterial(m1, 0);
	models[1].setMaterial(m2, 1);
	models[2].setMaterial(m3, 2);
	models[3].setMaterial(m4, 3);*/

	light.setAmbient(vec4(0.2, 0.2, 0.2, 1.0));
	light.setPosition(vec3(5, 15, 0));
	light.setDiffuse(vec4(1.0, 1.0, 1.0, 1.0));
	light.setSpecular(vec4(1.0, 1.0, 1.0, 1.0));

	light.apply();

}
