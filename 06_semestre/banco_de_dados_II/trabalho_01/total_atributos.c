#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "total_atributos.h"

int total_atributos(att* schema) {
    int i = 0;
    while (schema[i].atributo[0] != '\0') {
        i++;
    }
    return i;
}