#include <Servo.h>

Servo servo_9;

int M1 = 0;

int M1Max = 160;

int M1Min = 20;

Servo servo_10;

int M2 = 0; 

int M2Max = 160;

int M2Min = 20;



 void setup () 

 {

  pinMode(A0, INPUT);

  pinMode(A1, INPUT);

  pinMode(A2, INPUT);

  pinMode(A3, INPUT);

  servo_11.attach(11);

  servo_12.attach(12);

 }



void loop()

{

  int BottomLeft = analogRead(A3);

  int TopRight = analogRead(A2);

  int TopLeft = analogRead(A1);

  int BottomRight = analogRead(A0);

  int AvgTop = (TopLeft + TopRight) / 2; 

  int AvgBottom = (BottomLeft + BottomRight) / 2;

  int AvgLeft = (TopLeft + BottomLeft) / 2; 

  int AvgRight = (TopRight + BottomRight) / 2; 



  if (AvgTop < AvgBottom)

  {

    servo_12.write(M1 +1);

    if (M1 > M1Max) 

     { 

      M1 = M1Max;

     }

    delay(10);

  }

  else if (AvgBottom < AvgTop)

  {

    servo_12.write(M1 -1);

    if (M1 < M1Min)

  {

    M1 = M1Min;

  }

    delay(10);

  }

  else 

  {

    servo_12.write(M1);

  }

  

  if (AvgLeft > AvgRight)

  {

    servo_11.write(M2 +1);

    if (M2 > M2Max)

    {

    M2 = M2Max;

    }

    delay(10);

  }

  else if (AvgRight > AvgLeft)

  {

    servo_11.write(M2 -1);

    if (M2 < M2Min)

     {

     M2 = M2Min;

     }

    delay(10);

  }

  else 

  {

    servo_11.write(M2);

  }

  delay(50);

}

#include <Servo.h>



int buttonState = 0;



Servo servo_11;



void setup()

{

  pinMode(2, INPUT);

  servo_11.attach(11, 500, 2500);



}



void loop()

{

  buttonState = digitalRead(2);

  if (buttonState == HIGH) {

    servo_11.write(720);

  } 

  else {

    servo_11.write(0);

  }

}
