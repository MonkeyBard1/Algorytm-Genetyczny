#pragma once

#include "TCandidate.h"

class TCandidate_zad1 : public TCandidate 
{
public:
	TCandidate_zad1() : TCandidate() { init_vector(); }
	TCandidate_zad1(const TCandidate_zad1& original) : TCandidate(original) {}

	void rate() {
		double x1 = genotype[0].get_val();
		double x2 = genotype[1].get_val();

		mark = 2 * (x1 + x2);
	}
protected:
	void init_vector();
};

void TCandidate_zad1::init_vector() {
	genotype.push_back({ "x1",0,100,1 });
	genotype.push_back({ "x2",0,10,1 });

	gens_count = genotype.size();
}
