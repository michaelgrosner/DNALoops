/*
 * PDBLoopParser.h
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

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
	virtual ~PDBLoopParser();

	Loop parse();


private:

	void parse_single_pdb_file(string pdb_filename);

	string         m_directory;
	vector<string> m_filepaths;
	Loop		   m_loop;

};

#endif /* PDBLOOPPARSER_H_ */
