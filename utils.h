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
	
	// read TS packets
    	uint32 read_TSPacket();

	// get file size
    	uint32 get_fileSize(uint32* pfileSize);
    
    	// TODO - What is the function of this function
	// uint32 read_TSPacketAddr(uint8** pTSPacket);
    	uint32 read_TSFileAddr(uint8** pTSPacket);

	uint32 read_fileAddr(fstream** pfile);

private:
	
	// read file size
	uint32 get_file_size();
	
	// Private data members
	const char* filename;

	fstream tsfile;
	
	uint32 file_size;

	uint8* data;
};

