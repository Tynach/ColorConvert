#include <colorvec/vec3.h>
using colorvec::vec3;

/*const floatp vec3::dot(const vec3& other) const
{return x*other.x + y*other.y + z*other.z;}

const floatp vec3::dot(const floatp& other) const
{return x*other + y*other + z*other;}*/

/*vec3& vec3::operator=(const vec3& other)
{
	if (this != &other) {
		*this = {other.x, other.y, other.z};
	}

	return *this;
}*/

/*vec3& vec3::operator+=(const vec3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;

	return *this;
}

vec3& vec3::operator-=(const vec3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;

	return *this;
}

vec3& vec3::operator*=(const vec3& other)
{
	x *= other.x;
	y *= other.y;
	z *= other.z;

	return *this;
}

vec3& vec3::operator/=(const vec3& other)
{
	x /= other.x;
	y /= other.y;
	z /= other.z;

	return *this;
}*/

/*const vec3 vec3::operator+(const vec3& other) const
{return vec3(*this) += other;}

const vec3 vec3::operator-(const vec3& other) const
{return vec3(*this) -= other;}

const vec3 vec3::operator*(const vec3& other) const
{return vec3(*this) *= other;}

const vec3 vec3::operator/(const vec3& other) const
{return vec3(*this) /= other;}*/

/*vec3& vec3::operator+=(const floatp& other)
{
	*this += {other, other, other};

	return *this;
}

vec3& vec3::operator-=(const floatp& other)
{
	*this -= {other, other, other};

	return *this;
}

vec3& vec3::operator*=(const floatp& other)
{
	*this *= {other, other, other};

	return *this;
}

vec3& vec3::operator/=(const floatp& other)
{
	*this /= {other, other, other};

	return *this;
}*/

/*const vec3 vec3::operator+(const floatp& other) const
{return vec3(*this) += other;}

const vec3 vec3::operator-(const floatp& other) const
{return vec3(*this) -= other;}

const vec3 vec3::operator*(const floatp& other) const
{return vec3(*this) *= other;}

const vec3 vec3::operator/(const floatp& other) const
{return vec3(*this) /= other;}

bool vec3::operator==(const vec3& other) const
{return (x == other.x) && (y == other.y) && (z == other.z);}

bool vec3::operator!=(const vec3& other) const
{return !(*this == other);}*/