#include <Wire.h>                     // usando a biblioteca Wire
#include <LiquidCrystal_I2C.h>        // usando a biblioteca LiquidCrystal I2C
 
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Configura endereço I2C e display com 16 caracteres e 2 linhas 
int thisChar = 0 ;

const int UP    = 0;
const int DOWN  = 1;
const int LEFT  = 2;
const int RIGHT = 3;

 const int YELLOW        = 0;
 const int GREEN         = 1;
 const int RED           = 2;
 const int BLUE          = 3;
 const int CENTER        = 4;
 const int GROUP1        = 5;
 const int GROUP2        = 6;
 const int GROUP3        = 7;
 const int GROUP4        = 8;

 const int RED_BLUE      = 9;
 const int YELLOW_GREEN  = 10;
 const int RED_YELLOW    = 11;
 
 const int ALL_COLOR     = 11;
 const int ALL_WHITE     = 12;
 const int ALL_GROUPS    = 13;
 const int LEFT_SIDE     = 14;
 const int RIGHT_SIDE    = 15;
 const int DIAGONAL_DOWN = 16;
 const int DIAGONAL_UP   = 17;
  
 const int ALL           = 18;

 const int OFF           = 99;
 

int redPin                = 3; 
int yellowPin             = 2; 
int bluePin               = A1; 
int greenPin              = 4; 
int whiteCenterPin        = 5;
int whiteGroup1Pin        = 6;
int whiteGroup2Pin        = 10;
int whiteGroup3Pin        = 11;
int whiteGroup4Pin        = 9;

int potentiometerPin      = A3;

int soundSensorAnalogPin  = A0;
int soundSensorDigitalPin = 7;

int joyX = A2;
int joyY = A3;
int joyZ = 8;

boolean backLightOn = true;
 
void setup()
{
  lcd.init();                      // inicializa LCD
  lcd.backlight();

  title();
  
  pinMode(redPin,OUTPUT);
pinMode(bluePin,OUTPUT);
pinMode(yellowPin,OUTPUT);
pinMode(greenPin,OUTPUT);
pinMode(whiteCenterPin,OUTPUT);
pinMode(whiteGroup1Pin,OUTPUT);
pinMode(whiteGroup2Pin,OUTPUT);
pinMode(whiteGroup3Pin,OUTPUT);
pinMode(whiteGroup4Pin,OUTPUT);

pinMode(joyZ,INPUT);

pinMode(soundSensorDigitalPin,INPUT);
pinMode(soundSensorAnalogPin,INPUT);
on(ALL);

delay(3000);

off(ALL);

}

void cPrint(int line, String text)
{
  lcd.setCursor(8-text.length()/2,line);
  lcd.print(text);
}

void title()
{
  cPrint(0,"Lightoino 1.0");
  cPrint(1,"by M. Schneider");
}

void on(int led)
{
  switch(led)
  {
case YELLOW : digitalWrite(yellowPin,HIGH); break;
 case GREEN : digitalWrite(greenPin,HIGH); break;
 case RED   : digitalWrite(redPin,HIGH); break;
 case BLUE  : digitalWrite(bluePin,HIGH); break;
 case CENTER : digitalWrite(whiteCenterPin,HIGH); break;
 case GROUP1 : digitalWrite(whiteGroup1Pin,HIGH); break;
 case GROUP2 : digitalWrite(whiteGroup2Pin,HIGH); break;
 case GROUP3 : digitalWrite(whiteGroup3Pin,HIGH); break;
 case GROUP4 : digitalWrite(whiteGroup4Pin,HIGH); break;
 
 case ALL_COLOR :
  digitalWrite(redPin,HIGH);
digitalWrite(bluePin,HIGH);
digitalWrite(yellowPin,HIGH);
digitalWrite(greenPin,HIGH);
break;    


 case RED_BLUE :
  digitalWrite(redPin,HIGH);
digitalWrite(bluePin,HIGH);
break;    


 case YELLOW_GREEN :
digitalWrite(yellowPin,HIGH);
digitalWrite(greenPin,HIGH);
break;    
    
 case ALL_WHITE  :
 digitalWrite(whiteCenterPin,HIGH);
digitalWrite(whiteGroup1Pin,HIGH);
digitalWrite(whiteGroup2Pin,HIGH);
digitalWrite(whiteGroup3Pin,HIGH);
digitalWrite(whiteGroup4Pin,HIGH);
break;
    
 case ALL_GROUPS :
digitalWrite(whiteGroup1Pin,HIGH);
digitalWrite(whiteGroup2Pin,HIGH);
digitalWrite(whiteGroup3Pin,HIGH);
digitalWrite(whiteGroup4Pin,HIGH);
break;

 case LEFT_SIDE   :
digitalWrite(whiteGroup1Pin,HIGH);
digitalWrite(whiteGroup3Pin,HIGH);
break;
 
 case RIGHT_SIDE   :
digitalWrite(whiteGroup2Pin,HIGH);
digitalWrite(whiteGroup4Pin,HIGH);
break;


 case DIAGONAL_UP   :
digitalWrite(whiteGroup2Pin,HIGH);
digitalWrite(whiteGroup3Pin,HIGH);
break;
 
 case DIAGONAL_DOWN   :
digitalWrite(whiteGroup1Pin,HIGH);
digitalWrite(whiteGroup4Pin,HIGH);
break;
 
 case ALL :
    digitalWrite(redPin,HIGH);
digitalWrite(bluePin,HIGH);
digitalWrite(yellowPin,HIGH);
digitalWrite(greenPin,HIGH);
digitalWrite(whiteCenterPin,HIGH);
digitalWrite(whiteGroup1Pin,HIGH);
digitalWrite(whiteGroup2Pin,HIGH);
digitalWrite(whiteGroup3Pin,HIGH);
digitalWrite(whiteGroup4Pin,HIGH);
   break;
  }   
}

