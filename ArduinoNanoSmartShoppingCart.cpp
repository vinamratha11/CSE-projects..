#include<Arduino.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
#include<string.h>

LiquidCrystal_I2C lcd(0X27,20,4);
int count=0;
char input[12];
double total=0;
int count_prod=0;
void setup()
{
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,1);
  lcd.print("Automatic Billing");
  delay(2000);
  lcd.setCursor(0,2);
  lcd.print("Shopping Cart");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Welcome to");
  lcd.setCursor(0,1);
  lcd.print("JSSATEB");
}
void loop()
{
  if(Serial.available())
  {
    count=0;
    while(Serial.available() && count<12)
    {
      input[count]=Serial.read();
      count++;
      delay(5);
    }
    if(input[0]=='4' && input[1]=='C' && input[2]=='0' && input[3]=='0' && input[4]=='3' && input[5]=='9' && input[6]=='0' && input[7]=='7' && input[8]=='9' && input[9]=='A' 
    && input[10]=='E' && input[11]=='8')
    {
        lcd.setCursor(0,0);
         lcd.print("Biscuits added ");
  lcd.setCursor(0,1);
lcd.print("price(Rs):4.00");
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
delay(1000);
total=total+4.00;
count_prod++;
digitalWrite(4 , LOW) ;
digitalWrite(5 , LOW) ;
}
if(input[0] == '4' && input[1] == '3' && input[2] == '0' && input[3] =='0' &&
   input[4] == '4' && input[5] == '3' && input[6] == 'B' && input[6] == 'B'  &&
   input[8] == '5' && input[9] == '4' && input[10] == 'E' && input[11] == 'F' )
{
  lcd.setCursor(0, 0);
    lcd.print("soap Added ");
    lcd.setCursor(0, 1);
    lcd.print("price(Rs) :6.00");
    digitalWrite(4 , HIGH);
    digitalWrite(5 , HIGH);
   delay(1000);
total = total + 6.00;
count_prod++;
digitalWrite(4 , LOW);
digitalWrite(5 , LOW);
}
if(input[0] == '4' && input[1] == '3' && input[2] == '0' && input[3] == '0' && 
  input[4] == '4' && input[5] == '3' && input[6] == 'D' && input[7] == '4' &&
  input[8] == '1' && input[9] == 'A' && input[10] == 'C' && input [11] == 'E' )
{
  lcd.clear();
 lcd.setCursor(0 , 0);
 digitalWrite(6 , HIGH);
 digitalWrite(5 , HIGH);
   delay(1000);
 lcd.print("Total Price :");
 lcd.print(total);
 digitalWrite(6, LOW);
 digitalWrite(5, LOW);
 
 delay(5000);
 lcd.clear();
 lcd.setCursor(0, 1);
 lcd.print(" THANKS FOR ");
 lcd.setCursor(0, 2);
 lcd.print ("   VISITING   ");
    }
  
  }

}
