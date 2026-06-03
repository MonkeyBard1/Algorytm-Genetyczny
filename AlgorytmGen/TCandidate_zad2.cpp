#include "TCandidate_zad2.h"

void TCandidate_zad2::set_gens_range() {
	genotype[0].set_range(0, 10, 1);
	genotype[1].set_range(11, 20, 2);

}

void TCandidate_zad2::init_vector() {
	genotype.push_back({ "x1",0,10,1 });
	genotype.push_back({ "x2",11,10,2 });

	gens_count = genotype.size();
}