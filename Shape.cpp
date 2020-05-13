#include"Shape.h"
#include<iostream>
#include<string>
using std::cout;
using std::endl;
Polygon* operator|(const Shape*,const Polygon)
{
	Polygon* a=new Polygon;
	return(a);
}
Polygon* operator&(const Shape*,const Polygon)
{
	Polygon* a=new Polygon;
	return(a);
}

Circle::Circle(const Point center,double rad)
{
	center_ = center;
	radius_ = rad;
}
Circle::Circle(const Point* center, double rad)
{
	center_ = *center;
	radius_ = rad;
}
Circle::Circle(double x,double y,double rad)
{
	center_ = Point(x, y);
	radius_ = rad;
}
Shape* Circle::operator&(const Shape&) const
{
	Polygon* a=new Polygon;
	return(a);
}
Shape* Circle::operator|(const Shape&) const
{
	Polygon* a = new Polygon;
	return(a);
}
double Circle::Circumference()
{
	return(2 * pi * radius_);
}
double Circle::Area()
{
	return(pi * radius_ * radius_);
}
void Circle::Print() 
{
	std::cout << "Center:";
	center_.Print();
	std::cout << std::endl << "Radius:" << radius_<<std::endl;
	std::cout << "Circumference:" << Circumference() << std::endl;
	std::cout << "Area:" << Area() << endl<<endl;
}
bool Circle::IsValid()const
{
	if (radius_ < 0)
	{
		std::cout << "Wrong Enter"<<std::endl; return(0);
	}
	else return (1);
}


Edge::Edge(double ax, double ay, double bx, double by)
{
	a = Point(ax, ay);
	b = Point(bx, by);
}
Edge::Edge(const Point a1, const Point b1)
{
	a = a1;
	b = b1;
}
double Edge::Length()
{
	double x = (a.GetX() - b.GetX());
	double y = (a.GetY() - b.GetY());
	return(sqrt(x * x + y * y));
}
void Edge::Print()
{
	std::cout << "Point 1:";
	a.Print();
	std::cout << "Point 2:";
	b.Print();
	std::cout << "Length:" << Length() << std::endl;
}

