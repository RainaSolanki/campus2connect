#include <stdio.h>

int main(){
    double num1, num2 , result;
    char op;
    char choice;

    do {

        printf("Enter first number : ");
        scanf("%lf" , &num1);

        printf("Enter second number : ");
        scanf("%lf" , &num2);

        printf("Select operation to perform (+ , - , * , /) : ");
        scanf(" %c" , &op);

        switch (op) {

            case '+' :
                result = num1 + num2 ;
                printf("Result : %.2lf\n" , result);
                break;

            case '-' :
                result = num1 - num2 ;
                printf("Result : %.2lf\n" , result);
                break;

            case '*' :
                result = num1 * num2 ;
                printf("Result : %.2lf\n" , result);
                break;
                
            case '/' :
                if(num2 == 0){
                    printf("Error : Division by Zero is not allowed. \n");
                }
                else {
                    result = num1/num2 ;
                    printf("Result : %.2lf\n" , result);
                }
                break;
            default:
                printf("Invalid Operation. \n");

        }

        printf("Do you want to perform another calculation ? (y/n) : ");
        scanf(" %c" , &choice);

    }while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the calculator! \n");

    return 0;

}