#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <generated/csr.h>

int main(void)
{
    // uart_init();
    printf("Hello from DDR firmware!\n\r");
    printf("If you see this, UART is working.\n\r");

    while (1) {
        busy_wait(1000);
        printf("alive\n\r");
    }

    return 0;
}
