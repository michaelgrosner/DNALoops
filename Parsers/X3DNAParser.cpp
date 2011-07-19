/*
 * X3DNAParser.cpp
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

#include "X3DNAParser.h"

X3DNAParser::X3DNAParser(Loop &l) {
	m_loop = l;
}

X3DNAParser::~X3DNAParser() {
	// TODO Auto-generated destructor stub
}

vector<vector<int> > X3DNAParser::read_inp_file() {
	path     x3dna_temp = path(X3DNA_TEMP_PATH);
	path     ref_frames = x3dna_temp / path("all.pdb.inp");
	ifstream ifs;
	string   line;
	ifs.open(ref_frames.string().c_str());

	vector<vector<int> > all_pairings;

	int line_count = 0;
	while( getline(ifs, line) ) {
		line_count += 1;

		// Get rid of stats at the top and commented lines starting with #
		if (line_count < 5 || line.compare(0, 1, string("#")) == 0) continue;

		vector<string> strs;
		boost::split(strs, line, boost::is_any_of(" "));
		vector<int> pairing;

		foreach(string st, strs) {
			if (boost::trim_copy(st).empty() || st == "#") continue;
			int p = atoi(st.c_str());

			// He uses counting from 1 instead of 0, thus the minus sign.
			pairing.push_back(p-1);
			if (pairing.size() == 2) break;
		}
		all_pairings.push_back(pairing);
	}

	return all_pairings;
}

void X3DNAParser::get_ref_frames() {

	/* This function is a total mess. Not because my coding sucks (it does), but
	 * because the output from X3DNA is in a very parser-friendly output scheme.
	 *
	 * A sample is below:
	 * ...     1 T-A ...
  -13.5919    19.7778   -33.4245  # origin
   -0.1508    -0.6103    -0.7777  # x-axis
    0.6875     0.5005    -0.5261  # y-axis
    0.7103    -0.6140     0.3441  # z-axis
	 */

	path     x3dna_temp = path(X3DNA_TEMP_PATH);
	path     ref_frames = x3dna_temp / path("ref_frames.dat");
	ifstream ifs;
	string   line;
	ifs.open(ref_frames.string().c_str());

	BasePairEntity *bp;

	vector<vector<int> > parings = read_inp_file();

	int file_line_number = 0;
	int bp_line_number   = 0;
	int bp_number;
	string base1;
	string base2;
	while( getline(ifs, line) ) {
		vector<string> strs;
		boost::split(strs, line, boost::is_any_of(" "));

		double bp_o[3];
		double bp_x[3];
		double bp_y[3];
		double bp_z[3];

		int rec_number = 0;
		foreach(string st, strs) {

			int bp_line_number = (file_line_number-1) % 5;

			if (boost::trim_copy(st).empty() || st == "#") continue;

			// If the BP number comes up
			else if (bp_line_number == 0 && rec_number == 1) {
				bp_number = atoi(st.c_str());
			}
			// Read in the two residues string names
			else if (bp_line_number == 0 && rec_number == 2) {
				// These are the ACGT string representation of the atom. Save?
				//base1 = st.substr(0,1);
				//base2 = st.substr(2,1);
			}
			// Read the origins
			else if (bp_line_number == 1) {
				bp_o[rec_number]=  atof(st.c_str());
			}
			// Read the x coords
			else if (bp_line_number == 2) {
				bp_x[rec_number]=  atof(st.c_str());
			}
			// Read y coords
			else if (bp_line_number == 3) {
				bp_y[rec_number]=  atof(st.c_str());
			}
			// And z
			else if (bp_line_number == 4) {
				bp_z[rec_number]=  atof(st.c_str());
			}

			// Now load this data into the BasePairEntity
			if (bp_line_number == 4 && rec_number == 3) {
				CoordinateSystem coords(Vector3D<double>(bp_o[0],bp_o[1],bp_o[2]),
										Vector3D<double>(bp_x[0],bp_x[1],bp_x[2]),
										Vector3D<double>(bp_y[0],bp_y[1],bp_y[2]),
										Vector3D<double>(bp_z[0],bp_z[1],bp_z[2]));

				bp = new BasePairEntity(parings[bp_number], bp_number, coords, m_loop);
				cout << *bp << endl;
			}

			rec_number += 1;
		}
		file_line_number += 1;

	}
}

void X3DNAParser::get_bp_steps() {
	path     x3dna_temp = path(X3DNA_TEMP_PATH);
	path     bp_step = x3dna_temp / path("bp_step.par");
	ifstream ifs;
	string   line;

	ifs.open(bp_step.string().c_str());

	StepParameterEntity *sp;

	int line_count = 0;
	while( getline(ifs, line) ) {
		line_count += 1;
		if (line_count < 5) continue;

		// TODO: Test SPs are in correct order!!!!
		// Due to somewhat incompatible nature of my program and DNASim constructors
		// (as shown in the previous function), to construct the 6-dimensional
		// StepParameters vector, create a vector<string>, then join python-
		// style to get a suitable constructor
		vector<string> sp_vec;

		// Shift
		sp_vec.push_back( line.substr(52,8).c_str() );

		// Slide
		sp_vec.push_back( line.substr(60,8).c_str() );

		// Rise
		sp_vec.push_back( line.substr(68,8).c_str() );

		// Tilt
		sp_vec.push_back( line.substr(76,8).c_str() );

		// Roll
		sp_vec.push_back( line.substr(84,8).c_str() );

		// Twist
		sp_vec.push_back( line.substr(92,8).c_str() );

		string vec_string = "{" + boost::algorithm::join(sp_vec, ",") + "}";

		sp = new StepParameterEntity(vec_string, m_loop, line_count-5);

	}

}
