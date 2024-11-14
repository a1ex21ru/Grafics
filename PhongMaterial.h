#pragma once

#include "Header.h"

using namespace std;
using namespace glm;

class PhongMaterial
{
public:
	PhongMaterial(); 
	PhongMaterial(int value);

	// задание параметров материала
	void setAmbient(vec4 color);
	void setDiffuse(vec4 color);
	void setSpecular(vec4 color);
	void setEmission(vec4 color);
	void setShininess(float sh);

	// «агрузка параметров материала из внешнего файла
	void load(string filename);

	// ѕрименение параметров
	void apply();

private:

	// фонова€ составл€юща€
	vec4 ambient;
	// диффузна€ составл€юща€
	vec4 diffuse;
	// зеркальна€ составл€юща€
	vec4 specular;
	// самосвечение
	vec4 emission;
	// степень отполированности
	float shininess;

	string filename;

};



