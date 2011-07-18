/*
 * PDBLoopParser.cpp
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

#include "PDBLoopParser.h"

PDBLoopParser::PDBLoopParser(string model_directory) : m_directory(model_directory) {
	// TODO Auto-generated constructor stub

}

PDBLoopParser::~PDBLoopParser() {
	// TODO Auto-generated destructor stub
}

void PDBLoopParser::parse() {

	// TODO: Check for slash between directory and *.pdb
	string glob_query = m_directory + "*.pdb";

	glob_t globbuf;
	globbuf.gl_offs = 2;
	glob(glob_query.c_str(), 0, NULL, &globbuf);

	// If you ever need to append more paths later down the line, uncommment this line
	//glob("../*.cpp", GLOB_DOOFFS | GLOB_APPEND, NULL, &globbuf);

	for (unsigned int i = 0; i < globbuf.gl_pathc; i++) {
		m_filepaths.push_back(globbuf.gl_pathv[i]);
		parse_single(globbuf.gl_pathv[i]);
	}

}

void PDBLoopParser::parse_single(string filename) {
	PDBParser* p = new PDBParser(filename);

	p->parse();
}
