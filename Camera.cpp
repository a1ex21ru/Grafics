#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "Camera.h"

// Конструкторы камеры
Camera::Camera() : position(0.0f, 0.0f, 5.0f), r(5.0f), angleX(0.0f), angleY(0.0f) {}

Camera::Camera(vec3 position) : position(position), r(length(position)), angleX(0.0f), angleY(0.0f) {
    recalculatePosition();
}

Camera::Camera(float x, float y, float z) : position(x, y, z), r(length(vec3(x, y, z))), angleX(0.0f), angleY(0.0f) {
    recalculatePosition();
} 

// Установка позиции камеры
void Camera::setPosition(vec3 newPosition) {
    position = newPosition;
    r = length(position); // Обновление радиуса на основе новой позиции
    recalculatePosition();
}

// Получение текущей позиции камеры
vec3 Camera::getPosition() const {
    return position;
}

// Поворот камеры влево/вправо
void Camera::rotateLeftRight(float degree) {
    angleY += radians(degree); // Обновляем угол поворота по Y
    recalculatePosition();
}

// Поворот камеры вверх/вниз
void Camera::rotateUpDown(float degree) {
    angleX += radians(degree); // Обновляем угол поворота по X
    // Ограничиваем угол, чтобы избежать инверсии направления взгляда
    angleX = clamp(angleX, -glm::half_pi<float>(), glm::half_pi<float>());
    recalculatePosition();
}

// Приближение/отдаление камеры
void Camera::zoomInOut(float distance) {
    r += distance;
    if (r < 1.0f) r = 1.0f;  // Минимальное расстояние до цели
    recalculatePosition();
}

// Применение матрицы камеры для использования в OpenGL
void Camera::apply() {
    vec3 target = vec3(0.0f, 0.0f, 0.0f); // Камера смотрит на центр сцены
    vec3 up = vec3(0.0f, 1.0f, 0.0f);      // Ось вверх

    //mat4 view = lookAt(position, target, up);
    //glLoadMatrixf(value_ptr(view));
    gluLookAt(position.x, position.y, position.z, 0, 0, 0, 0, 1, 0);
}

// Приватный метод для пересчета позиции камеры
void Camera::recalculatePosition() {
    // Используем сферические координаты для установки позиции камеры
    position.x = r * cos(angleX) * sin(angleY);
    position.y = r * sin(angleX);
    position.z = r * cos(angleX) * cos(angleY);
}





















//Camera::Camera() {};
//Camera::Camera(vec3 position) : position(position) {
//    r = 30;
//    angleX = 40.0f;
//    angleY = 40.0f;
//    recalculatePosition();
//};
//Camera::Camera(float x, float y, float z) {
//    position[0] = x;
//    position[1] = y;
//    position[2] = z;
//    angleX = 40.0f;
//    angleY = 40.0f;
//    r = 30;
//    recalculatePosition();
//};
//void Camera::apply() {//положение камеры, положение цели
//    gluLookAt(position[0], position[1], position[2], 0, 0, 0, 0, 1, 0);
//    //gluLookAt(15, 20, 17.5, 0, 0, 0, 0, 1, 0);
//    //getPosition();
//};
//
//void Camera::rotateLeftRight(float degree) {
//    // Прибавляем degree к горизонтальному углу (angleX)
//    angleX += degree;
//    if (angleX > 180.0f) angleX = 180.0f;
//    if (angleX < -180.0f) angleX = -180.0f;
//    // Нормализуем угол в диапазоне от 0 до 360 градусов
//   // angleX = fmod(angleX, 360.0f);
//  // Пересчитываем позицию камеры
//    std::cout << angleY << std::endl;
//    recalculatePosition();
//};
//
//
//void Camera::rotateUpDown(float degree) {
//    // Прибавляем degree к вертикальному углу (angleY)
//    angleY += degree;
//    // Ограничиваем вертикальный угол от -90 до 90 градусов
//    if (angleY > 89.0f) angleY = 89.0f;
//    if (angleY < 0.0f) angleY = 0.0f;
//    // Пересчитываем позицию камеры
//    recalculatePosition();
//};
//void Camera::zoomInOut(float distance) {
//    // Изменяем расстояние до наблюдаемой позиции (r) на величину distance
//    std::cout << r << std::endl;
//    r += distance;
//    // Обеспечиваем, чтобы расстояние не было меньше минимального значения (для предотвращения деления на ноль)
//    if (r < 0.1f) r = 0.1f;
//    // Пересчитываем позицию камеры
//    recalculatePosition();
//};
//
//void Camera::recalculatePosition()
//{
//    getPosition();
//    // Переводим углы в радианы
//    float radX = radians(angleX);
//    float radY = radians(angleY);
//
//    // Пересчитываем положение камеры на основе радиуса и углов
//    position.x = r * cos(radY) * cos(radX);
//    position.y = r * sin(radY);
//    position.z = r * cos(radY) * sin(radX);
//
//};
//// установка позиции камеры
//void Camera::setPosition(vec3 position)
//{
//    // определяем радиус - расстояние от начала системы координат до заданной позиции
//    r = length(position);
//
//    // Определяем вертикальный угол (angleY), используя atan2
//    angleY = degrees(atan2(position.y, length(vec2(position.x, position.z)))); // Угол по вертикали
//
//    // Определяем горизонтальный угол (angleX), используя atan2
//    angleX = degrees(atan2(position.z, position.x)); // Угол по горизонтали
//
//    // Пересчитываем позицию камеры
//    recalculatePosition();
//};
//vec3 Camera::getPosition() {
//    return position;
//};