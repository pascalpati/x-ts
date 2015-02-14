//This file contains parser class definition

#include <iostream>
#include <fstream>

#include "common.h"

using std::fstream;

class Parser
{
public:
	// Constructor
	Parser();
	// Destructor
	~Parser();

	// Public member functions
	
	// Parse TS packet
	uint32 parse_tsPacket();
	
	// Set file addr
	uint32 set_fileAddr(fstream* pfile);

private:
	uint8* buffer_addr;

	fstream* pFile;

	uint8* ptsPacket;

	// ts header
	uint8 sync_byte;
	uint8 transport_error_indicator;
	uint8 payload_unit_start_indicator;
	uint8 transport_priority;
	uint16 packet_identifier;
	uint8 transport_scrambling_control;
	uint8 adaptation_field_counter;
	uint8 continuity_counter;
	
	// Set buffer address
	uint32 set_bufferAddr();
	
	// Parse TS header
	uint32 parse_tsHeader();
	
	// Print TS header
	uint32 print_tsHeader();
};
