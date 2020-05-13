#pragma once
#include<iostream>
#include<math.h>
#include<vector>
#include"Edge.h"

//Base Shape Class
class Shape
{
public:
	Shape(){};
	virtual ~Shape() {};
	//function
	virtual double Circumference() = 0 { return 0; };
	virtual double Area() = 0 { return 0; };
	virtual void Print() = 0 {};
	virtual bool IsValid() const { return true; };
	virtual Shape* operator & (const Shape&) const = 0 {};
	virtual Shape* operator | (const Shape&) const = 0 {};
private:
	std::vector<Point*> point_;
	std::vector<Edge*> edge_;
};
static const int UnknownValue = -1;

//Circle Class
class Circle:public Shape
{
public:
	Circle() :radius_(0) {};
	Circle(const Point, double);
	Circle(const Point*, double);
	Circle(double, double, double);
	virtual ~Circle() {};
	//function
	 virtual double Circumference()override;
	 virtual double Area() override ;
	 virtual void Print()  override;
	 virtual bool IsValid() const override ;
	 virtual Shape* operator & (const Shape&) const override;
	 virtual Shape* operator | (const Shape&) const override;
private:
	Point center_;
	double radius_;
	const double pi = 3.1415926;
};

//Polygon Class
class Polygon :public Shape
{
public:
	Polygon() {};
	Polygon(Point &, Point &, Point &);
	Polygon(Point &, Point & , Point &, Point &);
	virtual ~Polygon() {};
	//function
	void Add(Edge*);
	virtual double Circumference()override;
	virtual double Area() override;
	virtual void Print()  override;
	virtual bool IsValid() const override { return true; };
	virtual Shape* operator & (const Shape&) const override;
	virtual Shape* operator | (const Shape&) const override;
	friend Polygon* operator |(const Shape*, const Polygon);
	friend Polygon* operator &(const Shape*, const Polygon);
	
private:
	std::vector<Edge*> edges_;
	int i=0;
};

