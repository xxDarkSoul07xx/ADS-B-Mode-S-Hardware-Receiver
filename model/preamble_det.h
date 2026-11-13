#ifndef PREAMBLE_DET_H
#define PREAMBLE_DET_H

#include <stdint.h>

int preamble_detect(const uint8_t *samples, int n, int *positions, int max_pos, const uint8_t *preamble);

#endif