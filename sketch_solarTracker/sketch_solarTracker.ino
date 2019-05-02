   #include <Servo.h> // include Servo library 

Servo horizontal; // horizontal servo
int posh = 0; // stand horizontal servo
//
Servo vertical; // vertical servo 
int posv = 0; // stand vertical servo

int ldrrt = 3; //LDR top right
int ldrrd = 2; //LDR down right
int ldrlt = 0; //LDR top left
int ldrld = 1; //LDR down left

void setup()
{
  Serial.begin(9600);
  horizontal.attach(9);
  horizontal.write(0); //set initial pos as 0 deg
  vertical.attach(9);
  vertical.write(10); 
//delay(10);
  pinMode(ldrlt, INPUT);      // declare LDRs as input
  pinMode(ldrrt, INPUT);
  pinMode(ldrld, INPUT);
  pinMode(ldrrd, INPUT);
}
void loop() 
{

  int lt = analogRead(ldrlt); // top left
  int rt = analogRead(ldrrt); // top right
  int ld = analogRead(ldrld); // down left
  int rd = analogRead(ldrrd); // down rigt

  
  int avt = (lt + rt) / 2; // average value top
  int avd = (ld + rd) / 2; // average value down
  int avl = (lt + ld) / 2; // average value left
  int avr = (rt + rd) / 2; // average value right

if(avt==avd && avt==avl && avl==avr && avr==avd)
{}
else{

  

  if (avt > avd){
    while(avt!=avd){
      posv = ++posv;
      if (posv > 170){
        posv = 170;
       }
    }
    }
    else if (avt < avd){
      while(avt!=avd){
          posv= --posv;
      if (posv < 0){
          posv = 0;
                }
      }
      
    }
    vertical.write(posv);

    
     if (avl > avr){
while(avl!=avr){
       posh = ++posh;
                  
                  if (posh > 180){
                    posh = 180;
                  }
                  else{}
}
               
          }

          
          else if (avl < avr){
            while(avl!=avr){
 posh = --posh;
                
                if (posh < 0){
                  posh = 0;
                }
                else{}
            }
              }

              
          else if (avl == avr){
           }
           horizontal.write(posh);
           //delay();
}

}
  

  
