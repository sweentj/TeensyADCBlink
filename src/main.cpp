
#include <Arduino.h>
#include <Wire.h>
#include "ads1015.h"
#include "ChRt.h"

// ADS1015 I2C address
#define ADC_ADDRESS1 0x48
#define ADC_ADDRESS2 0x49

//GLOBALS

ADS1015 adc1 = ADS1015(ADC_ADDRESS1);
ADS1015 adc2 = ADS1015(ADC_ADDRESS2);

static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg) {

  uint16_t* config = (uint16_t*) arg;

  uint16_t pot1, pot2;

  int debug = adc1.Init(*config);
  chThdSleepMilliseconds(2);
  if(debug){
    Serial.println("Config okay");
  } else{
    Serial.println("Something fucked up");
  }

  while(true){
    pot1 = adc1.readSingleShot(CONFIG_MUX_SINGLE_AIN1);
    chThdSleepMilliseconds(1);

    pot2 = adc1.readSingleShot(CONFIG_MUX_SINGLE_AIN2);
    chThdSleepMilliseconds(1);

    //printf doesn't work with ChibiOS
    Serial.print("Pot1: ");
    Serial.print(pot1);
    Serial.print("\tPot2: ");
    Serial.println(pot2);
    chThdSleepMilliseconds(200);
    
  }
}


static THD_WORKING_AREA(waThread2, 128);
static THD_FUNCTION(Thread2, arg) {
  
  uint16_t* config = (uint16_t*) arg;

  uint16_t pot0;

  int debug = adc2.Init(*config);

  if(debug){
    Serial.println("Config okay");
  } else{
    Serial.println("Something fucked up");
  }

  while(true){
    pot0 = adc2.readSingleShot(CONFIG_MUX_SINGLE_AIN1);
    chThdSleepMilliseconds(1);

    Serial.print("Pot0: ");
    Serial.println(pot0);
    chThdSleepMilliseconds(400);
    
  }
}

void chSetup() {

  uint16_t* config = (uint16_t*) (CONFIG_PGA_2P048V |
                    CONFIG_MODE_SINGLESHOT |
                    CONFIG_DR_1600SPS |
                    CONFIG_CMODE_TRAD |
                    CONFIG_MUX_OS_SINGLE);

  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO + 1, Thread1, &config);
  
  chThdCreateStatic(waThread2, sizeof(waThread2), NORMALPRIO + 2, Thread2, &config);
  

}



void setup() {
  

  Serial.begin(9600);
  Wire.begin();

  chBegin(chSetup);

  while(true) { }


}

void loop() {


}
