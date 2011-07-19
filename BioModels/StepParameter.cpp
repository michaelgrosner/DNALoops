/*
 * StepParameter.cpp
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

#include "StepParameter.h"

StepParameterEntity::StepParameterEntity(const string& sp, Loop &l, const int& p) : StepParameters(sp), strand_position(p) {
	l.add_child(this);
}

StepParameterEntity::~StepParameterEntity() {
	// TODO Auto-generated destructor stub
}
