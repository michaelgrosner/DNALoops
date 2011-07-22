/*
 * IdealStructureBuilder.h
 *
 *  Created on: Jul 20, 2011
 *      Author: grosner
 */

#ifndef IDEALSTRUCTUREBUILDER_H_
#define IDEALSTRUCTUREBUILDER_H_

#include "Includes.h"
#include "BioModels/Structure.h"
#include "BioModels/StepParameter.h"

class IdealStructureBuilder {
public:

	/* On construction, the required file string argument gets made into a boost
	 * path object. This is to fix things like the inability to use the ~
	 * shortcut and make things more flexible. Or just pass a boost path obj */
	IdealStructureBuilder(const string& file);
	IdealStructureBuilder(const path& path);
	virtual ~IdealStructureBuilder();

	/* Parse the Ideal Step Parameters file and load it all into an ideal
	 * Structure object */
	Structure* parse();

	vector<Structure*> parse_directory();
private:
	path p;
};

#endif /* IDEALSTRUCTUREBUILDER_H_ */
