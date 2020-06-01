// In The Name Of Allah

// Buzzer Pin ???
int buzzerPin = 13;

// Hertz ???
int N = 0;
int C = 262;
int D = 294;
int E = 330;
int F = 349;
int G = 392;
int A = 440;
int B = 494;
//char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
//int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
bool light = false;

int playMelody(int melody[][3], int noteNum)
{
  for (int i = 0; i < noteNum; i++)
  {
    if (melody[i][0] == 0)
    {
      noTone(buzzerPin);
      delay(melody[i][2]);
      continue;
    }
    if(light)
    {
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      light = false;
    }
    else
    {
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      light = true;
    }
    tone(buzzerPin, melody[i][0] * melody[i][1], melody[i][2]);
    delay(melody[i][2]);
  }
}

int myMelody[24][3] = {{D, 3, 200}, {E, 3, 400}, {D, 3, 200}, {E, 3, 400}, {F, 3, 200}, {E, 3, 200}, {F, 3, 200}, {D, 3, 200}, {E, 3, 400}};
int myMelodeNoteNum = 24;

void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  playMelody(myMelody, myMelodeNoteNum);

}
