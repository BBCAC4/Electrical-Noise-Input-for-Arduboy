//Eletronical Noise Input (ENI) by BBCAC4
#pragma once

#define ANPIN 5
#define frameRefresh 30

uint16_t NoiseAverage;
uint8_t tmr;

//if you want to use the pins of the d-Pad[0, 1, 2, 3]
//put this function in the Setup(); while
//the buttons corresponding to the pins
//are held down it won't return any ENI
void ENIDpadSetup()
{
  pinMode(PIN_UP_BUTTON, INPUT); 
  pinMode(PIN_DOWN_BUTTON, INPUT); 
  pinMode(PIN_RIGHT_BUTTON, INPUT); 
  pinMode(PIN_LEFT_BUTTON, INPUT); 
}

//reads the value of the chosen pin [ANPIN]
uint16_t ENIPinRead()
{
  power_adc_enable();
  uint16_t v = analogRead(ANPIN);
  power_adc_disable();
  return v;
}

//returns the difference between 
//the NoiseAverage and the actual noise;
//the NoiseAverage is calculated every [frameRefresh] frames
uint16_t ENIValue()
{
  uint16_t v = ENIPinRead();
  if(tmr > 0) tmr--;
  else
  {
    NoiseAverage = (NoiseAverage + v) / 2;
    tmr = frameRefresh;
  }
  int intensity = NoiseAverage - v; 
  v = abs(intensity);
  return v;
}

//returns true if the ENIValue() is greater than the sensibility;
//the less is the value of sensibility the more sensitive it will be
bool ENIPressed(uint8_t sensibility)
{
  if(ENIValue() >= sensibility) return true;
  else return false;
}
