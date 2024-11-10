#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Data.h"
#include "Simulation.h"
#include "Display.h"


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");

	// ������������� ���������� GLUT
	glutInit(&argc, argv);
	// ������������� ������� (������ ������)
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	// �������� ����:
	// 1. ������������� ������� ����� ���� ����
	glutInitWindowPosition(200, 200);
	// 2. ������������� ������ ����
	glutInitWindowSize(800, 600);
	// 3. ������� ����
	glutCreateWindow("Lab_4");
	glClear;
	init();
	initData();


	// ��������� ������� ��������� ������
	// ������������� �������, ������� ����� ���������� ��� ����������� ����
	glutDisplayFunc(display);

	// ������������� �������, ������� ����� ���������� ��� ��������� �������� ����
	glutReshapeFunc(reshape);

	// ������������� �������, ������� ����� ���������� ��� ������������� ������ ����
	glutMouseWheelFunc(mouse_wheel);

	// �������� ���� ��������� ��������� ��
	glutIdleFunc(simulation);

	glutMainLoop();
};