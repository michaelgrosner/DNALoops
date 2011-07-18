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
#include "PDBParser.h"
#include "BioModels/Loop.h"
using namespace boost::filesystem;

class PDBLoopParser {
public:
	PDBLoopParser(string model_directory);
	virtual ~PDBLoopParser();

	void parse();

private:

	void parse_single(string filename);

	string         m_directory;
	vector<string> m_filepaths;
	//Loop           m_loop;

};

#endif /* PDBLOOPPARSER_H_ */
