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

	TCandidate* create() {
		return new TCandidate_zad1();
	}
	TCandidate* create_copy() const {
		return new TCandidate_zad1{ *this };
	}

protected:
	void init_vector();
};


