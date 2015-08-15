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
 
