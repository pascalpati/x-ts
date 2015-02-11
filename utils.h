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

        // Public member functions

	// open a file
        uint32 open_file();
	
	// read TS packets
	uint32 read_TSPacket();

	uint32 get_fileSize(uint32* pfileSize);
	uint32 read_TSPacketAddr(uint8** pTSPacket);

private:
	// Private member functions
	
	// read file size
	uint32 get_file_size();
	
	// Private data members
	const char* filename;

	fstream tsfile;
	
	uint32 file_size;

	uint8* data;
};

