#include <iostream>
#include <random>
#include <vector>
#include <array>
#include <cmath>       /* acos */

#include "Object.h"


float getFloatFromRange(float from, float to)
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<float> dis(from, to);
	return dis(gen);
}

void createObjects(std::vector<Object>& objects)
{
	int nb_objects = static_cast<int>( getFloatFromRange(1.f,3.f));
	std::cout <<"nb_objects "<<nb_objects<< std::endl;
	for (int i = 0; i < nb_objects; i++) {
		float x = getFloatFromRange(-1.f,1.f);
		float y = getFloatFromRange(-1.f, 1.f);
		std::cout << "x " << x << std::endl;
		std::cout << "y " << y << std::endl;
		int t = static_cast<int>(getFloatFromRange(0.f, 2.f));
		if (t) {
			Object t(Vector3D(x, y, 0), 'c');
			objects.push_back(t);
		}
		else {
			Object t(Vector3D(x, y, 0), 'p');
			objects.push_back(t);
		}
	}

}


void clearObjects(std::vector<Object>& objects) {
	objects.clear();
}

void printResult(std::vector<Object>& objects) {
	std::array<std::array<char,3>, 3> m_res;

	memset(&m_res, '0', sizeof(m_res));

	for (int i = 0; i < objects.size(); i++) {
		float dotProduct = objects[i].Position().DotProduct(Vector3D::AXIS_X);
		std::cout << "dotPro: " << dotProduct << std::endl;
		float angle = acosf(dotProduct / objects[i].Position().Magnitude());
		double pi = 2 * acos(0.0);
		angle = angle *180 / pi;
		if (objects[i].Position().CrossProduct(Vector3D::AXIS_X).Normalized().Z() == 1) {
			angle = -angle;
		}
		std::cout << "angle: " << angle<< std::endl;
		if (-22.5f < angle && angle <= 22.5f) { m_res[1][2] = objects[i].Name(); }
		else if (22.5f < angle && angle <= 67.5f) { m_res[0][2] = objects[i].Name(); }
		else if (67.5f < angle && angle <= 112.5f) { m_res[0][1] = objects[i].Name(); }
		else if (112.5f < angle && angle <= 157.5f) { m_res[0][0] = objects[i].Name(); }
		else if ((157.5f < angle && angle <= 180.f) || (-180.f < angle && angle < -157.5f)) { m_res[1][0] = objects[i].Name(); }
		else if (-157.5f < angle && angle <= -112.5f) { m_res[2][0] = objects[i].Name(); }
		else if (-112.5f < angle && angle <= -67.5f) { m_res[2][1] = objects[i].Name(); }
		else if (-67.5f < angle && angle <= -22.5f) { m_res[2][2] = objects[i].Name(); }
	}


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << m_res[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
}

int main()
{
	std::vector<Object> objectsPool;
	while (1) {
		std::cout << "get objects' position press g" << std::endl;
		std::cout << "clear objects press c" << std::endl;
		std::cout << "print result press p" << std::endl;
		std::cout << "quit program press q" << std::endl;
		char p;
		std::cin >> p;
		switch (p)
		{
		case 'g' :	
			createObjects(objectsPool);
			
			break;
		case 'c' : 
			clearObjects(objectsPool);
			break;
		case 'p':
			printResult(objectsPool);
			clearObjects(objectsPool);
			break;
		case 'q': return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}