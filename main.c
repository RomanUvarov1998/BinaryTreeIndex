#include <stdio.h>
#include <stdint.h>
#include "index.h"

int main() {
    struct node_t *index = create_node("asdsad");
    if (index == NULL) {
        return 1;
    }

    char cmd[1] = {0}, value_buf[100];
    int key = 0;
    enum IndexOperationResult result;

    while (*cmd != 'e') {
        *cmd = 0;
        printf("cmd> ");
        scanf("%s", cmd);

        switch (*cmd) {
            case 'a': // add
                scanf("%i", &key);
                scanf("%s", value_buf);
                printf("Adding for key %i:\n\r", key);

                result = try_add_value(index, key, value_buf);
                print_result(result);
                break;
            case 'f': // add
                scanf("%i", &key);
                printf("Searching for key %i:\n\r", key);
                result = try_find_value(index, key, value_buf);
                print_result(result);
                if (result == FoundNodeSawValue) {
                    printf("Found value: %s\n\r", value_buf);
                } 
                break;
            case 'e': // add
                printf("Exiting...\n\r");
                break;
            default:
                printf("Usage: 'a <key>' - add, 'f <key>' - find, 'e' - exit\n\r");
                break;
        }
    }
    
    free_node(index);

    return 0;
}