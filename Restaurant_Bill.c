/*
1. Initailize food prices to an array where I will randomly choose one
2. calculate tax and tip of chosen food price
3. calculate total price
4. print output according to which price we have
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv){
    //takes in input from command line
    char *input1 = argv[1];
    char *input2 = argv[2];
    int tax = atoi(input1);
    int tip = atoi(input2);

    //array of food prices
    double food[] = {9.95, 4.55, 13.25, 22.35};

    //random number generator
    time_t t;
    srand((unsigned) time(&t));

    //choose random food
    double foodPrice = food[rand() % 4] ;

    //calculates tax and tip
    double taxMult = (double)tax/100;
    double tipMult = (double)tip/100;
    double outTax = foodPrice * taxMult;
    double outTip = foodPrice * tipMult;

    //calculates total
    double total = foodPrice + outTax + outTip;

    //print correct food
    if(foodPrice == 9.95){
        printf("Salad($%.2lf), tax: $%.2lf, tip: $%.2lf, total: $%.2lf", foodPrice, outTax, outTip, total);
    }
    else if(foodPrice == 4.55){
        printf("Soup($%.2lf), tax: $%.2lf, tip: $%.2lf, total: $%.2lf", foodPrice, outTax, outTip, total);
    }
    else if(foodPrice == 13.25){
        printf("Sandwich($%.2lf), tax: $%.2lf, tip: $%.2lf, total: $%.2lf", foodPrice, outTax, outTip, total);
    }
    else if(foodPrice == 22.35){
        printf("Pizza($%.2lf), tax: $%.2lf, tip: $%.2lf, total: $%.2lf", foodPrice, outTax, outTip, total);
    }

    return 0;
}