/*
 *                    Detectores industriales de presencia y proximidad
 * 
 * Cadavid Piñero, Leopoldo
 * Penalva Martínez, Franciso
 * Pérez Vilaplana, Ignacio
 * Salcedo Salcedo, Raquel
 * 
 *                                                                                    Marzo, 2021
 */

//Esta parte del código se encarga de mostrar al usuario el estado y las indicaciones necesarias para 
//la circulación en el parking

 #include "lcd.h"
//Limpia la pantralla
 LCD::LCD(){
    LiquidCrystal lcd(PIN_RS, PIN_EN, PIN_D4, PIN_D5, PIN_D6, PIN_D7); 
    lcd.begin(16, 2);
    lcd.noDisplay();
 }

 LCD::~LCD(){} 
 
//Indica el número de plazas disponibles en el parking y da la bienvenida
 void LCD::printWelcome(){
    LiquidCrystal lcd(PIN_RS, PIN_EN, PIN_D4, PIN_D5, PIN_D6, PIN_D7); 
    lcd.begin(16, 2);
    lcd.display();
    
    lcd.setCursor(0,0);
    lcd.print("Bienvenido");

    lcd.setCursor(0,1);
    lcd.print("Plazas:");
    lcd.setCursor(13,1); 
 }

 void LCD::printGoodbye(){
    LiquidCrystal lcd(PIN_RS, PIN_EN, PIN_D4, PIN_D5, PIN_D6, PIN_D7); 
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Gracias,");
    lcd.setCursor(2,1);
    lcd.print("vuelva pronto");
 }

 void LCD::closeScreen(){
    LiquidCrystal lcd(PIN_RS, PIN_EN, PIN_D4, PIN_D5, PIN_D6, PIN_D7); 
    lcd.begin(16, 2);
    lcd.noDisplay();
 }
