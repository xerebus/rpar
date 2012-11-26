/* This Arduino sketch receives signals from the serial port
 * and coordinates movement accordingly.
 */
 
// Ports to which the servos are connected
int lw = 5;
int rw = 6;

void servoUp(int port) {
	
    pinMode(port,OUTPUT);
    digitalWrite(port,LOW);

}

void servoStep(int port, int dir) {
    
    long unsigned middle = 1500;
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
	servoUp(lw);
	servoUp(rw);
	
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
		input = Serial.read();
		
		// what to do based on input
		
		switch ( input ) {
			case f:
				servoStep(lw,1);
				servoStep(rw,-1);
				break;
			case b:
				servoStep(lw,-1);
				servoStep(rw,1);
				break;
			case l:
				servoStep(lw,1);
				break;
			case r:
				servoStep(rw,1);
				break;
			default:
				Serial.println("Bad input");
				break;
		}
		
	}

}
