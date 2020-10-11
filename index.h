#include <stdint.h>

#ifndef INDEX_GUARD
    #define INDEX_GUARD
    
    struct node_t {
        struct node_t* children[2];
        char* string;
    };

    struct node_t* 
    create_node();

    void free_node(struct node_t *node);

    enum IndexOperationResult {
        NullRootErr,
        NullContentToAddErr,
        NewNodeMallocErr,
        ContentMallocErr,
        ValueAddedSuccessfully,
        ValueForKeyAlreadyExists,
        FoundNodeSawNULL,
        FoundNodeSawValue,
        NodeNotFound
    };
    enum IndexOperationResult 
    try_add_value(struct node_t *root, uint32_t key, const char *content);
      
    enum IndexOperationResult 
    try_find_value(struct node_t *root, uint32_t key, char *out);

    void print_result(enum IndexOperationResult result);
#endif