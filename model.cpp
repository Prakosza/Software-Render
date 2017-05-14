#include<vector>
#include <fstream>
#include "model.h"
#include <string>
#include "vecs.h"
#include <sstream>
#include<iostream>
using namespace std;
Model::Model(fstream &file)
{
	char temp;
	int trash;
	float x,y,z;
	string line;
	while(!file.eof())
	{
		getline(file,line);
		istringstream iss(line.c_str());
		if(!line.compare(0,2,"v "))
		{
			iss >> temp;
			iss >> x >> y >> z;
			Vec3<float> vec(x,y,z);
			//cout << "vec " << " " << x << " "  << y << " "  << z << " "  << "\n";
			vecs.push_back(vec);
		}
		else
		{
			if(!line.compare(0,2,"f "))
			{
				iss >> temp;
				array<int, 3>  f;
				iss >> f[0] >> temp >> trash >> temp >> trash >> f[1] >> temp >> trash >> temp >> trash >> f[2];
				f[0]--;f[1]--;f[2]--;
				//cout << f[0] << " "  << f[1] << " "  << f[2] << " "  << "\n";
				faces.push_back(f);
			}
		}
		
	}
}

