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

	void get_gens_val();
private:
	void set_gens_range();

protected:
	void init_vector();
};

void TCandidate_zad2::init_vector() {
	genotype.push_back({ "x1",0,10,1 });
	genotype.push_back({ "x2",11,10,2 });

	gens_count = genotype.size();
}


