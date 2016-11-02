
//cube constants
#define DECODER_BITS 5
#define LEDS_PER_ROW 5

//decoder enable
#define pEN 12

// pins to decoders for anodes
#define p0 4
#define p1 3
#define p2 2
#define p3 6
#define p4 5

/*
#define p0 6
#define p1 5
#define p2 4
#define p3 3
#define p4 2
*/
// pins for cathode control
#define Z0 7
#define Z1 8
#define Z2 9
#define Z3 10
#define Z4 11

//potentiometer pin, for delay
#define POT_PIN A0

//PCB utility jumpers
#define j1 A5
#define j2 A4
#define j3 A3
#define j4 A2
#define j5 A1

#define HIGH 0x1
#define LOW  0x0

/**
 * Stores pin numbers of pins to decoders in array, for iteration
 */
unsigned int decoderPins[] = {p0, p1, p2, p3, p4};
unsigned int cathodePins[] = {Z0, Z1, Z2, Z3, Z4};
