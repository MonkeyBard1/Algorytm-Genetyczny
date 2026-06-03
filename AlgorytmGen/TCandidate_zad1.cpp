#include "TCandidate_zad1.h"

void TCandidate_zad1::init_vector() {
	genotype.push_back({ "x1",0,100,1 });
	genotype.push_back({ "x2",0,10,1 });

	gens_count = genotype.size();
}