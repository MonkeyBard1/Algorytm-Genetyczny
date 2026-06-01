#pragma once
#include "TParam.h"

#define GENS_COUNT 2

class TCandidate
{
protected: 
	TParam genotype[GENS_COUNT] =
	{
		TParam("x1", 0, 10, 1),
		TParam("x2", 0, 10, 1),		
	};
	double mark;

public:
	TCandidate();
	TCandidate(const TCandidate& original);

	double get_mark() const { return mark; }
	TParam get_gentype() const { return genotype[GENS_COUNT]; }
	virtual void rate();

	virtual void info();

protected:
	void rand_gens_val();
	double get_gens_val(int id) const { return genotype[id].get_val(); }
};

