#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <iomanip>

using namespace std;

struct Point {
	double x, y;
};

class Shape {
public:
	Shape() {};
	virtual bool within(Point p) = 0;
	virtual void print() = 0;
};

class Rectangle : public Shape {
public:
	Point p1, p2;

	Rectangle(float x1, float y1, float x2, float y2) {
		p1.x = x1; p1.y = y1;
		p2.x = x2; p2.y = y2;
	}

	bool within(Point p) {
		bool part_1 = (p.x > p1.x) && (p.y < p1.y);
		bool part_2 = (p.x < p2.x) && (p.y > p2.y);

		return (part_1 && part_2);
	}

	void print() {
		cout << "p1.x = " << p1.x << " p1.y = " << p1.y << " p2.x = " << p2.x << " p2.y = " << p2.y << endl;
	}
};

class Circle : public Shape {
public:
	Point Centre;
	float radius;

	Circle(float x, float y, float radius) {
		Centre.x = x; Centre.y = y;
		this->radius = radius;
	}

	bool within(Point p) {
		float x = p.x - Centre.x;
		float y = p.y - Centre.y;
		x = pow(x, 2);
		y = pow(y, 2);
		float dist = sqrt(x + y);
		return (dist <= radius);
	};

	void print() {
		cout << "c.x = " << Centre.x << " c.y = " << Centre.y << " r = " << radius << endl;
	}
};

vector <Shape*> s_vec;
vector <Point> p_vec;
int main() {
	string shape;
	while (1) {
		cin >> shape;
		if (shape == "r") {
			Point p1, p2;
			cin >> p1.x >> p1.y >> p2.x >> p2.y;
			Rectangle* Rec = new Rectangle(p1.x, p1.y, p2.x, p2.y);
			s_vec.push_back(Rec);
		}

		else if (shape == "c") {
			Point c;
			float r;
			cin >> c.x >> c.y >> r;
			Circle *circle = new Circle(c.x, c.y, r);
			s_vec.push_back(circle);
		}

		else if (shape == "*") {
			break;
		}
	}

	Point p;
	while (1) {
		cin >> p.x >> p.y;
		if (p.x == 9999.9 && p.y == 9999.9) {
			break;
		}
		else {
			p_vec.push_back(p);
		}
	}

	for (unsigned int i = 0; i < p_vec.size(); i++) {
		bool flag = false;
		for (unsigned int j = 0; j < s_vec.size(); j++) {
			if (s_vec.at(j)->within(p_vec.at(i))) {
				cout << "Point " << i + 1 << " is contained in figure " << j + 1 << endl;
				flag = true;
			}
		}
		if (!flag) {
			cout << "Point " << i + 1 << " is not contained in any figure" << endl;
		}

	}
	return 0;
}
