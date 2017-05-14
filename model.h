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
		vector<array<int, 3> > faces;
		vector<Vec3<float>> vecs; 
	public:	
		Model(fstream &file);
		~Model(){};
		vector<array<int, 3>> &getFaces(){return faces;}
		vector<Vec3<float>> &getVecs(){return vecs;}
};
#endif
