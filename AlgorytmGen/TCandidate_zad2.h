#pragma once

#include <iostream>
#include "TCandidate.h"

class TCandidate_zad2 : public TCandidate
{
public:
	TCandidate_zad2() : TCandidate()
	{
		init_vector();
	}

	TCandidate_zad2(const TCandidate& original) : TCandidate(original) {}

	void rate()
	{
		double x1 = genotype[0].get_val();
		double x2 = genotype[1].get_val();

		mark = 2 * (x1 + x2);
	}

protected:
	void init_vector();
	
};


void TCandidate_zad2::init_vector()
{
	genotype.push_back({ "x1",0,10,1 });
	genotype.push_back({ "x2",11,10,2 });

	gens_count = genotype.size();
}

