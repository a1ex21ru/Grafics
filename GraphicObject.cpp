#include "GraphicObject.h"

GraphicObjects::GraphicObjects()
{
	recalculateModelMatrix();
}

void GraphicObjects::setPosition(glm::vec3 position)
{
	this->position = position;

	recalculateModelMatrix();
}

vec3 GraphicObjects::getPosition() const
{
	return this->position;
}

void GraphicObjects::setAngle(float grad)
{
	this->angle = grad;

	recalculateModelMatrix();
}

float GraphicObjects::getAngle() const
{
	return this->angle;
}

void GraphicObjects::setColor(vec3 color)
{
	this->color = color;
}

vec3 GraphicObjects::getColor() const
{
	return this->color;
}

void GraphicObjects::setScale(vec3 scale)
{
	this->scal = scale;
}

vec3 GraphicObjects::getScale()
{
	return this->scal;
}


void GraphicObjects::draw()
{
	/// сохранение текущей матрицы
	glPushMatrix();

	/// применение модельной матрицы к объекту
	glMultMatrixf(value_ptr(modelMatrix));

	/// усатновка цвета объекта
	glColor3f(color.r, color.g, color.b);

	/// отрисовка объекта
	glutWireTeapot(1.f);

	/// восстановление матрицы
	glPopMatrix();
}

void GraphicObjects::recalculateModelMatrix()
{
	modelMatrix = mat4(1.0f);

	/// перемещение объкта
	modelMatrix = translate(modelMatrix, position);
	/// поворот объекта
	modelMatrix = rotate(modelMatrix, radians(angle), vec3(0.0f, 1.0f, 0.0f)); // поворот вокруг оси Y

	modelMatrix = scale(modelMatrix, scal); // масшатирование модели
	
}

