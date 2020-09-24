//assigns pins
int pressurePin1 = A0;
int pressurePin2 = A1;
int pressurePin3 = A2;
int pressurePin4 = A3;
int pressurePin5 = A4;

//flex pins
int pressurePin10 = A10;
int pressurePin9 = A9;
int pressurePin8 = A8;
int pressurePin11 = A11;

//force from each finger
int force1, force2, force3, force4, force5;
int flex1, flex2, flex3, flex4;

void setup() {
  Serial.begin(9600);
}//setup


void loop() {
  
  //Reads the input from each of the five pressure sensors.
  force1= analogRead(pressurePin1);
  force2 = analogRead(pressurePin2);
  force3 = analogRead(pressurePin3);
  force4 = analogRead(pressurePin4);
  force5 = analogRead(pressurePin5);

  //Reads the input from the two flex sensors
  flex1 = analogRead(pressurePin8);
  flex2 = analogRead(pressurePin9);
  
  //maps input to comport bandwidth range.
  //Each inputs is mapped to a range of values in which none of them overlap
  //The signal will be sorted in the Pure Data patch
  force1= map(force1, 678, 30, 120, 139);
  force2 = map(force2, 678, 30, 140, 159);
  force3 = map(force3, 678, 30, 160, 179);
  force4 = map(force4, 678, 30, 180, 199);
  force5 = map(force5, 678, 30, 200, 219);

  flex1= map(flex1, 660, 570,80, 99);
  flex2 = map(flex2, 660, 570, 0, 39);


  //Writes the value which will be picked up the comport object in PD
  Serial.write(force1);
  Serial.write(force2);
  Serial.write(force3);
  Serial.write(force4);
  Serial.write(force5);

  Serial.write(flex1);
  Serial.write(flex2);

}//loop


