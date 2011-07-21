/*
 * StepParameter.cpp
 *
 *  Created on: Jul 16, 2011
 *      Author: Michael Grosner
 */

#include "StepParameter.h"

StepParameterEntity::StepParameterEntity(const VectorReal& v, Entity &parent,
		BasePairEntity* bp1, BasePairEntity* bp2, const int&p) :
	StepParameters(v), strand_position(p) {
	parent.add_child(this);

	add_child(bp1);
	add_child(bp2);
	set_name(bp1->get_name() + ":" + bp2->get_name());
}

StepParameterEntity::StepParameterEntity(const VectorReal& v, Entity &parent,
		const int&p) :
	StepParameters(v), strand_position(p) {
	parent.add_child(this);
}

StepParameterEntity::~StepParameterEntity() {
	// TODO Auto-generated destructor stub
}

ostream& operator<<(ostream &out, const StepParameterEntity &sp) {
	out << "<StepParameter at " << sp.strand_position << " comprised of ";
	if (!sp.get_child_vector().empty()) {
		out << *(sp.get_child_vector()[0]) << ", ";
		out << *(sp.get_child_vector()[1]) << ">";
	}
	else {
		out << sp.get_name() << ">";
	}
	return out;
}

int StepParameterEntity::position () {
	return strand_position;
}

VectorReal StepParameterEntity::reversed() {
	VectorReal v = get_as_vector();
	v[SHIFT] = -v[SHIFT];
	v[TILT]  = -v[TILT];
	return v;
}
