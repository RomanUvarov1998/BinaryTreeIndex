#include <stdio.h>
#include <stdint.h>
// #include "index.h"
#include "index_contiguous.h"

int main() {
    struct node_c_t fixed_index[FI_LEN];
    printf("size %lu\n\r", sizeof(fixed_index));

    fi_init(fixed_index);

    enum AddValueResult result;

    result = fi_add_value(fixed_index, 200, "value1");
    fi_print_result(result);
    result = fi_add_value(fixed_index, 200, "value2");
    fi_print_result(result);

    return 0;

    // struct node_t *index = create_node(NULL);
    // if (index == NULL) {
    //     return 1;
    // }

    // char cmd[1] = {0}, value_buf[100];
    // int key = 0;
    // enum IndexOperationResult result;

    // while (*cmd != 'e') {
    //     *cmd = 0;
    //     printf("cmd> ");
    //     scanf("%s", cmd);

    //     switch (*cmd) {
    //         case 'a': // add
    //             scanf("%i", &key);
    //             scanf("%s", value_buf);
    //             printf("Adding for key %i:\n\r", key);

    //             result = try_add_value(index, key, value_buf);
    //             print_result(result);
    //             break;
    //         case 'f': // add
    //             scanf("%i", &key);
    //             printf("Searching for key %i:\n\r", key);
    //             result = try_find_value(index, key, value_buf);
    //             print_result(result);
    //             if (result == FoundNodeSawValue) {
    //                 printf("Found value: %s\n\r", value_buf);
    //             } 
    //             break;
    //         case 'e': // add
    //             printf("Exiting...\n\r");
    //             break;
    //         default:
    //             printf("Usage: 'a <key> <value>' - add, 'f <key>' - find, 'e' - exit\n\r");
    //             break;
    //     }
    // }
    
    // free_node(index);

    // return 0;
}