/*
 * PDBDirectory.h
 *
 *  Created on: Jul 21, 2011
 *      Author: grosner
 */

#ifndef PDBDIRECTORY_H_
#define PDBDIRECTORY_H_

#define ALL_EXTENSIONS "ALL_EXTENSIONS"

#include "Includes.h"
using namespace boost::filesystem;

class PDBDirectory {
public:
	PDBDirectory(string string_dir="PDBs");
	//PDBDirectory(path   path_dir);
	virtual ~PDBDirectory();

	vector<path> files_in(const string &model_name, const string& of_type=ALL_EXTENSIONS);
	vector<path> folders_in();

private:
	path dir;
};

#endif /* PDBDIRECTORY_H_ */
