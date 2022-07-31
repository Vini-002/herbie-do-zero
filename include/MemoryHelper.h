#pragma once

#include <EEPROM.h>

#define ADDRESS 64
// Escolha arbitrária de armazenar no 64 para evitar
// os bytes iniciais que já foram bastante utilizados

namespace Memory
{

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
    } MyData;

    MyData data; // Variável pra guardar os dados

    void read()
    {
        EEPROM.get(ADDRESS, data);
    }

    void write()
    {
        EEPROM.put(ADDRESS, data);
    }
}