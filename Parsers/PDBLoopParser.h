/*
 * PDBLoopParser.h
 *
 *  Created on: Jul 16, 2011
 *      Author: Michael Grosner */
#ifndef PDBLOOPPARSER_H_
#define PDBLOOPPARSER_H_

#include "Includes.h"

#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/trim.hpp>
#include "boost/foreach.hpp"

#include "BioModels/Entity.h"
#include "BioModels/Atom.h"
#include "BioModels/Residue.h"
#include "BioModels/Chain.h"
#include "BioModels/Structure.h"
#include "BioModels/Loop.h"

class PDBLoopParser {
public:
	PDBLoopParser(string model_directory);
	PDBLoopParser(char*  model_directory);
	PDBLoopParser(path   model_directory);
	virtual ~PDBLoopParser();

	/* To make sense of this class, for one Loop all PDB files belonging to
	 * this Loop must be in a directory pointed to by model_directory. By using
	 * the glob function, all *.pdb files in the model_directory will be loaded
	 * into memory (then saved to the database) as Atom/Residue/Chain/Structure
	 * objects. As the classname suggests, the Loop containing these objects
	 * as a vector containing pointers to the child objects.
	 * parse() will do that in one, convienient function.
	 */
	Loop parse();


private:

	// Handle a single PDB file.
	void parse_single_pdb_file(string pdb_filename);

	path           m_directory;
	vector<path>   m_filepaths;
	Loop		   m_loop;

};

#endif /* PDBLOOPPARSER_H_ */
