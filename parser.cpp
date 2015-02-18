// This file contains Parser class implementation

#include <iostream>
#include <iomanip>

#include "parser.h"
#include "common.h"

using namespace std;

#define TS_HEADER_LENGTH 4

// Constructor
Parser::Parser()
{
	ptsPacket = new uint8 [TS_PACKET_SIZE];
}

// Destruxtors
Parser::~Parser()
{
	delete[] ptsPacket;
}

uint32 Parser::parse_tsHeader()
{
	for (uint16 i = 0; i < TS_HEADER_LENGTH; i++)
	{
		cout << dec << "ts header[" << i << "]= " << left << hex << +(unsigned char)buffer_addr[i] << endl;
        cout << "ts header = " << left << (bitset<8>) +(unsigned char)buffer_addr[i] << endl;
	}

	sync_byte = buffer_addr[0];

	transport_error_indicator = (0x80 & buffer_addr[1]) >> 7;
	payload_unit_start_indicator = (0x40 & buffer_addr[1]) >> 6;
	transport_priority = (0x20 & buffer_addr[1]) >> 5;
	packet_identifier = ((0x1f & buffer_addr[1]) << 8) | (0x00ff & buffer_addr[2]);
    //cout << "packet_identifier_1 =" << (bitset<16>) (0x1f & buffer_addr[1]) << endl;
    //cout << "packet_identifier_2 =" << (bitset<16>) ((0x1f & buffer_addr[1]) << 8) << endl;
    //cout << "packet_identifier_3 =" << (bitset<16>) (0x00ff & buffer_addr[2]) << endl;
    //cout << "packet_identifier_4 =" << (bitset<16>) (((0x1f & buffer_addr[1]) << 8) | (0x00ff & buffer_addr[2])) << endl;
    //cout << "packet_identifier_5 =" << (uint16)(((0x1f & buffer_addr[1]) << 8) | (0x00ff & buffer_addr[2])) << endl;
	transport_scrambling_control = (0xc0 & buffer_addr[3]) >> 6;
	adaptation_field_counter = (0x30 & buffer_addr[3]) >> 4;
	continuity_counter = 0xf & buffer_addr[3];

    if ((0x0000 == packet_identifier) || (0x0001 == packet_identifier))
    {
        print_tsHeader();
    }
	
	return SUCCESS;
}

uint32 Parser::print_tsHeader()
{
	cout << "sync_byte = " << hex << (uint16)sync_byte << endl;
	cout << "transport_error_indicator = " << (uint16)transport_error_indicator << endl;
	cout << "payload_unit_start_indicator = " << (uint16)payload_unit_start_indicator << endl;
	cout << "transport_priority = " << (uint16)transport_priority << endl;
	cout << "PID = " << hex << packet_identifier << endl;
	cout << "transport_scrambling_control = " << hex << (uint16)transport_scrambling_control << endl;
	cout << "adaptation_field_counter = " << hex << (uint16)adaptation_field_counter << endl;
	cout << "continuity_counter = " << hex << (uint16)continuity_counter << endl;

	return SUCCESS;
}

uint32 Parser::parse_allTSPackets()
{
    // TODO: We need total number of TS packages in this file.
    // TODO: To be able to know it we need to know the file size.
    uint32 file_size = 0;
    
    (*pFile).seekg(0, ios::end);
    file_size = (*pFile).tellg();
    (*pFile).seekg(0, ios::beg);
    
    cout << "[Parser] file_size = " << dec << file_size << endl;
    
    for (uint32 i = 0; i < (file_size/TS_PACKET_SIZE); i++)
    	{
    		// Read 188 bytes into array
     		// tsfile.read((uint8*)data, TS_PACKET_SIZE);
            (*pFile).read((uint8 *)ptsPacket, TS_PACKET_SIZE);
    
    		// IMPORTANT: to set the position back to the beginning of the file. 
            // (as read advances the position)
    		//(*pFile).seekg(0, (*pFile).beg);
        
            cout << hex;

    		for (uint16 i = 0; i < TS_PACKET_SIZE; i++)
    		{
        		//cout << showbase << left << setw(8) << (uint16)ptsPacket[i] << setw(8);
                cout << showbase << left << hex << setw(6) << +(unsigned char)ptsPacket[i];
        		if (!(i%8))
        		{
            			cout << endl;
        		}
    		}
            cout << dec << endl;
    	
            // set the buffer address
            set_bufferAddr();

            parse_tsHeader();
        }

	return SUCCESS;
}

uint32 Parser::set_fileAddr(fstream* pfile)
{
	cout << "file address = " << hex << *pfile << endl;

	pFile = pfile;

	return SUCCESS;
}

uint32 Parser::set_bufferAddr()
{
	buffer_addr = &ptsPacket[0];

	cout << "buffer_addr = " << hex << (uint16 *)buffer_addr << endl;
	cout << "buffer_value = " << hex << (uint16)buffer_addr[0] << endl;

	return SUCCESS;
}

