/* This Arduino sketch receives signals from the serial port
 * and coordinates movement accordingly.
 */

void wheelStep(char wheel, int dir) {
    
    long unsigned middle;
    int port;
    
    /** EDIT THESE **/
    // wheel settings
    if ( wheel == 'l' ) {
		middle = 1320;
		port = 5;
	}
	else if ( wheel == 'r' ) {
		middle = 1340;
		port = 6;
	}
	else {
		Serial.println("Bad wheel input");
	}
    
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
			wheelStep(l,1);
			wheelStep(r,-1);
		}
		else if ( input == 'b' ) {
			wheelStep(l,-1);
			wheelStep(r,1);
		}
		else if ( input == 'l' ) {
			wheelStep(r,-1);
		}
		else if ( input == 'r' ) {
			wheelStep(l,-1);
		}
		else if ( input == 'c' ) {
			wheelStep(l,0);
			wheelStep(r,0);
		}
		else {
			Serial.println("Bad input");
		}
		
	}

}
