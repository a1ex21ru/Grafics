#pragma once
#include "Header.h"

using namespace std;
using namespace glm;

// ����� ��� ������ � ����������
class PhongMaterial
{
public:
	PhongMaterial(); 
	PhongMaterial(int value);

	// ������� ���������� ���������
	void setAmbient(vec4 color);
	void setDiffuse(vec4 color);
	void setSpecular(vec4 color);
	void setEmission(vec4 color);
	void setShininess(float sh);

	// �������� ���������� ��������� �� �������� �����
	void load(string filename);

	// ���������� ����������
	void apply();

private:

	// ������� ������������
	vec4 ambient;
	// ��������� ������������
	vec4 diffuse;
	// ���������� ������������
	vec4 specular;
	// ������������
	vec4 emission;
	// ������� ����������������
	float shininess;

	string filename;

};



