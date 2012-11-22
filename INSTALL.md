Installation Instructions
=========================

1. Plug the Arduino into the RPi and find out what port it is connected to.
> ls /dev/ttyUSB* /dev/ttyACM*

2. Make sure your user on the RPi has permission to write to that port. Usually, this can be done by adding your user to the 'dialout' group.
> gpasswd -a $YOUR_USERNAME dialout

3. Open the rpar bash script and edit the PORT value as needed.

4. Install the bash script to a convenient location.
> sudo install rpar /usr/local/bin/

5. Connect the Arduino to another computer.

6. Using your method of choice, upload the rpar-receiver project to the Arduino.

7. Remember that before it will work, you have to issue "rpar up". For all other commands, just look at the rpar bash script.
