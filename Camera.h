#pragma once

#include "Header.h"
using namespace glm;

class Camera
{
public:
    // конструкторы
    Camera();
    Camera(vec3 position);
    Camera(float x, float y, float z);

    // установка и получение позиции камеры
    void setPosition(vec3 position);
    vec3 getPosition() const;

    //функции для перемещения камеры
    void rotateLeftRight(float degree);
    void rotateUpDown(float degree);
    void zoomInOut(float distance);

    // функция для установки матрицы камеры
    void apply();
private:
    // перерасчет позиции камеры после поворотов
    void recalculatePosition();

    // радиус и углы поворота
    float r;
    float angleX;
    float angleY;

    // позиция камеры
    vec3 position;
};