// This file contains utility class definitions

#include <iostream>
#include <fstream>

#include "common.h"

using std::fstream;

class FileUtility
{
public:
	// Constructor
	FileUtility();
	// Destructor
	~FileUtility();

	// open a file
    	uint32 open_file();

	// get file size
    	uint32 get_fileSize(uint32* pfileSize);

    	// read file address
	uint32 read_fileAddr(fstream** pfile);

private:
	
	// Private data members
	const char* filename;

	fstream tsfile;
	
	uint32 file_size;
};

