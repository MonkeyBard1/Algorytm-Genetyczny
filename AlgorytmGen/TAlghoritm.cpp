#include "TAlghoritm.h"

TAlghoritm::TAlghoritm(unsigned int candidates_count,
	unsigned int max_population_count,
	unsigned int min_improvment_proc)
{
	stop_max_population_count = max_population_count;
	stop_min_improvement_proc = min_improvment_proc;
	wsk_population_pres = new TPopulation(candidates_count);
}
TAlghoritm::~TAlghoritm()
{
	delete wsk_population_pres;
	wsk_population_pres = nullptr;
	delete wsk_population_prev;
	wsk_population_prev = nullptr;

	std::cout << "Usunieto obiekt klasy TAlghoritm\n";
}

void TAlghoritm::run() {
	bool stop = false;

	while (!wsk_population_prev || !stop)
	{
		wsk_population_pres->calculate();

		std::cout << "== Population #" << wsk_population_pres->get_id();
		std::cout << " || best val: " << wsk_population_pres->get_best_val() << " ==\n";

		stop = is_stop();
		if (!stop) {
			unsigned int candidate_count = wsk_population_pres->get_candidate_count();

			delete wsk_population_prev;
			wsk_population_prev = wsk_population_pres;
			wsk_population_pres = new TPopulation{ candidate_count };
		}

		if (wsk_population_pres->get_id() == 25) return;
	}
}

bool TAlghoritm::is_max_population() {
	unsigned int _id_pres = wsk_population_pres->get_id();
	return(_id_pres == stop_max_population_count);
}

bool TAlghoritm::is_min_improvement() {
	TPopulation population_pres = (*wsk_population_pres);
	TPopulation population_prev = (*wsk_population_prev);

	double best_val_pres = population_pres.get_best_val();
	double best_val_prev = population_prev.get_best_val();

	int improvment = fabs(best_val_prev - best_val_pres) / best_val_prev * 100;
	return(improvment <= stop_min_improvement_proc);
}

bool TAlghoritm::is_stop() {
	bool stop = false;
	if (!wsk_population_prev) {
		stop = is_max_population();
	}
	else
	{
		bool stop1 = is_max_population();
		bool stop2 = is_min_improvement();
		stop = stop1 || stop2;
	}
	return stop;
}