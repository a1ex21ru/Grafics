#pragma once

#include "GL\freeglut.h"
#include "glm\glm.hpp"
#include "GraphicObject.h"
#include <cstdio>
#include <GL\gl.h>
#include <GL\glu.h>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp> 
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace glm;

class Camera
{
public:
    // ������������
    Camera();
    Camera(vec3 position);
    Camera(float x, float y, float z);

    // ��������� � ��������� ������� ������
    void setPosition(vec3 position);
    vec3 getPosition() const;

    //������� ��� ����������� ������
    void rotateLeftRight(float degree);
    void rotateUpDown(float degree);
    void zoomInOut(float distance);

    // ������� ��� ��������� ������� ������
    void apply();
private:
    // ���������� ������� ������ ����� ���������
    void recalculatePosition();

    // ������ � ���� ��������
    float r;
    float angleX;
    float angleY;

    // ������� ������
    vec3 position;
};