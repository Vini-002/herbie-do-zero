# herbie-do-zero

## Memory

The [MemoryHelper.h](include/MemoryHelper.h) file is responsible for managing the storage of the variables on the non-volatile EEPROM memory.

### Implementation

First, we declare a struct to pack the variables. There is an example below that can be modified to store any variable that is needed.

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

### Usage

As the code is implemented on a namespace called `Memory`, to use in the main code simply assign the values to be saved to the variable `Memory::stored_data` and call `Memory::put()` to write the values to memory, as shown below:

```c
Memory::stored_data = {
    {0.643, 0.16, 1.12},  // PID
    220,                  // PWM max
    160,                  // PWM min
    14,                   // Contagem lateral
    {65236, 43212, 76210} // Encoder ticks
};
Memory::put();
```

Likewise, to get the values from memory, call `Memory::put()` and then acess the values on the variable `Memory::stored_data`.