#pragma once
#include<fstream>
#include<iostream>
#include"Shape.h"
//ShapeFile
class ShapeFile
{
public:
	ShapeFile(std::ifstream&);
	~ShapeFile();
	void Generate(Shape&,Shape&);
	void Print();

private:
	std::vector<Shape*> shapes_;
	std::vector<Shape*> compositeShapes_;
	int PointSum = 0;
};
