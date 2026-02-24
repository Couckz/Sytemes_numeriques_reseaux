int detectPIN = 7;   // Entrée numérique
int ledPIN = 13;     // LED branchée sur la PIN 13

void setup() {
  pinMode(detectPIN, INPUT);   // detectPIN configurée en entrée
  pinMode(ledPIN, OUTPUT);     // LED en sortie
}

void loop() {

  int detectState = digitalRead(detectPIN);

  if (detectState == 1) {  // Si un état 1 (5V) est détecté
    digitalWrite(ledPIN, HIGH);   // Allumer la LED (état haut)
  }
  else {
    digitalWrite(ledPIN, LOW);    // Si un état 0 (0V) est détecté, éteindre la LED
  }

  delay(1);  // Délai entre chaque lecture pour la stabilité
}
