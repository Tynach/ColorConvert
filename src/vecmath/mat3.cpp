#include <vecmath/vec3.h>
#include <vecmath/mat3.h>
using vecmath::vec3;
using vecmath::mat3;

/*const floatp mat3::det() const
{
	return vec3({x.x, -y.x, z.x}).dot(
	            {y.y*z.z - y.z*z.y,
	             x.y*z.z - z.y*x.z,
	             x.y*y.z - y.y*x.z});
	     //x.x*(y.y*z.z - y.z*z.y) -
	     //y.x*(x.y*z.z - z.y*x.z) +
	     //z.x*(x.y*y.z - y.y*x.z);
}

const mat3 mat3::transpose() const
{
	return {x.x, y.x, z.x,
	        x.y, y.y, z.y,
	        x.z, y.z, z.z};
}

const mat3 mat3::adjoint() const
{
	return {y.y*z.z - y.z*z.y, -(x.y*z.z - z.y*x.z), x.y*y.z - y.y*x.z,
	        -(y.x*z.z - z.x*y.z), x.x*z.z - z.x*x.z, -(x.x*y.z - y.x*x.z),
	        y.x*z.y - z.x*y.y, -(x.x*z.y - z.x*x.y), x.x*y.y - y.x*x.y};
}

const mat3 mat3::inverse() const
{
	mat3 adj = this->adjoint();
	floatp det = adj.x.dot({x.x, y.x, z.x});

	return adj/det;
}

mat3& mat3::operator+=(const mat3& other)
{
	x += other.x, y += other.y, z += other.z;
	return *this;
}

mat3& mat3::operator-=(const mat3& other)
{
	x -= other.x, y -= other.y, z -= other.z;
	return *this;
}

mat3& mat3::operator*=(const mat3& other)
{
	mat3 m1 = this->transpose();

	*this = {m1.x.dot(other.x), m1.y.dot(other.x), m1.z.dot(other.x),
	         m1.x.dot(other.y), m1.y.dot(other.y), m1.z.dot(other.y),
	         m1.x.dot(other.z), m1.y.dot(other.z), m1.z.dot(other.z)};

	return *this;
}

mat3& mat3::operator/=(const mat3& other)
{
	return *this *= other.inverse();
}

const mat3 mat3::operator+(const mat3& other) const
{
	return mat3(*this) += other;
}

const mat3 mat3::operator-(const mat3& other) const
{
	return mat3(*this) -= other;
}

const mat3 mat3::operator*(const mat3& other) const
{
	return mat3(*this) *= other;
}

const mat3 mat3::operator/(const mat3& other) const
{
	return mat3(*this) /= other;
}

mat3& mat3::operator+=(const floatp& other)
{
	x += other, y += other, z += other;
	return *this;
}

mat3& mat3::operator-=(const floatp& other)
{
	x -= other, y -= other, z -= other;
	return *this;
}

mat3& mat3::operator*=(const floatp& other)
{
	x *= other, y *= other, z *= other;
	return *this;
}

mat3& mat3::operator/=(const floatp& other)
{
	x /= other, y /= other, z /= other;
	return *this;
}

const mat3 mat3::operator+(const floatp& other) const
{
	return mat3(*this) += other;
}

const mat3 mat3::operator-(const floatp& other) const
{
	return mat3(*this) -= other;
}

const mat3 mat3::operator*(const floatp& other) const
{
	return mat3(*this) *= other;
}

const mat3 mat3::operator/(const floatp& other) const
{
	return mat3(*this) /= other;
}

bool mat3::operator==(const mat3& other) const
{
	return (x == other.x) && (y == other.y) && (z == other.z);
}

bool mat3::operator!=(const mat3& other) const
{
	return !(*this == other);
}

const vec3 mat3::operator*(const vec3& other)
{
	mat3 m1 = this->transpose();

	return {m1.x.dot(other), m1.y.dot(other), m1.z.dot(other)};
}*/