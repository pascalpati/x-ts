// This is the main of the x-ts implementation.

#include <iostream>
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
    
	fileUtility_object.read_TSFileAddr(&ptsPacketAddr);
	cout << "main() *ptsPacketAddr = " << hex << (uint16)ptsPacketAddr[0] << endl;
	cout << "main() ptsPacketAddr = " << hex << (uint16 *)ptsPacketAddr << endl;

	// create the parser object
	Parser parser_object;

	parser_object.set_bufferAddr(ptsPacketAddr);
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

