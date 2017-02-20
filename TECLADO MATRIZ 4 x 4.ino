//Uso del teclado matricial 4 x 4
//Desarrollado por José Acosta      2017 - 03 - 19
//jz.akta@gmail.com

#include <Key.h>        
#include <Keypad.h>

const byte FILAS = 4;      //Definimos el número de filas
const byte COLUMNAS = 4;   //Definimos el número de columnas

char teclas[FILAS][COLUMNAS] =            //**
  {                                       // *
    {'1' , '2' , '3' , 'A'},              // *   Definimos teclas correspondientes
    {'4' , '5' , '6' , 'B'},              // *** dentro de la matriz de filas y
    {'7' , '8' , '9' , 'C'},              // *   columnas.
    {'*' , '0' , '#' , 'D'}               // *
  };                                      //**

byte filasPines[FILAS] = {23 , 25 , 27 , 29};             //Definimos pines digitales de entradas fila de la placa Arduino MEGA
byte columnasPines[COLUMNAS] = {31 , 33 , 35 , 37};       //Definimos pines digitales de entradas columna de la placa Arduino MEGA

Keypad teclado = Keypad(makeKeymap(teclas), filasPines, columnasPines, FILAS, COLUMNAS);   //Definimos la variable teclado con todos los elementos configurados

void setup() 
{
  Serial.begin(9600);                     //Iniciar comunicación serie
}

void loop() 
{
  char teclapulsada = teclado.getKey();   //Adquisición del caracter y almacenamiento en variable char

  if(teclapulsada != NO_KEY)              //Si existe comunicación se procede con lo siguiente
  {
    Serial.println(teclapulsada);         //Impresión de caracter
  }
}
