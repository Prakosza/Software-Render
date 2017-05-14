#ifndef __VEC2F_H__
#define __VEC2F_H__
class Vec2f
{
	public:
		float x,y;
		Vec3f(float x,float y,float z)
		{
			this->x=x;
			this->z=z;
			this->y=y;
		}
		~Vec3f(){}
};
#endif
