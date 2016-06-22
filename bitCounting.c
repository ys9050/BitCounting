#include <stdio.h>
#include <stdlib.h>

int* CountBits(int n, int* result_size) {

    //initialization of values
    int temp = n;
    int counter = 0;
    *result_size = 0;

    //use temp value to calculate number of binary digits
    while(temp){
        //if digit bit is one, then increment result_size
        if(temp&1) *result_size = *result_size+1;
        temp >>= 1;
        counter++;
    }


    //allocate memory for array for the result
    int* arr = malloc((*result_size+1)*(sizeof(int)));

    //assign temp as *result_size so that we don't currupt its data
    temp = *result_size;
    //assign first value of answer (result_size) in the array
    arr[0] = *result_size;
    
    /* Test Code. Ignore.
    printf("n is %d \n", n);
    printf("temp is %d \n", temp);
    printf("arr[0] is %d \n", arr[0]);
    printf("counter is %d \n", counter);
    */

    //use n parameter to assign answers in the array
    while(n){
        if(n&1){
            arr[temp] = counter;
            temp--;
        }
        n >>= 1;
        counter--;
    }

    //increment *result_size by one, since the arr[0] is not part of bit answer
    *result_size = *result_size+1;


   return arr; 
    

}

int main() {
    FILE *f = fopen("output.txt", "w+");
    
    int res_size;
    int* res;
    int _n;

    scanf("%d", &_n);

    res = CountBits(_n, &res_size);

    int res_i;

    for(res_i=0; res_i < res_size; res_i++) {

        printf("%d\n", res[res_i]);
        fprintf(f, "%d\n", res[res_i]);

    }

    fclose(f);

    return 0;

    
}
