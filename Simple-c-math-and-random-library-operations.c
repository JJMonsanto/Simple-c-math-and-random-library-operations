#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int randomNum;
    double number, product, ceilingVal, floorVal, powerVal, sqrtVal;

    srand(time(NULL));

    printf("Enter a number:                  ");
    scanf("%lf", &number);

    printf("\nEntered number:                  %.2f\n", number);

    randomNum = (rand() % 35) + 3;
    printf("Random number (3 to 37):         %d\n", randomNum);

    product = number * randomNum;
    printf("Product of the two numbers:      %.2f\n", product);

    ceilingVal = ceil(randomNum);
    printf("Ceiling of random number:        %.2f\n", ceilingVal);

    floorVal = floor(product);
    printf("Floor of product:                %.2f\n", floorVal);

    powerVal = pow(number, randomNum);
    printf("Number raised to random power:   %.2f\n", powerVal);

    sqrtVal = sqrt(randomNum);
    printf("Square root of random number:    %.2f\n", sqrtVal);

    return 0;
}
