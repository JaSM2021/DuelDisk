//DuelDisk.ino

#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini Sounds;

int BGMPin = 3;
int Count1 = 4;
int Count2 = 5;
int Count3 = 6;
int Count4 = 7;
int Voice = 8;
int BGMTrack = 0;
int VoiceTrack = 0;
int LPNumber = 0;
  
void setup()
{
  pinMode(BGMPin, INPUT);
  pinMode(Voice, INPUT);
  pinMode(Count1, INPUT);
  pinMode(Count2, INPUT);
  pinMode(Count3, INPUT);
  pinMode(Count4, INPUT);
  
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  Sounds.begin(mySoftwareSerial);
  Sounds.volume(25);
  
  delay(500);
  Sounds.playFolder(1,1);
  Serial.print( "DuelDisk ON"); 
}

void loop()
{
  if(digitalRead(BGMPin)){
     delay(200);
     BGMTrack = BGMTrack + 1;
     Sounds.playFolder(2,BGMTrack); 
     Serial.print(BGMTrack);
     Serial.print(LPNumber);

      if(BGMTrack == 4){
        BGMTrack = 0;
        }
      }
 
  if(digitalRead(Count1)){
     delay(200);
     LPNumber = LPNumber + 1;

     if(LPNumber == 11){
        LPNumber = 0;         
     }

     Serial.print(LPNumber);
  }

  if(digitalRead(Voice)){
     delay(200);
     
      Serial.print(LPNumber);

        switch(LPNumber){

          case 0:                                 //999 - 1 Life Points
            if(VoiceTrack == 3){   
            VoiceTrack = 0;
            }

            VoiceTrack = VoiceTrack + 1;
            Sounds.playFolder(3, VoiceTrack);
            break;

          case 1:                                 //1999 - 1000 Life Points
            if(VoiceTrack == 3){
            VoiceTrack = 0;
            }

            VoiceTrack = VoiceTrack + 1;
            Sounds.playFolder(4, VoiceTrack);
            break;
          
          case 2:                                 //2999 - 2000 Life Points
            if(VoiceTrack == 3){
            VoiceTrack = 0;
            }

            VoiceTrack = VoiceTrack + 1;
            Sounds.playFolder(5, VoiceTrack);
            break;

          case 3:                                 //3999 - 3000 Life Points
            if(VoiceTrack == 3){
            VoiceTrack = 0;
            }

            VoiceTrack = VoiceTrack + 1;
            Sounds.playFolder(6, VoiceTrack);
            break;

          case 4:                                 //4999 - 4000 Life Points
            if(VoiceTrack == 5){
            VoiceTrack = 0;
            }

            VoiceTrack = VoiceTrack + 1;
            Sounds.playFolder(7, VoiceTrack);
            break;

          case 5:                                 //5999 - 5000 Life Points
            if(VoiceTrack == 10){
            VoiceTrack = 0;
            }

            VoiceTrack = VoiceTrack + 1;
            Sounds.playFolder(8, VoiceTrack);
            break;

          case 6:                                 //6999 - 6000 Life Points
            if(VoiceTrack == 10){
            VoiceTrack = 0;
            }

            VoiceTrack = VoiceTrack + 1;
            Sounds.playFolder(9, VoiceTrack);
            break;

          default:                                 //9999 - 7000 Life Points
            if(VoiceTrack == 10){
            VoiceTrack = 0;
            }

            VoiceTrack = VoiceTrack + 1;
            Sounds.playFolder(10, VoiceTrack);
            break;
            }  
     }
}
  
