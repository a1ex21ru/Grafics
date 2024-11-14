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

	// �������
	void setPosition(vec3 position);
	vec3 getPosition() const;

	// ��������� � ��������� ����
	void setAngle(float grad);
	float getAngle() const;

	// ��������� �����
	void setColor(vec3 color);
	vec3 getColor() const;

	// ������� ������
	void setScale(vec3 scale);
	vec3 getScale() const;

	void setMaterial(shared_ptr<PhongMaterial> m);
	void setMaterial(shared_ptr<PhongMaterial> m, int mode);

	// ����� �������
	void draw();

private:

	// ������� ������� � ���������� �������
	vec3 position;

	// ���� �������� �� �������������� �������
	float angle;

	// ���� ������
	vec3 color;

	shared_ptr <PhongMaterial> material = make_shared<PhongMaterial>();

	// ������� ������
	vec3 scal;

	// ������� ������ (������������ �������) - ����� �� ��������� ������ ���
	mat4 modelMatrix;

	// ������ modelMatrix �� ������ position � angle
	void recalculateModelMatrix();
};
