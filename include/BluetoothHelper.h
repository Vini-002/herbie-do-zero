#pragma once

#include <SoftwareSerial.h>

namespace Bluetooth
{
    SoftwareSerial BT(10, 9);

    void begin(){
        BT.begin(9600);
    }

    
}
