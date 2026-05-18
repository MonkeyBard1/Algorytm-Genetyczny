#include<iostream>
#include<cstdlib>

#include "TParam.h"
#include "TCandidate.h"

int main() {

	srand(time(0));

	TParam param1{ 1, 4, 2, 5 };
	TParam param2{ 8, 12, 1, 1 };
	TParam param3{ 30, 120, 5, 5 };

	std::cout << "param1\n";
	param1.info();
	std::cout << "param2\n";
	param2.info();
	std::cout << "param3\n";
	param3.info();

	param2.set_val(100);
	param3.set_val(7.5);
	std::cout << "AFTER\n";
	
	std::cout << "param2\n";
	param2.info();
	std::cout << "param3\n";
	param3.info();

	TCandidate os1{};

	os1.rate();
	os1.info();

	return 0;
}