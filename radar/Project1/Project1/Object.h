#pragma once

#include "Vector3D.h"

using namespace phys;

class Object
{
private:
	Vector3D m_position;
	char m_name;
public:
	Object(Vector3D position,char name);

	inline Vector3D Position() const { return m_position; }
	inline char Name() const { return m_name; }
};

