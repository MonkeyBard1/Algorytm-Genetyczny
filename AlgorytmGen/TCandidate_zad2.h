#pragma once

#include "TCandidate.h"

class TCandidate_zad2 : public TCandidate
{
public:
	TCandidate_zad2() : TCandidate() 
	{
		set_gens_range();
		rand_gens_val();
	}

	TCandidate_zad2(const TCandidate& original) : TCandidate(original) {}

	void get_gens_val();
private:
	void set_gens_range();
};


