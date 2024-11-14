#pragma once

#include "Camera.h"
#include "GraphicObject.h"
#include "Light.h"
#include <cstdio>
#include <GL\freeglut.h>
#include <GL\glut.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp> 
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "PhongMaterial.h"

// список графических объектов
extern std::vector<GraphicObject> models;
// используемая камера
extern Camera camera;

// Объект света
extern Light light;

extern shared_ptr<PhongMaterial> m1;
extern shared_ptr<PhongMaterial> m2;
extern shared_ptr<PhongMaterial> m3;
extern shared_ptr<PhongMaterial> m4;

extern LARGE_INTEGER frequency;
extern LARGE_INTEGER start;
extern LARGE_INTEGER tend;
extern int fps;
extern int framecount;
extern void init();

extern float wheel_sensitive;
extern double degreees;

// функция для инициализации всех общих данных (камера, объекты и т.д.)
void initData();