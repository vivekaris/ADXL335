

const int XPin = A0;
const int YPin = A1;
const int ZPin = A2;

// Zero offsets: Average of max and min values
const int XZero = 512;
const int YZero = 512;
const int ZZero = 512;

void setup() {Serial.begin(19200);}
void loop() {
    long XAcc = analogRead(XPin) - XZero;
    long YAcc = analogRead(YPin) - YZero;
    long ZAcc = analogRead(ZPin) - ZZero;

    // apply trigonometry to get the pitch and roll:
    float pitch = atan(xAcc/sqrt(YAcc*YAcc + ZAcc*ZAcc)); 
    float roll = atan(YAcc/sqrt(XAcc* XAcc + ZAcc* ZAcc)); 

    // Print the values (in Radians)
    Serial.print(pitch); Serial.print(","); Serial.println(roll);

    delay(1000);
}



