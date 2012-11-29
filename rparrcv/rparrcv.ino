/* This Arduino sketch receives signals from the serial port
 * and coordinates movement accordingly.
 */

// wheel settings
int lw = 5;
int rw = 6;
long unsigned lw_middle = 1320;
long unsigned rw_middle = 1380;
long unsigned lw_pw_delta = 600;
long unsigned rw_pw_delta = 580;

void wheelStep(char wheel, int dir) {
    
    long unsigned middle;
    int port;
    long unsigned pulseWidth;
    
    /** EDIT THESE **/
    // wheel settings
    if ( wheel == 'l' ) {
		middle = lw_middle;
		port = lw;
		if ( dir == 1 ) { pulseWidth = middle + lw_pw_delta; }
		else if ( dir == 0 ) { pulseWidth = middle; }
		else if ( dir == -1 ) { pulseWidth = middle - lw_pw_delta; }
	}
	else if ( wheel == 'r' ) {
		middle = rw_middle;
		port = rw;
		if ( dir == 1 ) { pulseWidth = middle + rw_pw_delta; }
		else if ( dir == 0 ) { pulseWidth = middle; }
		else if ( dir == -1 ) { pulseWidth = middle - rw_pw_delta; }
	}
	else {
		Serial.println("Bad wheel input");
	}
    
    // send pulse width
    digitalWrite(port,HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(port,LOW);
    delay(20);
    
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
		
		if ( input == 'w' ) {
			wheelStep('l',1);
			wheelStep('r',-1);
		}
		else if ( input == 's' ) {
			wheelStep('l',-1);
			wheelStep('r',1);
		}
		else if ( input == 'd' ) {
			wheelStep('r',1);
		}
		else if ( input == 'a' ) {
			wheelStep('l',-1);
		}
		else if ( input == 'c' ) {
			wheelStep('l',0);
			wheelStep('r',0);
		}
		else {
			Serial.println("Bad input");
		}
		
	}

}
