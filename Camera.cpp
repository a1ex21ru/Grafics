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
    //��������� ������, ��������� ����
    gluLookAt(position[0], position[1], position[2], 0, 0, 0, 0, 1, 0);
};

void Camera::rotateLeftRight(float degree) {
    // ���������� degree � ��������������� ���� (angleX)
    angleX += degree;
    if (angleX > 180.0f) angleX -= 360.0f;
    if (angleX < -180.0f) angleX += 360.0f;
    // ����������� ���� � ��������� �� 0 �� 360 ��������
    // angleX = fmod(angleX, 360.0f);
    // ������������� ������� ������
    std::cout << angleY << std::endl;
    recalculatePosition();
};


void Camera::rotateUpDown(float degree) {
    // ���������� degree � ������������� ���� (angleY)
    angleY += degree;
    // ������������ ������������ ���� �� -90 �� 90 ��������
    if (angleY > 89.0f) angleY = 89.0f;
    if (angleY < 0.0f) angleY = 0.0f;
    // ������������� ������� ������
    recalculatePosition();
};
void Camera::zoomInOut(float distance) {
    // �������� ���������� �� ����������� ������� (r) �� �������� distance
    std::cout << r << std::endl;
    r += distance;
    // ������������, ����� ���������� �� ���� ������ ������������ �������� (��� �������������� ������� �� ����)
    if (r < 0.1f) r = 0.1f;
    // ������������� ������� ������
    recalculatePosition();
};

vec3 Camera::getPosition() const {
    return position;
};

void Camera::recalculatePosition()
{
    getPosition();
    // ��������� ���� � �������
    float radX = radians(angleX);
    float radY = radians(angleY);

    // ������������� ��������� ������ �� ������ ������� � �����
    position.x = r * cos(radY) * cos(radX);
    position.y = r * sin(radY);
    position.z = r * cos(radY) * sin(radX);

};
// ��������� ������� ������
void Camera::setPosition(vec3 position)
{
    // ���������� ������ - ���������� �� ������ ������� ��������� �� �������� �������
    r = length(position);

    // ���������� ������������ ���� (angleY), ��������� atan2
    angleY = degrees(atan2(position.y, length(vec2(position.x, position.z)))); // ���� �� ���������

    // ���������� �������������� ���� (angleX), ��������� atan2
    angleX = degrees(atan2(position.z, position.x)); // ���� �� �����������

    // ������������� ������� ������
    recalculatePosition();
};