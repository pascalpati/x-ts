// This file contains Parser class implementation

#include <iostream>

#include "parser.h"
#include "common.h"

using namespace std;

#define TS_HEADER_LENGTH 4

// Constructor
Parser::Parser()
{

}

// Destruxtors
Parser::~Parser()
{

}

uint32 Parser::parse_tsHeader()
{
	for (uint16 i = 0; i < TS_HEADER_LENGTH; i++)
	{
		cout << "ts header = " << hex << (uint16)buffer_addr[i] << endl;	
	}

	sync_byte = buffer_addr[0];

	transport_error_indicator = (0x80 & buffer_addr[1]) >> 7;
	
	payload_unit_start_indicator = (0x40 & buffer_addr[1]) >> 6;
	
	transport_priority = (0x20 & buffer_addr[1]) >> 5;
	
	packet_identifier = ((0x1F & buffer_addr[1]) << 8) || buffer_addr[2];
	
	transport_scrambling_control = (0xC0 & buffer_addr[3]) >> 6;
	
	adaptation_field_counter = (0x30 & buffer_addr[3]) >> 4;
	
	continuity_counter = 0xF & buffer_addr[3];
	
	return SUCCESS;
}

uint32 Parser::print_tsPacket()
{
	return SUCCESS;
}

uint32 Parser::print_tsHeader()
{
	cout << "sync_byte = " << hex << (uint16)sync_byte << endl;
	cout << "transport_error_indicator = " << (uint16)transport_error_indicator << endl;
	cout << "payload_unit_start_indicator = " << (uint16)payload_unit_start_indicator << endl;
	cout << "transport_priority = " << (uint16)transport_priority << endl;
	cout << "PID = " << hex << (uint16)packet_identifier << endl;
	cout << "transport_scrambling_control = " << hex << (uint16)transport_scrambling_control << endl;
	cout << "adaptation_field_counter = " << hex << (uint16)adaptation_field_counter << endl;
	cout << "continuity_counter = " << hex << (uint16)continuity_counter << endl;

	return SUCCESS;
}

// TODO: Parser now needs a function to read the ts packet
// read_TSPacket()

uint32 Parser::set_bufferAddr(uint8* buffAddr)
{
	cout << "buffAddr = " << hex << (uint16 *)buffAddr << endl;
	cout << "buffAddr[0] = " << hex << (uint16)buffAddr[0] << endl;

	buffer_addr = buffAddr;
	
	cout << "buffer_addr = " << hex << (uint16 *)buffer_addr << endl;

	return SUCCESS;
}




