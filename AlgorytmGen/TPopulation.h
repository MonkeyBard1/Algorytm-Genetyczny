#pragma once

#include <vector>

#include "TCandidate.h"

class TPopulation
{
	static unsigned int _id;
	unsigned int candidate_count;
	std::vector<TCandidate*> candidates;
	double best_val = 0;

public:
	TPopulation(unsigned int cands_count, TCandidate* pattern);
	TPopulation(const TPopulation& original);
	void calculate();
	TCandidate* get_best_candidate();
	void get_best_candidate_info();

	int get_candidate_count() const { return candidate_count; }

	double get_best_val() const { return best_val; }
	
	int get_id() const { return _id; }

	void info();

	TPopulation* rulette(TPopulation* original);

	const TCandidate* get_candidate_wsk(int id) const;
};


