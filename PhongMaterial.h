#pragma once
#include "Header.h"

using namespace std;
using namespace glm;

// КЛАСС ДЛЯ РАБОТЫ С МАТЕРИАЛОМ
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

	// Загрузка параметров материала из внешнего файла
	void load(string filename);

	// Применение параметров
	void apply();

private:

	// фоновая составляющая
	vec4 ambient;
	// диффузная составляющая
	vec4 diffuse;
	// зеркальная составляющая
	vec4 specular;
	// самосвечение
	vec4 emission;
	// степень отполированности
	float shininess;

	string filename;

};



