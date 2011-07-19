/*
 * X3DNAParser.h
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

#ifndef X3DNAPARSER_H_
#define X3DNAPARSER_H_

#include "Includes.h"

#include <fstream>
#include <sstream>

#include "BioModels/Entity.h"
#include "BioModels/Loop.h"
#include "BioModels/BasePair.h"
#include "BioModels/StepParameter.h"

#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

class X3DNAParser {
public:
	X3DNAParser(Loop &l);
	virtual ~X3DNAParser();

	vector<vector<int> > read_inp_file();
	void get_ref_frames();

private:
	Loop m_loop;
};

#endif /* X3DNAPARSER_H_ */
