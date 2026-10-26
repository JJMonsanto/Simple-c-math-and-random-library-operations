#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {
    int randomNum;
    double number, product;

    srand((unsigned int)time(NULL));

    printf("Enter a number: ");
    if (1 != scanf("%lf", &number)) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    printf("The number is: %.2f\n", number);

    randomNum = (rand() % 35) + 3;
    printf("The random number is: %d\n", randomNum);

    product = number * randomNum;
    printf("The product of the two numbers is: %.2f\n", product);

    printf("The ceiling of the random number is: %.2f\n", ceil(randomNum));
    printf("The floor of the product is: %.2f\n", floor(product));
    printf("%.2f raised to the power of %d is: %.2f\n", number, randomNum, pow(number, randomNum));
    printf("The square root of the random number is: %.2f\n", sqrt(randomNum));

    return 0;
}