void off(int led)
{
  switch(led)
  {
case YELLOW : digitalWrite(yellowPin,LOW); break;
 case GREEN : digitalWrite(greenPin,LOW); break;
 case RED   : digitalWrite(redPin,LOW); break;
 case BLUE  : digitalWrite(bluePin,LOW); break;
 case CENTER : digitalWrite(whiteCenterPin,LOW); break;
 case GROUP1 : digitalWrite(whiteGroup1Pin,LOW); break;
 case GROUP2 : digitalWrite(whiteGroup2Pin,LOW); break;
 case GROUP3 : digitalWrite(whiteGroup3Pin,LOW); break;
 case GROUP4 : digitalWrite(whiteGroup4Pin,LOW); break;

 case RED_BLUE :
  digitalWrite(redPin,LOW);
digitalWrite(bluePin,LOW);
break;    


 case YELLOW_GREEN :
digitalWrite(yellowPin,LOW);
digitalWrite(greenPin,LOW);
break;    

 
 case ALL_COLOR :
  digitalWrite(redPin,LOW);
digitalWrite(bluePin,LOW);
digitalWrite(yellowPin,LOW);
digitalWrite(greenPin,LOW);
break;    
    
 case ALL_WHITE :
 digitalWrite(whiteCenterPin,LOW);
digitalWrite(whiteGroup1Pin,LOW);
digitalWrite(whiteGroup2Pin,LOW);
digitalWrite(whiteGroup3Pin,LOW);
digitalWrite(whiteGroup4Pin,LOW);
break;
    
 case ALL_GROUPS :
digitalWrite(whiteGroup1Pin,LOW);
digitalWrite(whiteGroup2Pin,LOW);
digitalWrite(whiteGroup3Pin,LOW);
digitalWrite(whiteGroup4Pin,LOW);
break;

 case LEFT_SIDE   :
digitalWrite(whiteGroup1Pin,LOW);
digitalWrite(whiteGroup3Pin,LOW);
break;
 
 case RIGHT_SIDE   :
digitalWrite(whiteGroup2Pin,LOW);
digitalWrite(whiteGroup4Pin,LOW);
break;


 case DIAGONAL_UP   :
digitalWrite(whiteGroup2Pin,LOW);
digitalWrite(whiteGroup3Pin,LOW);
break;
 
 case DIAGONAL_DOWN   :
digitalWrite(whiteGroup1Pin,LOW);
digitalWrite(whiteGroup4Pin,LOW);
break;
 
 case ALL :
    digitalWrite(redPin,LOW);
digitalWrite(bluePin,LOW);
digitalWrite(yellowPin,LOW);
digitalWrite(greenPin,LOW);
digitalWrite(whiteCenterPin,LOW);
digitalWrite(whiteGroup1Pin,LOW);
digitalWrite(whiteGroup2Pin,LOW);
digitalWrite(whiteGroup3Pin,LOW);
digitalWrite(whiteGroup4Pin,LOW);
   break;
  }   
}

void flash(int led, int rep, int del)
{
  for(int j=0;j<rep;j++)
  {
    on(led);
    delay(del);
    off(led);
    delay(del);
  }
}

