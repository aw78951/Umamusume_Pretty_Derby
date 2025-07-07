#ifndef _VECTOR2_H_
#define _VECTOR2_H_

#include <cmath>

class Vector2 {
	public:
		float x = 0;
		float y = 0;

	public:
		Vector2() = default;
		~Vector2() = default;
	
		Vector2(float x, float y): x(x) , y(y){}

		Vector2 operator+(const Vector2& other) const {
			return Vector2(x + other.x, y + other.y);
		}

		Vector2 operator+=(const Vector2& other) {
			x += other.x;
			y += other.y;
			return *this;
		}

		Vector2 operator-(const Vector2& other) const {
			return Vector2(x - other.x, y - other.y);
		}

		Vector2 operator-=(const Vector2& other) {
			x -= other.x;
			y -= other.y;
			return *this;
		}

		Vector2 operator*(float val) const {
			return Vector2(x * val, y * val);
		}
		
		float operator*(const Vector2& other) const {
			return x * other.x + y * other.y;
		}
		
		Vector2& operator*=(float val){
			x*=val, y*=val;
			return *this;
		}

		Vector2 operator/(float val)const {
			return Vector2(x / val, y / val);
		}

		Vector2& operator/=(float val) {
			x /= val;
			y /= val;
			return *this;
		}

		float Length()const {
			return sqrt(x * x + y * y);
		}

		Vector2 Normalize()const {
			float len = Length();

			if (len == 0) return Vector2(0, 0);
			return Vector2(x / len, y / len);
		}

		bool approx(const Vector2& other) {
			return (*this - other).Length() < 0.0001f;
		}		
};

#endif // £¡_VECTOR2_H_
