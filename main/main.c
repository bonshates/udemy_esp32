#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    while (true) {
//        printf("Hello from app_main!\n");
//        sleep(1);
        
        vTaskDelay(300 / portTICK_PERIOD_MS);
    }
}
