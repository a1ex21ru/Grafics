#pragma once

#include "Camera.h"
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

// список графических объектов
extern std::vector<GraphicObject> models;

extern LARGE_INTEGER frequency;
extern LARGE_INTEGER start;
extern LARGE_INTEGER  end;
extern int fps;
extern int framecount;
extern void init();

extern float wheel_sensitive;

// используемая камера
extern Camera camera;
// функция для инициализации всех общих данных (камера, объекты и т.д.)
void initData();