/*
 * PDBParser.h
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

#ifndef PDBPARSER_H_
#define PDBPARSER_H_

#include "Includes.h"

#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/tokenizer.hpp>
#include <boost/foreach.hpp>
#include <fstream>
#include <sstream>
#include "BioModels/Atom.h"
#include "BioModels/Residue.h"
#include "BioModels/Chain.h"
#include "BioModels/Structure.h"

class PDBParser {
public:
	PDBParser(string filename);
	virtual ~PDBParser();

	void parse();

private:
	string pdb_filename;
};

#endif /* PDBPARSER_H_ */
