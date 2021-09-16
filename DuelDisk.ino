//DuelDisk.ino

#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
#include <ezButton.h>

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini Sounds;

ezButton BGM(3);
ezButton Voice(8);
ezButton Count1(4);
ezButton Count2(5);
ezButton Count3(6);
ezButton Count4(7);

int BGMTrack = 0;
int VoiceTrack = 0;
int LPNumber = 0;
int Value1 = 4;
int Value2 = 0;
int Value3 = 0;
int Value4 = 0;
String txt; 
int LPArray[4] = {Value1, Value2, Value3, Value4};

void setup()
{
  BGM.setDebounceTime(100);
  Voice.setDebounceTime(100);
  Count1.setDebounceTime(100);
  Count2.setDebounceTime(100);
  Count3.setDebounceTime(100);
  Count4.setDebounceTime(100);

  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  Sounds.begin(mySoftwareSerial);
  Sounds.volume(15);
  delay(500);
  Sounds.playFolder(1,1);
  Serial.print("DuelDisk ON"); 
}

void loop()
{
  BGM.loop();
  Voice.loop();
  Count1.loop();
  Count2.loop();
  Count3.loop();
  Count4.loop();

  if(Count1.isPressed()){
    Value1--;

    if(Value1 < 0){
      Value1 = 9;
    }

  }if(Count2.isPressed()){
    Value2--;

    if(Value2 < 0){
      Value2 = 9;
    }

  }if(Count3.isPressed()){
    Value3--;

    if(Value3 < 0){
      Value3 = 9;
    }

  }if(Count1.isPressed()){
    Value4--;

    if(Value4 < 0){
      Value4 = 9;
    }
  }

  LPArray[0] = Value1;
  LPArray[1] = Value2;
  LPArray[2] = Value3;
  LPArray[3] = Value4;
  
  for(int i = 0; i < 4; i++){
    txt+=LPArray[i];
  }
  Serial.println();
  
  //LPNumber = txt.toInt();
  Serial.print(txt);

  if(BGM.isPressed()){
     BGMTrack = BGMTrack + 1;
     Sounds.playFolder(2,BGMTrack); 
     //Serial.print(BGMTrack);

      if(BGMTrack == 4){
        BGMTrack = 0;
        }
      }
 
 /* if(Count1.isPressed()){
     LPNumber = LPNumber + 1;
     if(LPNumber == 11){
        LPNumber = 0;         
      }

     Serial.print(LPNumber);
  }*/

  if(Voice.isPressed()){
     delay(200);
     
        switch(Value1){

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
  
