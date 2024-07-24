#include <stdio.h>


// void function(int (*v) [3]){
//     printf("\n[ ");
//     for(int i = 0; i < 3; i ++){
//         printf("%d ", (*v)[i]);
//     }
//     printf("]\n\n");
// }

int main(void){

    int v[3] = {1, 2, 3};
    function((int *)v);
    function(v); // v == &v[0] == 傳陣列中第1個元素的位置 
    function(&v); // &v == 傳整個3個元素的陣列的位置

    return 0;

}

