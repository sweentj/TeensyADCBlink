
#ifndef __ADS1015_H
#define __ADS1015_H

#include <Arduino.h>
#include "ads1015_reg.h"

class ADS1015
{

    public:

        struct Reg
        {
            enum RegAddr_t
            {
                //Pointer register [W only]
                
                //Conversion reg [R only]
                CONV_REG = 0x00,
                //Config reg [R/W]
                CONFIG_REG = 0x01,
                //low threshold reg
                LO_THRSH_REG = 0x02,
                //hi threshold reg []
                HI_THRSH_REG = 0x03
            };

        };

        ADS1015(uint16_t address);

        
        //only need to setup 1 reg
        int Init(uint16_t config);

        void Shutdown();
        void WriteReg();

        uint16_t readSingleShot(uint16_t mux);


    private:
    uint16_t address;
    uint16_t config;
};


#endif