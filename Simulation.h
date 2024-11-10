#pragma once

// функция, вызываемая при изменении размеров окна
void reshape(int w, int h);
void mouse_wheel(int button, int dir, int x, int y);

void keyboard();

// функция вызывается каждые 20 мс
void simulation();
