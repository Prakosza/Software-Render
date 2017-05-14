#ifndef __VECS_H__
#define __VECS_H__

template < class type >
class Vec2
{
	public:
		type x,y,len;
		Vec2(type x,type y)
		{
			this->x=x;
			this->y=y;
			
		}
		~Vec2(){}
		
};
template < class type >
class Vec3
{
	public:
		type x,y,z;
		Vec3(type x,type y,type z)
		{
			this->x=x;
			this->z=z;
			this->y=y;
		}
		~Vec3(){}
		Vec2<int> conToVec2(int h,int w)
		{
			return(Vec2<int>((int)((x+1)*(w/2)),(int)((y+1)*(h/2))));
		}
};
#endif