void bam(int led, int rep, int del1, int del2)
{
  for(int j=0;j<rep;j++)
  {
    on(led);
    delay(del1);
    off(led);
    delay(del2);
  }
}

void beat()
{
  delay(100);
}

void sec()
{
  delay(1000);
}

void writeValue(int color, byte value)
{
    switch(color)
    {
      case ALL_WHITE :
    analogWrite(whiteCenterPin, value);
    analogWrite(whiteGroup1Pin, value);
    analogWrite(whiteGroup2Pin, value);
    analogWrite(whiteGroup3Pin, value);
    analogWrite(whiteGroup4Pin, value);
    break;

    case ALL_GROUPS :
    analogWrite(whiteGroup1Pin, value);
    analogWrite(whiteGroup2Pin, value);
    analogWrite(whiteGroup3Pin, value);
    analogWrite(whiteGroup4Pin, value);
    break;

    case RED :
    analogWrite(redPin, value);
    break;

    case CENTER :
    analogWrite(whiteCenterPin, value);
    break;

     case DIAGONAL_UP   :
analogWrite(whiteGroup2Pin,value);
analogWrite(whiteGroup3Pin,value);
break;
 
 case DIAGONAL_DOWN   :
analogWrite(whiteGroup1Pin,value);
analogWrite(whiteGroup4Pin,value);
break;
    }  
}

void slideOn(int color, int inc){
  for (int value = 0 ; value < 255; value+=inc){
    writeValue(color,value);
    delay(30); 
  } 
}
 
void slideOff(int color, int dec){
  for (int value = 255; value >0; value-=dec){
    writeValue(color,value);
    delay(30); 
  }

  off(ALL);
}

void wow(int color, int veloc, int del)
{
  slideOn(color,veloc);
  delay(del);
  slideOff(color,veloc);
}

void testLed()
{
  off(ALL);
  
  wow(RED,5,0);
  delay(500);
  wow(ALL_GROUPS,5,0);
  delay(500);
  wow(ALL_WHITE,5,0);
  delay(500);
  
  for(int i=YELLOW;i<ALL+1;i++)
  {
    on(i);
    sec();
    off(i);
  }

  for(int i=YELLOW;i<ALL+1;i++)
  {
    flash(i,25,20);
  }

  for(int i=YELLOW;i<ALL+1;i++)
  {
    bam(i,2,50,450);
  }

}

void countDown()
{
  off(ALL);

  //on(ALL_WHITE);

  lcd.clear();

  cPrint(0,"Get Ready!");

  lcd.setCursor(5,1);

  lcd.print("1");

  delay(1000);

  off(GROUP1);

  lcd.print("2");

  delay(1000);

  off(GROUP2);

  lcd.print("3");

  delay(1000);

  off(GROUP3);

  lcd.print("4");

    delay(1000);

  off(GROUP4);

  lcd.print("5");

  delay(1000);

  off(ALL);

  delay(500);

  lcd.clear();

  cPrint(0,"Go go go!!!");

  delay(500);

  lcd.clear();

  lcd.noBacklight();
}

