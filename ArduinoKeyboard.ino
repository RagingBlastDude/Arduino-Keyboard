/*
Name: Yama Kamal
Date: November 25 2021
Description: Final Project --> Old School Cell Phone Keypad
*/

//keypad setup from https://www.circuitbasics.com/how-to-set-up-a-keypad-on-an-arduino/
//timing control from https://forum.arduino.cc/t/using-millis-for-timing-a-beginners-guide/483573

//including the nessesary libraries
#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4; 
const byte COLS = 4; 

//creating a multidimensional char array that contains all the values of each of the 4x4 keypad buttons
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//creating two arrays that contains the pin for each row and column
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
LiquidCrystal lcd(13, 12, 11, 10, A4, A5);
int flag = 0;
int pressed = 0;
int position = 0; 
int rowPosition = 0;
long currentTime;
long startTime;
const long period = 3000; //this variable controls the period in miliseconds
char customKey;
int redRGB = A1;
int greenRGB = A2;
int blueRGB = A3;
char letter;
  
void setup()
{
  Serial.begin(9600); //opening the serial port
  lcd.begin (16,2);  //starting up the lcd to display 16x2
  startTime = millis(); 
  pinMode(redRGB, OUTPUT); //setting RGB as output
  pinMode(greenRGB, OUTPUT);
  pinMode(blueRGB, OUTPUT);
}
  
void loop()
{
  customKey = customKeypad.getKey(); //gets the current key 
  currentTime = millis(); //sets current time to time since program ran
  if (customKey) //if any key is pressed
  {
    Serial.println(customKey); //will print the value of the key pressed in Serial Monitor
    checkButton1(); //checks if any key from 0-9 and B-C are pressed
    checkButton2();
    checkButton3();
    checkButton4();
    checkButton5();
    checkButton6();
    checkButton7();
    checkButton8();
    checkButton9();
    checkButton0();
    checkButtonB();
    checkButtonC();
    lcd.setCursor(position,rowPosition); 
    lcd.blink(); //turns on the blinker
    startTime = currentTime; //resets the timer every time a key is pressed
  }
  
  //this will execute every period. For example if period = 4000 would execute every 4 sec
  if (currentTime - startTime >= period)
  {
    position++;
    lcd.setCursor(position,rowPosition); 
    lcd.blink();
    startTime = currentTime;
    if(position > 15) //if column position goes over 15 
    {
      rowPosition = 1; 
      position = 0;
    }
  }
}

//This function checks if the 1 key was pressed
//This key is used as a reset button
void checkButton1()
{
  if(customKey == '1')
  {
    lcd.clear();
    position = 0;
    digitalWrite(greenRGB,LOW);
    digitalWrite(blueRGB,LOW);
    digitalWrite(redRGB,LOW);
    letter = '*';
  }
}

//this function checks if the 2 key was pressed
//depending on the flag value it will output a different letter between A-C
void checkButton2()
{
  if(customKey == '2')
  {
    if (flag == 0)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("A");
      letter = 'A';
      flag = 1;
    }
    else if(flag == 1)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("B");
      letter = 'B';
      flag = 2;
    }
    else if(flag == 2)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("C");
      letter = 'C';
      flag = 0;
    }
  }
}

//this function checks if the 3 key was pressed
//depending on the flag value it will output a different letter between D-F
void checkButton3()
{
  if(customKey == '3')
  {
    if(flag == 0)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("D");
      letter = 'D';
      flag = 1;
    }
    else if(flag == 1)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("E");
      letter = 'E';
      flag = 2;
    }
    else if(flag == 2)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("F");
      letter = 'F';
      flag = 0;
    }
  }  
}

//this function checks if the 4 key was pressed
//depending on the flag value it will output a different letter between G-I
void checkButton4()
{
  if(customKey == '4')
  {
    if(flag == 0)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("G");
      letter = 'G';
      flag = 1;
    }
    else if(flag == 1)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("H");
      letter = 'H';
      flag = 2;
    }
    else if(flag == 2)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("I");
      letter = 'I';
      flag = 0;
    }
  } 
}

//this function checks if the 5 key was pressed
//depending on the flag value it will output a different letter between J-L
void checkButton5()
{
  if(customKey == '5')
  {
    if(flag == 0)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("J");
      letter = 'J';
      flag = 1;
    }
    else if(flag == 1)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("K");
      letter = 'K';
      flag = 2;
    }
    else if(flag == 2)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("L");
      letter = 'L';
      flag = 0;
    }
  }
}

//this function checks if the 6 key was pressed
//depending on the flag value it will output a different letter between M-O
void checkButton6()
{
  if(customKey == '6')
  {
    if(flag == 0)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("M");
      letter = 'M';
      flag = 1;
    }
    else if(flag == 1)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("N");
      letter = 'N';
      flag = 2;
    }
    else if(flag == 2)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("O");
      letter = 'O';
      flag = 0;
    }
  }
}

