# Electrical Noise Input for Arduboy (THE 7TH INPUT)
*Using the elctrical noise from the pins as a 7th input for the Arduboy.*

### But how it works? 
It detects the difference between the normal average of the noise and your interference.
To interfere with the noise you just have to rub your thumb between
the usb connector and the micro controller on the plastic case.

### Functions
*ElectricalNoiseInput.h* contains:
```
void ENIDpadSetup(); //for the [0, 1, 2, 3] pins, call just once in Startup()
uint16_t ENIPinRead(); //returns the noise value of the pin
uint16_t ENIValue(); //returns the difference between the average and the noise
bool ENIPressed(uint8_t sensibility); //returns true when ENIValue() is greater than the sensibility
```
While *ElectricalNoiseInputBase.h* contains:
```
void ENIDpadSetup(); //for the [0, 1, 2, 3] pins, call just once in Startup()
bool ENI(uint8_t pin, uint16_t sensibility); //returns true when electrical noise from the chosen pin is greater than the sensibility
```

### Remember
- The sounds from the Arduboy will heavily affect the noise.
- Do not press too hard on the case, just do a soft rub or a simple swipe.
- Made for the standard Arduboy not the DevKit one.