void nothingElseMatters()
{
   countDown();

   if(joyMoved()) return;

   wow(ALL_GROUPS,3,0);
   wow(CENTER,3,0);
   wow(ALL_GROUPS,3,0);
   wow(CENTER,3,0);
   on(BLUE);
   wow(DIAGONAL_UP,3,0);
   on(RED);
   wow(DIAGONAL_DOWN,3,0);
   on(YELLOW);
   wow(DIAGONAL_UP,3,0);
   on(GREEN);
   wow(DIAGONAL_DOWN,3,0);
   wow(ALL_GROUPS,3,0);
   wow(RED,3,0);
   wow(ALL_WHITE,2,0);

   delay(800);
   on(BLUE);
   delay(500);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   off(BLUE);
   on(RED);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   off(RED);
      on(YELLOW);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   off(YELLOW);
   on(GREEN);
   bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(CENTER,2,50,450);
   off(GREEN);
   on(RED_BLUE);
      bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(CENTER,2,50,450);
   off(RED_BLUE);
   on(YELLOW_GREEN);
      bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(CENTER,2,50,450);
   off(YELLOW_GREEN);   
       on(BLUE);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   off(BLUE);
   on(RED);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   off(RED);
      on(YELLOW);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   off(YELLOW);
   on(GREEN);
   bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(CENTER,2,50,450);
   off(GREEN);
   on(RED_BLUE);
      bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(CENTER,2,50,450);
   off(RED_BLUE);
   on(YELLOW_GREEN);
      bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(CENTER,2,50,450);
   off(YELLOW_GREEN);
      on(BLUE);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   off(BLUE);

   delay(700);
   
   on(RED);

    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(BLUE);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(GREEN);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(YELLOW);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    off(ALL);
    flash(ALL_WHITE,30,20);

on(RED);

    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(BLUE);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(GREEN);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(YELLOW);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    off(ALL);
    flash(ALL_WHITE,30,20);

   on(RED);

    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(BLUE);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(GREEN);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(YELLOW);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    off(ALL);
    flash(ALL_WHITE,20,20);
   flash(ALL,30,20);


  // end of first refrain
   
   on(BLUE);
   delay(500);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   off(BLUE);
   on(RED);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   off(RED);
      on(YELLOW);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   off(YELLOW);
   on(GREEN);
   bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(CENTER,2,50,450);
   off(GREEN);

// second refrain

      flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(BLUE);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(GREEN);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(YELLOW);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    off(ALL);
    flash(ALL_WHITE,30,20);

on(RED);

    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(BLUE);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(GREEN);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(YELLOW);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    off(ALL);

       on(RED);

    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(BLUE);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(GREEN);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(YELLOW);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    off(ALL);
    flash(ALL_WHITE,20,20);
   flash(ALL,30,20);

   // end of second refrain

      wow(ALL_GROUPS,3,0);
   wow(CENTER,3,0);
   wow(ALL_GROUPS,3,0);
   wow(CENTER,3,0);
   on(BLUE);
   wow(DIAGONAL_UP,3,0);
   on(RED);
   wow(DIAGONAL_DOWN,3,0);
   on(YELLOW);
   wow(DIAGONAL_UP,3,0);
   on(GREEN);
   wow(DIAGONAL_DOWN,3,0);

   
  // end of bridge

   delay(800);
   on(BLUE);
   delay(500);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   off(BLUE);
   on(RED);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   off(RED);
      on(YELLOW);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   off(YELLOW);
   on(GREEN);
   bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(CENTER,2,50,450);
   off(GREEN);
   on(RED_BLUE);
      bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(CENTER,2,50,450);
   off(RED_BLUE);
   on(YELLOW_GREEN);
      bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(DIAGONAL_UP,2,50,450);
   bam(DIAGONAL_DOWN,2,50,450);
   bam(CENTER,2,50,450);
   off(YELLOW_GREEN);   
       on(BLUE);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   off(BLUE);
   on(RED);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   off(RED);
      on(YELLOW);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   bam(ALL_WHITE,2,50,450);
   //bam(ALL_WHITE,2,50,450);
   //bam(ALL_WHITE,2,50,450);
   off(YELLOW);

  // third refrain

      flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(BLUE);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(GREEN);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(YELLOW);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    off(ALL);
    flash(ALL_WHITE,30,20);

on(RED);

    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(BLUE);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(GREEN);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(YELLOW);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    off(ALL);

       on(RED);

    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(BLUE);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(GREEN);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(YELLOW);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    off(ALL);
    flash(ALL_WHITE,20,20);
   flash(ALL,30,20);

          on(RED);

    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(BLUE);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(GREEN);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(YELLOW);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    off(ALL);
    flash(ALL_WHITE,20,20);
   flash(ALL,30,20);

          on(RED);

    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(BLUE);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(GREEN);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(YELLOW);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    off(ALL);
    flash(ALL_WHITE,20,20);
   flash(ALL,30,20);

          on(RED);

    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(BLUE);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(GREEN);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(YELLOW);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    off(ALL);
    flash(ALL_WHITE,20,20);
   flash(ALL,30,20);

             on(RED);

    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(BLUE);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(GREEN);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    on(YELLOW);
    flash(DIAGONAL_UP,15,20);
    flash(DIAGONAL_DOWN,15,20);
    off(ALL);
    flash(ALL_WHITE,20,20);
   flash(ALL,30,20);

   // end of third refrain

  on(ALL);
         wow(ALL_GROUPS,3,0);
  off(ALL);
   wow(CENTER,3,0);
   wow(ALL_GROUPS,3,0);
   wow(CENTER,3,0);
   on(BLUE);
   wow(DIAGONAL_UP,3,0);
   on(RED);
   wow(DIAGONAL_DOWN,3,0);
   on(YELLOW);
   wow(DIAGONAL_UP,3,0);
   on(GREEN);
   wow(DIAGONAL_DOWN,3,0);

         wow(ALL_GROUPS,3,0);
   wow(CENTER,3,0);
   wow(ALL_GROUPS,3,0);
   wow(CENTER,3,0);
   on(BLUE);
   wow(CENTER,3,0);
   off(BLUE);
   wow(CENTER,3,0);
   
   off(ALL);

   delay(1000);
    
   lcd.backlight();
}