//this function checks if the 7 key was pressed
//depending on the flag value it will output a different letter between P-S
void checkButton7()
{
  if(customKey == '7')
  {
    if(flag == 0)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("P");
      letter = 'P';
      flag = 1;
    }
    else if(flag == 1)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("Q");
      letter = 'Q';
      flag = 2;
    }
    else if(flag == 2)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("R");
      letter = 'R';
      flag = 3;
    }
    else if(flag == 3)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("S");
      letter = 'S';
      flag = 0;
    }
  }
}

//this function checks if the 8 key was pressed
//depending on the flag value it will output a different letter between T-V
void checkButton8()
{
  if(customKey == '8') 
  {
    if(flag == 0)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("T");
      letter = 'T';
      flag = 1;
    }
    else if(flag == 1)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("U");
      letter = 'U';
      flag = 2;
    }
    else if(flag == 2)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("V");
      letter = 'V';
      flag = 0;
    } 
  }
}

//this function checks if the 9 key was pressed
//depending on the flag value it will output a different letter between W-Z
void checkButton9()
{
  if(customKey == '9')
  {
   if(flag == 0)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("W");
      letter = 'W';
      flag = 1;
    }
    else if(flag == 1)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("X");
      letter = 'X';
      flag = 2;
    }
    else if(flag == 2)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("Y");
      letter = 'Y';
      flag = 3;
    }
    else if(flag == 3)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print("Z");
      letter = 'Z';
      flag = 0;
    } 
  }
}

//this function checks if the 0 key was pressed
//this key acts as a space button
void checkButton0()
{
  if(customKey == '0')
  {
    position+=2; 
    flag = 0;
    if(position > 15) //if column position goes over 15
    {
      rowPosition = 1;
      position = 0;
    }
  }
}

//this function checks if the B key was pressed
//the B button simulates a backspace
void checkButtonB()
{
  if(customKey == 'B')
  {
    if(pressed > 0) //if pressed is greater than 0
    {
      position--;
      lcd.setCursor(position,rowPosition); 
      lcd.print(" ");
      flag = 0;
    }
    else if(pressed == 0)
    {
      lcd.setCursor(position,rowPosition); 
      lcd.print(" ");
      flag = 0;
    }
   
    if(position < 0)
    {
      position = 0;
    }
    pressed++;
    digitalWrite(greenRGB,LOW);
    digitalWrite(blueRGB,LOW);
    digitalWrite(redRGB,LOW);
  }
  else //if b is not pressed
  {
    pressed = 0;
  }
}

//this function checks if the C key was pressed
//the goal of this function is to turn on the RGB depending on keypad input
void checkButtonC()
{
  if(customKey == 'C') 
  {
    if(letter == 'G') //if the last letter the user entered was G
    {
      digitalWrite(greenRGB,HIGH); //turn green RGB on 
      digitalWrite(blueRGB,LOW);
      digitalWrite(redRGB,LOW);
    }
    else if(letter == 'B') //if the last letter the user entered was B
    {
      digitalWrite(greenRGB,LOW);
      digitalWrite(blueRGB,HIGH); //turn blue RGB on
      digitalWrite(redRGB,LOW);
    }
    else if(letter == 'R') //if the last letter the user entered was R
    {
      digitalWrite(greenRGB,LOW);
      digitalWrite(blueRGB,LOW);
      digitalWrite(redRGB,HIGH); //turn red RGB on
    }
    else if(letter == 'Y') //if the last letter the user entered was Y
    {
      digitalWrite(greenRGB,HIGH); //turn green RGB on
      digitalWrite(blueRGB,LOW);
      digitalWrite(redRGB,HIGH); //turn red RGB on
    }
    else if(letter == 'P') //if the last letter the user entered was P
    {
      digitalWrite(greenRGB,LOW);
      digitalWrite(blueRGB,HIGH); //turn blue RGB on
      digitalWrite(redRGB,HIGH); //turn red RGB on
    }
    else if(letter == 'C') //if the last letter the user entered was C
    { 
      digitalWrite(greenRGB,HIGH); //turn green RGB on
      digitalWrite(blueRGB,HIGH); //turn blue RGB on
      digitalWrite(redRGB,LOW);
    }
    else if(letter == 'W') //if the last letter the user entered was W
    {
      digitalWrite(greenRGB,HIGH); //turn green RGB on
      digitalWrite(blueRGB,HIGH); //turn blue RGB on
      digitalWrite(redRGB,HIGH); //turn red RGB on
    }
    else //if user enters a letter that does not have a corresponding colour
    {
      digitalWrite(greenRGB,LOW); //turn off all RGBs
      digitalWrite(blueRGB,LOW);
      digitalWrite(redRGB,LOW);
    }
  }
}