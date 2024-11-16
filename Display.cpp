#include "Display.h"

void display(void)
{
	// �������� ����� ����� � ����� �������
	glClearColor(0.00, 0.00, 0.00, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// �������� ���� �������, ����� ������� ���������
	glEnable(GL_DEPTH_TEST);

	// ������������� ����� ������� ������������
	//GLfloat globalAmbientColor[] = { 0.2, 0.2, 0.2, 1.0 };
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientColor);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	camera.apply();

	glEnable(GL_LIGHTING);
	light.apply();

	QueryPerformanceCounter(&tend);

	// ������� ��� ����������� �������
	for (auto& go : models) {
		go.draw();
	}
	framecount++;

	glutSwapBuffers();

	QueryPerformanceCounter(&tend);

	double time_frames = static_cast<double>(tend.QuadPart - start.QuadPart) / frequency.QuadPart;
	if (time_frames >= 1.0) {
		fps = int(framecount / time_frames);
		std::string title = "Lab_5 FPS: [" + std::to_string(fps) + "]";
		glutSetWindowTitle(title.c_str());
		framecount = 0;
		QueryPerformanceCounter(&start);
	}

	glutPostRedisplay();
}
