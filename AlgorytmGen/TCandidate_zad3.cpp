#include "TCandidate_zad3.h"

void TCandidate_zad3::init_vector() {
	genotype.push_back({ "x1",0,10,1 });
	genotype.push_back({ "x2",0,10,1 });
	genotype.push_back({ "x3",0,10,1 });

	gens_count = genotype.size();
}