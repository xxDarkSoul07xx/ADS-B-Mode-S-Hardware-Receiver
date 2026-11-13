#ifndef CRC24_H
#define CRC24_H

#include <stdint.h>

uint32_t crc24(const uint8_t *data, int len_bits);

#endif