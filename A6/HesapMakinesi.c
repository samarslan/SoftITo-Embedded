//
// Created by Samet Arslan on 6.08.2025.
//

#include <stdio.h>

int main(){

    int a=0,b=0;
    char operation;

    printf("Enter a: ");
    scanf("%d",&a);

    printf("Enter b: ");
    scanf("%d",&b);

    printf("Chose Operation: \n+ Addition\n- Subtraction\n/ Division\n* Multiplication\n");
    scanf(" %c",&operation);

    switch (operation) {
        case '+':
            printf("Addition\n");
            printf("a+b\n");
            printf("%d", a+b);
            break;
        case '-':
            printf("Subtraction\n");
            printf("a-b\n");
            printf("%d", a-b);
            break;
        case '*':
            printf("Multiplication\n");
            printf("a*b\n");
            printf("%d", a*b);
            break;
        case '/':
            printf("Division\n");
            printf("a/b\n");
            printf("%d", a/b);
            break;
        default:
            printf("Error\n");
            break;
    }

    return 0;
}