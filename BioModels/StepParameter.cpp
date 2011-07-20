/*
 * StepParameter.cpp
 *
 *  Created on: Jul 16, 2011
 *      Author: Michael Grosner
 */

#include "StepParameter.h"

StepParameterEntity::StepParameterEntity(const string& sp, Entity &parent,
		BasePairEntity* bp1, BasePairEntity* bp2, const int&p) :
	StepParameters(sp), strand_position(p) {
	parent.add_child(this);

	add_child(bp1);
	add_child(bp2);
}

StepParameterEntity::~StepParameterEntity() {
	// TODO Auto-generated destructor stub
}



ostream& operator<<(ostream &out, const StepParameterEntity &sp) {
	out << "<StepParameter with comprised of ";
	out << *(sp.get_child_vector()[0]) << ", ";
	out << *(sp.get_child_vector()[1]) << ">";
	return out;
}
