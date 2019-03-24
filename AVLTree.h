

#ifndef Header_h
#define Header_h
#define OK 1
#define ERROR 0
#define ARRAY_LENGTH 130
#define LH 1
#define EH 0
#define RH -1
#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) < (b))
#define LQ(a,b) ((a) <= (b))
#define AVL_SUCCESS 1
#define AVL_FAILED 0
#define ARRAY_SIZE 130
#define SETS_LENGTH 30


#include <stdbool.h>
#include <time.h>
#include "Friends.h"

typedef int TElemType;

struct Data{
    char ID[20];
    char name[20];
    char hobby[20];
    struct BiTNode *Root_Friend;
    struct BiTNode *Root_Fans;
    struct BiTNode *Root_Spotted;
};

typedef struct BiTNode{
    int balance;
    TElemType data; 
    struct Data *profile;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


int checkBalance(BiTree AVLTree);
BiTree findSuperLocation(BiTree AVLTree, TElemType insertData);
int Visit(TElemType e);
int InsertAVL2(BiTree *AVLTree, TElemType data, bool *taller);
void LeftBalance(BiTree *T);
void RightBalance(BiTree *T);
void R_Rotate(BiTree *p);
void L_Rotate(BiTree *p);
void LeftBalanceforDeletion(BiTree *T);
void RightBalanceforDeletion(BiTree *T);
int InitAVL(BiTree *AVLTree);
int DestroyAVL(BiTree *AVLTree);
BiTree SearchAVL(BiTree AVLTree, TElemType data);
int InsertAVL(BiTree *AVLTree, TElemType insertData);
int DeleteAVL(BiTree *AVLTree, TElemType deletedData);
int TraverseAVL(BiTree AVLTree);
int PreorderAndInOrderTraverseAVL(BiTree AVLTree);
int BiTreeDepth(BiTNode *T);
int Save(BiTree store[], int data_number);
int Load(BiTree *AVLTree, int data_number);
BiTree PointerFinder(BiTree store[],int number, char name[]);

int DataGenerator(int number);
int NameGenerator(int number, int length, char name[][20]);
int HobbyGenerator(int number,char name[][20]);
int IDGenerator(int number, char name[][20]);

int mutualSpotted(BiTree A, BiTree B, BiTree mutualSpottedSet[]);
int mutualHobby(BiTree toBeCompared, BiTree toCompare);
int friends_Friend(BiTree AFriend, BiTree friends_FriendSet[]);

typedef struct Queue{
    BiTNode *data;
    struct Queue *next;
} Queue;

struct indicator{
    Queue *front;
    Queue *rear;
}Indicator;


void CreateQueue(Queue **head);
int AddQueue(Queue **head, BiTNode *elem);
BiTNode* DeleteQueue(Queue **head);
int QueueIsEmpty(Queue **head);



typedef struct Stack{
    BiTNode* stack[ARRAY_LENGTH+1];
    int length;
} Stack;

int InitStack(Stack **S);
int StackEmpty(Stack *S);
int GetTop(Stack *S, BiTNode **p);
int Push(Stack *S, BiTNode *p);
BiTNode* Pop(Stack *S, BiTNode **p);
int DumpStack(Stack *S);



#endif 
