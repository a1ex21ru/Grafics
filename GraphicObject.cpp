#include "GraphicObject.h"

GraphicObject::GraphicObject()
{
	recalculateModelMatrix();
}

void GraphicObject::setPosition(glm::vec3 position)
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
}

vec3 GraphicObject::getScale() const
{
	return this->scal;
}

void GraphicObject::draw()
{
	/// сохранение текущей матрицы
	glPushMatrix();

	/// применение модельной матрицы к объекту
	glMultMatrixf(value_ptr(modelMatrix));

	/// усатновка цвета объекта
	glColor3f(color.r, color.g, color.b);

	/// отрисовка объекта
	glutWireTeapot(1.0f);

	/// восстановление матрицы
	glPopMatrix();
}

void GraphicObject::recalculateModelMatrix()
{
	modelMatrix = mat4(1.0f);

	/// перемещение объкта
	modelMatrix = translate(modelMatrix, position);

	/// масшабирование объекта
	//modelMatrix = scale(modelMatrix, scal);

	/// поворот объекта
	modelMatrix = rotate(modelMatrix, radians(angle), vec3(0.0f, 1.0f, 0.0f)); // поворот вокруг оси Y

}

