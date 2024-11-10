#include "Display.h"

void display(void)
{

	glClearColor(0.00, 0.00, 0.00, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera.apply();

	for (auto& go : models) {
		go.draw();
	}
	framecount++;

	glutSwapBuffers();

	QueryPerformanceCounter(&end);

	double time_frames = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	if (time_frames >= 1.0) {
		fps = int(framecount / time_frames);
		std::string title = "FPS: " + std::to_string(fps);
		glutSetWindowTitle(title.c_str());
		framecount = 0;
		QueryPerformanceCounter(&start);
	}
};