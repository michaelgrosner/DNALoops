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

ostream& operator<<(ostream &out, Loop &l) {
	out << "<Loop " << l.get_name();
	out << " with " << l.n_of<Structure*>() << " structures, ";
	out << l.n_of<Atom*>() << " atoms and ";
	out << l.n_of<StepParameterEntity*>() << " StepParameters>";
	return out;
}

void Loop::find_ideal_sites(vector<Structure*> ideal_structures) {
	vector<StepParameterEntity> ideal_sps;
	Structure *ideal_s;

	int s_i;

	// TODO: Fix OpenMP and ensure safety
//#pragma omp parallel private(s,s_i,ideal_length,i,j,i_sp,l_sp,score,two_sp_score) shared(ideal_structures)
//#pragma omp for schedule(dynamic) nowait
	for (s_i = 0; s_i < ideal_structures.size(); s_i++) {
		ideal_s = ideal_structures[s_i];

		// Forwards
		find_ideal_sites__driver(ideal_s, false);

		// Backwards
		find_ideal_sites__driver(ideal_s, true);

	}
}

void Loop::find_ideal_sites__driver(Structure *ideal_s, bool flip_ideal) {
	StepParameterEntity* i_sp;
	StepParameterEntity* l_sp;
	vector<StepParameterEntity*> l_v = get_all<StepParameterEntity*>();

	vector<StepParameterEntity*> i_v;
	if (flip_ideal) {
		i_v = ideal_s->get_all<StepParameterEntity*>();
	}
	else {
		i_v = ideal_s->get_all_reversed<StepParameterEntity*>();
	}

	int ideal_length = i_v.size();
	double two_sp_score;
	double score = 0;

	for (int i = 0; i < l_v.size() - ideal_length; i++) {
		score = 0;
		for (int j = i; j < i + ideal_length; j++) {
			i_sp = i_v[j - i];
			l_sp = l_v[j];
			if (flip_ideal) {
				two_sp_score = (i_sp->get_as_vector() - l_sp->get_as_vector()).norm();
			}
			else {
				two_sp_score = (i_sp->get_as_vector() - l_sp->get_as_vector()).norm();
			}
			score += two_sp_score;
			//cout << i_sp->position() << " " << l_sp->position() << " " << score << endl;
		}
		if (score < 4) {
			Structure *best_s = nearest_real_structure_to_ideal_structure(i, i+ideal_length, ideal_s);
			best_s->set_ideal_structure(ideal_s);
			cout << ideal_s->get_name() << "-->" << i << "-" << i+ideal_length << " ";
			cout << score << " " << flip_ideal << " == " << *best_s  << endl;
		}

	}
}

vector<Structure*> Loop::ideal_structures() {
	vector<Structure*> ideals;
	foreach(Structure *l_s, get_all<Structure*>()) {
		if (!l_s->is_ideal()) continue;
		ideals.push_back(l_s);
	}
	return ideals;
}

vector<Structure*> Loop::real_structures() {
	vector<Structure*> reals;
	foreach(Structure *l_s, get_all<Structure*>()) {
		if (l_s->is_ideal()) continue;
		reals.push_back(l_s);
	}
	return reals;
}

Structure* Loop::nearest_real_structure_to_ideal_structure(int start,
		int end, const Structure* ideal_s) {
	vector<StepParameterEntity*> loop_sps = get_all<StepParameterEntity*>();

	double min_score = 1e30;
	Structure *best;

	foreach(Structure *real_s, real_structures()) {

		Vector3D<double> real_s_center = real_s->center_of_mass();
		Vector3D<double> score_3d;
		double score = 0;

		// TODO: This scoring algorithm might need some deeper thought.
		for (int i=start; i < end; i++) {
			score_3d += loop_sps[i]->position_3d() - real_s_center;
		}
		score_3d /= fabs(end-start);
		score = score_3d.norm();

		// score != score is a test for nan, when the Structure has only DNA
		if (score < min_score && score == score) {
			min_score = score;
			best = real_s;
		}

	}

	return best;

}

bool Loop::commit(SQLiteDB &db) {
	//db->create_table(get_name(), "name VARCHAR(100), ");
	return false;
}

vector<Structure*> Loop::hus() {
	foreach(Structure *s, real_structures()) {
		if
	}
}
