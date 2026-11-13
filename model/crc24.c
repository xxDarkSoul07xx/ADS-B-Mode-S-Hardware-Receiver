#include <stdint.h>
#include <stdio.h>

#define CRC24_POLY 0xFFF409

uint32_t crc24(const uint8_t *data, int len_bits) {
    uint32_t crc = 0;

    for (int i = 0; i < len_bits; i++) {
        // extract current bit
        int byte_idx = i / 8;
        int bit_idx = 7 - (i % 8);
        int bit = (data[byte_idx] >> bit_idx) & 1;

        int top = (crc >> 23) & 1;
        crc = crc << 1;
        crc |= bit;
        crc &= 0xFFFFFF; // make 24 bits
        if (top == 1) crc ^= CRC24_POLY;

    }

    return crc & 0xFFFFFF;
}

int main() {
    uint8_t msg[] = {0x8D, 0x48, 0x40, 0xD6, 0x20, 0x2C, 0xC3, 0x71, 0xC3, 0x2C, 0xE0, 0x57, 0x60, 0x98};

    // when you feed a valid ads-b message, you should get 0
    uint32_t full = crc24(msg, 112);
    printf("%s\n", full == 0 ? "PASS" : "FAIL");

    return 0;
}