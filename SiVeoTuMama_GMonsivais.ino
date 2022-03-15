/*
 MelodyPlays a melodycircuit:
 * 8-ohm speaker on digital pin 8
 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe
 modified 7 Feb 2014
 by Mark Easley
 This example code is in the public domain.
 modified 15 March 2022 
 by George Monsivais

 I would like to point out that the pitches.h file was given here https://energia.nu/guide/tutorials/digital/tutorial_tone/
 I simply derived the note duration for 16 different notes and inputed 445 notes to the array melody[]
 I would like to credit Midi Arrangement, Edited And Recorded By MUSICHELP for the piano tutorial that I followed https://www.youtube.com/watch?v=2ESKbce-Xek 
*/
#include "pitches.h"
// notes in the melody: 

double melody[] = {NOTE_A5,
NOTE_FS5,NOTE_FS5,NOTE_E5,NOTE_A5,NOTE_FS5,NOTE_FS5,NOTE_FS5,NOTE_E5,NOTE_A5,NOTE_FS5,NOTE_FS5,NOTE_E5,NOTE_A5,NOTE_FS5,NOTE_FS5,NOTE_FS5,NOTE_G5,NOTE_A5,NOTE_FS5,
NOTE_FS5,NOTE_E5,NOTE_A5,NOTE_FS5,NOTE_FS5,NOTE_FS5,NOTE_E5,NOTE_A5,NOTE_FS5,NOTE_FS5,NOTE_E5,NOTE_A5,NOTE_D5,NOTE_D5,NOTE_D5,
NOTE_D5,NOTE_D5,NOTE_B4,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_E5,NOTE_D5,NOTE_CS5,NOTE_B4,NOTE_B4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_B4,NOTE_A4,
NOTE_G4,NOTE_A4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_B4,NOTE_A4,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_FS5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_E5,NOTE_D5,
NOTE_CS5,NOTE_B4,NOTE_FS4,NOTE_B4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_B4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_B4,NOTE_A4,NOTE_D5,NOTE_D5,
NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_FS5,NOTE_A5,NOTE_D5,NOTE_B4,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_B4,NOTE_D5,NOTE_B4,NOTE_B4,NOTE_D5,NOTE_B4,NOTE_B4,NOTE_A4,NOTE_A4,
NOTE_D5,NOTE_D5,NOTE_D5,NOTE_B4,NOTE_D5,NOTE_B4,NOTE_B4,NOTE_D5,NOTE_B4,NOTE_B4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_B4,NOTE_A4,0,NOTE_E5,NOTE_D5,NOTE_D5,
NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_CS5,NOTE_B4,NOTE_D5,NOTE_B4,NOTE_D5,NOTE_B4,NOTE_B4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_D5,NOTE_B4,NOTE_B4,NOTE_D5,
NOTE_B4,NOTE_D5,NOTE_B4,NOTE_D5,NOTE_D5,NOTE_B4,NOTE_B4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_D5,NOTE_B4,NOTE_D5,NOTE_B4,NOTE_D5,NOTE_B4,NOTE_D5,
NOTE_B4,NOTE_D5,NOTE_B4,NOTE_D5,NOTE_B4,NOTE_D5,NOTE_D5,NOTE_A4,NOTE_D5,NOTE_B4,NOTE_D5,NOTE_B4,NOTE_D5,NOTE_D5,0,NOTE_A4,NOTE_B4,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,
NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_B4,NOTE_A4,NOTE_B4,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_B4,NOTE_B4,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_B4,
NOTE_B4,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_A4,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_B4,NOTE_B4,NOTE_B4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_B4,NOTE_D5,
NOTE_B4,NOTE_D5,NOTE_D5,NOTE_B4,NOTE_D5,NOTE_D5,NOTE_A4,NOTE_B4,NOTE_D5,NOTE_B4,NOTE_D5,NOTE_D5,NOTE_B4,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_B4,NOTE_D5,NOTE_B4,NOTE_D5,
NOTE_D5,NOTE_B4,NOTE_D5,NOTE_D5,NOTE_B4,NOTE_D5,NOTE_D5,0,NOTE_FS5,NOTE_FS5,NOTE_FS5,NOTE_FS5,NOTE_A5,NOTE_B5,NOTE_FS5,NOTE_E5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,
NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_B4,NOTE_FS5,NOTE_E5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_B4,NOTE_FS5,NOTE_E5,NOTE_FS5,NOTE_E5,
NOTE_A4,NOTE_A4,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_B4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_A4,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_B4,NOTE_A4,NOTE_B4,
NOTE_A4,NOTE_FS4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_FS4,NOTE_FS4,NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_FS4,NOTE_G4,
NOTE_A4,NOTE_FS4,NOTE_A4,NOTE_A4,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_B4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_A4,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_B4,
NOTE_A4,NOTE_B4,NOTE_A4,NOTE_FS4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_FS4,NOTE_FS4,NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_FS4,NOTE_G4,
NOTE_FS4,NOTE_G4,NOTE_FS4,NOTE_E4,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_B4,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_E5,NOTE_D5,NOTE_CS5,NOTE_B4,NOTE_B4,
NOTE_A4,NOTE_B4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_B4,NOTE_A4,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D5,
NOTE_D5,NOTE_FS5,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_E5,NOTE_D5,NOTE_CS5,NOTE_B4,NOTE_FS4,NOTE_B4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_B4,NOTE_G4,NOTE_G4,NOTE_G4,
NOTE_G4,NOTE_G4,NOTE_G4,NOTE_B4,NOTE_A4,NOTE_E5,NOTE_FS5,NOTE_E5,NOTE_D5};


