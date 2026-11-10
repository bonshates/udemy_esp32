#include <stdbool.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
static const char *TAG = "main";

void app_main(void)
{
    while (true) {
        ESP_LOGI(TAG, "Main loop running");
        vTaskDelay(300 / portTICK_PERIOD_MS);
    }
}
