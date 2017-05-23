#define __USE_MINGW_ANSI_STDIO 0
#include "tgaimage.h"
#include "vecs.h"
#include "model.h"
#include "draw.h"
#include<math.h>
#include<fstream>
#include<vector>
#include<iostream>
#include <time.h>
#include <limits>
#include<string>
using namespace std;
TGAColor white = TGAColor(255, 255, 255, 255);
TGAColor red   = TGAColor(255, 0,   0,   255);
TGAColor green = TGAColor(0,   255, 0,   255);
int main(int argc, char** argv) {
	if(argc>2)
	{
		fstream file;
		int seed;
   		time_t tt;
    	seed = time(&tt);
    	srand(seed); 
    	float intensity;
		array<int, 6> face; 
		cout << argv[1] << "\n";
		
		file.open( argv[1], std::ios::in);
		TGAImage texture;
		texture.read_tga_file(argv[2]); 
		Model myModel(file); 
		Vec3<float> lightDir(0,0,-1);
		//cout << "uff\n";
		vector<array<int, 6> > &faces=myModel.getFaces();
		vector<Vec3<float>> &vecs=myModel.getVecs();
		vector<Vec2<float>> &vectex=myModel.getVectex();
		TGAImage image(800, 800, TGAImage::RGB);
		texture.flip_vertically(); 
		cout << "uff\n"; 
		float *zbuffer=new float[image.get_width()*image.get_height()];
		cout << "uff\n";
		for(int i=0;i<image.get_width()*image.get_height();i++)
			zbuffer[i]=numeric_limits<float>::min();
		cout << "uff\n";
		for(unsigned int i=0;i<faces.size();i++)
		{
			face=faces[i];
			Vec3<float> normalvec=((vecs[face[2]]-vecs[face[0]])^(vecs[face[1]]-vecs[face[0]]));
			normalvec.normalize();
			intensity=normalvec*lightDir;
			if(intensity>0)
			{
				Vec3<Vec3<float>> cord(vecs[face[0]].conToScreen(image.get_width(),image.get_height()),vecs[face[1]].conToScreen(image.get_width(),image.get_height()),vecs[face[2]].conToScreen(image.get_width(),image.get_height()));
				Vec2<float> a(vectex[face[3]].x*texture.get_width(),vectex[face[3]].y*texture.get_height());
				Vec2<float> b(vectex[face[4]].x*texture.get_width(),vectex[face[4]].y*texture.get_height());
				Vec2<float> c(vectex[face[5]].x*texture.get_width(),vectex[face[5]].y*texture.get_height());
				Vec3<Vec2<float>> colors(a,b,c);
				//cout << (unsigned int) rad.r << " " << ( unsigned int)  rad.g << " " << (unsigned int)  rad.b << " " << (int) (vectex[face[3]].x*texture.get_width()) << " " << (int) (vectex[face[3]].y*texture.get_height()) << "\n";
				//cout << (unsigned int) colors.x.r << " " << ( unsigned int)  colors.x.g << " " << (unsigned int)  colors.x.b << "\n";
				//cout << (unsigned int) colors.y.r << " " << ( unsigned int)  colors.y.g << " " << (unsigned int)  colors.y.b << "\n";
				//cout << (unsigned int) colors.z.r << " " << ( unsigned int)  colors.z.g << " " << (unsigned int)  colors.z.b << "\n";
				triangle(cord,zbuffer,image,colors,intensity,texture);
			}
		}
		image.flip_vertically();
		image.write_tga_file("output.tga");	
		delete zbuffer;	
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
