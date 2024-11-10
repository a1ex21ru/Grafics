#include "Data.h"
// ������������ ������������ ����
using namespace glm;
using namespace std;

// ������ ����������� ��������
vector<GraphicObject> graphicObjects;

// ������������ ������
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

// ������� ��� ������������� ���� ����� ������ (������, ������� � �.�.)
void initData()
{
	const int SIZE = 4;
	int offset = 6;

	colors = {
		{ 1.0, 0.0, 0.0 },  // �������
		{ 0.0, 1.0, 0.0 },  // �������
		{ 0.0, 0.0, 1.0 },  // �����
		{ 1.0, 0.0, 1.0 },  // ����������
		{ 1.0, 1.0, 0.0 },  // ������
		{ 0.0, 1.0, 1.0 },  // �������
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
