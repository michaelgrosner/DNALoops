/*
 * Entity.cpp
 *
 *  Created on: Jul 17, 2011
 *      Author: Michael Grosner
 */

#include "Entity.h"

// Construction and destruction
Entity::Entity() {
	pk = 0;
	m_name = "NO NAME";
	is_bottom = false;
	is_top = false;
}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

// Setters
void Entity::add_child(Entity *child) {
	m_children.push_back(child);
	child->set_parent(this);
}


void Entity::set_parent(Entity *parent) {
	m_parent = parent;

	//TODO: Fix this!!!!
	//parent->add_child(this);
}
;

void Entity::set_name(string name) {
	m_name = name;
}

void Entity::set_name(path name) {
	m_name = name.stem();
}

// Getters
vector<Entity*> Entity::get_child_vector() const {
	return m_children;
}

Entity* Entity::get_parent() {
	return m_parent;
}

string Entity::get_name() const {
	return m_name;
}

// Model-Specific getters


//vector<Atom*> Entity::get_CAs() {
//	vector<Atom*> atoms;
//	vector<Atom*> CAs;
//
//	get_all<Atom*>(atoms);
//
//	foreach(Atom* a, atoms) {
//		if (a->is_CA()) {
//			CAs.push_back(a);
//		}
//	}
//
//	return CAs;
//}

// Statistics
int Entity::n_children() const {
	return m_children.size();
}

//int Entity::n_atoms() {
//	vector<Atom*> entities;
//	get_all<Atom*>(entities);
//	return entities.size();
//}

/*Entity operator[](int i) {
	return get_child_vector()[i];
}*/

//bool Entity::commit(SQLiteDB &db) {}

// TODO: Make use of the Boost filesystem for this
void Entity::write_pdb(string filelocation) {

	// Not sure why, but ofstream requires a c_str here...
	ofstream pdbfile(filelocation.c_str(), ofstream::out);

	int atom_count = 1;
	int chain_count = 1;
	int residue_count = 1;

	as_pdb(chain_count, residue_count, atom_count, pdbfile);

	pdbfile.close();
}

void Entity::run_x3dna() {
	string pdbfilename = "all.pdb";
	path   x3dna_temp  = path(X3DNA_TEMP_PATH);

	if (is_directory(x3dna_temp)) {
		if (DEBUG) cout << x3dna_temp << " directory exists" << endl;
	}
	else {
		create_directory(x3dna_temp);
	}

	write_pdb(x3dna_temp.string() + "/" +pdbfilename);

	// TODO: Test these.
	// TODO: Ensure misc_3dna.par is in the cwd
	// TODO: Copy misc_3dna.par to x3dna_temp
	if (exists(x3dna_temp/path("misc_3dna.par"))) {
		if (DEBUG) cout << "misc_3nda.par found" << endl;
	}
	else {
		/*char *cmd = (boost::format("cp misc_3dna.par %s") % x3dna_temp).str().c_str();
		system(cmd);*/
	}

	// TODO: Check that 3dna programs are on the $PATH

	if (DEBUG) cout << (boost::format("cd %s") % x3dna_temp).str().c_str() << endl;

	// TODO: ret is the chdir status code, -1 meaning an error. Handle later.
	int ret = chdir(x3dna_temp.string().c_str());
	if (DEBUG) cout << (boost::format("find_pair %s %s%s") % pdbfilename % pdbfilename % ".inp").str().c_str() << endl;
	system((boost::format("find_pair %s %s%s") % pdbfilename % pdbfilename % ".inp").str().c_str());
	if (DEBUG) cout << (boost::format("analyze %s%s") % pdbfilename % ".inp").str().c_str() << endl;
	system((boost::format("analyze %s%s") % pdbfilename % ".inp").str().c_str());

	chdir("..");

}

// Output methods
// Use the subclass to handle output
ostream& operator<<(ostream &out, const Entity &e) {
	out << e.class_name() << " " << e.get_name();
	return out;
}
