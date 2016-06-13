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

}

// Destructor
FileUtility::~FileUtility()
{
	// Close the file
	tsfile.close();
}

uint32 FileUtility::open_file()
{
	// File name
	//filename = "/home/ulas/resources/ts-files/ed24p_00.ts";
        filename = "/Users/demirdru/work/x-ts/streams/rte1.ts";

	// Opening the file
	tsfile.open(filename, ios::in | ios::binary);
	
	if (!tsfile.is_open())
	{
		cout << endl << "ERROR: Can't open the .ts file.\n" << endl;
		return ERROR;
	}

	return SUCCESS; 
}

uint32 FileUtility::get_fileSize(uint32* pfileSize)
{
	file_size = 0;
    
    	tsfile.seekg(0, ios::end);
    	file_size = tsfile.tellg();
    	tsfile.seekg(0, ios::beg);
    
    	//cout << "File size = " << file_size << " bytes" << endl;
    
    	*pfileSize = file_size;

	return SUCCESS;
}

uint32 FileUtility::read_fileAddr(fstream** pfile)
{
	cout << "tsfile_addr = 0x" << tsfile << endl;
	
	*pfile = &tsfile;

	cout << "pfile_addr = 0x" << **pfile << endl;	

	return SUCCESS;
}

