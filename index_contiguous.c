#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "index_contiguous.h"

enum AddValueResult
find_next_free_node_index(const struct node_c_t *nodes, uint8_t *ind);

const uint8_t NULL_INDEX = 0;

void 
fi_init(struct node_c_t *nodes) {
    int i;
    for (i = 0; i < FI_LEN; ++i) {
        nodes[i].ind_0 = NULL_INDEX;
        nodes[i].ind_1 = NULL_INDEX;
        nodes[i].string[0] = 0;
    }
}

enum AddValueResult
fi_add_value(struct node_c_t *nodes, uint8_t key, const char *string) {
    if (nodes == NULL) return NullRootErr; 
    if (key == 0) return KeyMustBeGreaterThanZero; 

    struct node_c_t *current_node = nodes;
    uint8_t current_key = key, next_ind;
    enum AddValueResult add_node_result;

    while (current_key != 0) {
        int8_t lsb = current_key & 1;

        next_ind = lsb ? (current_node->ind_0) : (current_node->ind_1);

        printf("next ind %i; ", next_ind);
        printf("lsb %i; ", lsb);
        printf("key %i\r\n", current_key);
        
        if (next_ind == NULL_INDEX) {
            printf("adding node...\r\n");
            add_node_result = find_next_free_node_index(nodes, &next_ind);

            if (add_node_result != Success) return add_node_result;
            printf("added node on %i,\r\n", next_ind);
        }

        if (lsb) {
            current_node->ind_1 = next_ind;
        } else {
            current_node->ind_0 = next_ind;
        }

        current_node = nodes + next_ind;

        current_key >>= 1;
        printf("\r\n");
    }

    printf("added value '%s' to index!", string);

    return Success;
}

enum AddValueResult
find_next_free_node_index(const struct node_c_t *nodes, uint8_t *ind) {
    if (nodes == NULL) return NullRootErr; 

    uint8_t i = 1; // because 1st node is root
    for (; i < FI_LEN; ++i) {
        printf("node %i: ", i);
        printf("ind0: %i, ", nodes[i].ind_0);
        printf("ind1: %i, ", nodes[i].ind_1);

        if (nodes[i].ind_0 == NULL_INDEX && nodes[i].ind_1 == NULL_INDEX) {
            *ind = i;
            printf(" is free!\n\r");
            return Success;
        }
        printf("not free\n\r");
    }

    return AllOccupied;
}

static char *Results[] = {
    "NullRootErr",
    "KeyMustBeGreaterThanZero",
    "Success",
    "AllOccupied",
};
void
fi_print_result(enum AddValueResult result) {
    printf("%s\n\r", Results[result]);
}