/*How to Derive Notes
Whole Note was derived by 1000/1=1000
Quarter Note was derived by 1000/4=250
Half Note was derived by 1000/2=500
Then set custom values for however long a note is

KEY:
0.687= whole note + half note
0.727= whole note + quarter note + eighth note
0.8= whole note + quarter note
0.89 = whole note + eighth note
1= whole note
1.0667 = half note + quarter note + 3 eighth notes
1.143 = half note + quarter note + eighth note
1.33= half note + quarter note
1.6 = half note + eighth note
1.778 = half note + 16th note
2= half note
2.67= quarter note + eighth note
4= quarter note
5.33= eighth note + 16th note
8 = eighth note
16 = 16th note
*/

double noteDurations[] = {2.67,
8, 8, 4, 4, 4, 8, 4, 4, 2.67, 8, 8, 4, 4, 4, 8, 4, 4, 2.67, 8, 8, 4, 4, 4, 8, 4, 4, 2.67, 8, 8, 4, 2.67, 8, 8, 8, 8, 8, 8, 8, 0.89, 8, 8, 8, 8, 8, 8, 0.8, 
8, 8, 8, 8, 8, 8, 8, 8, 1, 8, 8, 8, 8, 8, 8, 0.8, 8, 8, 8, 8, 8, 8, 0.8, 8, 8, 8, 8, 8, 8, 0.89, 8, 8, 8, 8, 8, 8, 8, 4, 1, 8, 8, 8, 8, 8, 8, 0.8, 8, 8, 8, 8, 8, 8, 
0.667, 2, 0.727, 8, 8, 8, 8, 8, 4, 4, 8, 4, 4, 8, 2.67, 8, 8, 8, 8, 8, 4, 4, 8, 4, 4, 8, 8, 8, 8, 8, 8, 8, 4, 4, 8, 2.67, 8, 4, 8, 8, 8, 4, 2, 8, 8, 8, 8, 8, 8, 8, 8,
8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0.67, 8, 8, 8, 8, 8, 8, 8, 4, 16, 16, 16, 8, 2, 16, 16, 8, 16, 16, 8,
8, 2.67, 16, 16, 16, 8, 16, 16, 8, 8, 8, 16, 16, 8, 5.33, 16, 16, 16, 8, 5.33, 16, 16, 16, 8, 16, 16, 8, 16, 16, 8, 16, 4, 16, 16, 16, 8, 16, 16, 8, 16, 16, 2.67, 16, 
16, 8, 16, 16, 8, 16, 4, 16, 8, 16, 5.33, 16, 16, 16, 8, 16, 16, 8, 8, 8, 1, 8, 8, 8, 8, 4, 8, 1.143, 8, 1.33, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 4, 2.67, 8, 8, 8, 8, 8, 
8, 8, 4, 8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 1.143, 8, 8, 8, 8, 8, 8, 8, 8, 8, 1, 8, 8, 8, 8, 8, 8, 8, 8, 2.67, 1.6, 8, 8, 8, 8, 8, 8, 8, 8, 2.67, 2.67, 8, 8, 8,
8, 8, 8, 8, 8, 8, 8, 1.143, 8, 8, 8, 8, 8, 8, 8, 8, 8, 1, 8, 8, 8, 8, 8, 8, 8, 8, 2.67, 1.6, 8, 8, 8, 8, 8, 8, 8, 8, 2.67, 2.67, 8, 8, 8, 8, 8, 8, 8, 0.842, 8, 8, 8, 
8, 8, 8, 0.8, 8, 8, 8, 8, 8, 8, 8, 8, 1, 8, 8, 8, 8, 8, 8, 0.8, 8, 8, 8, 8, 8, 8, 0.8, 8, 8, 8, 8, 8, 8, 0.89, 8, 8, 8, 8, 8, 8, 8, 4, 1, 8, 8, 8, 8, 8, 8, 1.0667,
4, 1.778, 4, 1, };
void setup() {
  
    // iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < 445; thisNote++) 
    {
      // to calculate the note duration, take one second
      // divided by the note type. //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      double noteDuration = 1000/noteDurations[thisNote];
      tone(40, melody[thisNote], noteDuration);
      // to distinguish the notes, set a minimum time between them.
      //2.1 is how you change the speed of the song (a bigger number is faster)
      double pauseBetweenNotes = noteDuration * 2.1; delay(pauseBetweenNotes); 
      // stop the tone playing:
      //noTone(40);
    }
}
void loop() {
  // no need to repeat the melody.
}
