#include <bits/stdc++.h>
using namespace std;

class Point {
protected:
	double _x, _y;	

public:
	Point() : _x(0), _y(0) { }
	Point(double x, double y) : _x(x), _y(y) { }

	double distance(Point p1, Point p2) {
		return sqrt(((p2._x - p1._x) * (p2._x - p1._x)) + ((p2._y - p1._y) * (p2._y - p1._y))); 
	}

	friend ostream& operator<<(ostream& os, const Point& pt) {
        os << "(" << pt._x << ", " << pt._y << ")";
        return os;
    }
};

class Rectangle : public Point {
	Point _p1, _p2, _p3;

public:
	Rectangle() : _p1(Point()), _p2(Point()), _p3(Point()) { }
	Rectangle(Point p1, Point p2, Point p3) : _p1(p1), _p2(p2), _p3(p3) { }
	
	double area() {
		double d1 = distance(_p1, _p2);
		double d2 = distance(_p2, _p3);
		double d3 = distance(_p1, _p3);
		double hyp = max({d1, d2, d3});

		if (hyp == d1) return d2 * d3;
		else if (hyp == d2) return d1 * d3;
		else return d1 * d2;	
	}
	
	void display() {
		cout << "Area of rectangle with vertices " << _p1 << ", " << _p2 << ", " << _p3 << " is " << area() << endl;
	}
};

int main() {
	Point p1(0.0, 0.0), p2(0.0, 1.0), p3(1.0, 0.0);
	Rectangle r1(p1, p2, p3);
	
	Point p4(-1.0, 2.0), p5(3.0, 5.0), p6(1.0, 1.0);
 	Rectangle r2(p4, p5, p6);
  
	Point p7(5.0, 9.0), p8(-0.5, 0.0), p9(7.5, 5.0);
 	Rectangle r3(p7, p8, p9);
	
 	cout << fixed << setprecision(1);

	r1.display();
	r2.display();
	r3.display();

	return 0;
}
