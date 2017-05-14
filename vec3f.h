#ifndef __VEC3F_H__
#define __VEC3F_H__
class Vec3f
{
	public:
		float x,y,z;
		Vec3f(float x,float y,float z)
		{
			this->x=x;
			this->z=z;
			this->y=y;
		}
		~Vec3f(){}
};
#endif

