// https://github.com/toji/gl-matrix/blob/master/src/vec3.js
#include<sourcemod>
#define Vec3ToArray(%1) view_as<float>((%1).x, (%1).y, (%1).z)

enum struct Vec3
{
	float x;
	float y;
	float z;

	Length(bool squared = false)
	{
		return GetVectorLength(Vec3ToArray(this), squared);
	}
}

methodmap Vector3
{
	static public void Clone(const float in[3], float out[3])
	{
		out = in;
	}
	static public float Length(const float in[3], bool squared = false)
	{
		return GetVectorLength(in, false);
	}
	static public void Add(float out[3], const float a[3], const float b[3])
	{
		out[0] = a[0] + b[0];
		out[1] = a[1] + b[1];
		out[2] = a[2] + b[2];
	}
	static public void Sub(float out[3], const float a[3], const float b[3])
	{
		out[0] = a[0] - b[0];
		out[1] = a[1] - b[1];
		out[2] = a[2] - b[2];
	}
	static public void Multiply(float out[3], const float a[3], const float b[3])
	{
		out[0] = a[0] * b[0];
		out[1] = a[1] * b[1];
		out[2] = a[2] * b[2];
	}
	static public void Divide(float out[3], const float a[3], const float b[3])
	{
		out[0] = a[0] / b[0];
		out[1] = a[1] / b[1];
		out[2] = a[2] / b[2];
	}
	static public void Ceil(float out[3], const float a[3])
	{
		out[0] = RoundToCeil(a[0]);
		out[1] = RoundToCeil(a[1]);
		out[2] = RoundToCeil(a[2]);
	}
	static public void Floor(float out[3], const float a[3])
	{
		out[0] = RoundToFloor(a[0]);
		out[1] = RoundToFloor(a[1]);
		out[2] = RoundToFloor(a[2]);
	}
	static public void Round(float out[3], const float a[3])
	{
		out[0] = RoundFloat(a[0]);
		out[1] = RoundFloat(a[1]);
		out[2] = RoundFloat(a[2]);
	}
	static public void Scale(float out[3], const float a[3], const float b)
	{
		out[0] = a[0] * b;
		out[1] = a[1] * b;
		out[2] = a[2] * b;
	}
	static public void ScaleAndAdd(float out[3], const float a[3], const float b[3], const float scale)
	{
		out[0] = a[0] + (b[0] * scale);
  		out[1] = a[1] + (b[1] * scale);
  		out[2] = a[2] + (b[2] * scale);
	}
	static public float Distance(const float a[3], const float b[3])
	{
		float temp[3];
		temp[0] = b[0] - a[0];
		temp[1] = b[1] - a[1];
		temp[2] = b[2] - a[2];
		return GetVectorLength(temp);
	}
	static public float SquaredDistance(const float a[3], const float b[3])
	{
		float x = b[0] - a[0];
		float y = b[1] - a[1];
		float z = b[2] - a[2];
		return x*x + y*y + z*z;
	}
	static public float SquaredLength(const float a[3])
	{
		float x = a[0];
		float y = a[1];
		float z = a[2];
		return x*x + y*y + z*z;
	}
	static public void Negate(float out[3], const float a[3])
	{
		out[0] = -a[0];
		out[1] = -a[1];
		out[2] = -a[2];
	}
	static public void Inverse(float out[3], const float a[3])
	{
		out[0] = 1.0 / a[0];
		out[1] = 1.0 / a[1];
		out[2] = 1.0 / a[2];
	}
	static public void Normalize(float out[3], const float a[3])
	{
		float x = a[0];
		float y = a[1];
		float z = a[2];
		float len = x*x + y*y + z*z;

		if (len > 0.0)
		{
			len = 1.0 / SquareRoot(len);
		}

		out[0] = a[0] * len;
		out[1] = a[1] * len;
		out[2] = a[2] * len;
	}
	static public float Dot(const float a[3], const float b[3])
	{
		return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
	}
	static public void Cross(float out[3], const float a[3], const float b[3])
	{
		float ax = a[0], ay = a[1], az = a[2];
		float bx = b[0], by = b[1], bz = b[2];

		out[0] = ay * bz - az * by;
		out[1] = az * bx - ax * bz;
		out[2] = ax * by - ay * bx;
	}
	static public void Lerp(float out[3], const float a[3], const float b[3], const float t)
	{
		float ax = a[0];
		float ay = a[1];
		float az = a[2];
		out[0] = ax + t * (b[0] - ax);
		out[1] = ay + t * (b[1] - ay);
		out[2] = az + t * (b[2] - az);
		return out;
	}
	static public void Hermite(float out[3], const float a[3], const float b[3], const float c[3], const float d[3], const float t)
	{
		float factorTimes2 = t * t;
		float factor1 = factorTimes2 * (2 * t - 3) + 1;
		float factor2 = factorTimes2 * (t - 2) + t;
		float factor3 = factorTimes2 * (t - 1);
		float factor4 = factorTimes2 * (3 - 2 * t);

		out[0] = a[0] * factor1 + b[0] * factor2 + c[0] * factor3 + d[0] * factor4;
		out[1] = a[1] * factor1 + b[1] * factor2 + c[1] * factor3 + d[1] * factor4;
		out[2] = a[2] * factor1 + b[2] * factor2 + c[2] * factor3 + d[2] * factor4;
	}
	static public void Bezier(float out[3], const float a[3], const float b[3], const float c[3], const float d[3], const float t)
	{
		float inverseFactor = 1 - t;
		float inverseFactorTimesTwo = inverseFactor * inverseFactor;
		float factorTimes2 = t * t;
		float factor1 = inverseFactorTimesTwo * inverseFactor;
		float factor2 = 3 * t * inverseFactorTimesTwo;
		float factor3 = 3 * factorTimes2 * inverseFactor;
		float factor4 = factorTimes2 * t;

		out[0] = a[0] * factor1 + b[0] * factor2 + c[0] * factor3 + d[0] * factor4;
		out[1] = a[1] * factor1 + b[1] * factor2 + c[1] * factor3 + d[1] * factor4;
		out[2] = a[2] * factor1 + b[2] * factor2 + c[2] * factor3 + d[2] * factor4;
	}
	static public void RotateX(float out[3], const float a[3], const float b[3], const float c)
	{
		float p[3], r[3];
		//Translate point to the origin
		p[0] = a[0] - b[0];
		p[1] = a[1] - b[1];
		p[2] = a[2] - b[2];

		//perform rotation
		r[0] = p[0];
		r[1] = p[1] * Cosine(c) - p[2] * Sine(c);
		r[2] = p[1] * Cosine(c) + p[2] * Cosine(c);

		//translate to correct position
		out[0] = r[0] + b[0];
		out[1] = r[1] + b[1];
		out[2] = r[2] + b[2];
	}
	static public void rotateY(float out[3], const float a[3], const float b[3], const float c)
	{
		float p[3], r[3];
		//Translate point to the origin
		p[0] = a[0] - b[0];
		p[1] = a[1] - b[1];
		p[2] = a[2] - b[2];

		//perform rotation
		r[0] = p[2] * Sine(c) + p[0] * Cosine(c);
		r[1] = p[1];
		r[2] = p[2] * Cosine(c) - p[0] * Sine(c);

		//translate to correct position
		out[0] = r[0] + b[0];
		out[1] = r[1] + b[1];
		out[2] = r[2] + b[2];
	}
	static public void rotateZ(float out[3], const float a[3], const float b[3], const float c)
	{
		float p[3], r[3];
		//Translate point to the origin
		p[0] = a[0] - b[0];
		p[1] = a[1] - b[1];
		p[2] = a[2] - b[2];

		//perform rotation
		r[0] = p[0]*Cosine(c) - p[1]*Sine(c);
		r[1] = p[0]*Sine(c) + p[1]*Cosine(c);
		r[2] = p[2];

		//translate to correct position
		out[0] = r[0] + b[0];
		out[1] = r[1] + b[1];
		out[2] = r[2] + b[2];
	}
	static public float Angle(const float a[3], const float b[3])
	{
		float tempA[3] = a;
		float tempB[3] = b;

		Vec3.Normalize(tempA, tempA);
		Vec3.Normalize(tempB, tempB);

		float cosine = Vec3.Dot(tempA, tempB);

		if(cosine > 1.0)
		{
			return 0.0;
		}
		else if(cosine < -1.0)
		{
			return FLOAT_PI;
		}
		else
		{
			return ArcCosine(cosine);
		}
	}
	static public bool Equals(const float a[3], const float b[3])
	{
		return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
	}
}