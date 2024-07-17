#include <stdio.h>



void traverse(int level, int indent){

    for(int i = 0; i < indent; i ++){
        printf("  ");
    }
    printf("進入 traverse(%d)\n", level);
    
    if (level < 4) {
        traverse(level + 1, indent + 1);
    }
    
    for(int i = 0; i < indent; i ++){
        printf("  ");
    }
    printf("離開 traverse(%d)\n", level);
    
}

int main(void){

    traverse(1, 0);
    return 0;

}