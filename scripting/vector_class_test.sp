#include <sourcemod>
#include <vector_class>

public void OnPluginStart()
{
	float vec1[3], vec2[3], vec3[3], vec4[3], scale = 2.0, lerp = 0.1;

	Vec3.FromValues(vec1, 1.0, 2.0, 3.0);
	Vec3.FromValues(vec3, 4.0, 5.0, 6.0);

	Vec3.Clone(vec2, vec1);
	Vec3.Add(vec4, vec4, vec3);
	Vec3.Sub(vec4, vec4, vec3);
	Vec3.Multiply(vec4, vec4, vec3);
	Vec3.Divide(vec4, vec4, vec3);
	Vec3.Ceil(vec4, vec3);
	Vec3.Floor(vec4, vec3);
	Vec3.Round(vec4, vec4);
	Vec3.Scale(vec4, vec4, scale);
	Vec3.ScaleAndAdd(vec4, vec4, vec3, scale);
	Vec3.Distance(vec4, vec2);
	Vec3.SquaredDistance(vec4, vec2);
	Vec3.SquaredLength(vec4);
	Vec3.Negate(vec4, vec1);
	Vec3.Inverse(vec4, vec1);
	Vec3.Normalize(vec4, vec1);
	Vec3.Dot(vec4, vec1);
	Vec3.Cross(vec4, vec1, vec2);
	Vec3.Lerp(vec4, vec1, vec2, lerp);
	Vec3.Hermite(vec4, vec1, vec2, vec3, vec4, lerp);
	Vec3.Bezier(vec4, vec1, vec2, vec3, vec4, lerp);
	Vec3.RotateX(vec4, vec1, vec2, 30.0);
	Vec3.RotateY(vec4, vec1, vec2, 30.0);
	Vec3.RotateZ(vec4, vec1, vec2, 30.0);
	Vec3.Angle(vec4, vec1);

	bool result = Vec3.Equals(vec1, vec2);

	char buffer[32];
	Vec3.ToString(vec3, buffer, 32);
	float length = Vec3.Length(vec3);

}