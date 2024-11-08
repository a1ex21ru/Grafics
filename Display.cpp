
#include "Display.h"
#include "Data.h"
#include <string>

void display(void)
{
	
	// отчищаем буфер цвета и буфер глубины
	glClearColor(0.00, 1.00, 0.00, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// включаем тест глубины
	glEnable(GL_DEPTH_TEST);
	// устанавливаем камеру
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	camera.apply();
	//gluLookAt(15, 17, 20, 0, 0, 0, 0, 1, 0);

	QueryPerformanceCounter(&tend);
	// выводим все графические объекты
	for (auto& go : graphicObjects) {

		go.draw();
	}

	framecount++;
	// смена переднего и заднего буферов
	glutSwapBuffers();
	
	
	double time_frames = static_cast<double>(tend.QuadPart - start.QuadPart)/frequency.QuadPart;
	if (time_frames >= 1.0) {
		fps = int(framecount / time_frames);
		std::string title = "FPS: " + std::to_string(fps);
		glutSetWindowTitle(title.c_str());
		framecount = 0;
		QueryPerformanceCounter(&start);
	}

	glutPostRedisplay();
};
