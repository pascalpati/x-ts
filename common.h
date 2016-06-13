// This file contains the common definitions and types

// Type definitions
typedef unsigned int uint32;
typedef unsigned short int uint16;
typedef char uint8;

typedef int int32;
typedef short int int16;

// Time definitions
#define MILI_SECONDS 1000
#define SECONDS MILI_SECONDS * 1000

// TS related definitions
#define TS_PACKET_SIZE 188

// SI Table PID numbers
#define PAT 0x0000	// Program Association Table
#define CAT 0x0001	// Conditional Access Table
#define TSDT 0x0002	// 
#define NIT 0x0010	// Network Identification Table
#define TDT 0x0014	// Time and Date Table
#define SDT 0x0011	// Service Description Table

// Success
#define SUCCESS 0
// Error
#define ERROR -1

//EOF
