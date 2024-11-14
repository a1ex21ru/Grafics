#include "GraphicObject.h"

GraphicObject::GraphicObject() : scal(vec3(0))
{
	recalculateModelMatrix();
}

void GraphicObject::setPosition(vec3 position)
{
	this->position = position;

	recalculateModelMatrix();
}

vec3 GraphicObject::getPosition() const
{
	return this->position;
}

void GraphicObject::setAngle(float grad)
{
	this->angle = grad;

	recalculateModelMatrix();
}

float GraphicObject::getAngle() const
{
	return this->angle;
}

void GraphicObject::setColor(vec3 color)
{
	this->color = color;
}

vec3 GraphicObject::getColor() const
{
	return this->color;
}

void GraphicObject::setScale(vec3 scale)
{
	this->scal = scale;

	recalculateModelMatrix();
}

vec3 GraphicObject::getScale() const
{
	return this->scal;
}


void GraphicObject::setMaterial(shared_ptr<PhongMaterial> m, int mode)
{
	cout << "Method setMaterial called!" << endl;
	switch (mode)
	{
	case 1:
		m->load("D:/Users/User/source/repos/Grafics_4/materials/material_1.txt");
		break;

	case 2:
		m->load("material2.txt");
		break;

	case 3:
		m->load("material3.txt");

	case 4:
		m->load("materail4.txt");

	default:
		break;
	}

	this->material = m;
}

void GraphicObject::draw()
{
	/// сохранение текущей матрицы
	glPushMatrix();

	/// применение модельной матрицы к объекту
	glMultMatrixf(value_ptr(modelMatrix));

	/// усатновка цвета объекта
	glColor3f(color.r, color.g, color.b);

	material->apply();

	/// отрисовка объекта
	glutSolidTeapot(1.0f);

	/// восстановление матрицы
	glPopMatrix();
}

void GraphicObject::recalculateModelMatrix()
{
	modelMatrix = mat4(1.0f);

	/// перемещение объкта
	modelMatrix = translate(modelMatrix, position);

	/// масшабирование объекта
	modelMatrix = scale(modelMatrix, scal);

	/// поворот объекта
	modelMatrix = rotate(modelMatrix, radians(angle), vec3(0.0f, 1.0f, 0.f)); // поворот вокруг оси Y
}

