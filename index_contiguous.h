#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef INDEX_FIXED_G
    #define INDEX_FIXED_G

    #define FI_LEN (3)
    #define STR_LEN (20)

    enum AddValueResult {
        NullRootErr,
        KeyMustBeGreaterThanZero,
        Success,
        AllOccupied,
    };

    struct node_c_t {
        uint8_t ind_0;
        uint8_t ind_1;
        char string[STR_LEN];
    };

    void 
    fi_init(struct node_c_t *nodes);

    enum AddValueResult
    fi_add_value(struct node_c_t *nodes, uint8_t key, const char *string);
    
    void
    fi_print_result(enum AddValueResult result);
#endif