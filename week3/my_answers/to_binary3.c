#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
	int result[30] = {0}, i = 0, input_num;
     
	printf("Enter number you wish to convert to binary form: ");
    scanf("%d", &input_num);
	printf("The number that was entered is: %d\n"
		"The binary is: ", input_num);
    
    while (input_num) {
		result[i] = input_num % 2;
		if (input_num){
			input_num /= 2;
        	i++;
		}
	}

	for (i -= 1; i >= 0; i--) {
		printf("%d", result[i]);
	}

	printf("\n");
	return 0;
}
