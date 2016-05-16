/*
    Code given for the 2nd and 3rd assignments of CSC 305, University of Victoria
*/

#include "vector.h"

Vector3::Vector3(double m_x/* = 0.0f*/, double m_y/* = 0.0f*/, double m_z/* = 0.0f*/)
    : x(m_x),
      y(m_y),
      z(m_z)
{
}

Vector3::Vector3(const Vector3 & m_v)
: x(m_v.x), y(m_v.y), z(m_v.z)
{
}

Vector3 Vector3::CrossProduct(const Vector3& v1, const Vector3& v2)
    {
        Vector3 result;
        result.x = ((v1.y * v2.z) - (v2.y * v1.z));
        result.y = -((v1.x * v2.z) - (v2.x * v1.z));
        result.z = ((v1.x * v2.y) - (v2.x * v1.y));
        return result;
    }

Vector3 & Vector3::operator = (const Vector3 & v)
{
    if(this != & v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
    }
    return *this;
}

Vector3 & Vector3::operator +=(const Vector3 & v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector3 & Vector3::operator -=(const Vector3 & v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vector3 & Vector3::operator*= (const double  & m)
{
    x *= m;
    y *= m;
    z *= m;
    return *this;
}

Vector3 & Vector3::operator/= (const double & m)
{
    assert(m != 0 && "division by zero!");
    x /= m;
    y /= m;
    z /= m;
    return *this;
}


Vector4::Vector4(double m_x/* = 0.0f*/, double m_y/* = 0.0f*/, double m_z/* = 0.0f*/, double m_w/* = 1.0f*/)
    : x(m_x),
      y(m_y),
      z(m_z),
      w(m_w)
{

}

Vector3  Vector4::getVector3()
{
    return Vector3 (x, y, z);
}

Vector4 & Vector4::operator = (const Vector4 & v)
{
    if(this !=  & v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    return *this;
}

Vector4 & Vector4::operator +=(const Vector4 & v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}

Vector4 & Vector4::operator -=(const Vector4 & v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
}

Vector4 & Vector4::operator*= (const double & m)
{
    x *= m;
    y *= m;
    z *= m;
    w *= m;
    return *this;
}

Vector4 & Vector4::operator/= (const double  & m)
{
    assert(m != 0 && "division by zero!");
    x /= m;
    y /= m;
    z /= m;
    w /= m;
    return *this;
}

