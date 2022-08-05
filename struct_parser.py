# -*- coding: utf-8 -*-
"""struct_parser.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/gist/Vini-002/3051f52c88289fb3c5bddd2c179ad046/struct_parser.ipynb
"""

sample = """\
    
    typedef struct {
        float P; // Proporcional
        float I; // Integral
        float D; // Derivativo
    } PID;
    
    typedef struct {
        // Para armazenar mais dados
        // basta modificar esta estrutura

        PID reta; // PID da reta
        uint8_t pwm_max; // PWM máximo
        uint8_t pwm_min;
        uint8_t cont; // Contagem dos sensores laterais
        uint32_t encoder_count[3]; // Contagem do encoder
    } MyData;
"""

import re
from pprint import pprint

struct_p = re.compile('{(?P<fields>.+?)} (?P<name>\w+)', re.DOTALL)
field = re.compile(' +(?P<type>\w+) +(?P<name>\w+)(\[(?P<size>\d+)])?;( +// (?P<description>.*))?')

for m1 in struct_p.finditer(sample):
    struct = m1.groupdict()
    struct["fields"] = [m2.groupdict() for m2 in field.finditer(struct["fields"])]
    pprint(struct)