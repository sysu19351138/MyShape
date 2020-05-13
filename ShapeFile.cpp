#include<iostream>
#include"ShapeFile.h"
#include"Shape.h"
#include<string>
using std::endl;
using std::cout;
Polygon::Polygon(Point &p1, Point &p2, Point &p3)
{
	static Edge a1(p1, p2);
	edges_.push_back(&a1); i++;
	static Edge a2(p1,p3);
	edges_.push_back(&a2); i++;
	static Edge a3(p2, p3);
	edges_.push_back(&a3); i++;
}
Polygon::Polygon(Point &p1, Point &p2, Point &p3, Point &p4)
{
	static Edge a1(p1, p2);
	edges_.push_back(&a1); i++;
	static Edge a2(p2, p3);
	edges_.push_back(&a2); i++;
	static Edge a3(p3, p4);
	edges_.push_back(&a3); i++;
	static Edge a4(p4, p1);
	edges_.push_back(&a4); i++;
}
void Polygon::Add(Edge* New)
{
	edges_.push_back(New);
	i++;
	std::cout << "Succeed"<<std::endl;
}
double Polygon::Circumference()
{
	double sum = 0;
	for (int n = 0; n < i; n++)
	{
		sum += edges_[n]->Length();
	}
	return(sum);
}
double Polygon::Area()
{
	if (i == 3)
	{
		double p = Circumference() / 2;
		double a=p - edges_[0]->Length();
		double b = p - edges_[1]->Length();
		double c = p - edges_[2]->Length();
		double m = sqrt(p * a * b * c);
		return(m);
	}
	else return UnknownValue;
}
void Polygon::Print() 
{
	std::cout << "Area:" << Area()<<std::endl;
	std::cout << "Circumference:" << Circumference() << std::endl;
	
	for (int n = 0; n < i; n++)
	{
		std::cout << "Edges "<<n+1<<":"<<endl;
		edges_[n]->Print();
		std::cout << std::endl;
	}
}
Shape* Polygon::operator&(const Shape&) const
{
	Polygon* a = new Polygon;
	return(a);
}
Shape* Polygon::operator|(const Shape&) const
{
	Polygon* a = new Polygon;
	return(a);
}

ShapeFile::ShapeFile(std::ifstream& text)
{
	std::string line;
	std::vector<Point*> point;
	while (std::getline(text,line))
	{
		if (line[0] == 'P'&&line[1]!='o')
		{
			int n = 1;
			int x = 0; int y = 0;
			while (1)
			{	
				if (line[n] == '(')
				{
				x = line[n + 1] - 48;
				y = line[n + 3] - 48;
				}
				if (line[n] == '\0') break;
				n++;

			}
			Point* p = new Point(x, y);
			point.push_back(p);
		}

		if (line[0]=='C')
		{
			int n = 1;
			int px[3] = {0}; int rad = 0;
			while (1)
			{
				if (line[n] == 'P')
				{
					px[0] = line[n + 1] - 48;
					if (line[n + 2] == ',')
					{
						px[1] = line[n + 3] - 48;
					}
					else
					{
						px[1] = line[n + 2] - 48;
						px[0] = px[0] * 10 + px[1];
						px[1] = line[n + 4] - 48;
					}
				}
				if (line[n] == '\0') break;
				 n++;
			}
			Circle* p = new Circle(*point[px[0]], px[1]);
			shapes_.push_back(p);
		}
		if (line[0] == 'P'&&line[1]=='o')
		{
			int n = 1;
			std::vector<int> px;
			int i = 0;
			while (1)
			{
				if (line[n] >= '0' && line[n] <= '9')
				{
					int a = 0;
					a= line[n] - 48;
					if (line[n + 1] >= '0' && line[n + 1] <= '9')
					{
						a = a * 10 + (line[n + 1] - 48);
						n++;
					}
					px.push_back(a);
					i++;
				}
				if (line[n] == '\0') break;
				n++;
			}
			if (i == 3)
			{
				Polygon* p = new Polygon(*point[px[0]-1], *point[px[1]-1], *point[px[2]-1]);
				shapes_.push_back(p);
			}
			if (i == 4)
			{
				Polygon* p = new Polygon(*point[px[0]-1], *point[px[1]-1], *point[px[2]-1], *point[px[3]-1]);
				shapes_.push_back(p);
			}
			px.clear();
		}
	}
	
}
ShapeFile::~ShapeFile(){}
void ShapeFile::Generate(Shape& a1,Shape& a2)
{
	Shape* n1 = a1 & a2;
	Shape* n2 = a1 | a2;
	compositeShapes_.push_back(n1);
	compositeShapes_.push_back(n2);
}
void ShapeFile::Print()
{
	for(auto i:shapes_)
	{
		i->Print();
	}
}

