#include <Keypad.h>

//Declaration des variables
int pinMoteur = 10;
const byte numRows = 4;
const byte numCols = 4;
String valStr = "";
String tmppass = "";
String codealcool = "0123";
int count = 0;
String drinkarray[] = {"10", "16", "20", "30", "40", "42", "43", "50", "52", "53", "70", "76", "80", "90"};

byte rowPins[numRows] = {9, 8, 7, 6}; //Rows 0 to 3
byte colPins[numCols] = {5, 4, 3, 2}; //Columns 0 to 3
char customKey;
char passkey;
char keymap[numRows][numCols] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

//Debut du programme
void setup()
{
  Serial.begin(9600);
}

int check_passwd()
{
  while (1) {
    passkey = myKeypad.getKey();
    if (passkey)
    {
      if (isDigit(passkey))
      {
        tmppass += passkey;
        count++;
      } else
        tmppass = "";
      if (count == 4)
      {
        if (tmppass == codealcool) {
          Serial.println("Good password");
          count = 0;
          tmppass = "";
          return (1);
        } else {
          Serial.println("Wrong password");
          count = 0;
          tmppass = "";
          return (0);
        }
      }
    }
  }
}

void drink(String valStr)
{
  count = 0;
  if (valStr == drinkarray[0])
    Serial.println("eau");

  else if (valStr == drinkarray[1])
    Serial.println("eau+sirop");

  else if (valStr == drinkarray[2])
    Serial.println("jus de pomme");

  else if (valStr == drinkarray[3])
    Serial.println("jus d'ananas");

  else if (valStr == drinkarray[4]) {
    Serial.println("Enter the password");
    if (check_passwd() == 1)
      Serial.println("vodka");
  }

  else if (valStr == drinkarray[5]) {
    Serial.println("Enter the password");
    if (check_passwd() == 1)
      Serial.println("vodka pomme");
  }

  else if (valStr == drinkarray[6]) {
    Serial.println("Enter the password");
    if (check_passwd() == 1)
      Serial.println("vodka ananas");
  }

  else if (valStr == drinkarray[7]) {
    Serial.println("Enter the password");
    if (check_passwd() == 1)
      Serial.println("malibu");
  }

  else if (valStr == drinkarray[8]) {
    Serial.println("Enter the password");
    if (check_passwd() == 1)
      Serial.println("malibu pomme");
  }

  else if (valStr == drinkarray[9]) {
    Serial.println("Enter the password");
    if (check_passwd() == 1)
      Serial.println("malibu ananas");
  }

  else if (valStr == drinkarray[10])
    Serial.println("lait froid");

  else if (valStr == drinkarray[11])
    Serial.println("lait froid+sirop");

  else if (valStr == drinkarray[12])
    Serial.println("eau chaude");

  else if (valStr == drinkarray[13])
    Serial.println("lait chaud");
}

void loop()
{
  customKey = myKeypad.getKey();

  if (customKey)
  {
    if (isDigit(customKey))
    {
      valStr += customKey;
      count++;
    } else {
      count = 0;
      valStr = "";
    }
  }

  if (count == 2)
  {
    drink(valStr);
    count = 0;
    valStr = "";
  }
}
