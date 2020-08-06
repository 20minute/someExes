#include "Vector3D.h"

#include <cmath>

using namespace phys;

const Vector3D phys::Vector3D::AXIS_X = Vector3D(1, 0, 0);
const Vector3D phys::Vector3D::AXIS_Y = Vector3D(0, 1, 0);
const Vector3D phys::Vector3D::AXIS_Z = Vector3D(0, 0, 1);
const Vector3D phys::Vector3D::NEGATIVE_AXIS_X = Vector3D(-1, 0, 0);
const Vector3D phys::Vector3D::NEGATIVE_AXIS_Y = Vector3D(0, -1, 0);
const Vector3D phys::Vector3D::NEGATIVE_AXIS_Z = Vector3D(0, 0, -1);

Vector3D::Vector3D() :
	m_x(0),
	m_y(0),
	m_z(0)
{
}

Vector3D::Vector3D(float f) :
	m_x(f),
	m_y(f),
	m_z(f)
{
}

Vector3D::Vector3D(float x, float y, float z) :
	m_x(x),
	m_y(y),
	m_z(z)
{
}

Vector3D::Vector3D(const Vector3D& other) :
	m_x(other.m_x),
	m_y(other.m_y),
	m_z(other.m_z)
{
}

Vector3D::~Vector3D()
{
}

void Vector3D::Add(const Vector3D& other)
{
	m_x += other.m_x;
	m_y += other.m_y;
	m_z += other.m_z;
}

Vector3D Vector3D::operator+(const Vector3D& other) const
{
	Vector3D result(*this);
	result.Add(other);
	return result;
}

void Vector3D::Subtract(const Vector3D& other)
{
	m_x -= other.m_x;
	m_y -= other.m_y;
	m_z -= other.m_z;
}

Vector3D Vector3D::operator-(const Vector3D& other) const
{
	Vector3D result(*this);
	result.Subtract(other);
	return result;
}

Vector3D Vector3D::operator-() const
{
	Vector3D result(*this);
	result.m_x = -result.m_x;
	result.m_y = -result.m_y;
	result.m_z = -result.m_z;
	return result;
}

void Vector3D::Multiply(const Vector3D& other)
{
	m_x *= other.m_x;
	m_y *= other.m_x;
	m_z *= other.m_z;
}



Vector3D Vector3D::Product(const Vector3D& other) const
{
	return Vector3D(m_x * other.m_x, m_y * other.m_y, m_z * other.m_z);
}

float Vector3D::DotProduct(const Vector3D& other) const
{
	return (m_x * other.m_x) + (m_y * other.m_y) + (m_z * other.m_z);
}

Vector3D Vector3D::CrossProduct(const Vector3D& other) const
{
	return Vector3D(
		(m_y * other.m_z) - (m_z * other.m_y),
		(m_z * other.m_x) - (m_x * other.m_z),
		(m_x * other.m_y) - (m_y * other.m_x)
	);
}

void Vector3D::Divide(int scale)
{
	if (scale != 0) {
		m_x /= scale;
		m_y /= scale;
		m_z /= scale;
	}
}

Vector3D Vector3D::operator/(int scale) const
{
	Vector3D result(*this);
	result.Divide(scale);
	return result;
}

void Vector3D::Divide(float scale)
{
	if (scale != 0) {
		m_x /= scale;
		m_y /= scale;
		m_z /= scale;
	}
}

Vector3D Vector3D::operator/(float scale) const
{
	Vector3D result(*this);
	result.Divide(scale);
	return result;
}

void Vector3D::Divide(const Vector3D& other)
{
	if (other.m_x != 0) {
		m_x /= other.m_x;
	}
	if (other.m_y != 0) {
		m_y /= other.m_y;
	}
	if (other.m_z != 0) {
		m_z /= other.m_z;
	}
}

Vector3D Vector3D::operator/(const Vector3D& other) const
{
	Vector3D result(*this);
	result.Divide(other);
	return result;
}

bool Vector3D::operator==(const Vector3D & other) const
{
	if (m_x == other.X() && m_y == other.Y() && m_z == other.Z())
		return true;
	else
		return false;
}

float Vector3D::Magnitude() const
{
	return std::sqrt(DotProduct(*this));
}

float Vector3D::SqrMagnitude() const
{
	return DotProduct(*this);
}

bool Vector3D::IsUnit() const
{
	return Magnitude() == 1;
}

float Vector3D::Distance(const Vector3D& other) const
{
	return (*this - other).Magnitude();
}

void Vector3D::Normalize()
{
	*this /= Magnitude();
}

Vector3D Vector3D::Normalized() const
{
	Vector3D result(*this);
	result.Normalize();
	return result;
}

Vector3D Vector3D::localToWorld(const Vector3D& v) const
{
	return Vector3D(v.X() + m_x, v.Y() + m_y, v.Z() + m_z);

}
Vector3D Vector3D::worldToLocal(const Vector3D& v) const
{
	return Vector3D(m_x - v.X(), m_y - v.Y(), m_z - v.Z());
}
