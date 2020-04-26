#include <bits/stdc++.h>

using namespace std;

struct point2d
{
    int x, y;
    point2d() {}
    point2d(int x, int y) : x(x), y(y) {}
    point2d &operator+=(const point2d &t)
    {
        x += t.x;
        y += t.y;
        return *this;
    }
    point2d &operator-=(const point2d &t)
    {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point2d &operator*=(int t)
    {
        x *= t;
        y *= t;
        return *this;
    }
    point2d &operator/=(int t)
    {
        x /= t;
        y /= t;
        return *this;
    }
    point2d operator+(const point2d &t) const
    {
        return point2d(*this) += t;
    }
    point2d operator-(const point2d &t) const
    {
        return point2d(*this) -= t;
    }
    point2d operator*(int t) const
    {
        return point2d(*this) *= t;
    }
    point2d operator/(int t) const
    {
        return point2d(*this) /= t;
    }
};
point2d operator*(int a, point2d b)
{
    return b * a;
}

struct point3d
{
    int x, y, z;
    point3d() {}
    point3d(int x, int y, int z) : x(x), y(y), z(z) {}
    point3d &operator+=(const point3d &t)
    {
        x += t.x;
        y += t.y;
        z += t.z;
        return *this;
    }
    point3d &operator-=(const point3d &t)
    {
        x -= t.x;
        y -= t.y;
        z -= t.z;
        return *this;
    }
    point3d &operator*=(int t)
    {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    point3d &operator/=(int t)
    {
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }
    point3d operator+(const point3d &t) const
    {
        return point3d(*this) += t;
    }
    point3d operator-(const point3d &t) const
    {
        return point3d(*this) -= t;
    }
    point3d operator*(int t) const
    {
        return point3d(*this) *= t;
    }
    point3d operator/(int t) const
    {
        return point3d(*this) /= t;
    }
};
point3d operator*(int a, point3d b)
{
    return b * a;
}

point3d cross(point3d a, point3d b)
{
    return point3d(a.y * b.z - a.z * b.y,
                   a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
}

int dot(point3d a, point3d b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

int triple(point3d a, point3d b, point3d c)
{
    return dot(a, cross(b, c));
}
int cross(point2d a, point2d b)
{
    return a.x * b.y - a.y * b.x;
}