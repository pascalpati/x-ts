// This is the main of the x-ts implementation.

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <iomanip>

#include "utils.h"
#include "parser.h"
#include "common.h"

using namespace std;

// main function
int main()
{
	uint32 fileSize = 0;
	
	fstream* pFile = NULL;

	// create a file utility object to perform file operations
	FileUtility fileUtility_object;
	
	// open the file
    	if (SUCCESS != fileUtility_object.open_file())
    	{
        	// Unable to proceed as can't open the .ts file.
        	cout << "ERR: Unable to open file!" << endl;
        	return -1;
    	}
    
    	// get file size
    	fileUtility_object.get_fileSize(&fileSize);

    	cout << "File size = " << fileSize << " bytes" << endl;
    	//cout << "File size = " << ((fileSize/1024)/1024) << " MBytes" << endl;

    	fileUtility_object.read_fileAddr(&pFile);
    	cout << "File pointer = " << *pFile << endl;

#if 0
	(*pFile).read((uint8 *)test_data, TS_PACKET_SIZE);

	cout << hex;

    	for (uint16 i = 0; i < TS_PACKET_SIZE; i++)
    	{
        	cout << showbase << left << setw(8) <<(uint16)test_data[i] << setw(8);
        	if (!(i%8))
        	{
            		cout << endl;
        	}
    	}
	cout << dec << endl;
#endif

	// create the parser object
	Parser parser_object;

	// pass file addr to parser object
    	parser_object.set_fileAddr(pFile);
    
    	// parse ts packet
    	parser_object.parse_tsPacket();
	
	return 0;
}

