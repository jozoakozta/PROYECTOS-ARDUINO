//Servos controlados por Joystick X Y
//Desarrollado por José Acosta      2017 - 02 - 21
//jz.akta@gmail.com


#include <Servo.h>        //Librería Servo

/*DEFINICION DE VARIABLES*/
Servo miServo1;
Servo miServo2;
int entradaX = A0;
int entradaY = A1;
int x=0;

void setup() 
{
/*DECLARACIÓN PINES SALIDA SERVO*/  
  miServo1.attach(4);                       //Enlazamos la salida del primer servo al puerto 8
  miServo2.attach(5);                       //Enlazamos la salida del segundo servo al puerto 9
}

void loop()
{
/*DEFINICIÓN DEL PROGRAMA*/  
    int valor1 = analogRead(entradaX);       //Adquisición de datos Joystick Analógico en X
    int valor2 = analogRead(entradaY);       //Adquisición de datos Joystick Analógico en Y
//LECTURA DE DATOS
    valor1 = map(valor1,0,1023,0,179);       //conversión de resolución
    valor2 = map(valor2,0,1023,0,179);       //conversión de resolución
    miServo1.write(valor1);                  //Escritura de posición servo 1 ---> Joystick en X
    miServo2.write(valor2);                  //Escritura de posición servo 2 ---> Joystick en Y
    delay(50);
}
