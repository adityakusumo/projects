#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libbase/uart.h>
#include <generated/csr.h>

#define LM75_I2C_ADDR 0x48
#define LM75_TEMP_REG 0x00
#define TEMP_SCALE 500

#define ADV7390_SLAVE_ADDRESS_WRITE (0x56 >> 1)
#define ADV7390_SLAVE_ADDRESS_READ (0x57 >> 1)

/* AD9883A Address */
#define AD9883A_SLV_ADDR			0x98		// AD9883A Slave Address

/* AD9883A Control Register */
#define CHIP_VERSION		0x00
#define PLL_MSB				0x01
#define PLL_LSB				0x02
#define VCO_RANGE			0x03
#define PHASE_ADJUST		0x04
#define CLAMP_PLACEMENT		0x05
#define	CLAMP_DURATION		0x06
#define HSOUT_PULSEWIDTH	0x07
#define RED_GAIN			0x08
#define GREEN_GAIN			0x09
#define BLUE_GAIN			0x0a
#define RED_OFFSET			0x0b
#define GREEN_OFFSET		0x0c
#define BLUE_OFFSET			0x0d
#define SYNC_CONTROL		0x0e
#define CLAMP_COAST_SET		0x0f
#define SOG_THRESHOLD		0x10
#define SYNC_SEPARATOR		0x11
#define PRE_COAST			0x12
#define POST_COAST			0x13
#define SYNC_DETECT			0x14
#define TEST_REG1			0x15
#define TEST_REG2			0x16
#define TEST_REG3			0x17
#define TEST_REG4			0x18

void uart_write_word(const char *word);
uint32_t lm75_read_temperature(void);
void i2c_scan(void);

void uart_write_word(const char *word)
{
    while (*word)
    {
        uart_write(*word);
        word++;
    }
    uart_write('\n');
}

/*void adv7391_write(uint8_t devaddr, uint8_t subaddr, uint8_t data)
{
    static uint8_t len_rx, len_tx, recover;
    static uint32_t i2c_setting_reg;
    uint32_t i2c_data;
    uint8_t status;

    len_rx = 0;
    len_tx = 2;
    recover = 0;

    i2c_setting_reg = (len_tx & 0x7) | ((len_rx & 0x7) << 8) | (recover << 16);

    // Write date data
    i2c_data = 0;
    i2c_data = (subaddr << 8) | (data);
    i2c_master_settings_write(i2c_setting_reg);
    i2c_master_addr_write(devaddr);
    //   i2c_master_rxtx_write(0x0000001E); // Start at register 0x04
    i2c_master_rxtx_write(i2c_data);

    while (!(i2c_master_status_read() & 0x01))
        ;

    status = i2c_master_rxtx_read();
}

void adv7391_testpattern()
{
    adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x17, 0x02);
    adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x00, 0x1E);
    adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x80, 0x11);
    adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x82, 0xCB);
    adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x84, 0x40);
    adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x8C, 0xCB);
    adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x8D, 0x8A);
    adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x8E, 0x09);
    adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x8F, 0x2A);
}

void i2c_write(uint8_t devaddr, uint8_t subaddr, uint8_t data)
{
    static uint8_t len_rx, len_tx, recover;
    static uint32_t i2c_setting_reg;
    uint32_t i2c_data;
    uint8_t status;

    len_rx = 0;
    len_tx = 2;
    recover = 0;

    i2c_setting_reg = (len_tx & 0x7) | ((len_rx & 0x7) << 8) | (recover << 16);

    // Write date data
    i2c_data = 0;
    i2c_data = (subaddr << 8) | (data);
    i2c_master_settings_write(i2c_setting_reg);
    i2c_master_addr_write(devaddr);
    //   i2c_master_rxtx_write(0x0000001E); // Start at register 0x04
    i2c_master_rxtx_write(i2c_data);

    while (!(i2c_master_status_read() & 0x01))
        ;

    status = i2c_master_rxtx_read();
}

void i2c_scan(void)
{
    char msg[32];

    for (uint8_t addr = 0x00; addr < 0x80; addr++)
    {
        i2c_master_addr_write(addr);
        i2c_master_settings_write(0x00000100);
        while (!(i2c_master_status_read() & 0x01))
            ;

        if (!(i2c_master_status_read() & 0x04))
        {
            snprintf(msg, sizeof(msg), "Found I2C device at 0x%02X", addr);
            uart_write_word(msg);
        }
    }
}*/

int main(void)
{
    char buffer[32];

    // uart_init();
    // printf("mulai\r\n");
    printf("sawiiitt\r\n");
    // uart_write_word("mulai\r\n");

    // i2c_master_active_write(1);
    // // adv7391_testpattern();

    // adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x17, 0x02);
    // adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x00, 0x1E);
    // adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x01, 0x00);
    // adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x80, 0x11);
    // adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x82, 0xC3);
    // adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x8C, 0xCB);
    // adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x8D, 0x8A);
    // adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x8E, 0x09);
    // adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x8F, 0x2A);

    // gpio_in_read();

    while (1)
    {

        // snprintf(buffer, sizeof(buffer), "Tol:  C");
        // uart_write_word(buffer);
        // // gpio_out_write(0x0000);
        // busy_wait(250);
        //
        // // gpio_out_write(0xFFFF);
        // busy_wait(250);

        busy_wait(1);
    }

    return 0;
}
