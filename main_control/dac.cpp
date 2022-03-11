#include "dac.h"


#define LDACPIN_LOW  ( PORTC &= B01111111 ) // PC7 = D30
#define LDACPIN_HIGH ( PORTC |= B10000000 )
#define SDIPIN_LOW   ( PORTC &= B10111111 ) // PC6 = D31
#define SDIPIN_HIGH  ( PORTC |= B01000000 )
#define SCKPIN_LOW   ( PORTC &= B11011111 ) // PC5 = D32
#define SCKPIN_HIGH  ( PORTC |= B00100000 )
#define CSPIN_LOW    ( PORTC &= B11101111 ) // PC4 = D33
#define CSPIN_HIGH   ( PORTC |= B00010000 )

#define CLOCK        SCKPIN_HIGH; SCKPIN_LOW;
#define SET_HIGH     SDIPIN_HIGH; CLOCK;
#define SET_LOW      SDIPIN_LOW;  CLOCK;


void dac_init(void)
{
	
  DDRC |= B11110000;
  CSPIN_HIGH;
  SCKPIN_LOW;
  SDIPIN_LOW;
  LDACPIN_HIGH;
  set_dac (0,0);	
	
}



void set_dac ( int value_a, int value_b )
{

  // --- output A ---
  CSPIN_LOW;

  SDIPIN_HIGH; CLOCK; // 15
  SDIPIN_LOW;  CLOCK; // 14
  SDIPIN_HIGH; CLOCK; // 13
  CLOCK;              // 12
  
  SDIPIN_LOW;  if ( 2048 & value_a ){ SDIPIN_HIGH; } CLOCK; // 11
  SDIPIN_LOW;  if ( 1024 & value_a ){ SDIPIN_HIGH; } CLOCK; // 10
  SDIPIN_LOW;  if (  512 & value_a ){ SDIPIN_HIGH; } CLOCK; // 09
  SDIPIN_LOW;  if (  256 & value_a ){ SDIPIN_HIGH; } CLOCK; // 08
  SDIPIN_LOW;  if (  128 & value_a ){ SDIPIN_HIGH; } CLOCK; // 07
  SDIPIN_LOW;  if (   64 & value_a ){ SDIPIN_HIGH; } CLOCK; // 06
  SDIPIN_LOW;  if (   32 & value_a ){ SDIPIN_HIGH; } CLOCK; // 05
  SDIPIN_LOW;  if (   16 & value_a ){ SDIPIN_HIGH; } CLOCK; // 04
  SDIPIN_LOW;  if (    8 & value_a ){ SDIPIN_HIGH; } CLOCK; // 03
  SDIPIN_LOW;  if (    4 & value_a ){ SDIPIN_HIGH; } CLOCK; // 02
  SDIPIN_LOW;  if (    2 & value_a ){ SDIPIN_HIGH; } CLOCK; // 01
  SDIPIN_LOW;  if (    1 & value_a ){ SDIPIN_HIGH; } CLOCK; // 00

  CSPIN_HIGH; 
  

  // --- output B ---
  CSPIN_LOW;

  SDIPIN_LOW; CLOCK;  // 15
  CLOCK;              // 14
  SDIPIN_HIGH; CLOCK; // 13
  CLOCK;              // 12

  SDIPIN_LOW;  if ( 2048 & value_b ){ SDIPIN_HIGH; } CLOCK; // 11
  SDIPIN_LOW;  if ( 1024 & value_b ){ SDIPIN_HIGH; } CLOCK; // 10
  SDIPIN_LOW;  if (  512 & value_b ){ SDIPIN_HIGH; } CLOCK; // 09
  SDIPIN_LOW;  if (  256 & value_b ){ SDIPIN_HIGH; } CLOCK; // 08
  SDIPIN_LOW;  if (  128 & value_b ){ SDIPIN_HIGH; } CLOCK; // 07
  SDIPIN_LOW;  if (   64 & value_b ){ SDIPIN_HIGH; } CLOCK; // 06
  SDIPIN_LOW;  if (   32 & value_b ){ SDIPIN_HIGH; } CLOCK; // 05
  SDIPIN_LOW;  if (   16 & value_b ){ SDIPIN_HIGH; } CLOCK; // 04
  SDIPIN_LOW;  if (    8 & value_b ){ SDIPIN_HIGH; } CLOCK; // 03
  SDIPIN_LOW;  if (    4 & value_b ){ SDIPIN_HIGH; } CLOCK; // 02
  SDIPIN_LOW;  if (    2 & value_b ){ SDIPIN_HIGH; } CLOCK; // 01
  SDIPIN_LOW;  if (    1 & value_b ){ SDIPIN_HIGH; } CLOCK; // 00

  CSPIN_HIGH;

  LDACPIN_LOW;
  SCKPIN_HIGH;
  LDACPIN_HIGH;
  SCKPIN_LOW;

}
