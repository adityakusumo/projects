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

uint32_t lm75_read_temperature(void)
{
    uint32_t temp_raw;
    uint32_t temp_milli_celsius;
    char msg[32];

    i2c_master_addr_write(LM75_I2C_ADDR);

    i2c_master_rxtx_write(LM75_TEMP_REG);

    i2c_master_settings_write(0x00000101);

    while (!(i2c_master_status_read() & 0x01))
        ;

    i2c_master_addr_write(LM75_I2C_ADDR | 0x01);

    i2c_master_settings_write(0x00000200);

    while (!(i2c_master_status_read() & 0x02))
        ;

    temp_raw = i2c_master_rxtx_read(); // Langsung baca seluruh 16-bit data

    // snprintf(msg, sizeof(msg), "Temp: %04x", temp_raw);
    // uart_write_word(msg);

    temp_raw = temp_raw / 128; // Geser bit sesuai format LM75
    // temp_raw | 0b0000000000000000;
    // uint8_t data2 = ((temp_raw & 0b100000000) >> 8) & 0b11111111;
    // if (temp_raw & (1 << 8)) {  // Jika negatif (bit 10 = 1), lakukan sign extension
    // if(data2 == 0b00000001){
    // temp_raw -= (1 << 9);
    // }

    return temp_milli_celsius = temp_raw * TEMP_SCALE;
}

void adv7391_write(uint8_t devaddr, uint8_t subaddr, uint8_t data)
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
}

void check_hardware_value(void)
{
    char buffer[64];

    // Read the value driven by the Migen logic
    uint32_t hw_val = my_module_count_out_read();

    // Format and print it
    snprintf(buffer, sizeof(buffer), "Value from Migen: 0x%lx\n", hw_val);

    // Output to your console
    printf("%s", buffer);
}

uint8_t shift_pos = 0;
void vga_color_control(void)
{
    // Calculate the value: 0xFF shifted by 0, 8, or 16 bits
    uint32_t color_val = (0xAA << (shift_pos * 4));
    main_ctrl_reg_write(color_val);
    // main_ctrl_reg_write(0x7FFFF0);
    
    // Increment position: 0 -> 1 -> 2 -> 0...
    shift_pos++;
    if (shift_pos > 5)
    {
        shift_pos = 0;
    }
}

void const_led_blink_ms(uint32_t period){
    uint32_t clkdiv;
    clkdiv = 50000*period;
    my_blinker_period_write(clkdiv);
}

int main(void)
{
    char buffer[32];

    uart_init();
    printf("i love sawit menn >< <3\n\r");

    i2c_master_active_write(1);

    const_led_blink_ms(100);

    while (1)
    {
        vga_color_control();
        // snprintf(buffer, sizeof(buffer), "qiuqiu");
        check_hardware_value();
        // main_ctrl_write(!main_ctrl_read());
        if (main_button_read())
        {
            main_ctrl_write(0);
        }
        else
        {
            main_ctrl_write(1);
        }
        uart_write_word(buffer);
        adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x17, 0x02);
        adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x00, 0x1E);
        adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x80, 0x11);
        adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x82, 0xCB);
        adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x84, 0x40);
        adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x8C, 0xCB);
        adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x8D, 0x8A);
        adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x8E, 0x09);
        adv7391_write(ADV7390_SLAVE_ADDRESS_WRITE, 0x8F, 0x2A);
        busy_wait(50);
    }

    return 0;
}
