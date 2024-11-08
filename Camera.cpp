#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "Camera.h"

// ������������ ������
Camera::Camera() : position(0.0f, 0.0f, 5.0f), r(5.0f), angleX(0.0f), angleY(0.0f) {}

Camera::Camera(vec3 position) : position(position), r(length(position)), angleX(0.0f), angleY(0.0f) {
    recalculatePosition();
}

Camera::Camera(float x, float y, float z) : position(x, y, z), r(length(vec3(x, y, z))), angleX(0.0f), angleY(0.0f) {
    recalculatePosition();
} 

// ��������� ������� ������
void Camera::setPosition(vec3 newPosition) {
    position = newPosition;
    r = length(position); // ���������� ������� �� ������ ����� �������
    recalculatePosition();
}

// ��������� ������� ������� ������
vec3 Camera::getPosition() const {
    return position;
}

// ������� ������ �����/������
void Camera::rotateLeftRight(float degree) {
    angleY += radians(degree); // ��������� ���� �������� �� Y
    recalculatePosition();
}

// ������� ������ �����/����
void Camera::rotateUpDown(float degree) {
    angleX += radians(degree); // ��������� ���� �������� �� X
    // ������������ ����, ����� �������� �������� ����������� �������
    angleX = clamp(angleX, -glm::half_pi<float>(), glm::half_pi<float>());
    recalculatePosition();
}

// �����������/��������� ������
void Camera::zoomInOut(float distance) {
    r += distance;
    if (r < 1.0f) r = 1.0f;  // ����������� ���������� �� ����
    recalculatePosition();
}

// ���������� ������� ������ ��� ������������� � OpenGL
void Camera::apply() {
    vec3 target = vec3(0.0f, 0.0f, 0.0f); // ������ ������� �� ����� �����
    vec3 up = vec3(0.0f, 1.0f, 0.0f);      // ��� �����

    //mat4 view = lookAt(position, target, up);
    //glLoadMatrixf(value_ptr(view));
    gluLookAt(position.x, position.y, position.z, 0, 0, 0, 0, 1, 0);
}

// ��������� ����� ��� ��������� ������� ������
void Camera::recalculatePosition() {
    // ���������� ����������� ���������� ��� ��������� ������� ������
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
//void Camera::apply() {//��������� ������, ��������� ����
//    gluLookAt(position[0], position[1], position[2], 0, 0, 0, 0, 1, 0);
//    //gluLookAt(15, 20, 17.5, 0, 0, 0, 0, 1, 0);
//    //getPosition();
//};
//
//void Camera::rotateLeftRight(float degree) {
//    // ���������� degree � ��������������� ���� (angleX)
//    angleX += degree;
//    if (angleX > 180.0f) angleX = 180.0f;
//    if (angleX < -180.0f) angleX = -180.0f;
//    // ����������� ���� � ��������� �� 0 �� 360 ��������
//   // angleX = fmod(angleX, 360.0f);
//  // ������������� ������� ������
//    std::cout << angleY << std::endl;
//    recalculatePosition();
//};
//
//
//void Camera::rotateUpDown(float degree) {
//    // ���������� degree � ������������� ���� (angleY)
//    angleY += degree;
//    // ������������ ������������ ���� �� -90 �� 90 ��������
//    if (angleY > 89.0f) angleY = 89.0f;
//    if (angleY < 0.0f) angleY = 0.0f;
//    // ������������� ������� ������
//    recalculatePosition();
//};
//void Camera::zoomInOut(float distance) {
//    // �������� ���������� �� ����������� ������� (r) �� �������� distance
//    std::cout << r << std::endl;
//    r += distance;
//    // ������������, ����� ���������� �� ���� ������ ������������ �������� (��� �������������� ������� �� ����)
//    if (r < 0.1f) r = 0.1f;
//    // ������������� ������� ������
//    recalculatePosition();
//};
//
//void Camera::recalculatePosition()
//{
//    getPosition();
//    // ��������� ���� � �������
//    float radX = radians(angleX);
//    float radY = radians(angleY);
//
//    // ������������� ��������� ������ �� ������ ������� � �����
//    position.x = r * cos(radY) * cos(radX);
//    position.y = r * sin(radY);
//    position.z = r * cos(radY) * sin(radX);
//
//};
//// ��������� ������� ������
//void Camera::setPosition(vec3 position)
//{
//    // ���������� ������ - ���������� �� ������ ������� ��������� �� �������� �������
//    r = length(position);
//
//    // ���������� ������������ ���� (angleY), ��������� atan2
//    angleY = degrees(atan2(position.y, length(vec2(position.x, position.z)))); // ���� �� ���������
//
//    // ���������� �������������� ���� (angleX), ��������� atan2
//    angleX = degrees(atan2(position.z, position.x)); // ���� �� �����������
//
//    // ������������� ������� ������
//    recalculatePosition();
//};
//vec3 Camera::getPosition() {
//    return position;
//};