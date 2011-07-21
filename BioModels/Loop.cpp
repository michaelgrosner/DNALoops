/*
 * Loop.cpp
 *
 *  Created on: Jul 15, 2011
 *      Author: Michael Grosner*/

#include "Loop.h"

Loop::Loop() {
	is_top = true;
}

Loop::Loop(string name) {
	set_name(name);
	is_top = true;
}

Loop::~Loop() {
	// TODO Auto-generated destructor stub
}

void Loop::as_pdb(int &chain_count, int &residue_count, int &atom_count,
		ofstream &pdbfile) {
	foreach(Entity *le, get_child_vector())
				{
					le->as_pdb(chain_count, residue_count, atom_count, pdbfile);
					pdbfile << "TER\n";
				}
}

ostream& operator<<(ostream &out, const Loop &l) {
	out << "<Loop " << l.get_name() << " with " << l.n_children()
			<< " structures>";
	return out;
}

void Loop::list_ideal_sites(vector<Structure*> ideal_structures) {
	vector<StepParameterEntity> ideal_sps;
	Structure *s;

	int s_i;

	// TODO: Fix OpenMP and ensure safety
#pragma omp parallel private(s,s_i,ideal_length,i,j,i_sp,l_sp,score,two_sp_score) shared(ideal_structures)
#pragma omp for schedule(dynamic) nowait
	for (s_i = 0; s_i < ideal_structures.size(); s_i++) {
		s = ideal_structures[s_i];

		// Forwards
		list_ideal_sites__align(s, s->get_all<StepParameterEntity*> (),
				get_all<StepParameterEntity*> ());

		// Backwards
		list_ideal_sites__align(s,
				s->get_all_reversed<StepParameterEntity*> (),
				get_all_reversed<StepParameterEntity*> (), true);

	}
}

void Loop::list_ideal_sites__align(Structure *s,
		vector<StepParameterEntity*> i_v, vector<StepParameterEntity*> l_v, bool reversed=false) {

	StepParameterEntity* i_sp;
	StepParameterEntity* l_sp;
	int ideal_length = i_v.size();
	double two_sp_score;
	double score = 0;

	for (int i = 0; i < l_v.size() - ideal_length; i++) {
		score = 0;
		for (int j = i; j < i + ideal_length; j++) {
			i_sp = i_v[j - i];
			l_sp = l_v[j];
			if (reversed) {
				two_sp_score = (i_sp->get_as_vector() - l_sp->get_as_vector()).norm();
			}
			else {
				two_sp_score = (i_sp->reversed() - l_sp->reversed()).norm();
			}
			score += two_sp_score;
			cout << i_sp->position() << " " << l_sp->position() << " " << score << endl;
		}
		if (score < 100)
			cout << s->get_name() << "-->" << i << " " << score << " " << reversed << endl;
	}
}
