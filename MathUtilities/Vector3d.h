#ifndef _MYVECTOR3D_
#define _MYVECTOR3D_

#include "matrix2d.h"
#include "sphericalcoords.h"
#include <iostream>
#define PI	3.14159265358979323846
class Vector3d
{
public:
	float x,y,z;


	Vector3d () ;
	Vector3d (float newX, float newY, float newZ);
	Vector3d (float *input);
	Vector3d (SphericalCoords sph);

	//setVector

	Vector3d operator*(const Vector3d &);   //Vector Cross Product
	Vector3d operator*(float scale);  //size multiply

	Vector3d operator/(float scale);  //size divide
	
//	Vector3d operator*(Matrix2d rotationMatrix);  //matrix multiply

	Vector3d operator+(const Vector3d &);	//Vector addition
	Vector3d operator-(const Vector3d &);	//Vector subtraction
	
	Vector3d operator-(); //Vector Negation;


	bool operator!=(const Vector3d &);
	bool operator==(const Vector3d &);
	float operator[](unsigned int);

	friend std::ostream& operator << (std::ostream &os,const Vector3d &obj)
	{
		os << "X: "<< obj.x << " Y: " << obj.y << " Z: " <<	obj.z;
		return os;
	}

	float * glFormat();

	void normalize();			//Normalise a Vector

	Vector3d rangeCompress();

	float euclideanDistance(Vector3d &toDo);
	float squaredEuclideanDistance(Vector3d &toDo);
	float squaredEuclideanDistanceSCALE(Vector3d &toDo);
	
	Vector3d reflectInNormal(const Vector3d & d, const Vector3d & normal);
	static bool isEqual (Vector3d &vector1, Vector3d &vector2, float threshold);
	static float angleBetweenVectors(Vector3d &first,Vector3d &second);
	static float angleBetweenVectors2d(const Vector3d &first, const Vector3d &second, char axis);
	static float signedAngleBetweenVectors(Vector3d &first,Vector3d &second);
	static float dotProduct(const Vector3d &first, const Vector3d &second);
	static Vector3d crossProduct(const Vector3d &first, const Vector3d &second);

	static bool testEquality(Vector3d &toBeTested1, Vector3d &toBeTested2);

	static void limitVector(Vector3d &input, float maxSize);

	static float xzLength(Vector3d toWorkOut);
	static float xzLengthSqr(Vector3d toWorkOut);

	static Vector3d normalize(const Vector3d &toDo);
	
	float size();
	float sizeSqr(); // for comparing relative distances

	SphericalCoords getSphericalRep();
	void setValues(SphericalCoords spher);

	void multiplyMatrix(float *toDo);
};


#endif
