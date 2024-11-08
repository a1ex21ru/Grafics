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

#include "Camera.h"
#include "GraphicObject.h"

using namespace std;
using namespace glm;

// список графических объектов
extern std::vector<GraphicObjects> graphicObjects;
extern Camera camera;

extern LARGE_INTEGER frequency;
extern LARGE_INTEGER start;
extern LARGE_INTEGER tend;
extern int fps;
extern int framecount;
extern void init();


extern POINT prev_cursor_pos;
extern bool first_mouse_movement;
extern float rotateUDSens;
extern float rotateLRSens;

extern float wheel_sensitive;

extern vector <GraphicObjects> models;
extern vector <vec3> colors;

// функция для инициализации всех общих данных (камера, объекты и т.д.)
void initData();