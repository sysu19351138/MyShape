#pragma once
#include<iostream>
#include"Edge.h"
//Point & Edge
class Point
{
public:
	Point() :x_(0), y_(0) {};
	Point(double x, double y) :x_(x), y_(y) {};
	~Point() {};
	void Print() { std::cout << "x:" << x_ << "  " << "y:" << y_ << std::endl; };
	double GetX() const { return x_; };
	double GetY() const { return y_; };
private:
	double x_;
	double y_;
};

class Edge
{
public:
	Edge(const Point a1, const Point b1) ;
	Edge(double ax, double ay, double bx, double by);
	Edge() {};
	~Edge() {};
	//function
	double Length();
	void Print();
	double Ax() { return a.GetX(); };
	double Ay() { return a.GetY(); };
	double Bx() { return b.GetX(); };
	double By() { return b.GetY(); };
private:
	Point a;
	Point b;
};
