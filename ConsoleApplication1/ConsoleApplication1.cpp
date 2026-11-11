#include "pitches.h"

// Пінг, до якого підключено зумер
const int buzzerPin = 9;

// Ноти мелодії (фрагмент)
int melody[] = {
  NOTE_A4, NOTE_C5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_C5, NOTE_D5, NOTE_B4,
  NOTE_A4, NOTE_G4, NOTE_A4
};

// Тривалість нот
int noteDurations[] = {
  4, 4, 4, 2,
  4, 4, 4, 2,
  4, 4, 2
};

void setup() {
    pinMode(buzzerPin, OUTPUT);

    for (int thisNote = 0; thisNote < 11; thisNote++) {
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(buzzerPin, melody[thisNote], noteDuration);

        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        noTone(buzzerPin);
    }
}

void loop() {
    // Відтворення завершено
}