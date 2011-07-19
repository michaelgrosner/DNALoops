/*
 * BasePair.cpp
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

#include "BasePair.h"

BasePairEntity::BasePairEntity() {
	// TODO Auto-generated constructor stub

}

BasePairEntity::~BasePairEntity() {
	// TODO Auto-generated destructor stub
}

BasePairEntity::BasePairEntity(const vector<int>& pairing, const int& position,
		const CoordinateSystem& coords, Loop& l) :
	BasePair(coords), strand_position(position) {

	foreach(int bp_id, pairing)
				{
					vector<Entity*> loop_residues;
					l.get_sub_entities("Residue", loop_residues);
					add_child(loop_residues[bp_id]);
				}

	assert (get_child_vector().size() == 2);

}

ostream& operator<<(ostream &out, const BasePairEntity &bp) {
	string r1 = bp.get_child_vector()[0]->get_name();
	string r2 = bp.get_child_vector()[1]->get_name();

	out << "<BasePair " << r1 << "-" ;
	out << r2 << " in position " << bp.strand_position << ">";
	return out;
}
