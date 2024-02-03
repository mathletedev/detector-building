const double BLUE_MIN = 0;
const double GREEN_MIN = 0.1;
const double RED_MIN = 1.0;

void setup() {
	Serial.begin(9600);
	
	pinMode(2, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(8, OUTPUT);
}

void loop() {
	int data = analogRead(A0);
	double voltage = data * 5.0 / 1023.0;

	Serial.print("Voltage: ");
	Serial.println(voltage);

	digitalWrite(2, LOW);
	digitalWrite(5, LOW);
	digitalWrite(8, LOW);

	if (voltage > RED_MIN)
		digitalWrite(2, HIGH);
	else if (voltage > GREEN_MIN)
		digitalWrite(5, HIGH);
	else
		digitalWrite(8, HIGH);

	delay(500);
}
