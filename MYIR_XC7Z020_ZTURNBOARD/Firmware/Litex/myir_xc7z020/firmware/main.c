#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <libbase/uart.h>
#include <generated/csr.h>

#define LM75_I2C_ADDR 0x48
#define LM75_TEMP_REG 0x00
#define TEMP_SCALE 500

// STLM75 — 7-bit address 0b1001001 = 0x49
// LiteI2C takes 7-bit address directly (no shift needed)
#define STLM75_I2C_ADDR   0x49
#define STLM75_TEMP_REG   0x00

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
void i2c_write(uint8_t devaddr, uint8_t subaddr, uint8_t data);
void i2c_scan(void);
void adv7391_write(uint8_t devaddr, uint8_t subaddr, uint8_t data);
void adv7391_testpattern();

void uart_write_word(const char *word)
{
    while (*word)
    {
        uart_write(*word);
        word++;
    }
    uart_write('\n');
}
//
// void adv7391_write(uint8_t devaddr, uint8_t subaddr, uint8_t data)
// {
//     static uint8_t len_rx, len_tx, recover;
//     static uint32_t i2c_setting_reg;
//     uint32_t i2c_data;
//     uint8_t status;
//
//     len_rx = 0;
//     len_tx = 2;
//     recover = 0;
//
//     i2c_setting_reg = (len_tx & 0x7) | ((len_rx & 0x7) << 8) | (recover << 16);
//
//     // Write date data
//     i2c_data = 0;
//     i2c_data = (subaddr << 8) | (data);
//     i2c_master_settings_write(i2c_setting_reg);
//     i2c_master_addr_write(devaddr);
//     //   i2c_master_rxtx_write(0x0000001E); // Start at register 0x04
//     i2c_master_rxtx_write(i2c_data);
//
//     while (!(i2c_master_status_read() & 0x01))
//         ;
//
//     status = i2c_master_rxtx_read();
// }
//
// void adv7391_testpattern()
// {
//     adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x17, 0x02);
//     adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x00, 0x1E);
//     adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x80, 0x11);
//     adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x82, 0xCB);
//     adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x84, 0x40);
//     adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x8C, 0xCB);
//     adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x8D, 0x8A);
//     adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x8E, 0x09);
//     adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x8F, 0x2A);
// }
//
// void i2c_write(uint8_t devaddr, uint8_t subaddr, uint8_t data)
// {
//     static uint8_t len_rx, len_tx, recover;
//     static uint32_t i2c_setting_reg;
//     uint32_t i2c_data;
//     uint8_t status;
//
//     len_rx = 0;
//     len_tx = 2;
//     recover = 0;
//
//     i2c_setting_reg = (len_tx & 0x7) | ((len_rx & 0x7) << 8) | (recover << 16);
//
//     // Write date data
//     i2c_data = 0;
//     i2c_data = (subaddr << 8) | (data);
//     i2c_master_settings_write(i2c_setting_reg);
//     i2c_master_addr_write(devaddr);
//     //   i2c_master_rxtx_write(0x0000001E); // Start at register 0x04
//     i2c_master_rxtx_write(i2c_data);
//
//     while (!(i2c_master_status_read() & 0x01))
//         ;
//
//     status = i2c_master_rxtx_read();
// }
//
// void i2c_scan(void)
// {
//     char msg[32];
//
//     for (uint8_t addr = 0x00; addr < 0x80; addr++)
//     {
//         i2c_master_addr_write(addr);
//         i2c_master_settings_write(0x00000100);
//         while (!(i2c_master_status_read() & 0x01))
//             ;
//
//         if (!(i2c_master_status_read() & 0x04))
//         {
//             printf(msg, sizeof(msg), "Found I2C device at 0x%02X", addr);
//             uart_write_word(msg);
//         }
//     }
// }
//
// int16_t stlm75_read_temperature_raw(void);
// uint8_t i2c_probe(uint8_t addr);
//
// uint8_t i2c_probe(uint8_t addr)
// {
//     i2c_master_addr_write(addr);
//     i2c_master_settings_write(0x00000100); // tx=1, rx=0 — just send address, no data
//     while (!(i2c_master_status_read() & 0x01));
//
//     // bit2 = NACK flag: 0 = ACK (device present), 1 = NACK (no device)
//     return !(i2c_master_status_read() & 0x04);
// }
//
// int16_t stlm75_read_temperature_raw(void)
// {
//     uint32_t raw;
//
//     // Point to temperature register
//     i2c_master_addr_write(STLM75_I2C_ADDR);
//     i2c_master_rxtx_write(STLM75_TEMP_REG);
//     i2c_master_settings_write(0x00000101); // tx=1, rx=0, no recover
//     while (!(i2c_master_status_read() & 0x01));
//
//     // Read 2 bytes from temperature register
//     i2c_master_addr_write(STLM75_I2C_ADDR | 0x01); // set read bit
//     i2c_master_settings_write(0x00000200);           // tx=0, rx=2
//     while (!(i2c_master_status_read() & 0x02));
//
//     raw = i2c_master_rxtx_read(); // 16-bit: MSB=upper byte, LSB=lower byte
//
//     // STLM75: upper 9 bits are temp data, bit15..7
//     // Shift right 7 to get 9-bit signed value (0.5°C per LSB)
//     int16_t temp_raw = (int16_t)(raw >> 7);
//
//     return temp_raw; // unit: 0.5°C steps
// }

int main(void)
{
    char buffer[32];

    // uart_init();
    printf("mulaiiii\r\n");
    // uart_write_word("mulai\r\n");
    uart_write_word("STLM75 Temperature Reader on Zynq Z020\r\n");

    /*uint32_t timeout;
    timeout = 100000;
    while (!(i2c_master_status_read() & 0x01) && --timeout);
    if (!timeout) {
        printf("I2C timeout!\n");
        // still toggle LED so we know firmware is alive
        led_state ^= 1;
        status_led_out_write(led_state);
        busy_wait(1000);
        continue;
    }*/

    // i2c_master_active_write(1);
    //
    // uint8_t led_state = 1;
    // status_led_out_write(led_state); // initialize LED off
    //
    // uint8_t sensor_present = 0;
    //
    // // Probe for STLM75 at 0x49
    // sensor_present = i2c_probe(STLM75_I2C_ADDR);
    // if (sensor_present) {
    //     printf("STLM75 found at 0x%02X\r\n", STLM75_I2C_ADDR);
    // } else {
    //     printf("STLM75 NOT found at 0x%02X — LED will not blink\r\n", STLM75_I2C_ADDR);
    // }

    while (1)
    {
        // if (sensor_present) {
        //     int16_t raw = stlm75_read_temperature_raw();
        //
        //     int temp_int  = raw / 2;
        //     int temp_frac = (raw & 1) ? 5 : 0;
        //
        //     if (raw < 0 && temp_frac != 0) {
        //         temp_int -= 1;
        //         temp_frac = 5;
        //     }
        //
        //     printf("Temperature: %d.%d C\r\n", temp_int, temp_frac);
        //
        //     led_state ^= 1;
        //     status_led_out_write(led_state);
        // }
        //
        // busy_wait(1000);
    }

    return 0;
}
