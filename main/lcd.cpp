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

 #include "lcd.h"

 void setUpLCD(){
    lcd.begin(16, 2);
 }

 void printWelcome(){
    lcd.display();
    
    lcd.setCursor(0,0);
    lcd.print("Bienvenido");

    printNumCoches();    
 }
 
 void printNumCoches(){
    lcd.setCursor(0,1);
    lcd.print("Plazas:");
    lcd.setCursor(13,1);
    lcd.print(numCoches);
 }

 void printGoodbye(){
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Gracias,");
    lcd.setCursor(2,1);
    lcd.print("vuelva pronto");

    delay(1500);

    lcd.noDisplay();
 }
