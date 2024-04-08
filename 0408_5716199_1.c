#include <stdio.h>
#define MAX_TERMS 101

struct term {
    float coef;
    int expon;
};

struct term terms[MAX_TERMS] = {
    {4.0, 3}, {3.0, 2}, {2.0, 1},{1.0,0},
    {3.0, 2}, {2.0, 1}, {8.0, 0},
};

int avail = 7;

void print_poly(int start, int end);
void poly_multiply(int As, int Ae, int Bs, int Be, int* Cs, int* Ce);

int main() {
    int Cs, Ce;
    printf("A=");
    print_poly(0, 3);
    printf("\nB=");
    print_poly(4, 6);

    poly_multiply(0, 3, 4, 6, &Cs, &Ce);
    printf("\nA*B=");
    print_poly(Cs, Ce);

    return 0;
}

void poly_multiply(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
    int i, j, k;
    int CSTART = avail;
    int CEND;
    float c[MAX_TERMS] = { 0 };

    for (i = As; i <= Ae; i++) {
        for (j = Bs; j <= Be; j++) {
            k = terms[i].expon + terms[j].expon;
            c[k] += terms[i].coef * terms[j].coef;
        }
    }

    for (k = MAX_TERMS - 1; k >= 0; k--) {
        if (c[k] != 0) {
            terms[avail].coef = c[k];
            terms[avail].expon = k;
            avail++;
        }
    }

    CEND = avail - 1;
    *Cs = CSTART;
    *Ce = CEND;
}

void print_poly(int s, int e) {
    int i;
    for (i = s; i < e; i++) {
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}