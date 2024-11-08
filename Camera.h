#pragma once

#include "GL/freeglut.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <stdio.h>
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
private:
    // ������ � ���� ��������
    float r;
    float angleX;
    float angleY;
    // ������� ������
    vec3 position;
};


