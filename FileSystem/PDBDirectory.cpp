/*
 * PDBDirectory.cpp
 *
 *  Created on: Jul 21, 2011
 *      Author: grosner
 */

#include "PDBDirectory.h"

PDBDirectory::PDBDirectory(string string_dir) {
	dir = path(string_dir);
}

PDBDirectory::~PDBDirectory() {
	// TODO Auto-generated destructor stub
}

vector<path> PDBDirectory::files_in(const string &model_name, const string& of_type) {
	path p = path(model_name);

	directory_iterator end_itr;

	vector<path> files;

	// TODO: Raise an exception
	//if (exists(p)) return false;

	for (directory_iterator itr(p); itr != end_itr; itr++) {

		if (itr->path().extension() != of_type && of_type != ALL_EXTENSIONS) continue;

		if (is_regular_file(itr->path())) {
			files.push_back(itr->path());
		}
	}
	return files;
}

vector<path> PDBDirectory::folders_in() {

	directory_iterator end_itr;

	vector<path> folders;

	// TODO: Raise an exception
	//if (!exists(p)) return false;

	for (directory_iterator itr(dir); itr != end_itr; itr++) {
		// If this is a directory,
		if (is_directory(itr->path())) {
			folders.push_back(itr->path());
		}
	}
	return folders;
}
