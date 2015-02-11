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
	filename = "/home/ulas/resources/ts-files/ed24p_00.ts";

	// Opening the file
	tsfile.open(filename, ios::in | ios::binary);

	if (!tsfile.is_open())
	{
		cout << "ERROR: Can't open file.\n";
		return ERROR;
	}

	// Calculate the file size
	get_file_size();
	
	read_TSPacket();

	return SUCCESS; 
}

uint32 FileUtility::get_fileSize(uint32* pfileSize)
{
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
	 // Read 188 bytes into array
        tsfile.read((uint8*)data, TS_PACKET_SIZE);

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

	return SUCCESS;
}

uint32 FileUtility::read_TSPacketAddr(uint8** pTSPacket)
{	
	*pTSPacket = data;

	cout << "data = "  << hex << (uint16)data[0] << endl;
	cout << "*pnextTSPacket = " << hex << (uint16)*pTSPacket[0] << endl;

	return SUCCESS;
}
