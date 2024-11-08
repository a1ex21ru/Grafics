#pragma once
// graphicObjects.h
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

class GraphicObjects
{
public:

	GraphicObjects();

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
	vec3 getScale();

	// ����� �������
	void draw();

private:

	// ������� ������� � ���������� �������
	vec3 position{ 0 };

	// ���� �������� �� �������������� �������
	float angle = 0;

	// ���� ������
	vec3 color;

	// ������� ������
	vec3 scal;

	// ������� ������ (������������ �������) - ����� �� ��������� ������ ���
	mat4 modelMatrix = mat4(1.f);

	// ������ modelMatrix �� ������ position � angle
	void recalculateModelMatrix();

};
