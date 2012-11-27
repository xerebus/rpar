Basic info
==========

*rpar* is an interface to control a robot running on a Raspberry Pi and using an Arduino for sensor and motor control.

Usage
=====

Structure
---------

`rpar` is the bash script that's mean to be run on the Raspberry Pi (or other mobile computer) to send a particular signal to the Arduino. It also prepares tty settings on the RPi for proper communication through the serial port at 9600 baud. The Arduino project, rparrcv, is a program that runs constantly on the Arduino and executes certain actions (like movement) based on serial input.

Setup and Movement
-----------------

`rpar <cmd>` accepts the following values for `<cmd>`:

`up` - prepare the serial port

`f` - step forward

`b` - step backward

`l` - step left

`r` - step right

WASD Control
-----------

The `rpar-ctrl` script binds movement to the WASD keys. Pressing two keys at once is not supported, and `rpar-ctrl` will only take the first pressed key. It is a known issue that holding down a key will send one keypress, do nothing for a second or two, and then repeat the key - this is due to keyboard settings.
