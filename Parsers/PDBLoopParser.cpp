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

Loop PDBLoopParser::parse() {

	// TODO: Check for slash between directory and *.pdb
	string glob_query = m_directory + "*.pdb";

	Loop l;
	l.set_name(m_directory);

	glob_t globbuf;
	globbuf.gl_offs = 2;
	glob(glob_query.c_str(), 0, NULL, &globbuf);

	// If you ever need to append more paths later down the line, uncommment this line
	//glob("../*.cpp", GLOB_DOOFFS | GLOB_APPEND, NULL, &globbuf);

	for (unsigned int i = 0; i < globbuf.gl_pathc; i++) {
		m_filepaths.push_back(globbuf.gl_pathv[i]);
		vector<Structure> structures = parse_single(globbuf.gl_pathv[i]);

		vector<Structure>::iterator it;
		for (it=structures.begin(); it < structures.end(); it++) {
			l.add_child(*it);
		}
	}

	if (DEBUG) {
		foreach (Entity *s, l.get_child_vector()) {
			cout << "Structure: " << s << endl;
		}
	}

	return l;

}

vector<Structure> PDBLoopParser::parse_single(string filename) {
	PDBParser* p = new PDBParser(filename);

	return p->parse_pdb_file();

}
