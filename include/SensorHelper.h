#pragma once

#include <Arduino.h>

/**
 * @brief Manages the line sensor
 * 
 * 
 */
namespace LineSensor
{
    // Specific hardware information
    const uint8_t N_SENSORS = 7;
    const uint8_t PINS[] = {A0, A1, A2, A3, A4, A5, A7};

    typedef struct {
        uint8_t avg;
        uint8_t sum;
    } line_info;

    line_info readline(){
        
        line_info result = {0, 0};

        uint8_t value;
        
        for (int i = 0; i < N_SENSORS; i++)
        {
            value = digitalRead(PINS[i]);
            result.avg += value * i;
            result.sum += value;
        }

        return  result;
    }
    
    // sum all the values and 


}