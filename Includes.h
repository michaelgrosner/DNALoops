/*
 * Includes.h
 *
 *  Created on: Jul 17, 2011
 *      Author: Michael Grosner
 */

#ifndef INCLUDES_H_
#define INCLUDES_H_

// Providing many simulation tools
#include <DNASim.h>

// Database connection and interface
#include <sqlite3.h>
#include "Database/SQLiteDB.h"

// STL stuff probably declared in DNASim anyways.
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <unistd.h>
#include <assert.h>
#include <glob.h>
#include <sstream>

// C stuff. Just because I need them.
#include "stdlib.h"
#include "stdio.h"
using namespace std;

// BOOST_FOREACH in all caps is ugly.
#define foreach          BOOST_FOREACH
#define DEBUG			 true
#define X3DNA_TEMP_PATH  "x3dna_temp/"

#endif /* INCLUDES_H_ */
