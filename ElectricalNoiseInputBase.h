//Electrical Noise Input Base (ENI_BASE) by BBCAC4
//Just one function, insert the desidered pin and sensibility
#pragma once
#define frameRefresh 20

uint16_t NoiseAverage;
uint8_t tmr;

//if you want to use the pins of the d-Pad[0, 1, 2, 3]
//put this function in the Setup(); while
//the buttons corresponding to the pins
//are held down it won't return any true value
void ENIDpadSetup()
{
  pinMode(PIN_UP_BUTTON, INPUT); 
  pinMode(PIN_DOWN_BUTTON, INPUT); 
  pinMode(PIN_RIGHT_BUTTON, INPUT); 
  pinMode(PIN_LEFT_BUTTON, INPUT); 
}

bool ENI(uint8_t pin, uint16_t sensibility)
{
  if(tmr > 0) tmr--;
  else
  {
    power_adc_enable();
    uint16_t v = analogRead(pin);
    power_adc_disable();

    NoiseAverage = (NoiseAverage + v) / 2;
    tmr = frameRefresh;

    int intensity = NoiseAverage - v; 
    v = abs(intensity);
  
   if(v >= sensibility) return true;
   else return false;
  }
}
