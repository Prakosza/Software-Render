#ifndef __VECS_H__
#define __VECS_H__
#include<cmath>
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
		Vec2(){}
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
		Vec3(){}
		~Vec3(){}
		Vec2<int> conToVec2(int h,int w)
		{
			return(Vec2<int>((int)((x+1)*(w/2)),(int)((y+1)*(h/2))));
		}
		Vec3<float> conToScreen(int h,int w)
		{
			return(Vec3<float>(((x+1)*(w/2)),((y+1)*(h/2)),z));
		}
		inline Vec3<type> operator ^ (const Vec3<type> &vec) const 
		{
			return Vec3<type>(y*vec.z-z*vec.y,z*vec.x-x*vec.z,x*vec.y-y*vec.x);
		}
		inline Vec3<type> operator - (const Vec3<type> &vec) const 
		{
			return Vec3<type>(x-vec.x,y-vec.y,z-vec.z);
		}
		inline Vec3<type> operator + (const Vec3<type> &vec) const 
		{
			return Vec3<type>(x+vec.x,y+vec.y,z+vec.z);
		}
		inline type operator * (const Vec3<type> &vec) const 
		{
			return x*vec.x + y*vec.y + z*vec.z;
		}
		inline float norm() 
		{
			return std::sqrt(x*x+y*y+z*z);
		}
		inline void normalize()
		{
			float rn=1/norm();
			x=x*rn;y=y*rn;z=z*rn;
		}
		inline static Vec3<type> cross(const Vec3<type> &vec1,const Vec3<type> &vec2)
		{
			return Vec3<type>(vec1.y*vec2.z-vec1.z*vec2.y,vec1.z*vec2.x-vec1.x*vec2.z,vec1.x*vec2.y-vec1.y*vec2.x);
		}		
};
#endif



