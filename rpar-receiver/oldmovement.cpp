/* Movement of servo
 * Aritra Biswas 1.30.12
 */

void servoStep(int port, int dir) {
    
    long unsigned pulseWidth;
    
    // convert user direction input into pulse width
    if ( dir == 1 ) { pulseWidth = 1646; }
    else if ( dir == 0 ) { pulseWidth = 1430; }
    else if ( dir == -1 ) { pulseWidth = 1220; }
    
    // setup
    pinMode(port,OUTPUT);
    digitalWrite(port,LOW);
    
    // send pulse width
    digitalWrite(port,HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(port,LOW);
    delayMicroseconds(pulseWidth);
}

void setup() {
    int i;
    for ( i = 0; i <= 9001; i++ ) {
      servoStep(5,1);
      servoStep(6,-1);
    }
}

void loop() {
}
