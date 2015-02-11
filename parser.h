//This file contains parser class definition

#include <iostream>

#include "common.h"

class Parser
{
public:
	// Constructor
	Parser();
	// Destructor
	~Parser();

	// Public member functions
	// Parse TS header
	uint32 parse_tsHeader();

	// Print TS packet
	uint32 print_tsPacket();

	// Print TS header
	uint32 print_tsHeader();

	// Set buffer address
	uint32 set_bufferAddr(uint8* buffAddr);

private:
	uint8* buffer_addr;

	// ts header
	uint8 sync_byte;
	uint8 transport_error_indicator;
	uint8 payload_unit_start_indicator;
	uint8 transport_priority;
	uint16 packet_identifier;
	uint8 transport_scrambling_control;
	uint8 adaptation_field_counter;
	uint8 continuity_counter;
};
