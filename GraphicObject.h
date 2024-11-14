#pragma once

#include <windows.h>
#include <vector>
#include "glm\glm.hpp"
#include "GL\freeglut.h";
#include <iostream>
#include <GL\gl.h>
#include <GL\glu.h>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp> 
#include "string"
#include "cstdio"
#include "PhongMaterial.h"
#include <memory>

using namespace glm;

class GraphicObject
{
public:
	GraphicObject();

	// позиция
	void setPosition(vec3 position);
	vec3 getPosition() const;

	// установка и получение угла
	void setAngle(float grad);
	float getAngle() const;

	// установка цвета
	void setColor(vec3 color);
	vec3 getColor() const;

	// масштаб модели
	void setScale(vec3 scale);
	vec3 getScale() const;

	void setMaterial(shared_ptr<PhongMaterial> m);
	void setMaterial(shared_ptr<PhongMaterial> m, int mode);

	// вывод объекта
	void draw();

private:

	// позиция объекта в глобальной области
	vec3 position;

	// угол поворота по горизонтальной области
	float angle;

	// цвет модели
	vec3 color;

	shared_ptr <PhongMaterial> material = make_shared<PhongMaterial>();

	// масштаб модели
	vec3 scal;

	// Матрица модели (расположение объекта) - чтобы не вычислять каждый раз
	mat4 modelMatrix;

	// расчет modelMatrix на основе position и angle
	void recalculateModelMatrix();
};
