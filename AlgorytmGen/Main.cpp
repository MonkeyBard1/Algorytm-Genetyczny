#include<iostream>
#include<cstdlib>

#include "TParam.h"
#include "TCandidate.h"
#include "TPopulation.h"
#include "TAlghoritm.h"

int main() {

	unsigned int candidates_count = 10;
	unsigned int max_popualtion_count = 20;
	unsigned int min_improvment_proc = 3;

	srand(time(0));

	TAlghoritm task(candidates_count, max_popualtion_count, min_improvment_proc);
	task.run();
	
	return 0;
}