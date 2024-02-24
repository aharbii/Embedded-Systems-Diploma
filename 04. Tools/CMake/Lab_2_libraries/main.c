#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include "wifi.h"

int main()
{
    WIFI_init();
    printf("%d\n", sum(12, 15));
    return 0;   
}