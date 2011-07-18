/*
 * PDBLoopParser.h
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

#ifndef PDBLOOPPARSER_H_
#define PDBLOOPPARSER_H_

#include "Includes.h"

#include <glob.h>
#include "boost/filesystem.hpp"   // includes all needed Boost.Filesystem declarations
#include "boost/foreach.hpp"
#include "PDBParser.h"
#include "BioModels/Loop.h"
#include "BioModels/Structure.h"
using namespace boost::filesystem;

class PDBLoopParser {
public:
	PDBLoopParser(string model_directory);
	virtual ~PDBLoopParser();

	Loop parse();

private:

	vector<Structure> parse_single(string filename);

	string         m_directory;
	vector<string> m_filepaths;

};

#endif /* PDBLOOPPARSER_H_ */
