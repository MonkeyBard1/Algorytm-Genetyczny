#pragma once
#include <vector>
#include <iostream>
#include <string>

#include "TPopulation.h"

class TAlghoritm
{
	unsigned int stop_max_population_count;
	unsigned int stop_min_improvement_proc;
	
	TPopulation* wsk_population_pres = nullptr;
	TPopulation* wsk_population_prev = nullptr;

public: 
	TAlghoritm(unsigned int candidates_count = 50,
		unsigned int max_population_count = 70,
		unsigned int min_improvment_proc = 1);
	~TAlghoritm();

	void run();

private:
	bool is_stop();
	bool is_max_population();
	bool is_min_improvement();
};

