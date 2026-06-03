#include "TPopulation.h"
#include <iostream>
#include <algorithm> // max

using namespace std;

unsigned int TPopulation::_id = 0;

TPopulation::TPopulation(unsigned int cands_count, TCandidate* pattern) {
	candidate_count = cands_count;

	_id++;

	for (int i = 0;i < cands_count;i++) candidates.push_back(pattern->create());
}
TPopulation::TPopulation(const TPopulation& original) {
	unsigned int candidate_count = original.get_candidate_count();
	double best_val = original.get_best_val();
	_id++;

	for (int i = 0; i < candidate_count; i++) {
		const TCandidate* wsk_os_org = original.get_candidate_wsk(i);
		TCandidate* copy = wsk_os_org->create_copy();
		candidates.push_back(copy);
	}
	std::cout << "Utworzono kopie populacji #" << original.get_id() << " jako populacje #" << _id;
}

void TPopulation::calculate() {
	double best_val = 0.0;

	for (int i = 0; i < candidate_count;i++)
	{
		candidates[i]->rate();
		double val = candidates[i]->get_mark();
		if (i == 0) best_val = val;
		else best_val = max(best_val, val);
	}
	this->best_val = best_val;
}


	TCandidate* TPopulation::get_best_candidate() {

		int i=0;

		while (candidates[i]->get_mark() != best_val) i++;

		return candidates[i];
	}
	void TPopulation::get_best_candidate_info() {
		TCandidate* best_cand = get_best_candidate();
		best_cand->info();
		cout << "best value: " << best_val << endl;
	}
	void TPopulation::info() {
		cout << "\n\n";
		cout << "==============================\n";
		cout << "population size: " << candidate_count << "\n";
		cout << "best val: " << best_val << "\n";
		cout << "POPULATION #" << _id << "\n";

		for (int i = 0; i < candidate_count;i++)
		{
			cout << "candidate " << i << ": " << candidates[i]->get_mark() << endl;
		}
		cout << "==============================\n";
	}

	const TCandidate* TPopulation::get_candidate_wsk(int id) const {
		return candidates[id];
	}

	TPopulation* TPopulation::rulette(TPopulation* orginal) {
		std::vector<int> slots;
		int prev_id = 0;
		int pres_id = 0;
		for (int i = 0; i < this->candidates.size(); i++) {
			pres_id = candidates[i]->get_mark();
			for (int j = 0; j < candidates[i]->get_mark(); j++) {
				slots[j + prev_id] = i;
			}
			prev_id = pres_id;
		}

	}