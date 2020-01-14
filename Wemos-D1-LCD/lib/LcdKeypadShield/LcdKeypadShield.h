#include <LiquidCrystal.h>
#include "BoardType.h"
#include "Button.h"

class LcdKeypadShield : public LiquidCrystal
{
private:
    /*Default resistor deviation*/
    const static int _defaultResistorCurrentDeviation = 25;

    /*Buttons analog pin*/
    int _analogBtnPin;

    /*The number of buttons on the shield*/
    const static int _buttonsCount = 5;

    /*Analog max value (no key pressed)*/
    const static int _noKeyAnalogValue = 1024;

    /*This variable takes into account the possible 
    unstable current value when reading the analog button*/
    int _resistorCurrentDeviation;
    
    //Buttons analog values
    int _buttonsValues[_buttonsCount]{-1};

    /*Check if the value is within the deviation with the resistor*/
    bool isInRarnge(const int &analogValue, const int &etalonValue);

public:
    //Arbitrary connection of pins to LCD
    LcdKeypadShield(const uint8_t &rs,const uint8_t &enable, 
                    const uint8_t &d4,const  uint8_t &d5,const uint8_t &d6,const uint8_t &d7,
                    const int &aBtnPin);

    ~LcdKeypadShield();

    /*This method can be used if the shield display is connected directly to the board. 
    The detode will automatically initialize the display for your board*/
    static LcdKeypadShield createByBoaard(const BoardType &board);

    /*Button press check*/
    bool isAvailableButton();

    /*Returns the pressed button*/
    Button getButton();

    /*Manual setting of analog button value*/
    void setButtonAnalogValue(Button button, int analogButtonValue);

    /*Automatically adjust button values using the user menu.
    The method helps a lot if you need to constantly change the shield or if you need quick setup*/
    void userButtonsAutoCorrect();

    /*Returns the deviation of the resistor values ​​when the button contacts fluctuate*/
    int getResistorDeviation();

    /*Set the deviation of the resistor values ​​when the button contacts fluctuate*/
    void setResistorDeviation(const int &resistorDeviation);
};