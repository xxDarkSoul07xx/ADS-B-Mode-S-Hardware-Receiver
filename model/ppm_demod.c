#include <stdint.h>
#include <stdio.h>

int ppm_demod(const uint16_t *samples, int num_bits, uint8_t *out){
    int error = 0;
    for (int i = 0; i < num_bits; i++){
        if (samples[2*i] > samples[2*i + 1]) out[i] = 1;
        else if (samples[2*i] < samples[2*i + 1]) out[i] = 0;
        else error++;
    }
    return error;
}

int main(){
    uint16_t samples[8] = {900, 100, 200, 800, 500, 500, 100, 700};
    int num_bits = 4; // should be half of the number of elements in samples since each bit uses 2 samples
    uint8_t out[8] = {}; // allocate enough space
    int errors = ppm_demod(samples, num_bits, out);
    if (errors == 1) printf("PASS"); // expecting 1 error
    else printf("FAIL");
}