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


// ����� ��� ������ � ���������� �����
class Light
{
public:
	// ������������
	Light();
	Light(vec3 position);
	Light(float x, float y, float z);
	// ������� ��������� ���������� ��������� �����
	void setPosition(vec3 position);
	void setAmbient(vec4 color);
	void setDiffuse(vec4 color);
	void setSpecular(vec4 color);

	// ��������� ���� ���������� ��������� ����� � �������� �������
	// ������ ������� ������ ���������� ����� ��������� ������,
	// �.�. ����� ��������������� ������� ��������� �����
	void apply();
private:
	// ������� ��������� �����
	vec4 position;
	// ������� ������������ ��������� �����
	vec4 ambient;
	// ��������� ������������
	vec4 diffuse;
	// ���������� ������������
	vec4 specular;
};