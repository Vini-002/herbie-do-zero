#pragma once

#include <EEPROM.h>
#include <SoftwareSerial.h>

/**
 * @brief Manages storage and transmission of parameters
 * 
 */
namespace Parameters
{
    const uint8_t RX_PIN = 10, TX_PIN = 9, BAUD_RATE = 9600;
    
    const uint8_t MEM_ADDRESS = 64;
    
    typedef struct {
        float P;
        float I;
        float D;
    } PID;
    
    typedef struct {
        // Para armazenar mais dados
        // basta modificar esta estrutura
        PID pid;
        uint8_t pwm_max;
        uint8_t pwm_min;
        uint8_t cont;
        uint32_t encoder_count[3];
    } MyData; // Estrutura dos parâmetros

    MyData data; // Variável pra guardar os valores dos parâmetros

    SoftwareSerial serial(RX_PIN, TX_PIN);

    /**
     * @brief Receives the parameters over the serial communication (Bluetooth)
     * 
     */
    void receive(){
        serial.begin(BAUD_RATE);
        serial.readBytes((byte *) &data, sizeof(MyData));
        write();
    }

    /**
     * @brief Sends the parameters over the serial communication (Bluetooth)
     * 
     */
    void send(){
        serial.begin(BAUD_RATE);
        read();
        serial.write((byte *) &data, sizeof(MyData));
    }

    /**
     * @brief Reads the parameters stored on memory (EEPROM)
     * 
     */
    void read()
    {
        EEPROM.get(MEM_ADDRESS, data);
    }

    /**
     * @brief Stores the parameters on memory (EEPROM)
     * 
     */
    void write()
    {
        EEPROM.put(MEM_ADDRESS, data);
    }
}