# ledDisp
Arduino sketch that provides multiplexing for a single or multiple 7 segments displays without extra hardware

 SevenSeg - 1.0
 
 created 20 August 2014
 by Victor N. Borges - www.vitim.us
 
 This arduino sketch provides software to drive 7-segments display with multiplexing.
 Only turns a single segment is turned on at time, this allows the display to be turned with just the pins current,
 and only requires a single resistor per display on the common pin.
 
 Displays are connected directly to the arduinos output pins, with one current limiting resistor on the common pin.
 For more than 1 display wire then in parallel, and connect the common pin to different I/O pins, so they can be selected.
 
 This code is assyncronous, and will block other pieces of code like using delay.
 
 call sevenSeg_setup() on your setup function, and call sevenSeg_displayHold(unsigned int us); inside the loop()
 the 'us' parameter is the interval between segments in microseconds, adjust this value depending on how long your
 whole program takes to execute.
 If you code alredy takes too much time to execute you can try to call sevenSeg_display() directly on your loop instead.
 
# ledDisp
Arduino sketch that provides multiplexing for a single or multiple 7 segments displays without extra hardware

 SevenSeg - 1.0
 
 created 20 August 2014
 by Victor N. Borges - www.vitim.us
 
 This arduino sketch provides software to drive 7-segments display with multiplexing.
 Only turns a single segment is turned on at time, this allows the display to be turned with just the pins current,
 and only requires a single resistor per display on the common pin.
 
 Displays are connected directly to the arduinos output pins, with one current limiting resistor on the common pin.
 For more than 1 display wire then in parallel, and connect the common pin to different I/O pins, so they can be selected.
 
 This code is assyncronous, and will block other pieces of code like using delay.
 
 call sevenSeg_setup() on your setup function, and call sevenSeg_displayHold(unsigned int us); inside the loop()
 the 'us' parameter is the interval between segments in microseconds, adjust this value depending on how long your
 whole program takes to execute.
 If you code alredy takes too much time to execute you can try to call sevenSeg_display() directly on your loop instead.

## Setup the code

### Constants
 
 - `const uint8_t displayCount`  
 Number of displays

- `const uint8_t displayCommonPins[]`  
 Pin name which the display common are connected.  
 eg: const uint8_t displayCommonPins[2] = {A2, A3};

- `const uint8_t displayPins[8]`  
  Array containing the 8 pins of the displays.  
  {A, B, C, D, E, F, G, POINT}  
  e.g: {11, 10, 8, 7, 6, 12, A0, 9}

### Type of Display
Change settings to match Common Cathode/Anode  
```
#define SEGMENT_ON HIGH
#define COMMON_ON LOW
```

# Usage

## Initialization

- `void sevenSeg_setup()`  
 Call this on setup to set all pinsMode's

## Drive the Segments

- `void sevenSeg_displayHold(unsigned int us)`  
  Function that perform the multiplexing to draw every digit with a assyncronous delay between segments.  
  IMPORTANT: This should be called on your main loop repeatedly. But you cannot have code that blocks the main loop. E.G. delay.  
  
  Parameters:  
    - unsigned int **us**: adjust the interval between segments in microseconds.  This is used to adjust the scan rate (refresh rate per segment).
  
  Note: if your program is very busy, you can try to call sevenSeg_display() directly instead, in order to archive faster scan rates.

# ---

## Font

  A character is represented by a single byte. You can define your own charactes, in a font-like array, which every position of the array contains a bitmap of a diferent character.
  
  The code is provided with a set of numbers and optional letters that can be toggled using a macro.
```  
#define ALPHA 0 //change to 1 to include leters 

const byte sevenSeg_font[] = {
    B11111100,  // 0
    B01100000,  // 1
    B11011010,  // 2
    B11110010,  // 3
    B01100110,  // 4
    B10110110,  // 5
    B10111110,  // 6
    B11100000,  // 7
    B11111110,  // 8
    B11110110,  // 9
    B00000010, // dash -
    B00010000, // underscore _
  #if ALPHA==1
    B11101110, //A
    B00111110, //b
    B10011100, //C
    B00011010, //c
    B01111010, //d
    B10011110, //E
    B10001110, //F
    B01101110, //H
    B00101110, //h
    B00011100, //L
    B01100000, //l
    B11111100, //O
    B00111010, //o
    B11001110, //P
    B10110110, //S
  #endif
    B00000000,  // blank
};
```
 
## Writing data on the displays

- `void sevenSeg_setDigit(uint8_t digit, byte character)`  
  Set a display digit  
  
  Parameters:  
   - uint8_t digit - Display Index
   - byte character - 7bit 0 paded character
   
  Usage:  
   > sevenSeg_setDigit(**<display numeber>**, **sevenSeg_font[<characterIndex>]**)  
   > e.g.: `sevenSeg_setDigit(0, sevenSeg_font[0]);`  
   > Will display `0` on the first display

- `void sevenSeg_setDecimalPoint(uint8_t digit, bool on)`  
  Toggle the decimal point on/off  
  
  Parameters:  
   - uint8_t digit - Display Index
   - bool on - state true/false


----

#### Global Variables

  Those variables are not intended to be changed by your code.

 - `byte displayData[2];`  
  *buffer* of the data being pushed to each display.
  Size of the array must be the same as *displayCount*

 - `byte currentSegment;` (private)  
  keep state of the current segment being in the driven

 - `byte currentDigit;` (private)  
  keep state of the current segment being driven

 - `long previousMicros` (private)  
  keep state of interval between segments
