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
	
	uint8* ptsPacketAddr = NULL;;

	fstream* pFile = NULL;
	//uint8* test_data = new uint8 [TS_PACKET_SIZE];

	// create a file utility object to perform file operations
	FileUtility fileUtility_object;
	
    // open the file
    if (SUCCESS != fileUtility_object.open_file())
    {
        // Unable to proceed as can't open the .ts file.
        return 0;
    }
    
	// get file size
	fileUtility_object.get_fileSize(&fileSize);	

	cout << "File size = " << fileSize << " bytes" << endl;	

    	//fileUtility_object.read_TSPacket();
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

 
	fileUtility_object.read_TSFileAddr(&ptsPacketAddr);
	cout << "main() *ptsPacketAddr = " << hex << (uint16)ptsPacketAddr[0] << endl;
	cout << "main() ptsPacketAddr = " << hex << (uint16 *)ptsPacketAddr << endl;

	// create the parser object
	Parser parser_object;

	parser_object.set_fileAddr(pFile);
	parser_object.set_bufferAddr(ptsPacketAddr);
	parser_object.parse_tsPacket();
	parser_object.parse_tsHeader();
	parser_object.print_tsHeader();

#if 0
	cout << "Print three TS files:" << endl;	
	for (uint16 j = 0; j < 3; j++)
	{
		fileUtility_object.read_TSPacket();
	}
#endif

	return 0;
}

