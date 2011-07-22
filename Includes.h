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
#include <sstream>
#include <omp.h>
#include <algorithm>

// C stuff. Just because I need them.
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// These boost headers are used everywhere in this project.
#include "boost/foreach.hpp"
#include "boost/filesystem.hpp"

// Really shouldn't put this here...
using namespace std;

#include "Defines.h"
#include "Forwards.h"
#endif /* INCLUDES_H_ */
