#include <Wire.h> //Inclut la bibliothèque "Wire" qui gère la communicatio I2C
#include "rgb_lcd.h" //Inclut la bibliothèque spécifique au rgb de l'écran, non utilisée
rgb_lcd lcd; // Crée un objet "lcd"
// Initialisation des variables utiles contenant les PINS associés
int HOR = A0;
int VER = A1;
int SEL = 11;
int trigPin = 9; 
int echoPin = 8; 
int duree = 0;
int distance = 0;
int ledpin = 13;
void setup() {
  lcd.begin(16, 2); // Initialisation d'une fenêtre LCD de taille 16x2
  //Initialisation des entrées et sorties
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(HOR, INPUT);
  pinMode(VER, INPUT);
  pinMode(SEL, INPUT);
  pinMode(ledpin, OUTPUT);
  // Initialisation de la connexion entre la carte et l'ordinateur
  Serial.begin(9600);
}
void loop() {
  // Lecture des coordonnées X,Y envoyées par le Joystick. Detection de la pression sur le bouton
  int X = analogRead(HOR);
  int Y = analogRead(VER);
  int lecture_boutton = digitalRead(SEL);
  //Partie configurant le capteur ultrason. Determine la distance à l'obstacle
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(20); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  duree = pulseIn(echoPin, HIGH); 
  distance = duree * 0.034 / 2; 
  //Cas où le joystick est appuyé (lecture_boutton = 0)
  if(lecture_boutton == 0) {
    //Pour une distance inférieur à 20cm on affiche la distance sur un fond rouge
    if(distance < 20) {
      lcd.setRGB(255, 0, 0); // Mettre le LCD sur un fond rouge
      lcd.setCursor(0, 0);
  	  lcd.print(distance); //Affichage sur le LCD
    } else { //Pour une distance supérieure à 20cm on affiche la distance sur un fond vert
      lcd.setRGB(0, 255, 0); // Mettre le LCD sur un fond vert
      lcd.setCursor(0, 0);
  	  lcd.print(distance); //Affichage sur le LCD
    }
    //Cas où le joystick est à droite (X > 511)
  } else if (X > 511) {
    //Si la distance est inférieure à 20cm, on affiche la distance sur le port série avec la LED qui clignote
    if (distance < 20) {
      Serial.println(distance); //Affichage dans le port série de la mesure
      digitalWrite(ledpin, HIGH); //Allumer la LED
      delay(200); // Attendre 200 ms
      digitalWrite(ledpin, LOW); // Eteindre la LED 
      delay(200); // Attendre 200 ms
    } else { // Si la distance est supérieure à 20cm, on affiche la distance sur le port série sans LED qui clignote
      Serial.println(distance);
    }
    //Cas où le joystick est à gauche (X<511)
  } else if(X < 511){ 
    Serial.println(distance); // On affiche la mesure sur le port série
  } else if(Y < 511) { // Cas où le joystick est en bas
    if(distance < 20) { // Si la distance est inférieure à 20cm, on affiche la mesure sur le LCD sur un fond rouge
      lcd.setRGB(255, 0, 0); // Modifier le RGB et le mettre sur rouge
      lcd.setCursor(0, 0);
  	  lcd.print(distance); //Affichage sur le LCD 
    } else { // Si la distance est supérieure à 20cm, on affiche la mesure sur le LCD sur un fond vert
      lcd.setRGB(0, 255, 0); // Modifier le RGB et le mettre sur vert
      lcd.setCursor(0, 0);
  	  lcd.print(distance); //Affichage sur le LCD
    }
  } else if(Y > 511) {  // Cas où le joystick est en haut
    lcd.setRGB(0, 0, 255); //Affichage sur l'écran étant bleu
    lcd.setCursor(0, 0); 
  	lcd.print(distance); //Affichage sur le LCD
  }  
}

