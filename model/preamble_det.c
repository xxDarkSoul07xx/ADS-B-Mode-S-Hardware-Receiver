#include <stdint.h>
#include <stdio.h>


int preamble_detect(const uint8_t *samples, int n, int *positions, int max_pos, const uint8_t *preamble){
    int count = 0;

    for (int i = 0; i <= n - 16; i++) {
        int match = 1;
        for (int j = 0; j < 16; j++) {
            if (samples[i + j] != preamble[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            if (count < max_pos) positions[count] = i;
            count++;
        }
    }
    return count;
}

int main(){
    uint8_t preamble[16] = {1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,1};

    // preamble starts at index 3
    uint8_t stream[] = {0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0};

    int positions[10];
    int found = preamble_detect(stream, 22, positions, 10, preamble);

    printf("found: %d\n", found);
    printf("position: %d\n", positions[0]);
    printf("%s\n", (found == 1 && positions[0] == 3) ? "PASS" : "FAIL");

    return 0;
}