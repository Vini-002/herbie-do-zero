#pragma once

#include <EEPROM.h>

#define ADDRESS 128
// Escolha arbitrária de armazenar no 128 para evitar
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
    } data;

    data stored_data; // Variável pra guardar os dados

    union data_union
    {
        float P;
        float I;
        float D;
        uint8_t pwm_min;
        uint8_t pwm_max;
        uint8_t cont;
        uint32_t enc[3];
    };
    
    void get()
    {
        EEPROM.get(ADDRESS, stored_data);
    }

    void put()
    {
        EEPROM.put(ADDRESS, stored_data);
    }
}