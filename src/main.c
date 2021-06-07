#include <stdio.h>
#include <stdlib.h>
#include "nrf_delay.h"
#include "boards.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

/**@brief Function for handling the idle state (main loop).
 *                                                                                                                                                                  
 * @details Handle any pending log operation(s), then sleep until the next event occurs.
 */
static void idle_state_handle(void)
{
    NRF_LOG_FLUSH();
}

int main(void)
{
    /* Configure logging. */
    ret_code_t err_code = NRF_LOG_INIT(NULL);
    APP_ERROR_CHECK(err_code);
    NRF_LOG_DEFAULT_BACKENDS_INIT();
    /* Configure board. */
    bsp_board_init(BSP_INIT_LEDS);

    /* Toggle LEDs. */
    while (true)
    {
        for (int i = 0; i < LEDS_NUMBER; i++)
        {
            bsp_board_led_invert(i);
            nrf_delay_ms(500);
            NRF_LOG_ERROR("logging error...");
            NRF_LOG_DEBUG("logging debug...");
            NRF_LOG_WARNING("logging warn...");
            NRF_LOG_INFO("logging info...");
            NRF_LOG_INFO("logging %d...", i);
            idle_state_handle();
        }
    }
}
