#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Data.h"
#include "Simulation.h"
#include "Display.h"


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");

	// инициализация библиотеки GLUT
	glutInit(&argc, argv);
	// инициализация дисплея (формат вывода)
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	// СОЗДАНИЕ ОКНА:
	// 1. устанавливаем верхний левый угол окна
	glutInitWindowPosition(200, 200);
	// 2. устанавливаем размер окна
	glutInitWindowSize(800, 600);
	// 3. создаем окно
	glutCreateWindow("Lab_4");
	glClear;
	init();
	initData();


	// УСТАНОВКА ФУНКЦИЙ ОБРАТНОГО ВЫЗОВА
	// устанавливаем функцию, которая будет вызываться для перерисовки окна
	glutDisplayFunc(display);

	// устанавливаем функцию, которая будет вызываться при изменении размеров окна
	glutReshapeFunc(reshape);

	// устанавливаем функцию, которая будет вызываться при прокручивании колеса мыши
	glutMouseWheelFunc(mouse_wheel);

	// основной цикл обработки сообщений ОС
	glutIdleFunc(simulation);

	glutMainLoop();
};