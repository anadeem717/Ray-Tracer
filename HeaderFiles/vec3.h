#pragma once

#include <cmath>
#include <iostream>

// vec3 class can be used for colors, coordinates, directions, etc. 
class vec3 {

public:
	double vals[3];

	// Constructors
	vec3() {
		vals[0] = 0;
		vals[1] = 0;
		vals[2] = 0;
	}

	vec3(double pos0, double pos1, double pos2) {
		vals[0] = pos0;
		vals[1] = pos1;
		vals[2] = pos2; 
	}


	// funcs to return x,y,z positions
	double x() const { return vals[0]; }
	double y() const { return vals[1]; }
	double z() const { return vals[2]; }


	// --------------overloaded operators---------------

	vec3 operator-() const { return vec3(-vals[0], -vals[1], -vals[2]); }
	
	double operator[] (int i) const { return vals[i];  }
	
	// Allowing read/write access for pos at index i
	double& operator[] (int i) { return vals[i]; }
	 
	vec3& operator+= (const vec3& v) {
		vals[0] += v.vals[0];
		vals[1] += v.vals[1];
		vals[2] += v.vals[2];
		return *this;
	}

	vec3& operator*= (double t) {
		vals[0] *= t;
		vals[1] *= t;
		vals[2] *= t;
		return *this;
	}

	vec3& operator/=(double t) {
		return *this *= 1 / t;
	}

	double length_squared() const {
		return (vals[0] * vals[0] + vals[1] * vals[1] + vals[2] * vals[2]);
	}

	double length() const {
		return std::sqrt(length_squared());
	}


};

// -----------Utility Functions-------------


inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
	return out << v.vals[0] << ' ' << v.vals[1] << ' ' << v.vals[2];
}

inline vec3 operator+(const vec3& u, const vec3& v) {
	return vec3(u.vals[0] + v.vals[0], u.vals[1] + v.vals[1], u.vals[2] + v.vals[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
	return vec3(u.vals[0] - v.vals[0], u.vals[1] - v.vals[1], u.vals[2] - v.vals[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
	return vec3(u.vals[0] * v.vals[0], u.vals[1] * v.vals[1], u.vals[2] * v.vals[2]);
}

inline vec3 operator*(double t, const vec3& v) {
	return vec3(t * v.vals[0], t * v.vals[1], t * v.vals[2]);
}

inline vec3 operator*(const vec3& v, double t) {
	return t * v;
}

inline vec3 operator/(const vec3& v, double t) {
	return (1 / t) * v;
}

// the dot product of 2 vectors
inline double dot(const vec3& u, const vec3& v) {
	return u.vals[0] * v.vals[0]
		+ u.vals[1] * v.vals[1]
		+ u.vals[2] * v.vals[2];
}

// the cross product of 2 vectors
inline vec3 cross(const vec3& u, const vec3& v) {
	return vec3(u.vals[1] * v.vals[2] - u.vals[2] * v.vals[1],
				u.vals[2] * v.vals[0] - u.vals[0] * v.vals[2],
				u.vals[0] * v.vals[1] - u.vals[1] * v.vals[0]);
}

inline vec3 unit_vector(const vec3& v) {
	return v / v.length();
}