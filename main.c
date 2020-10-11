#include <stdio.h>
#include "index.h"

int main() {
    struct node_t *index = create_node("asdsad");
    if (index == NULL) {
        return 1;
    }

    char cmd[1] = {0};
    while (*cmd != 'e') {
        *cmd = 0;
        printf("cmd> ");
        scanf("%s", cmd);

        switch (*cmd) {
            case 'a': // add
                printf("Adding...\n\r");
                break;
            case 'f': // add
                printf("Finding...\n\r");
                break;
            case 'e': // add
                printf("Exiting...\n\r");
                break;
            default:
                printf("Usage: 'a' - add, 'f' - find, 'e' - exit\n\r");
                break;
        }
    }
    
    free_node(index);

    return 0;
}