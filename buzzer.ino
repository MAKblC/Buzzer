/*
исполнение мелодий на пианино

-------------
1 - ДО      ] 
2 - ДО#     ]
3 - РЕ      ]
4 - РЕ#     О 
5 - МИ      К
6 - ФА      Т
7 - ФА#     А
8 - СОЛЬ    В
9 - СОЛЬ#   А 
10 - ЛЯ     ]
11 - ЛЯ#    ]
12 - СИ     ]
-------------
13 - ДО
14 - ДО#

 Created by Kotov Maxim
*/

#include <Wire.h>
#include <Adafruit_MCP4725.h>
Adafruit_MCP4725 buzzer;

int ton;
int vol1 = 1000; // Уровень громкости = vol1-vol2
int vol2 = 900;  //

void setup() {
  // Инициализация последовательного порта
  Serial.begin(115200);
  // Инициализация модуля
  Wire.begin();
  buzzer.begin(0x61); // С перемычкой адрес будет 0x60
}

void loop() {
buzzer.setVoltage(0, false);   // выключение звука
delay(1000);

note(1,450); note(2,450); note(3,450);       // здесь пишем музыку ( в примере проигрываются ноты одной октавы)
note(4,450); note(5,450); note(6,450);
note(7,450); note(8,450); note(9,450);
note(10,450); note(11,450); note(12,450);
}

int note( int type, int duration) {   // нота (какая нота, длительность)
 switch (type){
  case 1:   ton=1000; break;
  case 2:   ton=860;  break;
  case 3:   ton=800;  break;
  case 4:   ton=700;  break;
  case 5:   ton=600;  break;
  case 6:   ton=525;  break;
  case 7:   ton=450;  break;
  case 8:   ton=380;  break;
  case 9:   ton=315;  break;
  case 10:  ton=250;  break;
  case 11:  ton=190;  break;
  case 12:  ton=130;  break;
  case 13:  ton=80;   break;
  case 14:  ton=30;   break;
   }
  delay(10);
   for(int i=0;i<duration;i++){
       buzzer.setVoltage(vol1, false);
       buzzer.setVoltage(vol2, false);
    delayMicroseconds(ton);
   }
}
