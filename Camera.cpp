#define _CRT_SECURE_NO_WARNINGS
#include "Camera.h"
#include <iostream>

Camera::Camera() { };

Camera::Camera(vec3 position) : position(position) 
{
    r = 30;
    angleX = 40.0f;
    angleY = 40.0f;
    recalculatePosition();
};
Camera::Camera(float x, float y, float z) 
{
    position[0] = x;
    position[1] = y;
    position[2] = z;
    angleX = 40.0f;
    angleY = 40.0f;
    r = 30;
    recalculatePosition();
};

void Camera::apply() 
{
    //положение камеры, положение цели
    gluLookAt(position[0], position[1], position[2], 0, 0, 0, 0, 1, 0);
};

void Camera::rotateLeftRight(float degree) 
{
    // Прибавляем degree к горизонтальному углу (angleX)
    angleX += degree;
    if (angleX > 180.0f) angleX -= 360.0f;
    if (angleX < -180.0f) angleX += 360.0f;

    // Пересчитываем позицию камеры
    std::cout << angleY << std::endl;
    recalculatePosition();
};

void Camera::rotateUpDown(float degree) 
{
    // Прибавляем degree к вертикальному углу (angleY)
    angleY += degree;
    // Ограничиваем вертикальный угол от -90 до 90 градусов
    if (angleY > 89.0f) angleY = 89.0f;
    if (angleY < 0.0f) angleY = 0.0f;
    // Пересчитываем позицию камеры
    recalculatePosition();
};
void Camera::zoomInOut(float distance) 
{
    // Изменяем расстояние до наблюдаемой позиции (r) на величину distance
    std::cout << r << std::endl;
    r += distance;
    // Обеспечиваем, чтобы расстояние не было меньше минимального значения (для предотвращения деления на ноль)
    if (r < 0.1f) r = 0.1f;
    // Пересчитываем позицию камеры
    recalculatePosition();
};

void Camera::setPosition(vec3 position)
{
    // определяем радиус - расстояние от начала системы координат до заданной позиции
    r = length(position);

    // Определяем вертикальный угол (angleY), используя atan2
    angleY = degrees(atan2(position.y, length(vec2(position.x, position.z)))); // Угол по вертикали

    // Определяем горизонтальный угол (angleX), используя atan2
    angleX = degrees(atan2(position.z, position.x)); // Угол по горизонтали

    // Пересчитываем позицию камеры
    recalculatePosition();
}

vec3 Camera::getPosition() const
{
    return position;
};

void Camera::recalculatePosition()
{
    //getPosition();
    // Переводим углы в радианы
    float radX = radians(angleX);
    float radY = radians(angleY);

    // Пересчитываем положение камеры на основе радиуса и углов
    position.x = r * cos(radY) * cos(radX);
    position.y = r * sin(radY);
    position.z = r * cos(radY) * sin(radX);
}
