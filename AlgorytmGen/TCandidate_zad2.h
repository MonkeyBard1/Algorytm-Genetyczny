#pragma once

#include "TCandidate.h"

class TCandidate_zad2 : public TCandidate
{
public:
	TCandidate_zad2() : TCandidate() 
	{
		init_vector();
	}

	TCandidate_zad2(const TCandidate& original) : TCandidate(original) {}

	void rate() {
		double x1 = genotype[0].get_val();
		double x2 = genotype[1].get_val();

		mark = 100 * x1 + x2;
	}

	TCandidate* create() {
		return new TCandidate_zad2();
	}
	TCandidate* create_copy() const{
		return new TCandidate_zad2{ *this };
	}

	void get_gens_val();
private:
	void set_gens_range();

protected:
	void init_vector();
};




