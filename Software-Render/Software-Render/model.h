#ifndef __MODEL_H__
#define __MODEL_H__
#include<array>
#include<vector>
#include "vecs.h"
#include <fstream>
using namespace std;
class Model
{
	private:
		vector<array<int, 6> > faces;
		vector<Vec3<float>> vecs; 
		vector<Vec2<float>> vectex;
	public:	
		Model(fstream &file);
		~Model(){};
		vector<array<int, 6>> &getFaces(){return faces;}
		vector<Vec3<float>> &getVecs(){return vecs;}
		vector<Vec2<float>> &getVectex(){return vectex;}  
};
#endif
