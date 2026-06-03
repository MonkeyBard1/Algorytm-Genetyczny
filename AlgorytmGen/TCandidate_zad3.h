#pragma once

#include "TCandidate.h"

class TCandidate_zad3 : public TCandidate
{
public:
	TCandidate_zad3() : TCandidate() { init_vector(); }
	TCandidate_zad3(const TCandidate_zad3& original) : TCandidate(original) {}

	void rate() {
		double x1 = genotype[0].get_val();
		double x2 = genotype[1].get_val();
		double x3 = genotype[2].get_val();

		mark = 100 * x1 + 10 * x2 + x3;
	}

	TCandidate* create() {
		return new TCandidate_zad3();
	}
	TCandidate* create_copy() const {
		return new TCandidate_zad3{ *this };
	}
protected:
	void init_vector();
};


