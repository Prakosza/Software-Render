#define __USE_MINGW_ANSI_STDIO 0
#include "tgaimage.h"
#include "vecs.h"
#include "model.h"
#include<math.h>
#include<fstream>
#include<vector>
#include<iostream>
#include <time.h>
#include<string>
using namespace std;
TGAColor white = TGAColor(255, 255, 255, 255);
TGAColor red   = TGAColor(255, 0,   0,   255);
TGAColor green = TGAColor(0,   255, 0,   255);
void triangle(Vec2<int> a,Vec2<int> b,Vec2<int> c,TGAImage &image, TGAColor &color)
{
	int minx=999999,maxx=0,miny=999999,maxy=0;
	Vec3<int> produkt;
	if(a.x>maxx)
		maxx=a.x;
	if(a.x<minx)
		minx=a.x;
	if(a.y>maxy)
		maxy=a.y;
	if(a.y<miny)
		miny=a.y;
	if(b.x>maxx)
		maxx=b.x;
	if(b.x<minx)
		minx=b.x;
	if(b.y>maxy)
		maxy=b.y;
	if(b.y<miny)
		miny=b.y;
	if(c.x>maxx)
		maxx=c.x;
	if(c.x<minx)
		minx=c.x;
	if(c.y>maxy)
		maxy=c.y;
	if(c.y<miny)
		miny=c.y;
	
	maxx=min(image.get_width(),maxx);
	minx=max(0,minx);
	maxy=min(image.get_height(),maxy);
	miny=max(0,miny);
	//cout << minx << " " << maxx << " " << miny << " " << maxy << "\n";
	for(;minx<=maxx;minx++)
	{
		for(int i=miny;i<=maxy;i++)
		{
			produkt=Vec3<int>::cross(Vec3<int>(b.x-a.x,c.x-a.x,a.x-minx),Vec3<int>(b.y-a.y,c.y-a.y,a.y-i));		
			if(!( 1-((float) (produkt.x+produkt.y))/produkt.z < 0 || ((float) produkt.x)/produkt.z < 0 || ((float) produkt.y)/produkt.z < 0  ))
			{
				image.set(minx,i,color);
				//cout << minx << " " << i << " " << 1-((float) (produkt.x+produkt.y))/produkt.z << " " << ((float) produkt.x)/produkt.z  << " " << ((float) produkt.y)/produkt.z << "\n";
			}
			
		}
		//cout << minx << " " << maxx << "\n";
	}
}
void oldTriangle(Vec2<int> a,Vec2<int> b,Vec2<int> c,TGAImage &image, TGAColor &color)
{
	//cout << "in\n";
	if(a.y>b.y) swap(a,b);
	if(b.y>c.y) swap(b,c);
	if(a.y>b.y) swap(a,b);
	float dabx=(a.x-b.x);
	//cout << "dabx: " << dabx << "\n";
	float daby=(b.y-a.y);
//	cout << "daby: " << daby << "\n";
	float dacx=(a.x-c.x);
	//cout << "dacx: " << dacx << "\n";
	float dacy=(c.y-a.y);
	//cout << "dacy: " << dacy << "\n";
	float dbcx=(b.x-c.x);
	//cout << "dbcx: " << dbcx << "\n";
	float dbcy=(c.y-b.y);
	//cout << "dbcy: " << dbcy << "\n";
	float dac=dacx/dacy;
	//cout << "dac: " << dac << "\n";
	float dab=dabx/daby;
//	cout << "dab: " << dab << "\n";
	float dbc=dbcx/dbcy;
	//cout << "dbc: " << dbc << "\n";
	float x0,y0,x1,p,e;
	int z=0;
	x0=c.x; x1=c.x;
	//cout << "somehow here\n";
	for(y0=c.y;y0>b.y;y0--)
	{
		//cout << z << " " << y0 << " " << x0 << " " << x1 << "\n";
		if(x0<x1)
		{
			p=(int) x0;
			e=(int) x1;
		}
		else
		{
			p=(int) x1;
			e=(int) x0;
		}
		for(;p<e;p++)
		{
			image.set(p,y0,color);
		}
		x0+=dac;
		x1+=dbc;
		//string s="output";
		//s+=to_string(z);
		//s+=+".tga";
		//image.write_tga_file(s.c_str());
		z++;
		
	}
	//cout << "jump\n";
	x1=b.x;
	for(;y0>=a.y;y0--)
	{
		//cout << z << " " << y0 << " " << x0 << " " << x1 << "\n";
		if(x0<x1)
		{
			p=(int) x0;
			e=(int) x1;
		}
		else
		{
			p=(int) x1;
			e=(int) x0;
		}
		for(;p<e;p++)
		{
			image.set(p,y0,color);
		}
		x0+=dac;
		x1+=dab;
		//string s="output";
	//	s+=to_string(z);
	//	s+=+".tga";
	//	image.write_tga_file(s.c_str());
		z++;
	}
	//cout << "out\n";
	
		
}
void line(int x0,int x1,int y0,int y1,TGAImage &image, TGAColor color)
{
	int dx=abs(x1-x0);
	int dy=abs(y1-y0);
	bool step=false;
	if(dy>dx)
	{
		swap(x0,y0);
		swap(x1,y1);
		swap(dx,dy);
		step=true;
	}
	if(x0>x1)
	{
		swap(x1,x0);
		swap(y1,y0);
	}
	int addery=1;
	if(y1<y0)
		addery=-1;
	int dif=dy*2;
	int compdif=dx*2;
	int coldif=0;
	for(;x0<=x1;x0++)
	{//a
		
		if(step)
			image.set(y0,x0,color);
		else
			image.set(x0,y0,color);
		coldif+=dif;
		if(coldif>dx)
		{
			coldif-=compdif;
			y0+=addery;
		}
	}
}
int main(int argc, char** argv) {
	if(argc>1)
	{
		fstream file;
		int seed;
   		time_t tt;
    	seed = time(&tt);
    	srand(seed); 
		array<int, 3> face;
		cout << argv[1] << "\n";
		file.open( argv[1], std::ios::in);
		Model myModel(file);
		//cout << "uff\n";
		vector<array<int, 3> > &faces=myModel.getFaces();
		vector<Vec3<float>> &vecs=myModel.getVecs();
		TGAImage image(800, 800, TGAImage::RGB);
		for(unsigned int i=0;i<faces.size();i++)
		{
			//cout << i << "\n";
			TGAColor rad = TGAColor(rand()%255,rand()%255,rand()%255, 255);
			face=faces[i];
			triangle(vecs[face[0]].conToVec2(800,800),vecs[face[1]].conToVec2(800,800),vecs[face[2]].conToVec2(800,800),image,rad);
			//string s="output";
			//s+=to_string(i);
		//	s+=+".tga";
		//	image.write_tga_file(s.c_str());
			
		}
		image.flip_vertically();
		image.write_tga_file("output.tga");		
	}
	else
	{
		 TGAImage image(200, 200, TGAImage::RGB);

   		Vec2<int> t0[3] = {Vec2<int>(10, 70),   Vec2<int>(50, 160),  Vec2<int>(70, 80)};
    	Vec2<int> t1[3] = {Vec2<int>(180, 50),  Vec2<int>(150, 1),   Vec2<int>(70, 180)};
    	Vec2<int> t2[3] = {Vec2<int>(180, 150), Vec2<int>(120, 160), Vec2<int>(130, 180)};

    	triangle(t0[0], t0[1], t0[2], image, red);
    	image.write_tga_file("output1.tga");
    	//triangle(t1[0], t1[1], t1[2], image, white);
    	//image.write_tga_file("output2.tga");
    	//triangle(t2[0], t2[1], t2[2], image, green);
    	//image.write_tga_file("output3.tga");


    	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    	image.write_tga_file("output.tga");
    	return 0;
	}
	return 0;
}
