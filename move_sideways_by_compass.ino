#define Motor1A 5
#define Motor1B 6
#define Motor2A 7
#define Motor2B 8
#define Motor3A 9
#define Motor3B 10

void setup() {
  
  pinMode(Motor1A, OUTPUT);
  pinMode(Motor1B, OUTPUT);
  pinMode(Motor2A, OUTPUT);
  pinMode(Motor2B, OUTPUT);
  pinMode(Motor3A, OUTPUT);
  pinMode(Motor3B, OUTPUT);

}

void setPWMSpeed(int pwmSpeed){
  // dummy method
}

void setMotorOnePwmSpeed(int pwmSpeed){
  // dummy method
}

void setMotorTwoPwmSpeed(int pwmSpeed){
  // dummy method
}

void setMotorThreePwmSpeed(int pwmSpeed){
  // dummy method
}

void moveSideWaysLeftWithCorrection(int tDelay, int compassHeading, int ballDistance, boolean check){
  int lastCompassHeading = compassHeading;
  
  while(ballDistance >= 20 && check == true){
     setMotorThreePwmSpeed(255); // max 255
     digitalWrite(Motor3B, HIGH);
     
    if (lastCompassHeading > compassHeading){
      setMotorOnePwmSpeed(90); // max 255
      setMotorTwoPwmSpeed(90); // max 255
      digitalWrite(Motor1A, HIGH);
      digitalWrite(Motor2B, HIGH);
      delay(tDelay);
      digitalWrite(Motor1A, LOW);
      digitalWrite(Motor2B, LOW);
    }

    if (lastCompassHeading < compassHeading){
      setMotorOnePwmSpeed(90); // max 255
      setMotorTwoPwmSpeed(90); // max 255
      digitalWrite(Motor1B, HIGH);
      digitalWrite(Motor2A, HIGH);
      delay(tDelay);
      digitalWrite(Motor1B, LOW);
      digitalWrite(Motor2A, LOW);
    }
      delay(tDelay);
      digitalWrite(Motor3B, LOW);

      break;
  }
}

void moveSideWaysRightWithCorrection(int tDelay, int compassHeading, int ballDistance, boolean check){
  int lastCompassHeading = compassHeading;
  
  while(ballDistance >= 20 && check == true){
     setMotorThreePwmSpeed(255); // max 255
     digitalWrite(Motor3A, HIGH);
     
    if (lastCompassHeading > compassHeading){
      setMotorOnePwmSpeed(90); // max 255
      setMotorTwoPwmSpeed(90); // max 255
      digitalWrite(Motor1A, HIGH);
      digitalWrite(Motor2B, HIGH);
      delay(tDelay);
      digitalWrite(Motor1A, LOW);
      digitalWrite(Motor2B, LOW);
    }

    if (lastCompassHeading < compassHeading){
      setMotorOnePwmSpeed(90); // max 255
      setMotorTwoPwmSpeed(90); // max 255
      digitalWrite(Motor1B, HIGH);
      digitalWrite(Motor2A, HIGH);
      delay(tDelay);
      digitalWrite(Motor1B, LOW);
      digitalWrite(Motor2A, LOW);
    }
      delay(tDelay);
      digitalWrite(Motor3A, LOW);
      
      break;
  }
}

void loop() {
  // some check goes on here to determine if this should run.
  moveSideWaysLeftWithCorrection(5, random(30, 90), 90, true);

}
