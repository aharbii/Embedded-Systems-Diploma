#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include "wifi.h"
#include "defaultconfig.h"

int main()
{
    WIFI_init();
    printf("%d\n", sum(12, 15));
    printf("%d\n", VARIABLESAPP_VERSION_MAJOR);
    return 0;
}