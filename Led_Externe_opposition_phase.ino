// the setup function runs once when you press reset or power the board
int LED = 12;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // Definition du PIN 13 par défaut pour la LED présente sur la carte
  pinMode(LED, OUTPUT); // Definition du PIN 12 comme sortie pour la LED branchée 
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // Mettre la LED builtin sous tension
  digitalWrite(LED, LOW);           // Eteindre la LED externe
  delay(1000);                      // Attendre une seconde
  digitalWrite(LED_BUILTIN, LOW);   // Eteindre la LED builtin
  digitalWrite(LED, HIGH);          // Allumer la LED externe
  delay(1000);                      // Attendre une seconde
}
