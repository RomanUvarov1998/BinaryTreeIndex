#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "index.h"

struct node_t* create_node(const char* content) {
    struct node_t *allocated_node = (struct node_t *)malloc(sizeof(struct node_t));
    if (allocated_node == NULL) {
        return NULL;
    }

    allocated_node->children[0] = NULL;
    allocated_node->children[0] = NULL;

    char *allocated_string = (char *)malloc(strlen(content) + 1);
    if (allocated_string == NULL) {
        free(allocated_node);
        return NULL;
    }

    strcpy(allocated_string, content);
    allocated_node->string = allocated_string;

    return allocated_node;
}

void free_node(struct node_t *node) {
    if (node != NULL) {
        free(node->string);

        int i;
        for (i = 0; i < 2; ++i) {
            free_node(node->children[i]);
        }        
    }

    free(node);
}

