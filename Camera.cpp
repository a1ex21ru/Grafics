#define _CRT_SECURE_NO_WARNINGS
#include "Camera.h"
#include <iostream>

Camera::Camera(){};
Camera::Camera(vec3 position) : position(position) {
    r = 30;
    angleX = 40.0f;
    angleY = 40.0f;
    recalculatePosition();
};
Camera::Camera(float x, float y, float z) {
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

void Camera::rotateLeftRight(float degree) {
    // ѕрибавл€ем degree к горизонтальному углу (angleX)
    angleX += degree;
    if (angleX > 180.0f) angleX -= 360.0f;
    if (angleX < -180.0f) angleX += 360.0f;
    // Ќормализуем угол в диапазоне от 0 до 360 градусов
    // angleX = fmod(angleX, 360.0f);
    // ѕересчитываем позицию камеры
    std::cout << angleY << std::endl;
    recalculatePosition();
};


void Camera::rotateUpDown(float degree) {
    // ѕрибавл€ем degree к вертикальному углу (angleY)
    angleY += degree;
    // ќграничиваем вертикальный угол от -90 до 90 градусов
    if (angleY > 89.0f) angleY = 89.0f;
    if (angleY < 0.0f) angleY = 0.0f;
    // ѕересчитываем позицию камеры
    recalculatePosition();
};
void Camera::zoomInOut(float distance) {
    // »змен€ем рассто€ние до наблюдаемой позиции (r) на величину distance
    std::cout << r << std::endl;
    r += distance;
    // ќбеспечиваем, чтобы рассто€ние не было меньше минимального значени€ (дл€ предотвращени€ делени€ на ноль)
    if (r < 0.1f) r = 0.1f;
    // ѕересчитываем позицию камеры
    recalculatePosition();
};

vec3 Camera::getPosition() const {
    return position;
};

void Camera::recalculatePosition()
{
    getPosition();
    // ѕереводим углы в радианы
    float radX = radians(angleX);
    float radY = radians(angleY);

    // ѕересчитываем положение камеры на основе радиуса и углов
    position.x = r * cos(radY) * cos(radX);
    position.y = r * sin(radY);
    position.z = r * cos(radY) * sin(radX);

};
// установка позиции камеры
void Camera::setPosition(vec3 position)
{
    // определ€ем радиус - рассто€ние от начала системы координат до заданной позиции
    r = length(position);

    // ќпредел€ем вертикальный угол (angleY), использу€ atan2
    angleY = degrees(atan2(position.y, length(vec2(position.x, position.z)))); // ”гол по вертикали

    // ќпредел€ем горизонтальный угол (angleX), использу€ atan2
    angleX = degrees(atan2(position.z, position.x)); // ”гол по горизонтали

    // ѕересчитываем позицию камеры
    recalculatePosition();
};