#include "ads1015.h"
#include "Wire.h"
#include <Arduino.h>

ADS1015::ADS1015(uint16_t address){
    ADS1015::address = address;
}

int ADS1015::Init(uint16_t config)
{
    this->config = config;

    Wire.beginTransmission(this->address);
    Wire.write(ADS1015::Reg::CONFIG_REG);
    Wire.write(config >> 8);//high byte
    Wire.write(config & 0xFF);//low byte
    int debug = Wire.endTransmission();

    if(debug == 0){
        return 1;
    }else{
        if(Serial){
            Serial.write("[ERROR] ADS1015 Init Failed\n");
            switch (debug){
                case 1:
                    Serial.write("REASON: Data too long");
                    break;
                case 2:
                    Serial.write("REASON: Received NACK on transmit of address");
                    break;
                case 3:
                    Serial.write("REASON: Data too long");
                    break;
                case 4:
                    Serial.write("REASON: Data too long");
                    break;
                case 5:
                    Serial.write("REASON: Data too long");
                    break;
                default:
                    Serial.write("REASON: Unknown error\n");
                    break;
            }
        }
        return 0;
    }

}


//assume the ADC has already been configured
//select which ADC to read single shot from
uint16_t ADS1015::readSingleShot(uint16_t mux)
{
    //bit mask to get MUX bits in config
    uint16_t mask = 0x8FFF; //1000 1111 1111 1111
    
    //set the mux config bits to 0
    this->config = this->config & mask;

    //set the mux bits
    this->config |= mux;

    Serial.print("Config: ");
    Serial.println(this->config, BIN);

    //config |= mux;
    int debug;

    Wire.beginTransmission(this->address);
    Wire.write(ADS1015::Reg::CONFIG_REG);
    Wire.write(this->config >> 8);
    Wire.write(this->config & 0xFF);
    debug = Wire.endTransmission();

    if(debug != 0){
        Serial.println("Something fucked up");
    }
     

    Wire.beginTransmission(this->address);
    Wire.write(ADS1015::Reg::CONV_REG);
    Wire.endTransmission();

    if(debug != 0){
        Serial.println("Something fucked up");
    }

    Wire.requestFrom(this->address, (uint8_t)2);
    uint8_t read1 = Wire.read();
    uint8_t read2 = Wire.read();
    uint16_t result = (read1 << 8) | read2;

    return result;
}