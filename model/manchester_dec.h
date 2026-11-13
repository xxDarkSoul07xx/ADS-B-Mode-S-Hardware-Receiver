#ifndef MANCHESTER_DEC_H
#define MANCHESTER_DEC_H

#include <stdint.h>

int manchester_decode(const uint8_t *samples, int num_bits, uint8_t *out);

#endif