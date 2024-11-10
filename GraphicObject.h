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

	// �������
	void setPosition(vec3 position);
	vec3 getPosition() const;

	//��������� � ��������� ����
	void setAngle(float grad);
	float getAngle() const;

	//��������� �����
	void setColor(vec3 color);
	vec3 getColor() const;

	// ������� ������
	void setScale(vec3 scale);
	vec3 getScale() const;

	// ����� �������
	void draw();

private:

	// ������� ������� � ���������� �������
	vec3 position;

	// ���� �������� �� �������������� �������
	float angle;

	// ���� ������
	vec3 color;

	// ������� ������
	vec3 scal;

	// ������� ������ (������������ �������) - ����� �� ��������� ������ ���
	mat4 modelMatrix;

	// ������ modelMatrix �� ������ position � angle
	void recalculateModelMatrix();
};
