#ifndef std_node_h
#define std_node_h

struct std_node {
    int id;
    char name[50];
    struct std_node *next;
};
typedef struct std_node STD;
typedef STD* NodePtr; 

#endif /* node_h */

