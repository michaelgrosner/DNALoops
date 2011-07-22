/*
 * IdealStructureBuilder.cpp
 *
 *  Created on: Jul 20, 2011
 *      Author: grosner
 */

#include "IdealStructureBuilder.h"

IdealStructureBuilder::IdealStructureBuilder(const string& file) : p(file) {}
IdealStructureBuilder::IdealStructureBuilder(const path& path) : p(path) {}

IdealStructureBuilder::~IdealStructureBuilder() {
	// TODO Auto-generated destructor stub
}

Structure* IdealStructureBuilder::parse() {
	ifstream ifs;
	string   line;

	const char* ifpath = p.string().c_str();
	ifs.open(ifpath);

	StepParameterEntity *sp;
	Structure *s = new Structure();
	VectorReal v;
	s->set_name(p);

	int sp_count = 0;
	// VIM: :.,+4s/\n^/,/g   --> 6 lines into one
	while( getline(ifs, line) ) {
		// line must be in format `AC:TG{sp1, sp2, ... ,sp6}`
		v = VectorReal(line.substr(5));
		sp = new StepParameterEntity(v, *s, sp_count);
		sp->set_name(line.substr(0,5));

		sp_count += 1;
	}

	// Recast to make a Structure object
	//Structure *s = static_cast<Structure*>(structure_e);

	// Make sure to mark this structure as Ideal
	s->set_ideal();
	return s;

}
