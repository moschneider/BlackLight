#include <Wire.h>                     // usando a biblioteca Wire
#include <LiquidCrystal_I2C.h>        // usando a biblioteca LiquidCrystal I2C
#include <CuteBuzzerSounds.h>
 
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Configura endereço I2C e display com 16 caracteres e 2 linhas 
int thisChar = 0 ;

const int MAX_MUSiC = 3;

const int ARRAY_END = 123;

const int NIL   = 99;

const int UP    = 0;
const int DOWN  = 1;
const int LEFT  = 2;
const int RIGHT = 3;
const int BUTTON = 4;
const int NONE = 5;

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

int soundSensorAnalogPin  = A0;
int soundSensorDigitalPin = 7;

int joyX = A2;
int joyY = A3;
int joyZ = 8;

int buzzerPin            = 12;  

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

cute.init(buzzerPin);

cute.play(S_CONNECTION);

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
  cPrint(0,"BlackLight 1.0");
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

void backLightFlash(String txt, int rep, int del)
{
  lcd.clear();

  cPrint(0,"!! BlackLight !!");
  cPrint(1,txt);
  
  for(int j=0;j<rep;j++)
  {
    lcd.backlight();
    delay(del);
    lcd.noBacklight();
    delay(del);
  }

  lcd.clear();
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

void spark(int led, int repFlash, int repBam, int delFlash, int delBam)
{
  for(int j=0;j<repBam;j++)
  {
    for(int j=0;j<repFlash;j++)
    {
      on(led);
      delay(delFlash);
      off(led);
      delay(delFlash);
    }
   
    delay(delBam);
  
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

void colorCircle(int rep, int del)
{
  for(int i=0;i<rep;i++)
  {
    on(RED);
    delay(del);
    off(RED);

    on(YELLOW);
    delay(del);
    off(YELLOW);

    on(GREEN);
    delay(del);
    off(GREEN);

    on(BLUE);
    delay(del);
    off(BLUE);

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

void wowAndColor(int wowA[], int colorA[], int veloc, int del)
{
  int pos=0;

  while(wowA[pos]!=ARRAY_END && colorA[pos]!=ARRAY_END)
  {
    on(colorA[pos]);

    wow(wowA[pos],veloc,del);

    off(colorA[pos]);
    
    pos++;
  }
  
}

void sWowAC(int wowA[], int colorA[])
{
  wowAndColor(wowA,colorA,5,0);
}

void standardWow(int led)
{
  wow(led,5,0);
}

void flashAndColor(int flashA[], int colorA[], int rep, int del)
{
  int pos=0;

  while(flashA[pos]!=ARRAY_END && colorA[pos]!=ARRAY_END)
  {
    on(colorA[pos]);

    flash(flashA[pos],rep ,del);

    off(colorA[pos]);
    
    pos++;
  }
  
}

void sFlashAC(int flashA[], int colorA[], int rep)
{
  flashAndColor(flashA,colorA,rep,20);
}

void standardFlash(int led, int rep)
{
  flash(led,rep,20);
}

void bamAndColor(int bamA[], int colorA[], int rep, int del1, int del2)
{
  int pos=0;

  while(bamA[pos]!=ARRAY_END && colorA[pos]!=ARRAY_END)
  {
    on(colorA[pos]);

    bam(bamA[pos],rep,del1,del2);

    off(colorA[pos]);
    
    pos++;
  }
  
}

void sBamAC(int bamA[], int colorA[], int rep)
{
  bamAndColor(bamA,colorA,rep,50,450);
}

void standardBam(int led, int rep)
{
   bam(led,rep,50,450);
}


void sparkAndColor(int sparkA[], int colorA[], int repFlash, int repBam, int delFlash, int delBam)
{
  int pos=0;

  while(sparkA[pos]!=ARRAY_END && colorA[pos]!=ARRAY_END)
  {
    on(colorA[pos]);

    spark(sparkA[pos], repFlash, repBam, delFlash, delBam);

    off(colorA[pos]);
    
    pos++;
  }
  
}

void sSparkAC(int sparkA[], int colorA[], int rep)
{
  sparkAndColor(sparkA, colorA,3,rep,20,450);
}

void standardSpark(int led, int rep)
{
  spark(led,3,rep,20,450);
}

void testLed()
{
  off(ALL);

  backLightFlash("Rock!!!",50,20);

  colorCircle(3,300);

  colorCircle(5,150);

  colorCircle(10,50);
  
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

  for(int i=YELLOW;i<ALL+1;i++)
  {
    spark(i,3,5,20,450);
  }

  backLightFlash("Rock!!!",50,20);

  lcd.backlight();
}

void countDown()
{
  on(ALL_WHITE);

  lcd.clear();

  cPrint(0,"Get Ready!");

  lcd.setCursor(8,1);

  lcd.print("5");

  cute.play(S_HAPPY_SHORT);

  delay(1000);

  off(GROUP1);

  lcd.setCursor(7,1);

  lcd.print("<4>");

  cute.play(S_HAPPY_SHORT);

  delay(1000);

  off(GROUP2);

  lcd.setCursor(6,1);

  lcd.print("< 3 >");

  cute.play(S_HAPPY_SHORT);

  delay(1000);

  off(GROUP3);

  lcd.setCursor(5,1);

  lcd.print("<  2  >");

  cute.play(S_HAPPY_SHORT);

  delay(1000);

  off(GROUP4);

  lcd.setCursor(4,1);

  lcd.print("<   1   >");

  cute.play(S_HAPPY_SHORT);

  delay(1000);

  off(ALL);

  delay(500);

  lcd.clear();

  cPrint(0,"!!! GO !!!");

    lcd.setCursor(3,1);

  lcd.print("< < <0> > >");

  cute.play(S_DISCONNECTION);

  delay (500);

  lcd.clear();

  lcd.noBacklight();
}

void nothingElseMatters()
{
   countDown();

   if(joyMoved()) 
   {
    lcd.backlight();
    return;
   }

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

void oneFlash()
{
  on(ALL_WHITE); beat(); off(ALL_WHITE);
}

void allFlash()
{
  on(ALL); beat(); off(ALL);
}

void loveOfMyLife()
{
  // https://www.youtube.com/watch?v=2bqm4gRY3mA
  
  countDown();

  if(joyMoved()) 
  {
    lcd.backlight();
    return;
  }

  colorCircle(7,250);

  oneFlash();

  colorCircle(13,250);

  oneFlash();

  for(int i=0;i<3;i++)
  {

    wow(CENTER,5,0);
  
    oneFlash();
  
    wow(RED,5,0);
  
    oneFlash();
  
    wow(DIAGONAL_DOWN,5,0);
  
    oneFlash();
  
    wow(DIAGONAL_UP,5,0);
  
    oneFlash();

  }

  colorCircle(15,50);

  colorCircle(15,25);

  oneFlash();

  for(int i=0;i<4;i++)
  {

    int f[] = {ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ARRAY_END};
    int c[] = {RED,BLUE,GREEN,YELLOW,ARRAY_END};
  
    bamAndColor(f,c,3,50,650);

  }

  for(int i=0;i<3;i++)
  {

    wow(CENTER,5,0);
  
    oneFlash();
  
    wow(RED,5,0);
  
    oneFlash();
  
    wow(DIAGONAL_DOWN,5,0);
  
    oneFlash();
  
    wow(DIAGONAL_UP,5,0);
  
    oneFlash();

  }

  sec();

  allFlash();

  sec();

   colorCircle(15,50);

  colorCircle(15,25);

  oneFlash();

  for(int i=0;i<3;i++)
  {

    int f[] = {ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ARRAY_END};
    int c[] = {RED,BLUE,GREEN,YELLOW,ARRAY_END};
  
    bamAndColor(f,c,3,50,650);

  }

  for(int i=0;i<20;i++)
  {
    allFlash();

    delay(250);
  }

  
  for(int i=0;i<2;i++)
  {

    wow(CENTER,5,0);
  
    oneFlash();
  
    wow(RED,5,0);
  
    oneFlash();
  
    wow(DIAGONAL_DOWN,5,0);
  
    oneFlash();
  
    wow(DIAGONAL_UP,5,0);
  
    oneFlash();

  }

  colorCircle(15,100);

  colorCircle(15,50);

  wow(CENTER,5,0);

  delay(3000);
  
  lcd.backlight();
}

void carryOnMyWaywardSon()
{

  // https://www.youtube.com/watch?v=P5ZJui3aPoQ
  
  countDown();

  if(joyMoved()) 
  {
    lcd.backlight();
    return;
  }

  backLightFlash("K A N S A S", 18, 450);

  on(ALL);

  delay(500);

  off(ALL);

  for(int i=0;i<6;i++)
  {
    colorCircle(3,100);

    flash(ALL_GROUPS,2,200);
  }

  for(int i=0;i<8;i++)
  {

    flash(DIAGONAL_DOWN,2,200);

    flash(DIAGONAL_UP,2,200);
  }
  
  for(int i=0;i<7;i++)
  {
    colorCircle(3,100);

    flash(ALL_GROUPS,2,200);
  }

  for(int i=0;i<5;i++)
  {

    flash(DIAGONAL_DOWN,2,200);

    flash(DIAGONAL_UP,2,200);
  }

  wow(ALL_WHITE,4,800);

  flash(CENTER,26,300);

    for(int i=0;i<6;i++)
  {

    flash(DIAGONAL_DOWN,2,300);

    flash(DIAGONAL_UP,2,300);
  }

    for(int i=0;i<10;i++)
  {

    int f[] = {ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ARRAY_END};
    int c[] = {RED,BLUE,GREEN,YELLOW,ARRAY_END};
  
    flashAndColor(f,c,3,50);

  }

  on(ALL);

  delay(500);

  off(ALL);

    for(int i=0;i<8;i++)
  {

    flash(DIAGONAL_DOWN,2,200);

    flash(DIAGONAL_UP,2,200);
  }

  flash(RED,26,300);

  on(ALL_GROUPS);

  flash(BLUE,26,300);

      for(int i=0;i<10;i++)
  {

    int f[] = {ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ARRAY_END};
    int c[] = {RED,BLUE,GREEN,YELLOW,ARRAY_END};
  
    flashAndColor(f,c,3,50);

  }

  on(ALL);

  delay(500);

  off(ALL);

  on(RED);

  for(int i=0;i<8;i++)
  {

    flash(DIAGONAL_DOWN,2,200);

    flash(DIAGONAL_UP,2,200);
  }

  off(RED);

  on(BLUE);

  for(int i=0;i<8;i++)
  {

    flash(DIAGONAL_DOWN,2,200);

    flash(DIAGONAL_UP,2,200);
  }

  off(BLUE);

  on(RED);

    for(int i=0;i<8;i++)
  {

    flash(DIAGONAL_DOWN,2,200);

    flash(DIAGONAL_UP,2,200);
  }

  off(RED);

  on(BLUE);

  for(int i=0;i<5;i++)
  {

    flash(DIAGONAL_DOWN,2,200);

    flash(DIAGONAL_UP,2,200);
  }

  off(BLUE);

  for(int i=0;i<6;i++)
  {
    colorCircle(3,100);

    flash(ALL_GROUPS,2,200);
  }

      for(int i=0;i<6;i++)
  {

    flash(DIAGONAL_DOWN,2,300);

    flash(DIAGONAL_UP,2,300);
  }

    for(int i=0;i<10;i++)
  {

    int f[] = {ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ARRAY_END};
    int c[] = {RED,BLUE,GREEN,YELLOW,ARRAY_END};
  
    flashAndColor(f,c,3,50);

  }

  on(ALL);

  delay(500);

  off(ALL);

  for(int i=0;i<7;i++)
  {

    flash(DIAGONAL_DOWN,2,300);

    flash(DIAGONAL_UP,2,300);
  }

  
  for(int i=0;i<6;i++)
  {
    colorCircle(3,100);

    flash(ALL_GROUPS,2,200);
  }

    for(int i=0;i<7;i++)
  {

    flash(DIAGONAL_DOWN,2,300);

    flash(DIAGONAL_UP,2,300);
  }

    for(int i=0;i<7;i++)
  {
    colorCircle(3,100);

    flash(ALL_GROUPS,2,200);
  }

  wow(ALL_WHITE,4,800);

  delay(3000);

  lcd.backlight();
}

void ImComingOut()
{

  // https://www.youtube.com/watch?v=zbYcte4ZEgQ
  
  countDown();

  if(joyMoved())
  {
    lcd.backlight();
    return;
  }

  bam(CENTER,10,50,450);

  for(int i=0;i<4;i++)
  {

    allFlash();
  
    bam(GROUP1,5,50,450);
  
    allFlash();
  
    bam(GROUP2,5,50,450);
  
    allFlash();
  
    bam(GROUP3,5,50,450);
  
    allFlash();
  
    bam(GROUP4,5,50,450);

    colorCircle(10,25);
  }

  colorCircle(10,15);

  
  for(int i=0;i<4;i++)
  {

    int f[] = {ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ARRAY_END};
    int c[] = {RED_BLUE,YELLOW_GREEN,RED_BLUE,YELLOW_GREEN,ARRAY_END};
  
    bamAndColor(f,c,2,50,500);
  }

  for(int i=0;i<6;i++)
  {

    int f[] = {ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ARRAY_END};
    int c[] = {RED,BLUE,GREEN,YELLOW,ARRAY_END};
  
    bamAndColor(f,c,2,50,500);

  }

  //colorCircle(20,25);

  for(int i=0;i<16;i++)
  {
    int f[] = {DIAGONAL_DOWN,DIAGONAL_UP,ALL_GROUPS,ALL_GROUPS,ARRAY_END};
    int c[] = {RED,BLUE,RED,BLUE,ARRAY_END};

    flashAndColor(f,c,10,27);

    delay(40);
  
  }

    for(int i=0;i<4;i++)
  {

    int f[] = {ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ARRAY_END};
    int c[] = {RED,BLUE,GREEN,YELLOW,ARRAY_END};
  
    bamAndColor(f,c,3,50,500);

  }

    for(int i=0;i<16;i++)
  {
    int f[] = {DIAGONAL_DOWN,DIAGONAL_UP,ALL_GROUPS,ALL_GROUPS,ARRAY_END};
    int c[] = {GREEN,YELLOW,GREEN,YELLOW,ARRAY_END};

    flashAndColor(f,c,10,27);

    delay(40);
  
  }

    for(int i=0;i<12;i++)
  {
    int f[] = {ALL_WHITE,ALL_WHITE,ALL_WHITE,ALL_WHITE,ARRAY_END};
    int c[] = {YELLOW_GREEN,RED_BLUE,YELLOW_GREEN,RED_BLUE,ARRAY_END};

    flashAndColor(f,c,10,27);

    delay(40);
  
  }

  
  for(int i=0;i<8;i++)
  {

    allFlash();
  
    bam(GROUP1,5,50,450);
  
    allFlash();
  
    bam(GROUP2,5,50,450);
  
    allFlash();
  
    bam(GROUP3,5,50,450);
  
    allFlash();
  
    bam(GROUP4,5,50,450);

    colorCircle(10,25);
  }

  colorCircle(30,15);

  wow(CENTER,5,0);

  wow(RED,5,0);

  delay(3000);

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
                return("Diana Ross");
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
    case 0 : return "> Beats <";
    case 1 : return "> Sensor <";
    case 2 : return "> Music <";
    case 3 : return "> Demo <";
  }
}

int joyPos()
{
   int valX = analogRead(joyX);
   int valY = analogRead(joyY);
   //int valZ = digitalRead(joyZ);

   if(valY<200) return UP;
   if(valY>800) return DOWN;
   if(valX<200) return RIGHT;
   if(valX>800) return LEFT;
   //if(valZ==1) return BUTTON;

   return NONE;
}

boolean joyMoved()
{
  int valX = 0;
  int valY = 0;
  //int valZ = 0;

  valX = analogRead(joyX);
  valY = analogRead(joyY);
  //valZ = digitalRead(joyZ);

  if(valX>800 || valX<200 || valY>800 || valY<200)
    return true;

  return false;
}

void effect0()
{
  off(ALL);
}

void effect1()
{
  wow(CENTER,25,400);
}

void effect2()
{
  off(ALL);

  for(int i=0;i<2;i++)
  {
    on(BLUE);

    delay(250);

    off(BLUE);

    delay(250);
    
  }

  on(BLUE);
}

void effect3()
{
  on(LEFT_SIDE);

  delay(250);

  off(LEFT_SIDE);

  delay(250);

  on(RIGHT_SIDE);

  delay(250);

  off(RIGHT_SIDE);

  delay(250);
}

void effect4()
{
  off(ALL);

    for(int i=0;i<2;i++)
  {
    on(RED);

    delay(250);

    off(RED);

    delay(250);
    
  }

  on(RED);
}

void effect5()
{
  on(DIAGONAL_UP);

  delay(250);

  off(DIAGONAL_UP);

  delay(250);

  on(DIAGONAL_DOWN);

  delay(250);

  off(DIAGONAL_DOWN);

  delay(250);  
}

void effect6()
{
  for(int i=0;i<2;i++)
  {
    on(CENTER);

    delay(250);

    off(CENTER);

    delay(250);
    
    on(ALL_GROUPS);

    delay(250);

    off(ALL_GROUPS);

    delay(250);
  }
}

void effect7()
{
  off(ALL);

  colorCircle(1,250);
}

void effect8()
{
  for(int i=0;i<4;i++)
  {
    on(ALL_WHITE);

    delay(150);

    off(ALL_WHITE);

    delay(100);
  }  
}

void effect9()
{
  off(ALL);

  for(int i=0;i<4;i++)
  {
    on(ALL_GROUPS);
    on(RED);

    delay(150);

    off(ALL_GROUPS);
    off(RED);

    delay(100);
  }
}

void effect10()
{
  off(ALL);

  for(int i=0;i<4;i++)
  {
    on(ALL);

    delay(150);

    off(ALL);

    delay(100);
  }
}

void byNoise()
{
  int noiseA = 0, minA = 2000, maxA = 0, rangeA = 0, offsetA = 0, tenPC = 0;
  int noiseD = 0;

  boolean tack = false;

  lcd.clear();

  while(joyMoved());

  int outTicks = 1000;

  cPrint(0,">>> Listening <<<");

  while(joyMoved()==false)
  {
     noiseA = analogRead(soundSensorAnalogPin);

    if(noiseA>maxA)
      maxA=noiseA;
    
    if(noiseA<minA)
      minA=noiseA;

     
     
     noiseD = digitalRead(soundSensorDigitalPin);    

     

     rangeA = maxA - minA;

     outTicks++;

     if(outTicks>1000)
     {

      cPrint(1,"      ");

     lcd.setCursor(7,1);

    lcd.print(rangeA);
     
     delay(1);

    outTicks=0;

     }
  }

  cPrint(1,"      ");

  cute.play(S_CONNECTION);

  rangeA = maxA - minA;

  offsetA = minA + rangeA / 2;

  tenPC = (maxA - offsetA) / 10;

   //averageA = minA + rangeA / 4;

   //th1A = minA + (rangeA / 5) * 4;

   //th2A = minA + (rangeA / 9) * 8;

   /*lcd.setCursor(0,0);

   lcd.print(minA);

   lcd.setCursor(6,0);

   lcd.print(rangeA);

   lcd.setCursor(12,0);

   lcd.print(averageA);

   lcd.setCursor(0,1);

   lcd.print(th1A);

   lcd.setCursor(6,1);

   lcd.print(th2A);

   lcd.setCursor(12,1);

   lcd.print(maxA);*/

   cPrint(0,">>> Playing <<<");

   while(joyMoved());

   lcd.setCursor(0,1);

   lcd.print(minA);

   lcd.setCursor(6,1);

   lcd.print(offsetA);

   lcd.setCursor(12,1);

   lcd.print(maxA);

   delay(2000);

   lcd.clear();

   lcd.noBacklight();

   int colTicks = 0, maxColTicks = 6, currentColor = YELLOW;

   while(joyMoved()==false)
   {
      noiseA = analogRead(soundSensorAnalogPin);

      if(noiseA<offsetA) effect0(); else
      if(noiseA<(offsetA+tenPC)) effect1(); else
      if(noiseA<(offsetA+tenPC*2)) effect2(); else
      if(noiseA<(offsetA+tenPC*3)) effect3(); else
      if(noiseA<(offsetA+tenPC*4)) effect4(); else
      if(noiseA<(offsetA+tenPC*5)) effect5(); else
      if(noiseA<(offsetA+tenPC*6)) effect6(); else
      if(noiseA<(offsetA+tenPC*7)) effect7(); else
      if(noiseA<(offsetA+tenPC*8)) effect8(); else
      if(noiseA<(offsetA+tenPC*9)) effect9(); else
      effect10();
   }

   //cute.play(S_CONNECTION);

  while(joyMoved());

  off(ALL);

  lcd.backlight();
}

void beats()
{
  int choice = 0;
  
  lcd.clear(); 
  
  cPrint(0,"<< Beats >>");

  cPrint(1,">1< .2. .3. .4.");

  int beatNum = 1, rate = 200;

  while(joyMoved())
    choice=joyPos();

  while(choice!=RIGHT)
  {
      if(choice==DOWN)
      {
        beatNum++;

        if(beatNum>4) beatNum = 4;

        choice=NONE;

        cute.play(S_BUTTON_PUSHED);

        while(joyMoved());
      } else
      if(choice==UP)
      {
        beatNum--;

        if(beatNum<1) beatNum=1;

        choice=NONE;

        cute.play(S_BUTTON_PUSHED);

        while(joyMoved());
      }

      switch(beatNum)
      {
        case 1: cPrint(1,">1< .2. .3. .4."); break;
        case 2: cPrint(1,".1. >2< .3. .4."); break;
        case 3: cPrint(1,".1. .2. >3< .4."); break;
        case 4: cPrint(1,".1. .2. .3. >4<"); break;
      }

      if(joyMoved())
        choice=joyPos();

  }

  lcd.clear();

  choice=NONE;

  cPrint(0,"<< Beats >>");

  cPrint(1,"< 400 / > 450");

  cute.play(S_BUTTON_PUSHED);

  while(joyMoved());

  while(!joyMoved());

  while(joyMoved() && choice==NONE)
    choice=joyPos();

  if(choice==LEFT)
    rate=400; else rate=450;

 cute.play(S_BUTTON_PUSHED);
    
  lcd.clear();

  cPrint(0,"<< Beats >>");

  lcd.setCursor(3,1);

  lcd.print(beatNum);

  lcd.setCursor(10,1);

  lcd.print(rate);

  delay(3000);

  lcd.noBacklight();

  while(joyMoved());

  boolean breakRequested = false;

  while(!joyMoved() && breakRequested==false)
  {
    switch(beatNum)
    {
    case 1: 

        {

        for(int i=0;i<2;i++)
        {

          int f[] = {ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ARRAY_END};
          int c[] = {RED,BLUE,GREEN,YELLOW,ARRAY_END};
  
          bamAndColor(f,c,2,50,rate);

          
        if(joyMoved()) 
        {
          lcd.backlight();
          breakRequested=true;
        }

        }

        colorCircle(rate/10,10);

        
        if(joyMoved()) 
        {
          lcd.backlight();
          breakRequested=true;
        }

        int f[] = {DIAGONAL_DOWN,DIAGONAL_UP,ALL_GROUPS,ALL_GROUPS,ARRAY_END};
        int c[] = {RED,BLUE,RED,BLUE,ARRAY_END};

        flashAndColor(f,c,10,rate/10);

        delay(rate/10);

        
        if(joyMoved()) 
        {
          lcd.backlight();
          breakRequested=true;
        }

        }

        break;
    
    case 2: 
    
    wow(CENTER,5,0);
  
    oneFlash();

    delay(450-rate);

    
        if(joyMoved()) 
        {
          lcd.backlight();
          breakRequested=true;
        }
  
    wow(RED,5,0);
  
    oneFlash();

    delay(450-rate);
  
    wow(DIAGONAL_DOWN,5,0);
  
    oneFlash();

    delay(450-rate);

    
        if(joyMoved()) 
        {
          lcd.backlight();
          breakRequested=true;
        }
  
    wow(DIAGONAL_UP,5,0);
  
    oneFlash();

    delay(450-rate);

  colorCircle(15,rate/10);

  colorCircle(15,rate/20);

  oneFlash();

  for(int i=0;i<4;i++)
  {

    int f[] = {ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ALL_GROUPS,ARRAY_END};
    int c[] = {RED,BLUE,GREEN,YELLOW,ARRAY_END};
  
    bamAndColor(f,c,3,50,rate);

    
        if(joyMoved()) 
        {
          lcd.backlight();
          breakRequested=true;
        }

  }

    
    break;
    
    case 3:   
    
    for(int i=0;i<2;i++)
  {
    colorCircle(3,rate/4);

    flash(ALL_GROUPS,2,rate/2);

    
        if(joyMoved()) 
        {
          lcd.backlight();
          breakRequested=true;
        }
  }

  for(int i=0;i<4;i++)
  {

    flash(DIAGONAL_DOWN,2,rate/2);

    flash(DIAGONAL_UP,2,rate/2);

    
        if(joyMoved()) 
        {
          lcd.backlight();
          breakRequested=true;
        }
  }
    
            break;
    
    case 4:      
 
   wow(ALL_GROUPS,3,0);
   on(BLUE);
      delay(450-rate);
   wow(DIAGONAL_UP,3,0);


        if(joyMoved()) 
        {
          lcd.backlight();
          breakRequested=true;
        }
   
   on(RED);
      delay(450-rate);
   wow(DIAGONAL_DOWN,3,0);
   on(YELLOW);
      delay(450-rate);
   wow(DIAGONAL_UP,3,0);
   on(GREEN);
      delay(450-rate);
   wow(DIAGONAL_DOWN,3,0);
      delay(450-rate);


        if(joyMoved()) 
        {
          lcd.backlight();
          breakRequested=true;
        }
      
   wow(ALL_GROUPS,3,0);
      delay(450-rate);
   wow(RED,3,0);
      delay(450-rate);
   wow(ALL_WHITE,2,0);
   delay(450-rate);
   delay(800);


        if(joyMoved()) 
        {
          lcd.backlight();
          breakRequested=true;
        }
   
   on(BLUE);
      delay(450-rate);
   delay(500);
   bam(ALL_WHITE,2,50,rate);
   bam(ALL_WHITE,2,50,rate);
   bam(ALL_WHITE,2,50,rate);
   bam(ALL_WHITE,2,50,rate);
   bam(ALL_WHITE,2,50,rate);
   off(BLUE);


        if(joyMoved()) 
        {
          lcd.backlight();
          breakRequested=true;
        }
    
    break;
    
    }
  }

  lcd.backlight();
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
  cPrint(0,"<< BlackLight >>");

  String aux = getFunc(pos);
  
  cPrint(1,aux);
}

void navigation()
{
  int mainPos = 0;
  int subPos = 0;

  boolean inMain = true;

  const int BEATS = 0;
  const int SENSOR = 1;
  const int MUSIC = 2;
  const int DEMO = 3; 

  int valX = 0;
  int valY = 0;
 


  while(true)
  {
  lcd.clear();

  cPrint(0,"<< BlackLight >>");

    
    if(inMain)
    {

      printMain(mainPos);

    } else
    {
      printMusic(subPos);
    }

  while(joyMoved());

while(!joyMoved());
      
    if(joyMoved())
    {
      if(inMain)
      {
        
        switch(joyPos())
        {
          case RIGHT : cute.play(S_BUTTON_PUSHED);
                        if(mainPos==MUSIC) 
                        {
                          printMusic(0);
                          subPos=0;
                          inMain=false;
                          mainPos=1;
                        }
                        else if(mainPos==DEMO)
                        {
                          testLed();
                          mainPos=2;
                        } else if(mainPos==BEATS)
                        {
                          beats();
                          mainPos=-1;
                        } else
                        {
                          byNoise();
                          mainPos=0;
                        }
          case DOWN : cute.play(S_BUTTON_PUSHED);
                      if(mainPos<3) mainPos++; break;
          case UP : cute.play(S_BUTTON_PUSHED);
                    if(mainPos>0) mainPos--; break;
          
        }

        lcd.clear();

        while(joyMoved());

        
      } else
      {
        
        
        switch(joyPos())
        {
          case RIGHT : cute.play(S_BUTTON_PUSHED);
                        switch(subPos)
                        {
                          case 0 : nothingElseMatters(); break;
                          case 1 : loveOfMyLife(); break;
                          case 2 : carryOnMyWaywardSon(); break;
                          case 3 : ImComingOut(); break;
                        }
          case LEFT : cute.play(S_BUTTON_PUSHED);
                      inMain = true;
                      mainPos = 2;
                      lcd.clear();
                      break;
          case DOWN : cute.play(S_BUTTON_PUSHED);
                      if(subPos<MAX_MUSiC) subPos++; break;
          case UP : cute.play(S_BUTTON_PUSHED);
                    if(subPos>0) subPos--; break;
          
        }

            

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
