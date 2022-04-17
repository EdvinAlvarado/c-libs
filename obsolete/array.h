typedef enum {
    INT,
    FLOAT,
    CHAR,
} array_type;

struct array{
    unsigned int size;
    void* ptr;
    array_type type;
};

// const struct arrayClass{
//     struct array (*new)(unsigned int arrsize, char* type);
//     // void (*print)(struct array *this);
//     // void (*print_f)(struct array *this);
//     // int (*sum)(struct array *this);
//     // float (*sumf)(struct array *this);
//     // int* (*at)(struct array *this, unsigned int pos);
//     // float* (*at_f)(struct array *this, unsigned int pos);
//     // void (*push_back)(struct array *this, int n);
//     // void (*push_back_f)(struct array *this, float n);
//     // void (*pop_back)(struct array *this);
//     // void (*insert)(struct array *this, unsigned int index, int n);
//     // void (*insert_f)(struct array *this, unsigned int index, float n);
//     // void (*pop)(struct array *this, unsigned int index);
// } array;