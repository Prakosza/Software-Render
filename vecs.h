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
		Vec3()
		{
			this->x=0;
			this->z=0;
			this->y=0;
		}
		~Vec3(){}
		Vec2<int> conToVec2(int h,int w)
		{
			return(Vec2<int>((int)((x+1)*(w/2)),(int)((y+1)*(h/2))));
		}
		Vec3<type> cross(Vec3<type> vec)
		{
			Vec3<type> ret(y*vec.z-z*vec.y,z*vec.x-x*vec.z,x*vec.y-y*vec.x);
			return ret;
		}
		static Vec3<type> cross(Vec3<type> vec1,Vec3<type> vec2)
		{
			Vec3<type> ret(vec1.y*vec2.z-vec1.z*vec2.y,vec1.z*vec2.x-vec1.x*vec2.z,vec1.x*vec2.y-vec1.y*vec2.x);
			return ret;
		}		
};
#endif