void loveOfMyLife()
{
  countDown();

  if(joyMoved()) return;

  lcd.backlight();
}

void carryOnMyWaywardSon()
{
  countDown();

  if(joyMoved()) return;

  lcd.backlight();
}

void ImComingOut()
{
  countDown();

  if(joyMoved()) return;

  lcd.backlight();
}

String getMusicDesc(int music, int line)
{
  switch(music)
  {
    case 0 : if(line==0)
                return("Metallica");
                else
                return("Nothing else");
    case 1 : if(line==0)
                return("Queen");
                else
                return("Love of my life");
    case 2 : if(line==0)
                return("Kansas");
                else
                return("Carry on");
    case 3 : if(line==0)
                return("Donna Summer");
                else
                return("I'm coming out");
    case 4 : if(line==0)
                return("* Fim da lista *");
                else
                return("Voltar?");
  }
}

String getFunc(int func)
{
  switch(func)
  {
    case 0 : return "> Music <";
    case 1 : return "> Demo <";
    case 2 : return "> Sensor <";
  }
}

int joyPos()
{
   int valX = analogRead(joyX);
   int valY = analogRead(joyY);

   if(valY<200) return UP;
   if(valY>800) return DOWN;
   if(valX<200) return RIGHT;
   if(valX>800) return LEFT;
}

boolean joyMoved()
{
  int valX = 0;
  int valY = 0;

  valX = analogRead(joyX);
  valY = analogRead(joyY);

  if(valX>800 || valX<200 || valY>800 || valY<200)
    return true;

  return false;
}

void byNoise()
{
  int noiseA = 0;
  int noiseD = 0;

  while(joyMoved()==false)
  {
     noiseA = analogRead(soundSensorAnalogPin);
     noiseD = digitalRead(soundSensorDigitalPin);    
  }
}

void printMusic(int music)
{
  String aux1 = getMusicDesc(music,0);
  String aux2 = getMusicDesc(music,1);
  
  lcd.clear();

  cPrint(0,aux1);
  cPrint(1,aux2);
}

void printMain(int pos)
{
  cPrint(0,"<< Lightoino >>");

  String aux = getFunc(pos);
  
  cPrint(1,aux);
}

void navigation()
{
  int mainPos = 0;
  int subPos = 0;

  boolean inMain = true;
  
  const int MUSIC = 0;
  const int DEMO = 1;
  const int SENSOR = 2; 

  int valX = 0;
  int valY = 0;
 
  lcd.clear();

  cPrint(0,"<< Lightoino >>");
  cPrint(1,"> Music <");

  while(true)
  {
    if(joyMoved())
    {
      if(inMain)
      {
        
        switch(joyPos())
        {
          case DOWN : if(mainPos<2) mainPos++; break;
          case UP : if(mainPos>0) mainPos--; break;
          case RIGHT : if(mainPos==MUSIC) 
                        {
                          printMusic(0);
                          subPos=0;
                          inMain=false;
                        }
                        else if(mainPos==DEMO)
                        {
                          testLed();
                        } else byNoise();
        }

        lcd.clear();

        
      } else
      {
        
        
        switch(joyPos())
        {
          case DOWN : if(subPos<4) subPos++; break;
          case UP : if(subPos>0) subPos--; break;
          case RIGHT : switch(subPos)
                        {
                          case 0 : nothingElseMatters(); break;
                          case 1 : loveOfMyLife(); break;
                          case 2 : carryOnMyWaywardSon(); break;
                          case 3 : ImComingOut(); break;
                          case 4 : inMain=true;
                                    mainPos=0;
                                    break;
                        }
        }

            

      }
    
    if(inMain)
    {

      printMain(mainPos);

    } else
    {
      printMusic(subPos);
    }

    while(joyMoved());
    

    }

    /* lcd.setCursor(0,0);

    lcd.print(valX); lcd.print("     ");

    
    lcd.setCursor(0,1);

    lcd.print(valY); lcd.print("     ");

    switch(joyPos()) */
  }
}
 
void loop()
{
  navigation();
}
