typedef long long ftype; //example

struct point2d {
  ftype x, y;
  point2d() {}
  point2d(ftype x, ftype y): x(x), y(y) {}
  point2d& operator+=(const point2d &t) {
    x += t.x; y += t.y;
    return *this;
  }
  point2d& operator-=(const point2d &t) {
    x -= t.x; y -= t.y;
    return *this;
  }
  point2d& operator*=(ftype t) {
    x *= t; y *= t;
    return *this;
  }
  point2d& operator/=(ftype t) {
    x /= t; y /= t;
    return *this;
  }
  point2d operator+(const point2d &t) const {
    return point2d(*this) += t;
  }
  point2d operator-(const point2d &t) const {
    return point2d(*this) -= t;
  }
  point2d operator*(ftype t) const {
    return point2d(*this) *= t;
  }
  point2d operator/(ftype t) const {
    return point2d(*this) /= t;
  }

  ftype dot(const point2d &t) const {
    return x * t.x + y * t.y;
  }
  ftype dot(const point2d &a, const point2d &b) const {
    return (a - *this).dot(b - *this);
    //relative to this
  }

  ftype cross(const point2d &t) const {
    return x * t.y - y * t.x;
  }
  ftype cross(const point2d &a, const point2d &b) const {
    return (a - *this).cross(b - *this);
    //relative to this
  }

  ftype sqrLen() const {
    return this->dot(*this);
  }
};
point2d operator*(ftype a, point2d b) {
  return b * a;
}