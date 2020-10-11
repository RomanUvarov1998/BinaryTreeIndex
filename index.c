#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "index.h"

struct node_t* 
create_node() {
    struct node_t *allocated_node = (struct node_t *)malloc(sizeof(struct node_t));
    if (allocated_node == NULL) return NULL;

    allocated_node->children[0] = NULL;
    allocated_node->children[0] = NULL;
    allocated_node->string = NULL;

    return allocated_node;
}

enum IndexOperationResult 
try_set_node_string(struct node_t *node, const char *content) {
    if (content == NULL) return NullContentToAddErr;
    if (node == NULL) return NullRootErr;
    
    char *allocated_string = (char *)malloc(strlen(content) + 1);
    if (allocated_string == NULL) return ContentMallocErr;

    strcpy(allocated_string, content);

    node->string = allocated_string;

    return ValueAddedSuccessfully;
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

enum IndexOperationResult 
try_add_value(struct node_t *root, uint32_t key, const char *content) {
    if (root == NULL) return NullRootErr;

    struct node_t *current_node = root, **next_node_p;
    uint32_t current_key = key;

    printf("root ");
    while (current_key) {
        uint32_t lsb = current_key & 1;

        next_node_p = &(current_node->children[lsb]);

        printf("-> [%i%c] ", lsb, next_node_p == NULL ? 'n' : ' ');

        if (*next_node_p == NULL) {
            *next_node_p = create_node();

            if (*next_node_p == NULL) return NewNodeMallocErr;
        } 

        current_node = *next_node_p;

        current_key >>= 1;
    }

    return current_node->string == NULL ?
        try_set_node_string(current_node, content) :
        ValueForKeyAlreadyExists;
}

enum IndexOperationResult 
try_find_value(struct node_t *root, uint32_t key, char *out) {
    if (root == NULL) return NullRootErr;

    struct node_t *current_node = root;
    uint32_t current_key = key;

    while (current_key) {
        uint32_t lsb = current_key & 1;

        current_node = current_node->children[lsb];

        printf("-> %i ", lsb);

        if (current_node == NULL) return NodeNotFound;

        current_key >>= 1;
    }

    if (current_node->string != NULL) {
        strcpy(out, current_node->string);
        return FoundNodeSawValue;
    } else {
        return FoundNodeSawNULL;
    }
}

static char *ErrorMsgs[] = {
    "NullRootErr",
    "NullContentToAddErr",
    "NewNodeMallocErr",
    "ContentMallocErr",
    "ValueAddedSuccessfully",
    "ValueForKeyAlreadyExists",
    "FoundNodeSawNULL",
    "FoundNodeSawValue",
    "NodeNotFound"
};
void print_result(enum IndexOperationResult result) {
    printf("%s\n\r", ErrorMsgs[result]);
}