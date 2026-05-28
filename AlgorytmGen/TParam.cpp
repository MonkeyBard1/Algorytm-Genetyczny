#include "TParam.h"
#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

TParam::TParam(double x_start, double x_end, double dx) : name{""}
{
	set_range(x_start, x_end, dx);
	
	set_rand_val();
}
TParam::TParam(double x_start, double x_end, double dx, double val) : TParam::TParam(x_start, x_end, dx)
{
	set_val(val);
}
TParam::TParam(std::string name, double x_start, double x_end, double dx) : name{name}
{
	set_range(x_start, x_end, dx);
	set_rand_val();
}
TParam::TParam(std::string name, double x_start, double x_end, double dx, double val) : TParam::TParam( x_start,  x_end,  dx,  val)
{
	set_val(val);
}
TParam::TParam(const TParam &original) {
	double x_start = original.get_x_start();
	double x_end = original.get_x_end();
	double dx = original.get_dx();
	set_range(x_start, x_end, dx);

	double val = original.get_val();
	set_val(val);
}

void TParam::set_range(double x_start, double x_end, double dx)
{
	this->x_start = x_start;
	this->x_end = x_end;
	this->dx = dx;
}


void TParam::set_rand_val() {
	int vals_count = fabs(x_end - x_start) / dx + 1;
	val_id = rand() % vals_count;
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
