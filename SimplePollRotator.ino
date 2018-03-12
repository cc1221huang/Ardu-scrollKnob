// -----
// SimplePollRotator.ino - Example for the RotaryEncoder library.
// This class is implemented for use with the Arduino environment.
// Copyright (c) by Matthias Hertel, http://www.mathertel.de
// This work is licensed under a BSD style license. See http://www.mathertel.de/License.aspx
// More information on: http://www.mathertel.de/Arduino
// -----
// 18.01.2014 created by Matthias Hertel
// -----

// This example checks the state of the rotary encoder in the loop() function.
// The current position is printed on output when changed.

// Hardware setup:
// Attach a rotary encoder with output pins to A2 and A3.
// The common contact should be attached to ground.

#include "RotaryEncoder.h"
#include "HID-Project.h"

// Setup a RoraryEncoder for pins A2 and A3:
RotaryEncoder encoder(A0, A1);

void setup()
{
//  Serial.begin(57600);
//  Serial.println("SimplePollRotator example for the RotaryEncoder library.");
  // Sends a clean report to the host. This is important on any Arduino type.
  AbsoluteMouse.begin();
} // setup()


// Read the current position of the encoder and print out when changed.
void loop()
{
  static int pos = 0;
  static int i=0;
  encoder.tick();

  int newPos = encoder.getPosition();
  if (pos != newPos) {
//    Serial.print(newPos);
//    Serial.println();
    AbsoluteMouse.move(100, 100, 4);
    pos = newPos;
  } // if
  else{
//    Serial.println(newPos);
  }
} // loop ()

// The End

