/*
 * BasePair.cpp
 *
 *  Created on: Jul 16, 2011
 *      Author: Michael Grosner Grosner
 */

#include "BasePair.h"

BasePairEntity::BasePairEntity() {
	// TODO Auto-generated constructor stub

}

BasePairEntity::~BasePairEntity() {
	// TODO Auto-generated destructor stub
}

BasePairEntity::BasePairEntity(const vector<int>& pairing, const int& position,
		const CoordinateSystem& coords, Entity& e) : BasePair(coords) {

	vector<Entity*> residues;
	e.get_sub_entities("Residue", residues);

	foreach(int bp_id, pairing) {
		add_child(residues[bp_id]);
	}
	assert (get_child_vector().size() == 2);

	strand_position = position;
	set_name(residues[pairing[0]]->get_name()+residues[pairing[1]]->get_name());

}

ostream& operator<<(ostream &out, const BasePairEntity &bp) {
	string r1 = bp.get_child_vector()[0]->get_name();
	string r2 = bp.get_child_vector()[1]->get_name();

	out << "<BasePair " << r1 << "-" ;
	out << r2 << " in position " << bp.strand_position << ">";
	return out;
}
