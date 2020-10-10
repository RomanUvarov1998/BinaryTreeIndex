#ifndef INDEX_GUARD
    #define INDEX_GUARD
    
    struct node_t
    {
        struct node_t* children[2];
        char* string;
    };

    struct node_t* create_node(const char* content);

    void free_node(struct node_t *node);
#endif