#include <windows.h>

#include <iostream>

#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"


// ���������� ������������ ���� ����������� ����������
using namespace std;

// ������ ������
float colors[][3] = {
	{0.0f, 0.0f, 0.0f},  // ������
	{1.0f, 1.0f, 1.0f},  // �����
	{0.0f, 0.0f, 1.0f},  // �����
	{1.0f, 0.0f, 0.0f},  // �������
	{0.5f, 0.0f, 0.5f}   // ����������
};

//float* current_color = colors[0];

int count_for_colors = 0;

int currentColorIndex = 0;

// �������, ���������� ��� ��������� �������� ����
void reshape(int w, int h)
{
	// ���������� ����� ������� ���������, ������ ���� ������� ����
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	// ���������� ������� �������� � ���������� ��������
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.0, (float)w / h, 0.2, 70.0);
};

// ������� ���������� ��� ����������� ����
// � ��� ����� � �������������, �� �������� glutPostRedisplay
void display(void)
{
	// �������� ����� ����� � ����� �������
	glClearColor(0.22, 0.88, 0.11, 0.5);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// �������� ���� �������
	glEnable(GL_DEPTH_TEST);

	// ������������� ������
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5, 5, 7.5, 0, 0, 0, 0, 1, 0);

	if (count_for_colors % 50 == 0)
	{
		current_color++; 
	}
	
	glColor3fv(current_color);
	glutWireTeapot(1.0);

	// ����� ��������� � ������� �������
	glutSwapBuffers();
};

// ������� ���������� ������ 20 ��
void simulation(int value)
{
	// ������������� ������� ����, ��� ���� ��������� � �����������
	glutPostRedisplay();

	// ���� ������� ������ 50, ������ �������
	count_for_colors++;

	// ��� �� ������� ����� ������� ��� ��� ����� 20 ��
	glutTimerFunc(20, simulation, 0);
};

// ������� ��������� ������� ������
void keyboardFunc(unsigned char key, int x, int y)
{
	printf("Key code is %i\n", key);
};

// ������� ��� ��������� ������ ����
void mouseFunc(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		currentColorIndex = (currentColorIndex + 1) % (sizeof(colors) / sizeof(colors[0]));
	}
}

void main(int argc, char **argv)
{
	setlocale(0, "ru");

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
	glutCreateWindow("Lab_01");

	// ��������� ������� ��������� ������
	// ������������� �������, ������� ����� ���������� ��� ����������� ����
	glutDisplayFunc(display);

	// ������������� �������, ������� ����� ���������� ��� ��������� �������� ����
	glutReshapeFunc(reshape);

	// ������������� �������, ������� ����� ������� ����� 20 ��
	glutTimerFunc(20, simulation, 0);

	// ������������� �������, ������� ����� ���������� ��� ������� �� �������
	glutKeyboardFunc(keyboardFunc);

	// ��������� �������, ������� ����� ���������� ��� ����� ����
	glutMouseFunc(mouseFunc);

	// �������� ���� ��������� ��������� ��
	glutMainLoop();
};
