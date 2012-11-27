/* This Arduino sketch receives signals from the serial port
 * and coordinates movement accordingly.
 */
 
// Ports to which the servos are connected
int lw = 5;
int rw = 6;

void servoStep(int port, int dir) {
    
    long unsigned middle = 1320;
    long unsigned pulseWidth;
    
    // convert user direction input into pulse width
    if ( dir == 1 ) { pulseWidth = middle + 200; }
    else if ( dir == 0 ) { pulseWidth = middle; }
    else if ( dir == -1 ) { pulseWidth = middle - 200; }
    
    // send pulse width
    digitalWrite(port,HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(port,LOW);
    delayMicroseconds(pulseWidth);
    
}

void setup() {
	
	// make sure both wheel ports are ready to receive pulse width
        pinMode(lw,OUTPUT);
        digitalWrite(lw,LOW);
        pinMode(rw,OUTPUT);
        digitalWrite(rw,LOW);
	
	// brind up serial port
	Serial.begin(9600);

}

void loop() {

	Serial.println("Ready for input");
	
	// while there is no input
	while ( Serial.available() <= 0 ) {
		// do nothing
    }
    
    // when input becomes available
    while ( Serial.available() > 0 ) {
		
		// read single character
		char input = Serial.read();
		
		// what to do based on input
		
		if ( input == 'f' ) {
			servoStep(lw,1);
			servoStep(rw,-1);
		}
		else if ( input == 'b' ) {
			servoStep(lw,-1);
			servoStep(rw,1);
		}
		else if ( input == 'l' ) {
			servoStep(rw,-1);
		}
		else if ( input == 'r' ) {
			servoStep(lw,-1);
		}
		else if ( input == 'c' ) {
			servoStep(lw,0);
			servoStep(rw,0);
		}
		else {
			Serial.println("Bad input");
		}
		
	}

}
