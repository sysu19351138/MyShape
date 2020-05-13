#include"Shape.h"
#include"Edge.h"
#include"ShapeFile.h"
#include<iostream>
#include<fstream>
#include<string>
using std::cout;
using std::endl;
int main()
{
	std::ifstream inFile;
	inFile.open("shapes.txt");
	ShapeFile a1(inFile);
	Circle c1,c2,c3;//
	Shape* d = (c1 & c2) ;
	Polygon p1, p2, p3;
	Shape* d1 = p1 & p2 | p3;
	a1.Print();
}