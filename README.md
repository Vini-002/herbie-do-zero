# herbie-do-zero

## Memory

The [MemoryHelper.h](include/MemoryHelper.h) file is responsible for managing the storage of the variables on the non-volatile EEPROM memory.

First, we declare a struct to pack the variables.

```c
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

```

The PID constants are packed togheter to make easier to store many PID's combinations in the future.

Next, we instantiate this struct and use it to write and read to memory with a single function call.

```c
#include <EEPROM.h>

#define ADDRESS 128

data stored_data; // Variável pra guardar os dados

EEPROM.get(ADDRESS, stored_data); // Função para ler os valores da memória

EEPROM.put(ADDRESS, stored_data); // Função para escrever os valores na memória
```

The address is an arbitrary choice.