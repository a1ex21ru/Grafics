#include "PhongMaterial.h"

PhongMaterial::PhongMaterial()
{
}

inline PhongMaterial::PhongMaterial(int value)
{
	cout << "Method called" << endl;
}

void PhongMaterial::setAmbient(vec4 color)
{
	this->ambient = color;
}

void PhongMaterial::setDiffuse(vec4 color)
{
	this->diffuse = color;
}

void PhongMaterial::setSpecular(vec4 color)
{
	this->specular = color;
}

void PhongMaterial::setEmission(vec4 color)
{
	this->emission = color;
}

void PhongMaterial::setShininess(float sh)
{
	this->shininess = sh;
}

void PhongMaterial::load(string filename) 
{
	this->filename = filename;
	ifstream file(filename);
	shared_ptr<PhongMaterial> m = make_shared<PhongMaterial>();
	if (file.is_open() && m != nullptr) {

		string in;
		cout << "File open!" << endl;
		float x, y, z, w;

		file >> x >> y >> z >> w;
		diffuse = vec4(x, y, z, w);

		file >> x >> y >> z >> w;
		ambient = vec4(x, y, z, w);

		file >> x >> y >> z >> w;
		specular = vec4(x, y, z, w);

		file >> x >> y >> z >> w;
		emission = vec4(x, y, z, w);

		file >> shininess;
	}
	else {
		cout << "File is not open" << endl;
	}
};

void PhongMaterial::apply()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, glm::value_ptr(ambient));
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, glm::value_ptr(diffuse));
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, glm::value_ptr(specular));
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, glm::value_ptr(emission));

	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}

