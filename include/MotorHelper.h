#pragma once

/**
 * @brief Controls the motor
 * 
 */
class Motor
{
    public:
        const struct {uint8_t IN1, IN2, PWM} PINS; // Input pins
}

namespace Motors
{
    Motor right(1, 2, 3);
    Motor left(2, 3, 4, 2);
}