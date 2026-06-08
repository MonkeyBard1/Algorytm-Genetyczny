#include<iostream>
#include<cstdlib>
#include<vector>
#include<array>

#include "TParam.h"
#include "TCandidate.h"
#include "TPopulation.h"
#include "TAlghoritm.h"

#include "TCandidate_zad1.h"
#include "TCandidate_zad2.h"
#include "TCandidate_zad3.h"

int main() {

	TCandidate_zad1 os_zad1;
	os_zad1.rate();
	os_zad1.info();

	TCandidate_zad2 os_zad2;
	os_zad2.rate();
	os_zad2.info();

	TCandidate_zad3 os_zad3;
	os_zad3.rate();
	os_zad3.info();
	
	std::cout << "Ruletka: ";
	unsigned int x = 20;
	TPopulation pop ( x , new TCandidate_zad1);
	pop.calculate();
	std::array<TCandidate*, 2> parents;
	parents = pop.roulette();
	TCandidate* parent1 = parents[0];
	TCandidate* parent2 = parents[1];
	parent1->info();
	parent2->info();

	//unsigned int candidates_count = 10;
	//unsigned int max_popualtion_count = 20;
	//unsigned int min_improvment_proc = 3;

	//srand(time(0));

	//TAlghoritm task(candidates_count, max_popualtion_count, min_improvment_proc);
	//task.run();

	//// Polmorfizm i funkcje wirtualne

	//std::cout << "\n\n\n";

	//std::vector<TCandidate*> candidates;

	//int cand_case;
	//int cand_num;

	//
	//std::cout << "Wybierz wariant kandydata (0-2): ";
	//std::cin >> cand_case;
	//std::cout << "Ile utworzyc osobnikow? ";
	//std::cin >> cand_num;

	//if (cand_case >= 0 && cand_case <= 2) {
	//	for (int i = 0; i < cand_num; i++) {
	//		switch (cand_case) {
	//		case 0:
	//			candidates.push_back(new TCandidate{});
	//			std::cout << "Wariant " << cand_case << " - TCandidate. ID= " << i << std::endl;
	//			candidates[i]->rate();
	//			candidates[i]->info();
	//			break;
	//		case 1:
	//			candidates.push_back(new TCandidate_zad1{});
	//			std::cout << "Wariant " << cand_case << " - TCadnidate_zad1. ID= " << i << std::endl;
	//			candidates[i]->rate();
	//			candidates[i]->info();;
	//			break;
	//		case 2:
	//			candidates.push_back(new TCandidate_zad2{});
	//			std::cout << "Wariant " << cand_case << "- TCadnidate_zad2. ID= " << i << std::endl;
	//			candidates[i]->rate();
	//			candidates[i]->info();
	//			break;
	//		}
	//	}
	//	for (int i = 0; i < candidates.size(); i++) {
	//		delete candidates[i];
	//	}
	//}
	//else { std::cout << "Wprowadzono niepoprawne dane wejsciowe! \n"; }

	
	

	
	return 0;
}
