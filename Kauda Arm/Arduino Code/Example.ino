/*
   _____     __     __  __     ______   ______     ______     __  __
  /\  __-.  /\ \   /\ \_\ \   /\__  _\ /\  ___\   /\  ___\   /\ \_\ \
  \ \ \/\ \ \ \ \  \ \____ \  \/_/\ \/ \ \  __\   \ \ \____  \ \  __ \
   \ \____-  \ \_\  \/\_____\    \ \_\  \ \_____\  \ \_____\  \ \_\ \_\
    \/____/   \/_/   \/_____/     \/_/   \/_____/   \/_____/   \/_/\/_/

  DIY-TECH
  by Giovanni Lerda
  https://www.diy-technology.com

*/

/*
  Note:
  This sketch is developed on the basis of the wiring diagram
  that you can find on the KAUDA project website.
  https://www.diy-technology.com/010-kauda

  This example allows you to test the command of the stepper 
  motors through commands launched from the serial port 
  (to which the Arduino board is connected).
  
*/


//Enable pin - DON'T MODIFY
#define EN        8
//Direction pin - DON'T MODIFY
#define X_DIR     5
#define Y_DIR     6
#define Z_DIR     7
//Step pin - DON'T MODIFY
#define X_STP     2
#define Y_STP     3
#define Z_STP     4

//Steps number
int steps = 200;
/*
  Note:
  If you increase the value in the steps variable you will increase accordingly
  the speed with which the steps are performed.
*/
int data;

void setup()
{
  Serial.begin(9600);

  // Pin configuration.
  // DON'T MODIFY.
  pinMode(X_DIR, OUTPUT); pinMode(X_STP, OUTPUT);
  pinMode(Y_DIR, OUTPUT); pinMode(Y_STP, OUTPUT);
  pinMode(Z_DIR, OUTPUT); pinMode(Z_STP, OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW);

}
void loop() {

  if (Serial.available())
  {
    data = Serial.read();

    //In case of reading the command "a" (modifiable) follow the action.
    if (data == 'a')
    {
      for (int i = 0; i < steps; i++) {

        /*
          The axes execute the steps indicated in
          the "steps" variable in one direction.
        */

        digitalWrite(Y_DIR, LOW); //Direction of the Y axis.
        digitalWrite(X_DIR, LOW); //Direction of the X axis.
        digitalWrite(Z_DIR, LOW); //Direction of the Z axis.

        //Execution of a step:

        digitalWrite(Y_STP, HIGH);
        digitalWrite(X_STP, HIGH);
        digitalWrite(Z_STP, HIGH);
        delay(1);
        digitalWrite(Y_STP, LOW);
        digitalWrite(X_STP, LOW);
        digitalWrite(Z_STP, LOW);
        delay(1);

        /*
          Note:
          The cycle will be executed for a number of times equal
          to that indicated in the steps tag.
        */

      }
    }
    //In case of reading the command "b" (modifiable) follow the action.
    if (data == 'b')
    {

      for (int i = 0; i < steps; i++) {

        /*
          The axes execute the steps indicated in the "steps" variable
          in the opposite direction to the previous if condition.
        */

        digitalWrite(Y_DIR, HIGH); //Direction of the Y axis.
        digitalWrite(X_DIR, HIGH); //Direction of the X axis.
        digitalWrite(Z_DIR, HIGH); //Direction of the Z axis.

        //Execution of a step:

        digitalWrite(Y_DIR, HIGH);
        digitalWrite(X_DIR, HIGH);
        digitalWrite(Z_STP, HIGH);
        delay(1);
        digitalWrite(Y_STP, LOW);
        digitalWrite(X_STP, LOW);
        digitalWrite(Z_STP, LOW);
        delay(1);

        /*
          Note:
          The cycle will be executed for a number of times equal
          to that indicated in the steps tag.
        */
      }
    }
  }
}

/*

  Attention!

  The A axis is not indicated as it will execute the same movements (in parallel)
  that the axis that is selected through the hardware configuration of the CNC Shield performs.
  For more information:https://www.handsontec.com/dataspecs/cnc-3axis-shield.pdf

  This sketch does NOT include the command of the servomotors.
*/
