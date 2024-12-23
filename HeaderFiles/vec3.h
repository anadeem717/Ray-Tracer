#pragma once

#include <cmath>
#include <iostream>

class vec3 {

public:
	double pos[3];

	// Constructors
	vec3() {
		pos[0] = 0;
		pos[1] = 0;
		pos[2] = 0;
	}

	vec3(double pos0, double pos1, double pos2) {
		pos[0] = pos0;
		pos[1] = pos1;
		pos[2] = pos2; 
	}


	// funcs to return x,y,z positions
	double x() const { return pos[0]; }
	double y() const { return pos[1]; }
	double z() const { return pos[2]; }


	// --------------overloaded operators---------------

	vec3 operator-() const { return vec3(-pos[0], -pos[1], -pos[2]); }
	
	double operator[] (int i) const { return pos[i];  }
	
	// Allowing read/write access for pos at index i
	double& operator[] (int i) { return pos[i]; }

	vec3& operator+= (const vec3& v) {
		pos[0] += v.pos[0];
		pos[1] += v.pos[1];
		pos[2] += v.pos[2];
		return *this;
	}

	vec3& operator*= (double t) {
		pos[0] *= t;
		pos[1] *= t;
		pos[2] *= t;
		return *this;
	}

	vec3& operator/=(double t) {
		return *this *= 1 / t;
	}

	double length_squared() const {
		return (pos[0] * pos[0] + pos[1] * pos[1] + pos[2] * pos[2]);
	}

	double length() const {
		return std::sqrt(length_squared());
	}






};