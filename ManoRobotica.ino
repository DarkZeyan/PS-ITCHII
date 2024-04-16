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


int val[5];

void setup(){

    servo1.attach(8);
    servo2.attach(9);
    servo3.attach(10);
    servo4.attach(11);
    servo5.attach(12);

}


void loop(){

    val[0]=analogRead(dedo1);
    val[0]=map(val[0],450,384,0,180);
    servo1.write(val[0]);
    delay(1);

    val[1]=analogRead(dedo2);
    val[1]=map(val[1],750,585,0,180);
    servo2.write(val[1]);
    delay(1);

    val[2]=analogRead(dedo3);
    val[2]=map(val[2],854,641,0,175);
    servo3.write(val[2]);
    delay(1);

    val[3]=analogRead(dedo4);
    val[3]=map(val[3],823,725,0,175);
    servo4.write(val[3]);
    delay(1);

    val[4]=analogRead(dedo5);
    val[4]=map(val[4],874,845,0,175);
    servo5.write(val[4]);
    delay(1);


}