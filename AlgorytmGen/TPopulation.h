#pragma once

#include <vector>

#include "TCandidate.h"

class TPopulation
{
	unsigned int candidate_count;
	std::vector<TCandidate> candidates;
	double best_val = 0;

public:
	TPopulation(unsigned int cands_count = 10);
	void calculate();
	TCandidate get_best_candidate();
	void get_best_candidate_info();

	void info();
};


