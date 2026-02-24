int HORZ = A0;   // Broche horizontale du joystick
int VER  = A1;   // Broche verticale du joystick
int SEL  = A2;   // Broche du bouton poussoir du joystick

void setup() {
  pinMode(HORZ, INPUT);   // A0 configurée en entrée
  pinMode(VER, INPUT);    // A1 configurée en entrée
  pinMode(SEL, INPUT);    // A2 configurée en entrée (lecture numérique)

  Serial.begin(9600);     // Initialisation de la liaison série à 9600 bits/s
}

void loop() {

  int X = analogRead(VER);    // Lecture analogique axe vertical
  int Y = analogRead(HORZ);   // Lecture analogique axe horizontal
  int bouton = digitalRead(SEL);  // Lecture numérique du bouton

  Serial.println(X);   // Affichage valeur axe vertical
  Serial.println(Y);   // Affichage valeur axe horizontal

  if (bouton == 1) {   // Si le bouton n'est pas pressé (état haut)
    Serial.println("Aucune pression sur le bouton poussoir");
  } 
  else {               // Si le bouton est pressé (état bas)
    Serial.println("Bouton-poussoir actif");
  }
}
