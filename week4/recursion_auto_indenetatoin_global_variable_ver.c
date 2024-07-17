#include <stdio.h>



int indent = 0;

void traverse(int level){

    for(int i = 0; i < indent; i ++){
        printf("  ");
    }
    printf("進入 traverse(%d)\n", level);

    indent++;
    if (level < 4) {
        traverse(level + 1);
    }
    indent--;
    
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
    printf("離開 traverse(%d)\n", level);

}

int main(void){

    traverse(1);
    return 0;

}