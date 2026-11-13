#ifndef PPM_DEMOD_H
#define PPM_DEMOD_H
#include <stdint.h>
int ppm_demod(const uint16_t *samples, int num_bits, uint8_t *out);
#endif