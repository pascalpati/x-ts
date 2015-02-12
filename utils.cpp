// This file contains utility class implementation

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>

#include "utils.h"
#include "common.h"

using namespace std;

// Constructor
FileUtility::FileUtility()
{
	data = new uint8 [TS_PACKET_SIZE];
}

// Destructor
FileUtility::~FileUtility()
{
	delete[] data;
	
	// Close the file
	tsfile.close();
}

uint32 FileUtility::open_file()
{
	// File name
<<<<<<< HEAD
	filename = "/home/ulas/resources/ts-files/ed24p_00.ts";
    	//filename = "/Users/demirdru/home/work/x-ts/streams/rte1.ts";
=======
	//filename = "/home/ulas/resources/ts-files/ed24p_00.ts";
    filename = "/Users/demirdru/home/work/x-ts/streams/rte1.ts";
>>>>>>> 8bfe930b277766de05cf3ebee3bb832b021cd25b

	// Opening the file
	tsfile.open(filename, ios::in | ios::binary);
    	if (NULL != &tsfile)
    	{
        	// tsfile.peek();
        	// isdigit(tsfile.peek())
        	// tsfile.seekg(0, tsfile.beg);
        	// cout << "open_file() tsfile = " << hex << (uint16 *)&tsfile.seekg(0, tsfile.beg) << endl;
    	}

	if (!tsfile.is_open())
	{
		cout << endl << "ERROR: Can't open the .ts file.\n" << endl;
		return ERROR;
	}

<<<<<<< HEAD
	// Calculate the file size
	get_file_size();

=======
>>>>>>> 8bfe930b277766de05cf3ebee3bb832b021cd25b
	return SUCCESS; 
}

uint32 FileUtility::get_fileSize(uint32* pfileSize)
{
<<<<<<< HEAD
	*pfileSize = file_size;

	return SUCCESS;
}

uint32 FileUtility::get_file_size()
{
	file_size = 0;

	tsfile.seekg(0, ios::end);
    	file_size = tsfile.tellg();
    	tsfile.seekg(0, ios::beg);
	
	cout << "File size = " << file_size << " bytes" << endl;

	return SUCCESS;
}

uint32 FileUtility::read_TSPacket()
{
    	for (uint32 i = 0; i < 3; i++)
    	{
    		// Read 188 bytes into array
     		tsfile.read((uint8*)data, TS_PACKET_SIZE);
    
    		// IMPORTANT: to set the position back to the beginning of the file. (as read advances the position)
    		tsfile.seekg(0, tsfile.beg); 
        
		cout << hex;

    		for (uint16 i = 0; i < TS_PACKET_SIZE; i++)
    		{
        		cout << showbase << left << setw(8) <<(uint16)data[i] << setw(8);
        		if (!(i%8))
        		{
            			cout << endl;
        		}
    		}
		cout << dec << endl;
    	}
=======
	file_size = 0;
    
    tsfile.seekg(0, ios::end);
    file_size = tsfile.tellg();
    tsfile.seekg(0, ios::beg);
    
    //cout << "File size = " << file_size << " bytes" << endl;
    
    *pfileSize = file_size;
>>>>>>> 8bfe930b277766de05cf3ebee3bb832b021cd25b

	return SUCCESS;
}

uint32 FileUtility::read_fileAddr(fstream** pfile)
{
	cout << "tsfile_addr = 0x" << tsfile << endl;
	
	*pfile = &tsfile;

	cout << "pfile_addr = 0x" << **pfile << endl;	

	return SUCCESS;
}

uint32 FileUtility::read_TSFileAddr(uint8** pTSPacket)
{	
	uint8 firstByte;

	// read one byte to get the address
    	tsfile.read(&firstByte, 1);
   	cout << "firstByte = " << hex << (uint16)firstByte << endl;
   	cout << "firstByte_addr = " << hex << (uint16 *)&firstByte << endl;
    
    	// set position to the beginning of the file
    	tsfile.seekg(0, tsfile.beg);
    
    	*pTSPacket = &firstByte;

	cout << "data = "  << hex << (uint16)data[0] << endl;
	cout << "*pnextTSPacket = " << hex << (uint16)*pTSPacket[0] << endl;

	return SUCCESS;
}
