#include <stdio.h>
#include "index.h"

int main() {
    struct node_t *index = create_node("asdsad");
    if (index == NULL) {
        return 1;
    }

    char inp[500];
    while (1) {
        scanf("%5s", inp);
        printf("Hello, %s!\n\r", inp);
    }
    
    free_node(index);

    return 0;
}