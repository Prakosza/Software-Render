#include "tgaimage.h"
#include "vecs.h"
#include "model.h"
void triangle(Vec2<int> a,Vec2<int> b,Vec2<int> c,TGAImage &image, TGAColor &color);
void oldTriangle(Vec2<int> a,Vec2<int> b,Vec2<int> c,TGAImage &image, TGAColor &color);
void triangle(Vec3<Vec3<float>> cord,float *zbuffer,TGAImage &image, const Vec3<Vec2<float>> &colors,float intensity,TGAImage &textures);
void line(int x0,int x1 ,int y0,int y1,TGAImage &image, TGAColor color);
