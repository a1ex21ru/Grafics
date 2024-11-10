#pragma once

#include "GL/freeglut.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <windows.h>

using namespace glm;

class GraphicObject
{
public:
	GraphicObject();

	// позиция
	void setPosition(vec3 position);
	vec3 getPosition() const;

	//установка и получение угла
	void setAngle(float grad);
	float getAngle() const;

	//установка цвета
	void setColor(vec3 color);
	vec3 getColor() const;

	// масштаб модели
	void setScale(vec3 scale);
	vec3 getScale() const;

	// вывод объекта
	void draw();

private:

	// позиция объекта в глобальной области
	vec3 position;

	// угол поворота по горизонтальной области
	float angle;

	// цвет модели
	vec3 color;

	// масштаб модели
	vec3 scal;

	// Матрица модели (расположение объекта) - чтобы не вычислять каждый раз
	mat4 modelMatrix;

	// расчет modelMatrix на основе position и angle
	void recalculateModelMatrix();
};
