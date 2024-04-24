#include <Servo.h>
// Importacion de la libreria Servo.h
// Declaracion de cada uno de los servo motores
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

// Declarar los dedos

#define dedo1 A1
#define dedo2 A2
#define dedo3 A3
#define dedo4 A4
#define dedo5 A5


int val1,val2,val3,val4,val5;

void setup(){

    servo1.attach(8);
    servo2.attach(9);
    servo3.attach(10);
    servo4.attach(11);
    servo5.attach(12);

}


void loop(){

    val1=analogRead(dedo1);
    val1=map(val1,450,384,0,180);
    servo1.write(val1);
    delay(1);

    val2=analogRead(dedo2);
    val2=map(val2,750,585,0,180);
    servo2.write(val2);
    delay(1);

    val3=analogRead(dedo3);
    val3=map(val3,854,641,0,175);
    Serial.println(val3);
    servo3.write(val3);
    delay(1);

    val4=analogRead(dedo4);
    val4=map(val4,823,725,0,175);
    Serial.println(val4);
    servo4.write(val4);
    delay(1);

    val5=analogRead(dedo5);
    val5=map(val5,874,845,0,175);
    Serial.println(val5);
    servo5.write(val5);
    delay(1);


}