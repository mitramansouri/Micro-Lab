#include <Arduino.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <string.h>

// Define Password
String saved_password = "1234";

// Dynamic Password 
String password = ""; //Hold pressed keys

// LCD
const int rs = 6, en = 5, d4 = 4, d5 = 3, d6 = 1, d7 = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// keypad
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
byte rowPins[ROWS] = {13, 12, 11, 10}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {9, 8, 7}; //connect to the column pinouts of the kpd

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


// password states
bool pass_state = false;

// Write password
void show_password(){

  if (!pass_state)
  {
    // Does not show the password
    lcd.clear();
    for (unsigned int i =0 ; i<password.length();i++){
    lcd.print('*');
    }
    pass_state = true;
  }
  else {
    // shows password
    lcd.clear();
    lcd.print(password);
    pass_state = false;
  }
}

void setup() {
  // put your setup code here, to run once:
  // Pins - Buttons
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),show_password, RISING);

  // LCD
  lcd.begin(16,2);
  lcd.print("Password Access: ");
  lcd.setCursor(0,1); //Move coursor to second Line
  lcd.cursor();
  delay(500);
  // Keypad
}

void loop() {  
  // put your main code here, to run repeatedly:
  char customKey = kpd.getKey();

  if (customKey){  
    // Gets charachters
    if((password.length() <4) && (customKey !='*') && (customKey !='#')){
      password = password + customKey ;
    }
    // Clear #
    if(customKey == '#'){
      lcd.clear();
      password = password.substring(0, password.length()-1);  
    }
    // Submit 
    if(customKey == '*'){
      // match the password 
      if((password[0]=='1') && (password[1]=='2') && (password[2]=='3') && (password[3]=='4')){
        lcd.clear();  
        lcd.print("Password Garantied!");
        delay(2000);
        lcd.clear();
      }
      else{
        lcd.clear();
        lcd.print("Wrong Password!");
        delay(2000);
        lcd.clear();
      }
    }
    lcd.clear();
    for (unsigned int i =0 ; i<password.length();i++){
      lcd.print('*');
    }
  }
}