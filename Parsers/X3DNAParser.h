/*
 * X3DNAParser.h
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

#ifndef X3DNAPARSER_H_
#define X3DNAPARSER_H_

#include "Includes.h"
#include "BioModels/Entity.h"
#include "BioModels/Loop.h"

class X3DNAParser {
public:
	X3DNAParser(Loop &l);
	virtual ~X3DNAParser();
private:
	Loop m_loop;
};

#endif /* X3DNAPARSER_H_ */
