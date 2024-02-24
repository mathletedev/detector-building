const double BLUE_MIN = 0;
const double GREEN_MIN = 2000;
const double RED_MIN = 4000;

void setup() {
	Serial.begin(9600);
	
	pinMode(2, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(8, OUTPUT);
}

double voltageToPPM(double voltage) {
	return (voltage - 0.651) / (2.03e-4);
}

void loop() {
	int data = analogRead(A0);
	double voltage = data * 5.0 / 1023.0;

	Serial.print("Voltage: ");
	Serial.print(voltage);

	double ppm = voltageToPPM(voltage);
	Serial.print(" PPM: ");
	Serial.println(ppm);

	digitalWrite(2, LOW);
	digitalWrite(5, LOW);
	digitalWrite(8, LOW);

	if (ppm > RED_MIN)
		digitalWrite(2, HIGH);
	else if (ppm > GREEN_MIN)
		digitalWrite(5, HIGH);
	else
		digitalWrite(8, HIGH);

	delay(500);
}
