#include "TParam.h"
#include <iostream>
#include <math.h>

using namespace std;

TParam::TParam(double x_start, double x_end, double dx)
{
	set_range(x_start, x_end, dx);
	name = "";
	val_id = 0;
}
TParam::TParam(double x_start, double x_end, double dx, double val)
{
	set_range(x_start, x_end, dx);
	name = "";
	set_val(val);
}
TParam::TParam(std::string name, double x_start, double x_end, double dx)
{
	set_range(x_start, x_end, dx);
	this->name = name;
	val_id = 0;
}
TParam::TParam(std::string name, double x_start, double x_end, double dx, double val)
{
	set_range(x_start, x_end, dx);
	this->name = name;
	set_val(val);
}

void TParam::set_range(double x_start, double x_end, double dx)
{
	this->x_start = x_start;
	this->x_end = x_end;
	this->dx = dx;
}

int TParam::get_val_Id(double val) {
	if (val < x_start) return 0;
	else if (val > x_end) return (x_end - x_start) / dx;

	else {
		double x = x_start;
		int _id = 0;
		while (fabs(x + _id * dx - val) > dx / 2) _id++;

		return _id;

	}
}
	
void TParam::info() {
	cout << "\n";
	cout << "=======================" << "\n";
	cout << "Name: " << name << "\n";
	cout << "Range: [" << x_start << "; " << x_end << "; " << dx << "] \n";
	cout << "Value: " << get_val() << " \t (id: #" << val_id << ")\n";
	cout << "=======================" << "\n";
	}
