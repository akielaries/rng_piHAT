#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *file = fopen("random_numbers.bin", "wb");
    
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    const int num_random_numbers = 10000000;

    srand(time(NULL));

    for (int i = 0; i < num_random_numbers; i++) {
        unsigned int rand_num = rand();
        fwrite(&rand_num, sizeof(rand_num), 1, file);
    }

    fclose(file);

    printf("Generated %d random numbers and saved to random_numbers.bin\n", num_random_numbers);
    
    return 0;
}

