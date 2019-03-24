

#include "Friends.h"

#ifndef Set_functions_h
#define Set_functions_h




int set_init(struct BiTNode **set);//
int set_destroy(struct BiTNode **set);//
int set_insert(struct BiTNode *set, struct BiTNode *set2);//
int set_remove(struct BiTNode **set, struct BiTNode *set2);//
struct BiTNode** set_intersection(struct BiTNode *set1, struct BiTNode *set2, struct BiTNode *intersection[]);//
struct BiTNode** set_union(struct BiTNode *set1, struct BiTNode *set2, struct BiTNode *Union[]);//
struct BiTNode** set_difference(struct BiTNode *set1, struct BiTNode *set2, struct BiTNode *difference[]);//
int set_size(struct BiTNode *set);//
int set_member(struct BiTNode *set, struct BiTNode *toBeFound);//
int set_subset(struct BiTNode *set, struct BiTNode *sub);//
int set_equal(struct BiTNode *set1, struct BiTNode *set2);//


int InsertAVLforSet(BiTree *T, BiTree insert, bool *taller);
BiTree SearchAVLforSet(BiTree AVLTree, char name[]);
int DeleteAVLforSet(BiTree *AVLTree, char name[]);//

#endif 
