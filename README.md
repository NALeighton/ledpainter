# LED PAINTER
### Description
The LED Painter is a custom built WS series based led panel driven by an Arduino Due and a Leap Motion connected to a laptop to track where a user's finger is located. The location on the user's finger is used to create a painting effect by lighting the pixels that are closest to the user's finger tip making it look like they are "painting" onto the panel without actually touching it.
### Setup
The firmware in the firmware folder is to be flashed onto an Arduino Due. You can use an Arduino Mega but the response time was very slow.

The software in the software program is to be ran in processing along with the LEAP motion SDK to allow for tracking the participant's finger.

If everything is working you'll see a mirror of what the LED array is doing on the computer screen, but in black and white.
### Notes
This was built as a demo piece for the Computer Science department at Johnson and Wales University. This repository is not actively maintained and will only be updated/modified if the university wants new features added.
