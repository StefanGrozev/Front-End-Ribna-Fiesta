#pragma warning(disable : 4996)
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>

//global variables declaration
char* input_url = "C:\\tu_ribna_fiesta\\PIK2\\ribna_fiesta\\Database\\data.txt";
char* output_url = "C:\\tu_ribna_fiesta\\PIK2\\ribna_fiesta\\Database\\data.bin";

typedef struct Max {
    float value;
    int id;
}Max_t;

Max_t max;

void readHighestResult() {
    Max_t max = { 0 };

    FILE* fp_b = fopen(output_url, "rb");
    if (NULL != fp_b) {
        size_t freadresult = fread(&max, sizeof(Max_t), 1, fp_b);
        fclose(fp_b);
    }

    printf("Highest expense is: %.2f, type is: %d\n", max.value, max.id);
}

void readMonthlyResult() {
    float sum[12] = { 0 };
    FILE* fp_b = fopen(output_url, "rb");
    if (NULL != fp_b) {
        size_t freadresult = fread(sum, sizeof(float), 12, fp_b);
        fclose(fp_b);
    }
    for (int i = 0; i < 12; i++) {
        printf("Month %d: %.2f\n", i + 1, sum[i]);
    }
}

int main() {

    calculateMonthlyExpense();
    readMonthlyResult();
    calculateHighestExpense();
    readHighestResult();

    return 0;
}
