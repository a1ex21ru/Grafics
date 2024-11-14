#include "Light.h"

using namespace glm;

Light::Light() {};

Light::Light(vec3 position) {

	this->position.x = position.x;
	this->position.y = position.y;
	this->position.z = position.z;
};

Light::Light(float x, float y, float z) {

	position.x = x;
	position.y = y;
	position.z = z;

};

// задание различных параметров источника света
void Light::setPosition(vec3 position) {

	this->position.x = position.x;
	this->position.y = position.y;
	this->position.z = position.z;

};

void Light::setAmbient(vec4 color) {

	this->ambient = color;
};

void Light::setDiffuse(vec4 color) {

	this->diffuse = color;

};
void Light::setSpecular(vec4 color) {

	this->specular = color;

};

// установка всех параметров источника света с заданным номером
// данная функция должна вызываться после установки камеры,
// т.к. здесь устанавливается позиция источника света

void Light::apply() {

	glEnable(GL_LIGHT0);
	GLfloat diffuse_array[] = { diffuse.x, diffuse.y, diffuse.z, diffuse.w };
	GLfloat ambient_array[] = { ambient.x, ambient.y, ambient.z, ambient.w };
	GLfloat specular_array[] = { specular.x, specular.y, specular.z, specular.w };
	GLfloat position_array[] = { this->position.x, this->position.y, this->position.z, this->position.w };

	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_array);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_array);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular_array);
	glLightfv(GL_LIGHT0, GL_POSITION, position_array);

};