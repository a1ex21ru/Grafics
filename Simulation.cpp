#include "Simulation.h"
#include "Data.h"

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

void mouse_wheel(int button, int dir, int x, int y) 
{
	if (dir > 0) {
		camera.zoomInOut(-wheel_sensitive);
	}
	if (dir < 0) {
		camera.zoomInOut(wheel_sensitive);
	}
	std::cout << "��������������" << std::endl;

	glutPostRedisplay();
}

void cursor()
{
	POINT cursor_pos;
	GetCursorPos(&cursor_pos);
	if (first_mouse_movement) {
		prev_cursor_pos = cursor_pos;
		first_mouse_movement = 0;
	}

	int deltaY = cursor_pos.y - prev_cursor_pos.y;
	int deltaX = cursor_pos.x - prev_cursor_pos.x;
	if (deltaY != 0) {
		camera.rotateUpDown(deltaY * rotateUDSens);
	}
	if (deltaX != 0) {
		camera.rotateLeftRight(deltaX * rotateLRSens);
	}
	prev_cursor_pos = cursor_pos;
	glutPostRedisplay();
}

void keyboard()
{
	if (GetAsyncKeyState(VK_UP)) 
	{
		camera.rotateUpDown(1.5);
	}
	if (GetAsyncKeyState(VK_DOWN)) 
	{
		camera.rotateUpDown(-1.5);
	}
	if (GetAsyncKeyState(VK_RIGHT)) 
	{
		camera.rotateLeftRight(1.5);
	}
	if (GetAsyncKeyState(VK_LEFT)) 
	{
		camera.rotateLeftRight(-1.5);
	}
	glutPostRedisplay();

};


// ������� ���������� ������ 20 ��
void simulation()
{
	cursor();
	keyboard();
	// ������������� ������� ����, ��� ���� ��������� � �����������
	glutPostRedisplay();
};