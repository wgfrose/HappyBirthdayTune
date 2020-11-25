// Audio out pin
int SPEAKER_PIN = 11;

// The number of notes
int length = 28;

// Notes for the 'Happy Birthday' tune
char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";

// Note beat durations - 2 for quaver, 8 for crotchet, 16 for minim
int beats[] = {2,2,8,8,8,16,1,2,2,8,8,8,16,1,2,2,8,8,8,8,16,1,2,2,8,8,8,16};

// Time delay between notes
int tempo = 220;  

// Write the tone output to the audio out pin on the board
void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
     digitalWrite(SPEAKER_PIN, HIGH);
     delayMicroseconds(tone);
     digitalWrite(SPEAKER_PIN, LOW);
     delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B',           

                   'c', 'd', 'e', 'f', 'g', 'a', 'b',

                   'x', 'y' };


  // Frequencies of each note
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014,
 
                  956,  834,  765,  593,  468,  346,  224,

                   655 , 715 };

  // Speed
  int SPEED = 3;

  // Play the tone corresponding to the note name
  for (int i = 0; i < 17; i++) {
    if (names[i] == note) {
      int newduration = duration/SPEED;
      playTone(tones[i], newduration);
    }
  }
}

// Mandatory method for setting up the audio out pin on the board
void setup() {
  pinMode(SPEAKER_PIN, OUTPUT);
}

// Mandatory method for the program to run - infinitely!
void loop() {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo);
    } else {
      playNote(notes[i], beats[i] * tempo);
    }
   
    // Time delay between notes
    delay(tempo);
  }
}
