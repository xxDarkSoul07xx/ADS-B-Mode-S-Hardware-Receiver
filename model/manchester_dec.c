#include <stdint.h>
#include <stdio.h>

int manchester_decode(const uint8_t *samples, int num_bits, uint8_t *out){
    int half1 = 0;
    int half2 = 1;
    int error = 0;
    for (int i = 0; i < num_bits; i++){
        // 0, 1 = low
        // 1, 0 = high
        // equal = error
        if (samples[half1] == 0 && samples[half2] == 1) out[half1 / 2] = 0;
        if (samples[half1] == 1 && samples[half2] == 0) out[half1 / 2] = 1;
        if (samples[half1] == samples[half2]) error++;
        half1 += 2;
        half2 += 2;
    }
    return error;
}

int main() {
    uint8_t samples[] = {1, 0, 0, 1, 1, 0, 0, 1};
    uint8_t expected[] = {1, 0, 1, 0};
    uint8_t res[4] = {};

    uint32_t decoded = manchester_decode(samples, 4, res);
    int pass = 1;
    for (int i = 0; i < 4; i++) {
        if (res[i] != expected[i]) pass = 0;
    }
    printf("%s\n", pass ? "PASS" : "FAIL");

    return 0;
}