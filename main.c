#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Set_functions.h"
#include "Friends.h"
#include "AVLTree.h"
#include "windows.h" 
int DataGenerator2(int );
Stack *stack;
Queue *queue;
int insert_num=6;
int del_num=6;
int initial_num=6;
BiTree AVLTree = NULL;
int data;
int taller;


int main(int argc, const char * argv[]) {
    InitStack(&stack);
    CreateQueue(&queue);
    BiTree set1 = NULL, set2 = NULL;
    bool taller = false;
    bool hasInitialized = false, hasInitializedForSet = false;
    char hobby[20];
    BiTree store[ARRAY_LENGTH];
    BiTree sets[SETS_LENGTH];
    BiTree intersection[SETS_LENGTH];
    BiTree unionSet[SETS_LENGTH];
    BiTree difference[SETS_LENGTH];
    BiTree mutualSpottedSet[ARRAY_LENGTH];
    BiTree mutualHobbySet[ARRAY_LENGTH];
    BiTree friendSet[ARRAY_LENGTH];
    BiTree friends_FriendSet[ARRAY_LENGTH];
    char name2[20] = "bar";
    int size = -1, exist = -2, equal = -2;
    int indicator = 0;
/*****************************************初始化各元素保存数组************************************/  
    for (indicator = 0; indicator<20; indicator++) {
        hobby[indicator] = '\0';
    }
    
    for (indicator = 0; indicator<ARRAY_LENGTH; indicator++) {
        store[indicator] = NULL;
    }
    
    for (indicator = 0; indicator<SETS_LENGTH; indicator++) {
        sets[indicator] = NULL;
    }
    
    for (indicator = 0; indicator<SETS_LENGTH; indicator++) {
        intersection[indicator] = NULL;
    }
    
    for (indicator = 0; indicator<SETS_LENGTH; indicator++) {
        unionSet[indicator] = NULL;
    }
    
    for (indicator = 0; indicator<SETS_LENGTH; indicator++) {
        difference[indicator] = NULL;
    }
    
    for (indicator = 0; indicator<ARRAY_LENGTH; indicator++) {
        mutualSpottedSet[indicator] = NULL;
    }
    
    for (indicator = 0; indicator<ARRAY_LENGTH; indicator++) {
        friendSet[indicator] = NULL;
    }
    
    for (indicator = 0; indicator<ARRAY_LENGTH; indicator++) {
        friends_FriendSet[indicator] = NULL;
    }
    
    for (indicator = 0; indicator<ARRAY_LENGTH; indicator++) {
        mutualHobbySet[indicator] = NULL;
    }
/*****************************************初始化各元素保存数组结束************************************/   


// 主菜单界面
    int function = -1, furtherFunction = -1;
    int loop = 1, furtherLoop = 1;
    int data = -1, choice = -1;
    int data_number = -1;
    int indicator1 = -1, indicator2 = -1;
    int saveDataNumber = -1;
    char name[20];
    BiTree temp = NULL, temp2 = NULL;
    
    for (indicator = 0; indicator<20; indicator++) {
    	name[indicator] = '\0';
	}
    
    while (loop) {
    H:  system("cls");
		printf("1.AVL tree basic operations\n2.Set basic operations\n3.Application layer operations\n4.Exit\n");
        scanf("%d",&function);
        getchar();        
        if (function!=1 && function!=2 && function!=3 && function!=4) {
        	system("cls");
            goto H;
        }
        
        switch (function) {
        	
/**************************************AVL树基本数据表示层***********************************/
            case 1:
                while (furtherLoop) {
                K:  system("cls");
				    printf("1.initial AVL\n2.destroy AVL\n");
                    printf("3.search node\n4.insert node\n");
                    printf("5.delete node\n6.traverse AVL\n");
                    printf("7.exit\n");
                    scanf("%d",&furtherFunction);
                    getchar();
                    if (furtherFunction!=1 && furtherFunction!=2 && furtherFunction!=3 && furtherFunction!=4 && furtherFunction!=5 && furtherFunction!=6 && furtherFunction!=7) {
                        goto K;
                    }
                    
                    switch (furtherFunction) {
                        case 1:
                            InitAVL(&AVLTree);
                            printf("initial succeed！\n");
                            getchar();
                            getchar();
                            break;
                        case 2:
                            DestroyAVL(&AVLTree);
                            printf("destroy succeed！\n");
                            getchar();
                            getchar();
                            break;
                        case 3:
                            printf("the data of the node：");
                            scanf("%d",&data);
                            getchar();
                            temp = SearchAVL(AVLTree, data);
                            if(temp)
                            {
                            	printf("the location of the node %d is: %d\n",data,temp);
                            	getchar();	
							}
                            break;
                        case 4:
                            printf("the data of the new node：");
                            scanf("%d",&data);
                            InsertAVL2(&AVLTree, data, &taller);
                            printf("Insert succeed! \n");
        					getchar();
        					getchar();
                            break;
                        case 5:
                            printf("the data of the node to delete: ");
                            scanf("%d",&data);
                            getchar();
                            DeleteAVL(&AVLTree, data);
                            break;
                        case 6:
                            PreorderAndInOrderTraverseAVL(AVLTree);
                            break;
                        case 7:
                            furtherLoop = 0;
                            break;
                        default:
                            break;
                    }
                    printf("\n");
                }
                furtherFunction = -1;
                furtherLoop = 1;
                break;
/**************************************AVL树基本数据表示层结束***********************************/
        
        
/**************************************集合抽象层***********************************/       
            case 2:
            	
            	for (indicator = 0; indicator<20; indicator++) {
    				name[indicator] = '\0';
				}
                while (furtherLoop) {
                    /*默认对sets[0]进行操作*/
                F:  system("cls");
                    printf("1.Initialize the set\t2.Destroy the set\n");
                    printf("3.insert node\t4.delete node\n");
                    printf("5.Intersection\t6.Union\n");
                    printf("7.Difference\t8.Num of Set\n");
                    printf("9.Search node\t10.Subset\n");
                    printf("11.Equal\t12.Exit\n");
                    scanf("%d",&furtherFunction);
                    getchar();
                    if (furtherFunction!=1 && furtherFunction!=2 && furtherFunction!=3 && furtherFunction!=4 && furtherFunction!=5 && furtherFunction!=6 && furtherFunction!=7 && furtherFunction!=8 && furtherFunction!=9 && furtherFunction!=10 && furtherFunction!=11 && furtherFunction!=12) {
                        goto F;
                    }
                    
                    switch (furtherFunction) {
                        case 1: 
                        for(;initial_num<6;initial++)
                        {
                            set_init(&set1);
                        }
                            DataGenerator2(6);
                            Load(sets,6);
                            initial_num=6; 
                            hasInitializedForSet = true;
                            printf("\n"); 
                            printf("succeed! \n");
                            getchar();
                            break;
                        case 2:
                        	set_destroy(set1);
							//将每个树的根节点删除 
                            for (indicator = 0; indicator<SETS_LENGTH; indicator++) {
                                free(sets[indicator]);
                                sets[indicator] = NULL;
                            }
                            hasInitializedForSet = false;
                            printf("succeed! \n");
                            getchar();
                            break;
                        case 3:
                            if (hasInitializedForSet==false) {
                                printf("Please initialize first！\n");
                            }
                            else{
                            	//调用第一层函数，将数组成员增加，并将其插入到指定树中 
                                set_init(&set1);
                                printf("name:\n");
                                scanf("%s",name);
                                getchar();
                                strcpy(set1->profile->name, name);
                                printf("hobby:\n");
                                scanf("%s",hobby);
                                getchar();
                                strcpy(set1->profile->hobby, hobby);
                                for (indicator=0; indicator<SETS_LENGTH; indicator++) {
                                    if (sets[indicator]==NULL) {
                                        sets[indicator] = set1;
                                        //指定树函数 
                                        set_insert(sets[0], sets[indicator]);
                                        break;
                                    }else if (indicator == SETS_LENGTH-1){
                                        printf("无法为新成员分配空间\n");
                                    }
                                }
                               
                                printf("finished!\n");
                                getchar();
                            }
                            break;
                        case 4:
                            if (hasInitializedForSet==false) {
                                printf("Please initialize first！\n");
                            }else{
                                printf("the name of the node you want to del：\n");
                                scanf("%s",name);
                                getchar();
                                temp = PointerFinder(sets, SETS_LENGTH, name);
                                if (temp==NULL) {
                                    printf("No such node！\n");
                                }else{
                                    for (indicator = 0; indicator<SETS_LENGTH; indicator++) {
                                        if (sets[indicator]==NULL) {
                                            continue;
                                        }
                                        if (strcmp(sets[indicator]->profile->name, name)==0) {
                                            indicator2 = indicator;
                                            continue;
                                        }
                                         
                                        DeleteAVLforSet(&(sets[indicator]->profile->Root_Friend), name);
                                        DeleteAVLforSet(&(sets[indicator]->profile->Root_Fans), name);
                                        DeleteAVLforSet(&(sets[indicator]->profile->Root_Spotted), name);
                                    }
                                    DestroyAVL(&temp);
                                    temp = NULL;
                                    sets[indicator2] = NULL;
                                }
                                
                            }   
							printf("succceed！\n");   
							getchar();                 
                            break;
                        case 5:
                            if (hasInitializedForSet==false) {
                                printf("Please initialize first！\n");
                                break;
                            }
                            else{
                            L:  printf("choose two sets to compare!\n");
							    printf("1.Friends Set and Fans Set  2.Friends Set and Spotted Set  3.Fans Set and Spotted Set\n");
                                scanf("%d",&choice);
                                getchar();
                                if (choice!=1 && choice!=2 && choice!=3) {
                                    goto L;
                                }else if (choice == 1){
                                    set_intersection(sets[0]->profile->Root_Friend, sets[0]->profile->Root_Fans, intersection);
                                    for (indicator = 0; indicator<SETS_LENGTH; indicator++) {
                                        if (intersection[0]==NULL) {
                                            printf("The \n");
                                            break;
                                        }
                                        if (intersection[indicator]==NULL) {
                                            break;
                                        }
                                        printf("name--%s\n",intersection[indicator]->profile->name);
                                    }
                                }else if (choice == 2){
                                    set_intersection(sets[0]->profile->Root_Friend, sets[0]->profile->Root_Spotted, intersection);
                                    for (indicator = 0; indicator<SETS_LENGTH; indicator++) {
                                        if (intersection[0]==NULL) {
                                            printf("the Intersection is NULL!\n");
                                            break;
                                        }
                                        if (intersection[indicator]==NULL) {
                                            break;
                                        }
                                        printf("name:%s\n",intersection[indicator]->profile->name);
                                    }
                                }else if (choice == 3){
                                    set_intersection(sets[0]->profile->Root_Fans, sets[0]->profile->Root_Spotted, intersection);
                                    for (indicator = 0; indicator<SETS_LENGTH; indicator++) {
                                        if (intersection[0]==NULL) {
                                            printf("the Intersection is NULL!\n");
                                            break;
                                        }
                                        if (intersection[indicator]==NULL) {
                                            break;
                                        }
                                        printf("name:%s\n",intersection[indicator]->profile->name);
                                    }
                                }
                                printf("Finished! \n");
        
                            }
                            getchar();
                            break;
                        case 6:
                            if (hasInitializedForSet==false) {
                                printf("Please initialize first！\n");
                            }else{
                            U:  printf("choose two sets to compare!\n");
							    printf("1.Friends Set and Fans Set  2.Friends Set and Spotted Set  3.Fans Set and Spotted Set\n");
                                scanf("%d",&choice);
                                getchar();
                                if (choice!=1 && choice!=2 && choice!=3) {
                                    goto U;
                                }else if (choice == 1){
                                    set_union(sets[0]->profile->Root_Friend, sets[0]->profile->Root_Fans, unionSet);
                                    for (indicator = 0; indicator<SETS_LENGTH; indicator++) {
                                        if (unionSet[0]==NULL) {
                                            printf("the Union is NULL! \n");
                                            break;
                                        }
                                        if (unionSet[indicator]==NULL) {
                                            break;
                                        }
                                        printf("name:%s\n",unionSet[indicator]->profile->name);
                                    }
                                }else if (choice == 2){
                                    set_union(sets[0]->profile->Root_Friend, sets[0]->profile->Root_Spotted, unionSet);
                                    for (indicator = 0; indicator<SETS_LENGTH; indicator++) {
                                        if (unionSet[0]==NULL) {
                                            printf("the Union is NULL! \n");
                                            break;
                                        }
                                        if (unionSet[indicator]==NULL) {
                                            break;
                                        }
                                        printf("name:%s\n",unionSet[indicator]->profile->name);
                                    }
                                }else if (choice == 3){
                                    set_union(sets[0]->profile->Root_Fans, sets[0]->profile->Root_Spotted, unionSet);
                                    for (indicator = 0; indicator<SETS_LENGTH; indicator++) {
                                        if (unionSet[0]==NULL) {
                                            printf("the Union is NULL!\n");
                                            break;
                                        }
                                        if (unionSet[indicator]==NULL) {
                                            break;
                                        }
                                        printf("name:%s\n",unionSet[indicator]->profile->name);
                                    }
                                }
                                printf("Finished!\n");
                            }
                            getchar();
                            break;
                        case 7:
                            if (hasInitializedForSet==false) {
                                printf("Please initialize first！\n");
                            }
                            else{
                            V:  printf("choose two sets to compare!\n");
							    printf("1.Friends Set and Fans Set  2.Friends Set and Spotted Set  3.Fans Set and Spotted Set\n");
                                scanf("%d",&choice);
                                getchar();
                                if (choice!=1 && choice!=2 && choice!=3) {
                                    goto V;
                                }else if (choice == 1){
                                    set_difference(sets[0]->profile->Root_Friend, sets[0]->profile->Root_Fans, difference);
                                    for (indicator = 0; indicator<SETS_LENGTH; indicator++) {
                                        if (difference[0]==NULL) {
                                            printf("The set is NULL！ \n");
                                            break;
                                        }
                                        if (difference[indicator]==NULL) {
                                            break;
                                        }
                                        printf("name：%s\n",difference[indicator]->profile->name);
                                    }
                                }else if (choice == 2){
                                    set_difference(sets[0]->profile->Root_Friend, sets[0]->profile->Root_Spotted, difference);
                                    for (indicator = 0; indicator<SETS_LENGTH; indicator++) {
                                        if (difference[0]==NULL) {
                                            printf("The set is NULL！ \n");
                                            break;
                                        }
                                        if (difference[indicator]==NULL) {
                                            break;
                                        }
                                        printf("name：%s\n",difference[indicator]->profile->name);
                                    }
                                }else if (choice == 3){
                                    set_difference(sets[0]->profile->Root_Fans, sets[0]->profile->Root_Spotted, difference);
                                    for (indicator = 0; indicator<SETS_LENGTH; indicator++) {
                                        if (difference[0]==NULL) {
                                            printf("The set is NULL！ \n");
                                            break;
                                        }
                                        if (difference[indicator]==NULL) {
                                            break;
                                        }
                                        printf("name：%s\n",difference[indicator]->profile->name);
                                    }
                                }
                                printf("Finished\n");
                            }
                            getchar(); 
                            break;
                        case 8:
                            if (hasInitializedForSet==false) {
                                printf("Please initialize first！\n");
                            }
                            else{
                            X:  printf("which set do you want?\n");
							    printf("1.Friends Set  2.Fans Set  3.Spotted Set\n");
                                scanf("%d",&choice);
                                getchar();
                                if (choice!=1 && choice!=2 && choice!=3) {
                                    goto X;
                                }else if (choice==1){
                                    size = set_size(sets[0]->profile->Root_Friend);
                                    printf("The num of Friends Set is:%d\n",size);
                                }else if (choice==2){
                                    size = set_size(sets[0]->profile->Root_Fans);
                                    printf("The num of Fans Set is:%d\n",size);
                                }else if (choice==3){
                                    size = set_size(sets[0]->profile->Root_Spotted);
                                    printf("The num of Spotted Set is:%d\n",size);
                                }
                                printf("finished!\n");
                            }
                            getchar();
                            break;
                        case 9:
                            if (hasInitializedForSet==false) {
                                printf("Please initialize first！\n");
                            }
                            else{
                                printf("name:\n");
                                scanf("%s",name);
                                getchar();
                                temp = PointerFinder(sets, SETS_LENGTH, name);
                                if (temp==NULL) {
                                    printf("No such name!\n");
                                }else{
               
                                    printf("Location in RAM：%d\nHobby：%s\n",temp,temp->profile->hobby);
                                }
                                printf("Finished!\n");
                            }
                            getchar();
                            break;
                        case 10:
                            if (hasInitializedForSet==false) {
                                printf("Please initialize first！\n");
                            }
                            else{
                            	
                            Y:  printf("where do you to find the sub?");
							    printf("1.Friends Set  2.Fans Set  3.Spotted Set\n");
                                scanf("%d",&choice);
                                getchar();
                                if (choice!=1 && choice!=2 && choice!=3) {
                                    goto Y;
                                }else{
                                	
                                    printf("name:\n");
                                    scanf("%s",name);
                                    
                                    getchar();
                                    temp = PointerFinder(sets, SETS_LENGTH, name);
                                    if (temp==NULL) {
                                        printf("No such name!\n");
                                    }else{
                                        if (choice==1) {
                                            exist = set_subset(sets[0]->profile->Root_Friend, temp);
                                            if (exist == OK) {
                                                printf("It's the sub of the Friends Set\n");
                                            }else if (exist == -1){
                                                printf("It's not the sub of the Friends Set\n");
                                            }
                                        }else if (choice==2){
                                            exist = set_subset(sets[0]->profile->Root_Fans, temp);
                                            if (exist == OK) {
                                                printf("It's the sub of the Fans Set\n");
                                            }else if (exist == -1){
                                                printf("It's not the sub of the Fans Set\n");
                                            }
                                        }else if (choice==3){
                                            exist = set_subset(sets[0]->profile->Root_Spotted, temp);
                                            if (exist == OK) {
                                                printf("It's the sub of the Spotted Set");
                                            }else if (exist == -1){
                                                printf("It's not the sub of the Spotted Set\n");
                                            }
                                        }
                                    }
                                }
       
                            }
                            getchar();
                            break;
                        case 11:
                            if (hasInitializedForSet==false) {
                                printf("Please initialize first！\n");
                            }
                            else{
                            Z:  printf("choose two sets to compare!\n");
							    printf("1.Friends Set and Fans Set  2.Friends Set and Spotted Set  3.Fans Set and Spotted Set\n");
                                scanf("%d",&choice);
                                getchar();
                                if (choice!=1 && choice!=2 && choice!=3) {
                                    goto Z;
                                }else if (choice==1){
                                    equal = set_equal(sets[0]->profile->Root_Friend, sets[0]->profile->Root_Fans);
                                    if (equal==1) {
                                        printf("Friends Set and Fans Set are equal\n");
                                    }else if (equal==-1){
                                        printf("Friends Set and Fans Set are not equal\n");
                                    }
                                }else if (choice==2){
                                    equal = set_equal(sets[0]->profile->Root_Friend, sets[0]->profile->Root_Spotted);
                                    if (equal==1) {
                                        printf("Friends Set and Spotted Set are equal\n");
                                    }else if (equal==-1){
                                        printf("Friends Set and Spotted Set are not equal\n");
                                    }
                                }else if (choice==3){
                                    equal = set_equal(sets[0]->profile->Root_Fans, sets[0]->profile->Root_Spotted);
                                    if (equal==1) {
                                        printf("Fans Set and Spotted Set are equal\n");
                                    }else if (equal==-1){
                                        printf("Fans Set and Spotted Set are  not equal\n");
                                    }
                                }
                            }
                            getchar();
                            break;
                        case 12:
                            furtherLoop = 0;
                            break;
                        default:
                            break;
                    }
                    printf("\n");
                }
                furtherLoop = 1;
                furtherFunction = -1;
                break;
/**************************************集合抽象层结束***********************************/



/**************************************应用功能层**************************************/
            case 3:
            	for (indicator = 0; indicator<20; indicator++) {
    				name[indicator] = '\0';
				}
                while (furtherLoop) {
                W:  system("cls");
                    printf("1.Initialize\t2.Insert Node and the Relationship\n");
                    printf("3.Delete Node\t4.Change Info \n");
                    printf("5.Search\t6.Same Spotted\n");
                    printf("7.Same Hobby\t8.Further Friends\n");
                    printf("9.Save\t10.Load\n");
                    printf("11.Exit\n");
                    scanf("%d",&furtherFunction);
                    getchar();
                    if (furtherFunction!=1 && furtherFunction!=2 && furtherFunction!=3 && furtherFunction!=4 && furtherFunction!=5 && furtherFunction!=6 && furtherFunction!=7 && furtherFunction!=8 && furtherFunction!=9 && furtherFunction!=10 && furtherFunction!=11) {
                        goto W;
    
                    }
                
                    switch (furtherFunction) {
                        case 1:
                            printf("How many members do you want？\n");
                            scanf("%d",&data_number);
                            getchar();
                            DataGenerator(data_number);
                            Load(store, data_number);
                            hasInitialized = true;
                            printf("Succeed!\n");
                            getchar();
                            break;
                        case 2:
                            if (hasInitialized == false) {
                                printf("Please initialize first!\n");
                            }else{
                            P:  printf("1.New Node\t2.New Relationship\n");
                                scanf("%d",&choice);
                                if (choice!=1 && choice!=2) {
                                    goto P;
                                }else if (choice==1){
                                    set_init(&set1);
                                    printf("Name:\t");
                                    scanf("%s",name);
                                    getchar();
                                    strcpy(set1->profile->name, name);
                                    for (indicator = 0; indicator<ARRAY_LENGTH; indicator++) {
                                        if (store[indicator]==NULL) {
                                            store[indicator] = set1;
                                            break;
                                        }else if (indicator == ARRAY_LENGTH-1){
                                            printf("Failed! \n");
                                            indicator = 100000;
                                            break;
                                        }
                                    }
                                    if (indicator<ARRAY_LENGTH) {
                                        // 说明有位置增加成员
                                        printf("Num:\t");
                                        scanf("%d",&indicator1);
                                        set_insert(store[indicator1], set1);
                                        printf("succeed!\n");
                                    }
                                }else if (choice==2){
                                Q:  printf("Which member do you want to insert into?\nname:\t");
                                        scanf("%s",name);
                                        getchar();
                                        temp = PointerFinder(store, ARRAY_LENGTH, name);
                                    
                                    if (temp!=NULL) {
                                        
                                    R: 
                                            printf("Which member do you want to insert into %s?\nname:\t",temp->profile->name);
                                            scanf("%s",name);
                                            getchar();
                                            temp2 = PointerFinder(store, ARRAY_LENGTH, name);
                                       
                                    }
                                    
                                    if (temp2!=NULL) {
                                        
                                        set_insert(temp, temp2);
                                        printf("Succeed\n");
                                    }else{
                                        printf("No such member!\n");
                                        printf("Failed\n");
                                    }
                                }
                            }
                            	getchar();
                            	getchar();
                                break;
                        case 3:
                            if (hasInitialized == false) {
                                printf("Please initialize first!\n");
                            }else{
                                printf("Which member do you want to delete?\n");
                                scanf("%s",name);
                                getchar();
                                for (indicator = 0; indicator<ARRAY_LENGTH ; indicator++) {
                                    if (store[indicator] == NULL) {
                                        continue;
                                    }
                                    if (strcmp(store[indicator]->profile->name, name)==0) {
                                        indicator2 = indicator;
                                        continue;
                                    }
                                    DeleteAVLforSet(&(store[indicator]->profile->Root_Friend), name);
                                    DeleteAVLforSet(&(store[indicator]->profile->Root_Fans), name);
                                    DeleteAVLforSet(&(store[indicator]->profile->Root_Spotted), name);
                                }
                                temp = PointerFinder(store, ARRAY_SIZE, name);
                                DestroyAVL(&temp);
                                temp = NULL;
                                store[indicator2] = NULL;
                                printf("succeed!\n");
                            }
                            getchar();
                            break;
                        case 4:
                            if (hasInitialized == false) {
                                printf("Please initialize first!\n");
                            }else{
                                printf("Which member do you want to change?\n");
                                scanf("%s",name);
                                getchar();
                                temp = PointerFinder(store, ARRAY_LENGTH, name);
                                if (temp!=NULL) {
                                J:  printf("What is the data you want to change?");
								    printf("\t1.hobby\t2.Friends\t3.Fans\t4.Spotted\n");
                                    scanf("%d",&choice);
                                    getchar();
                                    if (choice!=1 && choice!=2 && choice!=3 && choice!=4) {
                                        goto J;
                                    }else if (choice==1){
                    
                                        printf("New hobby is:\t");
                                        scanf("%s",hobby);
                                        getchar();
                                        strcpy(temp->profile->hobby, hobby);
                                    }else if (choice==2){
                                        if (temp->profile->Root_Friend!=NULL) {
                                            printf("Former Friends:\n");
                                            TraverseAVL(temp->profile->Root_Friend);
                                            printf("Which friend do you want to delete?\n");
                                            scanf("%s",name);
                                            getchar();
                                            DeleteAVLforSet(&(temp->profile->Root_Friend), name);
                                        }else{
                                            printf("The Friends Set is NULL\n");
                                        }
                                    }else if (choice==3){
                                        if (temp->profile->Root_Fans!=NULL) {
                                            printf("Former Fans\n");
                                            TraverseAVL(temp->profile->Root_Fans);
                                            printf("Which fans do you want to delete?\n");
                                            scanf("%s",name);
                                            getchar();
                                            DeleteAVLforSet(&(temp->profile->Root_Fans), name);
                                        }else{
                                            printf("The Fans Set is NULL\n");
                                        }
                                    }else if (choice==4){
                                        if (temp->profile->Root_Spotted!=NULL) {
                                            printf("Former Spotted\n");
                                            TraverseAVL(temp->profile->Root_Spotted);
                                            printf("Which spotted do you want to delete?\n");
                                            scanf("%s",name);
                                            getchar();
                                            DeleteAVLforSet(&(temp->profile->Root_Spotted), name);
                                        }else{
                                            printf("The Spotted Set is NULL\n");
                                        }
                                    }
                                }
                                printf("Finished!\n");
                            }
                            
                           
                            getchar();
                            break;
                        case 5:
                            if (hasInitialized == false) {
                                printf("Please initialize first!\n");
                            }
                            else{
                            N:  
						
                                    printf("Which member do you want to search?\n");
                                    scanf("%s",name);
                                    getchar();
                                    temp = PointerFinder(store, ARRAY_LENGTH, name);
                           
                                
                                if (temp!=NULL) {
                        
                                M:  
                                  		printf("Hobby:\t%s\n",temp->profile->hobby);
                                  		printf("Friends Set:\n");
                                        TraverseAVL(temp->profile->Root_Friend);
                                        printf("\n");
                                        printf("----------------------------------------\n");
                                  
                                        printf("Fans Set:\n");
                                        TraverseAVL(temp->profile->Root_Fans);
                                        printf("\n");
                                        printf("----------------------------------------\n");
                                
                                 		printf("Spotted Set:\n");
                                        TraverseAVL(temp->profile->Root_Spotted);
                                        printf("\n");
                                        printf("----------------------------------------\n");
                              
                                    printf("Finished! \n");
                                } else {
                                    printf("No such member\n");
                                   
                                }
                            }
                            getchar();
                            break;
                        case 6:
                            if (hasInitialized == false) {
                                printf("Please initialize first!\n");
                            }else{
                                printf("The num of the first one:\t");
                                scanf("%d",&indicator1);
                                getchar();
                                printf("The num of the second one:\t");
                                scanf("%d",&indicator2);
                                getchar();
                                mutualSpotted(store[indicator1], store[indicator2], mutualSpottedSet);
                                printf("The same spotted:\n");
                                for (indicator = 0; mutualSpottedSet[indicator]!=NULL; indicator++) {
                                    TraverseAVL(mutualSpottedSet[indicator]);
                                }
                                printf("Finished!\n");
                            }
                            
                            getchar();
                            break;
                        case 7:
                            if (hasInitialized == false) {
                                printf("Please initialize first!\n");
                            }
                            else{
                                printf("The num of the member:\t");
                                scanf("%d",&indicator1);
                                printf("The second num of the member:\t");
                                getchar();
                                getchar();
                                for (indicator = 0, indicator2 = 0; indicator<ARRAY_LENGTH; indicator++) {
                                    if (indicator == indicator1) {
                                        continue;
                                    }
                                    if (store[indicator] == NULL) {
                                        continue;
                                    }
                                    if (mutualHobby(store[indicator1], store[indicator])==1) {
                                        mutualHobbySet[indicator2] = store[indicator];
                                        indicator2++;
                                    }
                                }
                                printf("they all have the hobby:\n%s\n",name2);
                                printf("These members has the same hobby with them:\n");
                                for (indicator = 0; mutualHobbySet[indicator]!=NULL; indicator++) {
                                    TraverseAVL(mutualHobbySet[indicator]);
                                    getchar();
                                }
                                
                                printf("\nFinished!\n");
                            }
                            getchar();
                            break;
                        case 8:
                            if (hasInitialized == false) {
                                printf("Please initialize first!\n");
                            }else{
                                printf("The num of the member:\n");
                                scanf("%d",&indicator1);
                                getchar();
                                
                                friends_Friend(store[indicator1] , friendSet);
                                for (indicator = 0; indicator<ARRAY_LENGTH; indicator++) {
                                    if (friendSet[indicator]==NULL) {
                                        break;
                                    }
                                    
                                    friends_Friend(friendSet[indicator], friends_FriendSet);
                                    printf("His %d firend`s friends:\n",indicator+1);
                                    for (indicator2 = 0; indicator2<ARRAY_LENGTH; indicator2++) {
                                        if (friends_FriendSet[indicator2]==NULL) {
                                            break;
                                        }
                                        printf("name:%s\n",friends_FriendSet[indicator2]->profile->name);
                                    }
                                    printf("\n");
                                    //                                清空数组
                                    for (indicator2 = 0; indicator2<ARRAY_LENGTH; indicator2++) {
                                        friends_FriendSet[indicator2] = NULL;
                                    }
                                }
                                
                                //                            将第一个朋友的朋友集合放入数组friends_FriendSet
                                //                            friends_Friend(store[indicator1], store[indicator1]->profile->Root_Friend, friends_FriendSet);
                                
                                
                                printf("Finished!\n");
                                for (indicator = 0; indicator<ARRAY_LENGTH; indicator++) {
                                    friendSet[indicator] = NULL;
                                    friends_FriendSet[indicator] = NULL;
                                }
                            }
                            getchar();
                            break;
                        case 9:
                            if (hasInitialized == false) {
                                printf("Please initialize first\n");
                            }else{
                                printf("How many data do you want to save?\n");
                                scanf("%d",&saveDataNumber);
                                getchar();
                                Save(store, saveDataNumber);
                                printf("Finished!\n");
                            }
                            getchar();
                            break;
                        case 10:
                           
                            Load(store, saveDataNumber);
                            hasInitialized = true;
                            printf("Finished!\n");
                            getchar;
                            break;
                        case 11:
                            furtherLoop = 0;
                            break;
                        default:
                            break;
                    }
               
                    printf("\n");
                }
                furtherFunction = -1;
                furtherLoop = 1;
                break;
/***********************************应用功能层结束**********************************/ 
            default:
                loop = 0;
                printf("Thanks！\n");
                break;
        }
    }
    return 0;
}


//初始化AVL树并给第一个结点赋初值 
int InitAVL(BiTree *AVLTree){
    if(!((*AVLTree) = (BiTNode*)malloc(sizeof(BiTNode)))){
        printf("Failed to apply memory! \n");
        getchar();
        return ERROR;
    }
    
    int data = -1;
    
    BiTNode *T = *AVLTree;
    T->data = -1;
    T->balance = -1;
    T->lchild = NULL;
    T->rchild = NULL;
    
    printf("Please input the data of the first node: \n");
    scanf("%d",&data);
    T->data = data;
    
    return OK;
}


//销毁AVL树 
int DestroyAVL(BiTree *AVLTree){
    if (*AVLTree == NULL) {
        printf("No such AVL tree! \n");
        getchar();
        return ERROR;
    }
    BiTNode *temp = NULL;
    Push(stack, *AVLTree);
    while (!StackEmpty(stack)) {
        while (GetTop(stack, &temp) && temp) {
            Push(stack, temp->lchild);//向左走到尽头
        }
        Pop(stack, &temp);//空指针退栈
        if (!StackEmpty(stack)) 
		{
            Pop(stack, &temp);
            Push(stack, temp->rchild);
            free(temp);
            temp = NULL;
        }
    }
    *AVLTree = NULL;
    AVLTree = NULL;
    return OK;
}

//插入结点 
int InsertAVL2(BiTree *T, TElemType e, bool *taller){
    if (!(*T)){
        if (!(*T = (BiTree)malloc(sizeof(BiTNode)))) {
            printf("Failed to apply memory! \n");
            getchar();
            return ERROR;
        }
        (*T)->data = e;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        (*T)->balance = EH;
        *taller = true;
    }
    else{
        if (EQ(e, (*T)->data)){
            *taller = false;
            return ERROR;
        }
        if (LT(e, (*T)->data)) {
            if (!InsertAVL2((&(*T)->lchild), e, taller)) {
                return ERROR;
            }
            if (*taller) {
                switch ((*T)->balance) {
                    case LH:
                        LeftBalance(T);
                        *taller = false;
                        break;
                    case EH:
                        (*T)->balance = LH;
                        *taller = true;
                        break;
                    case RH:
                        (*T)->balance = EH;
                        *taller = false;
                        break;
                }
            }
        }
        else{
            if (!InsertAVL2((&(*T)->rchild), e, taller)) {
                return ERROR;
            }
            if (*taller) {
                switch ((*T)->balance) {
                    case LH:
                        (*T)->balance = EH;
                        *taller = false;
                        break;
                    case EH:
                        (*T)->balance = RH;
                        *taller = true;
                        break;
                    case RH:
                        RightBalance(T);
                        *taller = false;
                        break;
                }
            }
        }
    }
    checkBalance(*T);
    return OK;
}

void LeftBalance(BiTree *T){
    BiTree lc = NULL, rd = NULL;//lc为T的左孩子，rd为lc的右孩子
    lc = (*T)->lchild;
    switch (lc->balance) {
        case LH://左左
            (*T)->balance = EH;
            lc->balance = EH;
            R_Rotate(T);
            break;
        case RH://左右
            rd = lc->rchild;
            switch (rd->balance) {
                case LH:
                    (*T)->balance = RH;
                    lc->balance = EH;
                    break;
                case EH:
                    (*T)->balance = EH;
                    lc->balance = EH;
                    break;
                case RH:
                    (*T)->balance = EH;
                    lc->balance = LH;
                    break;
            }
            rd->balance = EH;
            L_Rotate(&((*T)->lchild));//右右情况，左旋
            R_Rotate(T);//左左情况，右旋
    }
}

void RightBalance(BiTree *T){
    BiTree lc = NULL, rd = NULL;
    lc  = (*T)->rchild;
    switch (lc->balance) {
        case RH://右右
            (*T)->balance = EH;
            lc->balance = EH;
            L_Rotate(T);
            break;
        case LH:
            rd = lc->lchild;
            switch (rd->balance) {
                case RH:
                    (*T)->balance = LH;
                    lc->balance = EH;
                    break;
                case EH:
                    (*T)->balance = EH;
                    lc->balance = EH;
                    break;
                case LH:
                    (*T)->balance = EH;
                    lc->balance = RH;
                    break;
            }
            rd->balance = EH;
            R_Rotate(&((*T)->rchild));
            L_Rotate(T);
    }
}

void LeftBalanceforDeletion(BiTree *T){
    BiTree lc = NULL, rd = NULL;//lc为T的左孩子，rd为lc的右孩子
    lc = (*T)->lchild;
    switch (lc->balance) {
        case LH://左左
            (*T)->balance = EH;
            lc->balance = EH;
            R_Rotate(T);
            break;
        case EH://特殊情况
            if (lc->lchild!=NULL) {
                /*特殊情况*/
                (*T)->lchild = lc->rchild;
                lc->rchild = (*T);
                (*T) = lc;
            }
            break;
         case RH://左右
            rd = lc->rchild;
            switch (rd->balance) {
//                    可能需要修改case的值？
                case LH:
                    (*T)->balance = RH;
                    lc->balance = EH;
                    break;
                case EH:
                    (*T)->balance = EH;
                    lc->balance = EH;
                    break;
                case RH:
                    (*T)->balance = EH;
                    lc->balance = LH;
                    break;
            }
            rd->balance = EH;
            L_Rotate(&((*T)->lchild));//右右情况，左旋
            R_Rotate(T);//左左情况，右旋
            break;
    }
}

void RightBalanceforDeletion(BiTree *T){
    BiTree lc = NULL, rd = NULL;
    lc  = (*T)->rchild;
    switch (lc->balance) {
        case RH://右右
            (*T)->balance = EH;
            lc->balance = EH;
            L_Rotate(T);
            break;
        case EH://右左改进版
            if (lc->rchild!=NULL) {
                /*特殊情况*/
                (*T)->rchild = lc->lchild;
                lc->lchild = *T;
                *T = lc;
            }
            break;
        case LH:
            rd = lc->lchild;
            switch (rd->balance) {
                case RH:
                    (*T)->balance = LH;
                    lc->balance = EH;
                    break;
                case EH:
                    (*T)->balance = EH;
                    lc->balance = EH;
                    break;
                case LH:
                    (*T)->balance = EH;
                    lc->balance = RH;
                    break;
            }
            rd->balance = EH;
            R_Rotate(&((*T)->rchild));
            L_Rotate(T);
            break;
        }
}


void R_Rotate(BiTree *p){
    BiTree lc = NULL;
    lc = (*p)->lchild;
    (*p)->lchild = lc->rchild;
    lc->rchild = *p;
    *p = lc;
}

void L_Rotate(BiTree *p){
    BiTree rc = NULL;
    rc = (*p)->rchild;
    (*p)->rchild = rc->lchild;
    rc->lchild = *p;
    *p = rc;
}

BiTree findSuperLocation(BiTree AVLTree, TElemType insertData){
    if (AVLTree->data > insertData) {
        if (AVLTree->lchild == NULL) {
            return AVLTree;
        }
        else {
            return findSuperLocation(AVLTree->lchild, insertData);
        }
    }
    else {
        if (AVLTree->rchild == NULL) {
            return AVLTree;
        }
        else{
            return findSuperLocation(AVLTree->rchild, insertData);
        }
    }
}

int DeleteAVL(BiTree *AVLTree, TElemType key){
    if (*AVLTree == NULL) {
        printf("No such AVL tree!\n");
        getchar();
        return ERROR;
    }
    BiTNode *p = *AVLTree, *f = NULL, *q, *s;
    //寻找要删除的节点，当做是普通二叉树进行删除
    while (p!=NULL&&!EQ(p->data, key)) {
        f = p;
        if (LT(key, p->data)) {
            p = p->lchild;
        }
        else{
            p = p->rchild;
        }
    }
    
    if (p == NULL) {
        printf("No such Node!\n");
        getchar();
        return ERROR;
    }
    
    s = p;
    if (p->lchild!=NULL && p->rchild!=NULL) {
        f = p;
        s = p->lchild;
        while (s->rchild!=NULL) {
            f = s;
            s = s->rchild;
        }
        p->data = s->data;
        p->balance = s->balance;
    }
    
    if (s->lchild!=NULL) {
        q = s->lchild;
    }
    else{
        q = s->rchild;
    }
    
    if (f == NULL) {
        *AVLTree = q;
    }
    else if (f->lchild==s){
        f->lchild = q;
    }
    else
        f->rchild = q;
    free(s);
//    BST树的删除完成
    
    checkBalance(*AVLTree);
//    在下面的代码中实现恢复平衡
//    找到最小不平衡树->恢复平衡
    BiTNode *temp = NULL, *super = NULL;
A:    Push(stack, *AVLTree);
    while (!StackEmpty(stack)) {
        while (GetTop(stack, &temp) && temp) {
            Push(stack, temp->lchild);//向左走到尽头
        }
        Pop(stack, &temp);//空指针退栈
        if (!StackEmpty(stack)) {
            Pop(stack, &temp);
            if (temp->balance<-1 || temp->balance>1) {
//                大于2或小于-2情况未知
                if (temp->balance == 2) {
                    if (temp->data == (*AVLTree)->data) {
                        //不平衡点在根节点
                        LeftBalanceforDeletion(&temp);
                        (*AVLTree) = temp;
                        DumpStack(stack);
                        checkBalance(*AVLTree);
                        goto A;
                    } else {
                        //不平衡点不在根节点
                        super = *AVLTree;
                        while (super!=NULL) {
                                if ((temp->data < super->data) && (temp->data != super->lchild->data)){
                                    super = super->lchild;
                                }else if ((temp->data > super->data) && (temp->data != super->rchild->data)) {
                                    super = super->rchild;
                                }else if (temp->data == super->lchild->data) {
                                    LeftBalanceforDeletion(&temp);
                                    super->lchild = temp;
                                    DumpStack(stack);
                                    checkBalance(*AVLTree);
                                    goto A;
                                }else if (temp->data == super->rchild->data) {
                                    LeftBalanceforDeletion(&temp);
                                    super->rchild = temp;
                                    DumpStack(stack);
                                    checkBalance(*AVLTree);
                                    goto A;
                                }
                        }
                    }

                }
                else if (temp->balance == -2) {
                    if (temp->data == (*AVLTree)->data) {
                        //不平衡点在根节点
                        RightBalanceforDeletion(&temp);
                        
                        (*AVLTree) = temp;
                        DumpStack(stack);
                        checkBalance(*AVLTree);
                        goto A;
                    } else {
                        //不平衡点不在根节点
                        super = *AVLTree;
                        while (super!=NULL) {
                            if ((temp->data < super->data) && (temp->data != super->lchild->data)){
                                super = super->lchild;
                            }else if ((temp->data > super->data) && (temp->data != super->rchild->data)) {
                                super = super->rchild;
                            }else if (temp->data == super->lchild->data) {
                                RightBalanceforDeletion(&temp);
                                super->lchild = temp;
                                DumpStack(stack);
                                checkBalance(*AVLTree);
                                goto A;
                            }else if (temp->data == super->rchild->data) {
                                RightBalanceforDeletion(&temp);
                                super->rchild = temp;
                                (*AVLTree) = temp;
                                DumpStack(stack);
                                checkBalance(*AVLTree);
                                goto A;
                            }
                        }
                    }

                }
                else{
//                   平衡因子>3或<-3
                    return ERROR;
                }
            }
            Push(stack, temp->rchild);
        }
    }
    checkBalance(*AVLTree);
    printf("succeed!");
    getchar(); 
    return OK;

}

int TraverseAVL(BiTree AVLTree){
    if (AVLTree == NULL) {
        printf("No such AVL tree! \n");
        return ERROR;
    }
    BiTNode *temp = NULL;
    Push(stack, AVLTree);
    while (!StackEmpty(stack)) {
        while (GetTop(stack, &temp) && temp) {
            Push(stack, temp->lchild);//向左走到尽头
        }
        Pop(stack, &temp);//空指针退栈
        if (!StackEmpty(stack)) {
            Pop(stack, &temp);
//            if (!Visit(temp->data)) {/*暂设为mark*/
//                return ERROR;
//            }
            printf("%s\t",temp->profile->name);
            Push(stack, temp->rchild);
        }
    }
    return OK;
}

int PreorderAndInOrderTraverseAVL(BiTree AVLTree){
    if (AVLTree == NULL) {
        printf("No such AVL! \n");
        getchar();
        getchar();
        return ERROR;
    }
    printf("Inorder traversal:\t");
    BiTNode *temp = NULL;
    Push(stack, AVLTree);
    while (!StackEmpty(stack)) {
        while (GetTop(stack, &temp) && temp) {
            Push(stack, temp->lchild);//向左走到尽头
        }
        Pop(stack, &temp);//空指针退栈
        if (!StackEmpty(stack)) {
            Pop(stack, &temp);
            if (!Visit(temp->data)) {/*暂设为mark*/
                return ERROR;
            }
            //            printf("name--%s\n",temp->profile->name);
            Push(stack, temp->rchild);
        }
    }
    printf("\n");
    printf("Preorder traversal:\t");
    Push(stack, AVLTree);
    while (!StackEmpty(stack)) {
        while (GetTop(stack, &temp) && temp) {
            if (!Visit(temp->data)) {/*暂设为mark*/
                return ERROR;
            }
            Push(stack, temp->lchild);//向左走到尽头
        }
        Pop(stack, &temp);//空指针退栈
        if (!StackEmpty(stack)) {
            Pop(stack, &temp);
            Push(stack, temp->rchild);
        }
    }
    getchar();
    getchar();
    return OK;
}

int Visit(TElemType e){
    //暂且将访问定义为输出元素值
    printf("%d\t",e);
    return OK;
}

BiTree SearchAVL(BiTree AVLTree, TElemType data){
    BiTree p = AVLTree;
    if (AVLTree == NULL) {
        printf("No such AVL tree! \n");
        getchar();
        return ERROR;
    }
    while (p!=NULL) {
        if (data == p->data) {
            return p;
        }
        else {
            if (data<p->data){
                p = p->lchild;
            }
            else{
                p = p->rchild;
            }
        }
    }
    printf("No such node! \n");
    getchar();
    return NULL;
}


/*********************************************队列与栈********************************/ 
void CreateQueue(Queue **head){
    *head = (Queue*)malloc(sizeof(Queue));
    (*head)->data = NULL;
    (*head)->next = NULL;
    Indicator.front = *head;
    Indicator.rear = Indicator.front;
}

int AddQueue(Queue **head, BiTNode *elem){
    if (head == NULL){
        printf("Queue doesn't exist!\n");
        return ERROR;
    }
    if (Indicator.front->next == NULL) {
        Indicator.rear = Indicator.front;
    }
    (Indicator.rear->next) = (Queue*)malloc(sizeof(Queue));
    Indicator.rear = (Indicator.rear)->next;
    Indicator.rear->data = elem;
    Indicator.rear->next = NULL;
    return OK;
}

BiTNode* DeleteQueue(Queue **head){
    //    没有释放空间
    if (head == NULL){
        printf("Queue doesn't exist!\n");
        return ERROR;
    }
    BiTNode *value = NULL;
    value = Indicator.front->next->data;
    (*head)->next = Indicator.front->next->next;
    return value;
}

int QueueIsEmpty(Queue **head){
    if (head == NULL){
        printf("Queue doesn't exist!\n");
        return ERROR;
    }
    if(Indicator.front->next == NULL){
        return 1;
    }
    else
        return 0;
}

int InitStack(Stack **S){
    if (!(*S = (Stack*)malloc(sizeof(Stack)))) {
        printf("无法初始化栈\n");
        return ERROR;
    }
    int index;
    for (index = 0; index<ARRAY_LENGTH; index++) {
        ((*S)->stack)[index] = NULL;
    }
    (*S)->length = 0;
    return OK;
}

int StackEmpty(Stack *S){
    if (S == NULL) {
        printf("栈不存在\n");
        return ERROR;
    }
    if (S->length == 0) {
        return 1;
    }
    else
        return 0;
}

int GetTop(Stack *S, BiTNode **p){
    if (S == NULL) {
        printf("栈不存在\n");
        return ERROR;
    }
    if (S->length == 0) {
        printf("栈为空\n");
        return ERROR;
    }
    *p = (S->stack)[1];//stack[0]不放东西，为哨兵位置
    return OK;
}

int Push(Stack *S, BiTNode *p){
    if (S == NULL) {
        printf("栈不存在\n");
        return ERROR;
    }
    if (S->length == 100) {
        printf("栈已满\n");
        return ERROR;
    }
    BiTNode *temp = NULL;
    int len = S->length;
    for (temp = S->stack[len];len>0;len--){
        (S->stack)[len+1] = (S->stack)[len];
    }
    (S->stack)[1] = p;
    S->length++;
    return OK;
}

BiTNode* Pop(Stack *S, BiTNode **p){
    if (S == NULL) {
        printf("栈不存在\n");
        return NULL;
    }
    if (S->length == 0) {
        printf("栈为空\n");
        return NULL;
    }
    int len = 1;
    *p = (S->stack)[1];
    for (;len<S->length;len++){
        (S->stack)[len] = (S->stack)[len+1];
    }
    (S->stack)[S->length] = NULL;
    S->length--;
    return *p;
}

int DumpStack(Stack *S){
    BiTNode **p = NULL;
    while (!StackEmpty(S)) {
        Pop(S, p);
    }
    return OK;
}

/*******************************************队列与栈******************************************/ 


int checkBalance(BiTree AVLTree){
    BiTNode *temp = NULL;
    Push(stack, AVLTree);
    while (!StackEmpty(stack)) {
        while (GetTop(stack, &temp) && temp) {
            Push(stack, temp->lchild);//向左走到尽头
        }
        Pop(stack, &temp);//空指针退栈
        if (!StackEmpty(stack)) {
            Pop(stack, &temp);
            temp->balance = BiTreeDepth(temp->lchild)-BiTreeDepth(temp->rchild);
            Push(stack, temp->rchild);
        }
    }
    return OK;
}

int BiTreeDepth(BiTNode *T){
    int rightdepth = 0;
    int leftdepth = 0;
    if (T == NULL) {
        return 0;
    }
    
    if (T->lchild != NULL){
        leftdepth = BiTreeDepth(T->lchild);
    }
    else
        leftdepth = 0;
    
    if (T->rchild != NULL){
        rightdepth = BiTreeDepth(T->rchild);
    }
    else
        rightdepth = 0;
    
    return (rightdepth>leftdepth)?rightdepth+1:leftdepth+1;
}

int set_init(struct BiTNode **set){
    if (!((*set) = (BiTNode*)malloc(sizeof(BiTNode)))) {
        printf("内存分配失败\n");
        return ERROR;
    }
    
    if (!((*set)->profile = (struct Data*)malloc(sizeof(struct Data)))) {
        printf("内存分配失败\n");
        return ERROR;
    }
    
    int temp = 0;
    
    for (temp = 0; temp<20; temp++) {
        (*set)->profile->name[temp] = '\0';
    }
    for(;insert_num<6;insert_num++)
    {
    	InsertAVL2(&AVLTree, data, &taller);
	}
    (*set)->balance = 0;
    (*set)->data = 0;
    (*set)->lchild = NULL;
    (*set)->rchild = NULL;
    (*set)->profile->Root_Fans = NULL;
    (*set)->profile->Root_Friend = NULL;
    (*set)->profile->Root_Spotted = NULL;
    //调用第一层函数 InitAVL(&AVLTree) 
    for(;initial_num<6;initial_num++)
    {
        InitAVL(&AVLTree);
	}
    return OK;
}

int set_destroy(struct BiTNode **set){

//调用第一层DestroyAVL(&AVLTree)函数将每个树先清空 
        if (hasInitializedForSet==false) {
            printf("Please initialize first！ \n");
            getchar();
            break;
        }
        for(;initial_num<6;initial_num++)
        {
            DestroyAVL(&AVLTree);
	    }	
}

int set_insert(struct BiTNode *set, struct BiTNode *set2){
    if (set==NULL) {
        printf("Set is NULL\n");
        return ERROR;
    }
    if (set2==NULL) {
        printf("Set2 is NULL\n");
        return ERROR;
    }
    
    int choice = -1;
//    struct BiTNode **temp = NULL;
    bool taller = false;
    printf("where do you want to insert？\n");
  A:printf("1.friends set\t2.fans set\tspotted set\n");
    scanf("%d",&choice);
    getchar();
    switch (choice) {
        case 1:
//            *temp = set->profile->Root_Friend;
            if(!(InsertAVLforSet(&(set->profile->Root_Friend), set2, &taller))){
                printf("failed\n");
                return ERROR;
            }
            break;
        case 2:
//            *temp = set->profile->Root_Fans;
            if(!(InsertAVLforSet(&(set->profile->Root_Fans), set2, &taller))){
                printf("failed\n");
                return ERROR;
            }
            break;
        case 3:
//            *temp = set->profile->Root_Spotted;
            if(!(InsertAVLforSet(&(set->profile->Root_Spotted), set2, &taller))){
                printf("failed\n");
                return ERROR;
            }
            break;
        default:
            printf("put in again:\n");
            goto A;
            break;
    }
    return OK;
}

int set_remove(struct BiTNode **set1, struct BiTNode *set2){
    if (set1==NULL) {
        printf("AVL树为空\n");
        return ERROR;
    }
    DeleteAVLforSet(set1, set2->profile->name);
    return OK;
}


int InsertAVLforSet(BiTree *T, BiTree insert, bool *taller){
    char name[20];
    int indicator = 0;
    for (; indicator<20; indicator++) {
        name[indicator] = '\0';
    }
    
    strcpy(name, insert->profile->name);
    if (!(*T)){
        if (!(*T = (BiTree)malloc(sizeof(BiTNode)))) {
            printf("内存分配失败\n");
            return ERROR;
        }
        
        (*T)->balance = EH;
        (*T)->data = insert->data;
        (*T)->profile = insert->profile;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        
        *taller = true;
//        (*T)->balance = EH;
        //        printf("原树为空，现用传入元素作为树的根建树已完成\n");
//        在不同的朋友圈中，balance可能不同，不能指向同一个区域
//        (*T) = insert;
    }
    else{
        if (strcmp((*T)->profile->name, name)==0){
            *taller = false;
            return ERROR;
        }
        if (strcmp((*T)->profile->name, name)>0) {
            if (!InsertAVLforSet((&(*T)->lchild), insert, taller)) {
                return ERROR;
            }
            if (*taller) {
                switch ((*T)->balance) {
                    case LH:
                        LeftBalance(T);
                        *taller = false;
                        break;
                    case EH:
                        (*T)->balance = LH;
                        *taller = true;
                        break;
                    case RH:
                        (*T)->balance = EH;
                        *taller = false;
                        break;
                }
            }
        }
        else{
            if (!InsertAVLforSet((&(*T)->rchild), insert, taller)) {
                return ERROR;
            }
            if (*taller) {
                switch ((*T)->balance) {
                    case LH:
                        (*T)->balance = EH;
                        *taller = false;
                        break;
                    case EH:
                        (*T)->balance = RH;
                        *taller = true;
                        break;
                    case RH:
                        RightBalance(T);
                        *taller = false;
                        break;
                }
            }
        }
    }
    checkBalance(*T);
    return OK;
}

BiTree SearchAVLforSet(BiTree AVLTree, char name[]){
    BiTree p = AVLTree;
    while (p!=NULL) {
        if (strcmp(name, p->profile->name)==0) {
            return p;
        }
        else {
            if (strcmp(name, p->profile->name)<0) {
                p = p->lchild;
            }
            else{
                p = p->rchild;
            }
        }
    }
//    printf("集合中未找到要删除的成员\n");
    return NULL;
}

int DeleteAVLforSet(BiTree *AVLTree, char name[]){
    if (*AVLTree == NULL) {
//        printf("AVL树为空\n");
        return ERROR;
    }
    //调用第一层函数 DeleteAVL(&AVLTree, data);
    for(;del_num<6;del_num++)
    {
    	DeleteAVL(&AVLTree, data);
	}
    BiTNode *p = *AVLTree, *f = NULL, *q, *s;
    while (p!=NULL&&(strcmp(p->profile->name, name)!=0)) {
        f = p;
        if (strcmp(name, p->profile->name)<0) {
            p = p->lchild;
        }
        else{
            p = p->rchild;
        }
    }
    if (p == NULL) {
//        printf("树中未找到要删除的节点\n");
        return ERROR;
    }
    
    s = p;
    if (p->lchild!=NULL && p->rchild!=NULL) {
        f = p;
        s = p->lchild;
        while (s->rchild!=NULL) {
            f = s;
            s = s->rchild;
        }
        p->data = s->data;
        p->balance = s->balance;
        p->profile = s->profile;
    }
    
    if (s->lchild!=NULL) {
        q = s->lchild;
    }
    else{
        q = s->rchild;
    }
    
    if (f == NULL) {
        *AVLTree = q;
    }
    else if (f->lchild==s){
        f->lchild = q;
    }
    else
        f->rchild = q;
    free(s);
    //    BST树的删除完成
    checkBalance(*AVLTree);
    //    在下面的代码中实现恢复平衡
    //    找到最小不平衡树->恢复平衡
    BiTNode *temp = NULL, *super = NULL;
B:    Push(stack, *AVLTree);
    while (!StackEmpty(stack)) {
        while (GetTop(stack, &temp) && temp) {
            Push(stack, temp->lchild);//向左走到尽头
        }
        Pop(stack, &temp);//空指针退栈
        if (!StackEmpty(stack)) {
            Pop(stack, &temp);
            if (temp->balance<-1 || temp->balance>1) {
                //                大于2或小于-2情况未知
                /*if (temp->balance == 2) {
                    LeftBalanceforDeletion(&temp);
                    //可能不适用于全体情况
                    (*AVLTree) = temp;
                    DumpStack(stack);
                    checkBalance(*AVLTree);
                    goto B;*/
                if (temp->balance == 2) {
                    if (temp->data == (*AVLTree)->data) {
                        //不平衡点在根节点
                        LeftBalanceforDeletion(&temp);
                        (*AVLTree) = temp;
                        DumpStack(stack);
                        checkBalance(*AVLTree);
                        goto B;
                    } else {
                        //不平衡点不在根节点
                        super = *AVLTree;
                        while (super!=NULL) {
                            if ((temp->data < super->data) && (temp->data != super->lchild->data)){
                                super = super->lchild;
                            }else if ((temp->data > super->data) && (temp->data != super->rchild->data)) {
                                super = super->rchild;
                            }else if (temp->data == super->lchild->data) {
                                LeftBalanceforDeletion(&temp);
                                super->lchild = temp;
                                DumpStack(stack);
                                checkBalance(*AVLTree);
                                goto B;
                            }else if (temp->data == super->rchild->data) {
                                LeftBalanceforDeletion(&temp);
                                super->rchild = temp;
                                DumpStack(stack);
                                checkBalance(*AVLTree);
                                goto B;
                            }
                        }
                    }
                }else if (temp->balance == -2) {
                    /*RightBalanceforDeletion(&temp);
                    //可能不适用于全体情况
                    (*AVLTree) = temp;
                    DumpStack(stack);
                    checkBalance(*AVLTree);
                    goto B;*/
                    if (temp->data == (*AVLTree)->data) {
                        //不平衡点在根节点
                        RightBalanceforDeletion(&temp);
                        //可能不适用于全体情况
                        (*AVLTree) = temp;
                        DumpStack(stack);
                        checkBalance(*AVLTree);
                        goto B;
                    } else {
                        //不平衡点不在根节点
                        super = *AVLTree;
                        while (super!=NULL) {
                            if ((temp->data < super->data) && (temp->data != super->lchild->data)){
                                super = super->lchild;
                            }else if ((temp->data > super->data) && (temp->data != super->rchild->data)) {
                                super = super->rchild;
                            }else if (temp->data == super->lchild->data) {
                                RightBalanceforDeletion(&temp);
                                super->lchild = temp;
                                DumpStack(stack);
                                checkBalance(*AVLTree);
                                goto B;
                            }else if (temp->data == super->rchild->data) {
                                RightBalanceforDeletion(&temp);
                                super->rchild = temp;
                                (*AVLTree) = temp;
                                DumpStack(stack);
                                checkBalance(*AVLTree);
                                goto B;
                            }
                        }
                    }
                } else {
                    printf("未解决情况，平衡因子>3或<-3\n");
                    return ERROR;
                }
            }
            Push(stack, temp->rchild);
        }
    }
    checkBalance(*AVLTree);
    printf("succeed!");
    return OK;
}

struct BiTNode** set_intersection(struct BiTNode *set1, struct BiTNode *set2, struct BiTNode *intersection[]){
    if (set1==NULL) {
        printf("集合1为空\n");
        return ERROR;
    }
    
    if (set2==NULL) {
        printf("集合2为空\n");
        return ERROR;
    }
    
    BiTNode *p = NULL;
    BiTNode *temp = NULL;
    int count = 0;

//    遍历集合1
    Push(stack, set1);
    while (!StackEmpty(stack)) {
        while (GetTop(stack, &temp) && temp) {
            Push(stack, temp->lchild);//向左走到尽头
        }
        for(;initial_num<6;initial_num++)
        {
            if(SearchAVL(AVLTree, data)!=NULL)
           	break;
            	
		}
        Pop(stack, &temp);//空指针退栈
        if (!StackEmpty(stack)) {
        	for(;initial_num<6;initial_num++)
            {
            	if(SearchAVL(AVLTree, data)!=NULL)
            	break;
            	
			}
            Pop(stack, &temp);
            p = SearchAVLforSet(set2, temp->profile->name);
            if (p!=NULL) {
                intersection[count++] = temp;
            }
            Push(stack, temp->rchild);
        }
    }
    return intersection;
}

struct BiTNode** set_union(struct BiTNode *set1, struct BiTNode *set2, struct BiTNode *Union[]){
    if (set1==NULL) {
        printf("集合1为空\n");
        return ERROR;
    }
    
    if (set2==NULL) {
        printf("集合2为空\n");
        return ERROR;
    }
    
    BiTNode *temp = NULL;
    int count = 0, tail = 0;
    
    //    将集合1全部压入数组
    Push(stack, set1);
    while (!StackEmpty(stack)) {
        while (GetTop(stack, &temp) && temp) {
            Push(stack, temp->lchild);//向左走到尽头
        }
        Pop(stack, &temp);//空指针退栈
        if (!StackEmpty(stack)) {
            Pop(stack, &temp);
            Union[count++] = temp;
            Push(stack, temp->rchild);
        }
    }
    
    count--;
    tail = count;
    
//    将集合2每个元素都与数组中的元素比较，若非数组中的元素则压入数组
    Push(stack, set2);
    while (!StackEmpty(stack)) {
        while (GetTop(stack, &temp) && temp) {
            Push(stack, temp->lchild);//向左走到尽头
        }
        Pop(stack, &temp);//空指针退栈
        if (!StackEmpty(stack)) {
            Pop(stack, &temp);
            for (tail = count; tail>=0; tail--) {
                if (strcmp(Union[tail]->profile->name, temp->profile->name)==0) {
                    //此成员在集合1中也存在
                    break;
                }
                else if (tail==0){
                    Union[++count] = temp;
                }
            }
            Push(stack, temp->rchild);
        }
    }
    return Union;
}

struct BiTNode** set_difference(struct BiTNode *set1, struct BiTNode *set2, struct BiTNode *difference[]){
    if (set1==NULL) {
        printf("??1??\n");
        return ERROR;
    }
    
    if (set2==NULL) {
        printf("??2??\n");
        return ERROR;
    }
    
    BiTNode *temp = NULL;
    int count = 0, tail = 0, change = 0;
    
    //    ???1??????
    Push(stack, set1);
    while (!StackEmpty(stack)) {
        while (GetTop(stack, &temp) && temp) {
            Push(stack, temp->lchild);//??????
        }
        for(;initial_num<6;initial_num++)
        {
            if(SearchAVL(AVLTree, data)!=NULL)
           	break;
            	
		}
        Pop(stack, &temp);//?????
        if (!StackEmpty(stack)) {
            Pop(stack, &temp);
            difference[count] = temp;
            count++;
            Push(stack, temp->rchild);
        }
    }
    
    count--;
    tail = count;
    
    //    ???2??????????????,???????????????????
    Push(stack, set2);
    while (!StackEmpty(stack)) {
        while (GetTop(stack, &temp) && temp) {
            Push(stack, temp->lchild);//??????
        }
        Pop(stack, &temp);//?????
        if (!StackEmpty(stack)) {
            Pop(stack, &temp);
            for (tail = count; tail>=0; tail--) {
                if (strcmp(difference[tail]->profile->name, temp->profile->name)==0) {
            
                    difference[tail]=NULL;
                    for (change = tail; change<=count-1; change++) {
                        difference[change] = difference[change+1];
                    }
                    difference[count] = NULL;
                    count--;
                }
            }
            Push(stack, temp->rchild);
        }
    }
    return difference;
}


int set_size(struct BiTNode *set){
    if (set==NULL) {
//        printf("集合为空\n");
        return ERROR;
    }
    
    int size = 0;
    BiTNode *temp = NULL;
    Push(stack, set);
    while (!StackEmpty(stack)) {
        while (GetTop(stack, &temp) && temp) {
            Push(stack, temp->lchild);//向左走到尽头
        }
        Pop(stack, &temp);//空指针退栈
        if (!StackEmpty(stack)) {
            Pop(stack, &temp);
            size++;
            Push(stack, temp->rchild);
        }
    }
    return size;
}

int set_member(struct BiTNode *set, struct BiTNode *toBeFound){
    if (set==NULL) {
        printf("集合为空\n");
        return ERROR;
    }
    if (toBeFound==NULL) {
        printf("寻找的集合为空\n");
        return ERROR;
    }
    BiTree p = NULL;
    p = SearchAVLforSet(set->profile->Root_Friend, toBeFound->profile->name);
    if (p!=NULL) {
//        printf("在朋友集中找到了此成员\n");
        return OK;
    }
    
    p = SearchAVLforSet(set->profile->Root_Fans, toBeFound->profile->name);
    if (p!=NULL) {
//        printf("在粉丝集中找到了此成员\n");
        return OK;
    }
    
    p = SearchAVLforSet(set->profile->Root_Spotted, toBeFound->profile->name);
    if (p!=NULL) {
//        printf("在关注集中找到了此成员\n");
        return OK;
    }
//    printf("未找到此成员\n");
    return ERROR;
}

int set_subset(struct BiTNode *set, struct BiTNode *sub){
    BiTree p = NULL;
    if (set==NULL) {
        printf("集合为空\n");
        return ERROR;
    }
    p = SearchAVLforSet(set, sub->profile->name);
    if (p==NULL) {

        return -1;
    }
    else
        return OK;
}

//返回值为-1时为不相等
int set_equal(struct BiTNode *set1, struct BiTNode *set2){
    BiTNode *S[200];
    if (set1==NULL) {
        printf("集合1为空\n");
        return ERROR;
    }
    
    if (set2==NULL) {
        printf("集合2为空\n");
        return -1;
    }
    
    BiTNode *temp = NULL;
    int count = 0, compare = 0;
    
    //    将集合1全部压入数组
    Push(stack, set1);
    while (!StackEmpty(stack)) {
        while (GetTop(stack, &temp) && temp) {
            Push(stack, temp->lchild);//向左走到尽头
        }
        Pop(stack, &temp);//空指针退栈
        if (!StackEmpty(stack)) {
            Pop(stack, &temp);
            S[count++] = temp;
            Push(stack, temp->rchild);
        }
    }
    
    compare = 0;
    
    //    将集合2每个元素都与数组中的元素比较，若有一个元素不在数组中，则集合不相等
    Push(stack, set2);
    while (!StackEmpty(stack)) {
        while (GetTop(stack, &temp) && temp) {
            Push(stack, temp->lchild);//向左走到尽头
        }
        Pop(stack, &temp);//空指针退栈
        if (!StackEmpty(stack)) {
            Pop(stack, &temp);
            for (compare = 0; compare<=count; compare++) {
                if (S[compare]==temp) {
                    //在集合一中已找到此成员
                    break;
                }
                if (compare==count && S[compare]!=temp) {
                    //此成员在集合1中不存在
                    return -1;
                }
            }
            Push(stack, temp->rchild);
        }
    }
//    集合相等
    return OK;
}

int Save(BiTree store[], int data_number){
    int friends_size = 0,fans_size = 0,spotted_size = 0;
    int indicator = 0;
    FILE *fp;
    if ((fp=fopen("file1.txt","w"))==NULL){
        printf("Fail to open file\n ");
        return ERROR;
    }
    
    for (indicator = 0; indicator<data_number; indicator++) {
        
        friends_size = set_size(store[indicator]->profile->Root_Friend);
        fans_size = set_size(store[indicator]->profile->Root_Fans);
        spotted_size = set_size(store[indicator]->profile->Root_Spotted);
        
        fwrite(&(store[indicator]->profile->name), sizeof(char), 20, fp);
        fwrite(&(store[indicator]->data), sizeof(TElemType), 1, fp);
        fwrite(&(store[indicator]->profile->ID), sizeof(char), 20, fp);
        fwrite(&(store[indicator]->profile->hobby), sizeof(char), 20, fp);
        
        //    标志朋友集存储开始
        fwrite(&(friends_size), sizeof(int), 1, fp);
        BiTNode *temp = NULL;
        Push(stack, store[indicator]->profile->Root_Friend);
        while (!StackEmpty(stack)) {
            while (GetTop(stack, &temp) && temp) {
                Push(stack, temp->lchild);//向左走到尽头
            }
            Pop(stack, &temp);//空指针退栈
            if (!StackEmpty(stack)) {
                Pop(stack, &temp);
                //            fwrite(&(temp->balance), sizeof(int), 1, fp);
                fwrite(&(temp->profile->name), sizeof(char), 20, fp);
                fwrite(&(temp->data), sizeof(TElemType), 1, fp);
                fwrite(&(temp->profile->ID), sizeof(char), 20, fp);
                fwrite(&(temp->profile->hobby), sizeof(char), 20, fp);
                Push(stack, temp->rchild);
            }
        }
        
        //    标志粉丝集存储开始
        fwrite(&(fans_size), sizeof(int), 1, fp);
        Push(stack, store[indicator]->profile->Root_Fans);
        while (!StackEmpty(stack)) {
            while (GetTop(stack, &temp) && temp) {
                Push(stack, temp->lchild);//向左走到尽头
            }
            Pop(stack, &temp);//空指针退栈
            if (!StackEmpty(stack)) {
                Pop(stack, &temp);
                //            fwrite(&(temp->balance), sizeof(int), 1, fp);
                fwrite(&(temp->profile->name), sizeof(char), 20, fp);
                fwrite(&(temp->data), sizeof(TElemType), 1, fp);
                fwrite(&(temp->profile->ID), sizeof(char), 20, fp);
                fwrite(&(temp->profile->hobby), sizeof(char), 20, fp);
                Push(stack, temp->rchild);
            }
        }
        
        //    标志关注集存储开始
        fwrite(&(spotted_size), sizeof(int), 1, fp);
        Push(stack, store[indicator]->profile->Root_Spotted);
        while (!StackEmpty(stack)) {
            while (GetTop(stack, &temp) && temp) {
                Push(stack, temp->lchild);//向左走到尽头
            }
            Pop(stack, &temp);//空指针退栈
            if (!StackEmpty(stack)) {
                Pop(stack, &temp);
                fwrite(&(temp->profile->name), sizeof(char), 20, fp);
                fwrite(&(temp->data), sizeof(TElemType), 1, fp);
                fwrite(&(temp->profile->ID), sizeof(char), 20, fp);
                fwrite(&(temp->profile->hobby), sizeof(char), 20, fp);
                Push(stack, temp->rchild);
            }
        }
    }
    fclose(fp);
    return OK;
}

//调用的时候传入数据块数量
int Load(BiTree store[], int data_number){
    FILE *fp;
    int friends_size = 0, fans_size = 0, spotted_size = 0;
    int indicator = -1, count = -1, tail = -1;
    char name[20];
    bool taller = false;
    BiTree temp_main = NULL, temp = NULL;
    
//    初始化name[],store[]
    for (indicator = 0; indicator<20; indicator++) {
        name[indicator] = '\0';
    }
    for (indicator = 0; indicator<data_number; indicator++) {
        store[indicator] = NULL;
    }
    
    if ((fp=fopen("file1.txt","r"))==NULL){
        printf("Fail to open file\n");
        return ERROR;
    }
    
    for (indicator = 0, tail = 0, count = 0; count<data_number; count++) {
        fread(name, sizeof(char), 20, fp);
        temp_main = PointerFinder(store, data_number, name);
        
        if (temp_main == NULL) {
//            此元素在集合中还不存在，需要新建
            set_init(&(store[tail]));
            strcpy(store[tail]->profile->name, name);
            fread(&((store[tail])->data), sizeof(TElemType), 1, fp);
            fread(&((store[tail])->profile->ID), sizeof(char), 20, fp);
            fread(&((store[tail])->profile->hobby), sizeof(char), 20, fp);
            temp_main = store[tail];//temp_main指向此次循环的主成员
            tail++;//数组中多了一个元素
        }
        else{
//            仅仅为了读出数据, 重新覆盖原数据
            strcpy(temp_main->profile->name, name);
            fread(&(temp_main->data), sizeof(TElemType), 1, fp);
            fread(&(temp_main->profile->ID), sizeof(char), 20, fp);
            fread(&(temp_main->profile->hobby), sizeof(char), 20, fp);
        }
        
        //    开始读取朋友集
        fread(&(friends_size), sizeof(int), 1, fp);
        
        while (friends_size--) {
            if (friends_size<0) {
                break;
            }
            fread(name, sizeof(char), 20, fp);
            temp = PointerFinder(store, data_number, name);
            
            if (temp == NULL) {
                set_init(&(store[tail]));
                strcpy(store[tail]->profile->name, name);
                fread(&((store[tail])->data), sizeof(TElemType), 1, fp);
                fread(&((store[tail])->profile->ID), sizeof(char), 20, fp);
                fread(&((store[tail])->profile->hobby), sizeof(char), 20, fp);
                InsertAVLforSet(&((store[indicator])->profile->Root_Friend), store[tail], &taller);
                tail++;//数组中多了一个元素
            }
            else{
                strcpy(temp->profile->name, name);
                fread(&(temp->data), sizeof(TElemType), 1, fp);
                fread(&(temp->profile->ID), sizeof(char), 20, fp);
                fread(&(temp->profile->hobby), sizeof(char), 20, fp);
                InsertAVLforSet(&(temp_main->profile->Root_Friend), temp, &taller);
            }
        }
        
        //    开始读取粉丝集
        fread(&(fans_size), sizeof(int), 1, fp);
        
        while (fans_size--) {
            if (fans_size<0) {
                break;
            }
            fread(name, sizeof(char), 20, fp);
            temp = PointerFinder(store, data_number, name);
            
            if (temp == NULL) {
                set_init(&(store[tail]));
                strcpy(store[tail]->profile->name, name);
                fread(&((store[tail])->data), sizeof(TElemType), 1, fp);
                fread(&((store[tail])->profile->ID), sizeof(char), 20, fp);
                fread(&((store[tail])->profile->hobby), sizeof(char), 20, fp);
                InsertAVLforSet(&(temp_main->profile->Root_Fans), store[tail], &taller);
                tail++;//数组中多了一个元素
            }
            else{
//            仅仅为了读出数据, 重新覆盖原数据
                strcpy(temp->profile->name, name);
                fread(&(temp->data), sizeof(TElemType), 1, fp);
                fread(&(temp->profile->ID), sizeof(char), 20, fp);
                fread(&(temp->profile->hobby), sizeof(char), 20, fp);
                InsertAVLforSet(&(temp_main->profile->Root_Fans), temp, &taller);
            }
        }
        
        //    开始读取关注集
        fread(&(spotted_size), sizeof(int), 1, fp);
        
        while (spotted_size--) {
            if (spotted_size<0) {
                break;
            }
            fread(name, sizeof(char), 20, fp);
            temp = PointerFinder(store, data_number, name);
            
            if (temp == NULL) {
                set_init(&(store[tail]));
                strcpy(store[tail]->profile->name, name);
                fread(&((store[tail])->data), sizeof(TElemType), 1, fp);
                fread(&((store[tail])->profile->ID), sizeof(char), 20, fp);
                fread(&((store[tail])->profile->hobby), sizeof(char), 20, fp);
                InsertAVLforSet(&(temp_main->profile->Root_Spotted), store[tail], &taller);
                tail++;//数组中多了一个元素
            }
            else{
//            仅仅为了读出数据, 重新覆盖原数据
                strcpy(temp->profile->name, name);
                fread(&(temp->data), sizeof(TElemType), 1, fp);
                fread(&(temp->profile->ID), sizeof(char), 20, fp);
                fread(&(temp->profile->hobby), sizeof(char), 20, fp);
                InsertAVLforSet(&(temp_main->profile->Root_Spotted), temp, &taller);
            }
        }
    }
    fclose(fp);
    return OK;
}

BiTree PointerFinder(BiTree store[], int number, char name[]){
    int indicator = -1;
    for (indicator = 0; indicator<number; indicator++) {
        if (store[indicator]==NULL) {
            break;
        }
        if (strcmp(store[indicator]->profile->name, name)==0) {
            return store[indicator];
        }
    }
    return NULL;
}

int DataGenerator(int number){
    char ID[number][20], name[number][20], hobby[number][20];
    int i = 0, friend_num = -1, fans_num = -1, spotted_num = -1;
    int indicator = -1, indicator2 = -1;
    bool taller = false;
    BiTree temp[number];
    
    for (i = 0; i<number; i++) {
        for (indicator = 0; indicator<20; indicator++) {
            ID[i][indicator] = '\0';
            name[i][indicator] = '\0';
            hobby[i][indicator] = '\0';
        }
    }
    //随机生成ID、Name、Hobby 
    IDGenerator(number, ID);
    NameGenerator(number, 8, name);
    HobbyGenerator(number, hobby);
    
  
    for (i = 0; i<number; i++) {
        set_init(&temp[i]);
        strcpy(temp[i]->profile->ID, ID[i]);
        strcpy(temp[i]->profile->name, name[i]);
        strcpy(temp[i]->profile->hobby, hobby[i]);
    }
    
    srand((unsigned) time(NULL));
    
    for (i = 0; i<number; i++)
	{
        friend_num = rand()%20;//调整朋友集的数量
        for (indicator = 0; indicator < friend_num; indicator++)
		{
        Z: indicator2 = rand()%number;
            if (indicator2 == i) 
			{
			
                goto Z;
                
            }
        
            InsertAVLforSet(&(temp[i]->profile->Root_Friend), temp[indicator2], &taller);
            
        }
        
        fans_num = rand()%20;//调整粉丝集的数量
        for (indicator = 0; indicator < fans_num; indicator++) {
        C: indicator2 = rand()%number;
            if (indicator2 == i) {
                goto C;
            }
            InsertAVLforSet(&(temp[i]->profile->Root_Fans), temp[indicator2], &taller);
        }
        
        spotted_num = rand()%20;//调整关注集的数量
        for (indicator = 0; indicator < spotted_num; indicator++) {
        I: indicator2 = rand()%number;
            if (indicator2 == i) {
                goto I;
            }
            InsertAVLforSet(&(temp[i]->profile->Root_Spotted), temp[indicator2], &taller);
        }
    }
    
    //打出数据
    for (i = 0; i<number; i++) {
    	HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(h_console,FOREGROUND_BLUE| FOREGROUND_INTENSITY );
    	printf("the node is the %d node:",i);
    	SetConsoleTextAttribute(h_console,FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("ID：%s\tname：%s\thobby: %s\t\n",temp[i]->profile->ID,temp[i]->profile->name,temp[i]->profile->hobby);
        SetConsoleTextAttribute(h_console,FOREGROUND_GREEN| FOREGROUND_INTENSITY );
        printf("Friends:");
        SetConsoleTextAttribute(h_console,FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        TraverseAVL(temp[i]->profile->Root_Friend);
        printf("\n");
        SetConsoleTextAttribute(h_console,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("Fans:");
        SetConsoleTextAttribute(h_console,FOREGROUND_GREEN | FOREGROUND_BLUE| FOREGROUND_INTENSITY );
        TraverseAVL(temp[i]->profile->Root_Fans);
        printf("\n");
        SetConsoleTextAttribute(h_console,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("Spotted:");
        SetConsoleTextAttribute(h_console,FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        TraverseAVL(temp[i]->profile->Root_Spotted);
        printf("\n\n");
        SetConsoleTextAttribute(h_console,FOREGROUND_GREEN | FOREGROUND_BLUE  | FOREGROUND_RED);
    }
    Save(temp, number);
    return OK;
}



/*********************三个随机生成函数****************/
int NameGenerator(int number, int length, char name[][20]){
    int flag, i, count = 0;
    char* string;
    srand((unsigned) time(NULL));
    if ((string = (char*) malloc(length*sizeof(char))) == NULL ){
        printf("无法分配内存\n");
        return ERROR;
    }
    
    for (count = 0; count<length; count++) {
        string[count] = '\0';
    }
    
    for (count = 0; count<number; count++) {
        for (i = 0; i < length; i++){
            if (i==0) {
                flag = 0;
            }
            else{
                flag = 1;
            }
            switch (flag){
                case 0:
                    string[i] = 'A' + rand() % 26;
                    break;
                case 1:
                    string[i] = 'a' + rand() % 26;
                    break;
                default:
                    string[i] = 'x';
                    break;
            }
        }
        string[length] = '\0';
        strcpy(name[count], string);
    }
    return OK;
}

int HobbyGenerator(int number, char Hobby[][20]){
    int flag, i = 0;
    char string[20];
    for (i = 0; i<20; i++) {
        string[i] = '\0';
    }
    srand((unsigned) time(NULL));
    
    for (i = 0; i < number; i++){
        flag = rand() % 5;
        switch (flag){
            case 0:
                strcpy(string, "cartoon");
                break;
            case 1:
                strcpy(string, "Mountain climbing");
                break;
            case 2:
                strcpy(string, "bar");
                break;
            case 3:
                strcpy(string, "Swim");
                break;
            case 4:
                strcpy(string, "Switch");
                break;
            default:
                break;
        }
        strcpy(Hobby[i], string);
    }
    return OK;
}

int IDGenerator(int number, char ID[][20]){
    int count = 0, high = 0, middle = 0, tail = 0;
    char temp[20];
    for (count = 0; count<20; count++) {
        temp[count] = '\0';
    }
    
    for (count = 0; count<number; count++) {
        strcpy(temp, "201617000");
        high = count/100;
        temp[6]+=high;
        middle = (count - (count/100)*100)/10;
        temp[7]+=middle;
        tail = count%10;
        temp[8]+=tail;
        strcpy(ID[count], temp);
    }
    return OK;
}
/*********************三个随机生成函数****************/



int mutualSpotted(BiTree A, BiTree B, BiTree mutualSpottedSet[]){
    if (A == NULL) {
        printf("第一个成员不存在\n");
        return ERROR;
    }
    if (B == NULL) {
        printf("第二个成员不存在\n");
        return ERROR;
    }
    if (A->profile->Root_Spotted == NULL) {
        printf("第一个成员没有关注的对象\n");
        return ERROR;
    }
    if (B->profile->Root_Spotted == NULL) {
        printf("第二个成员没有关注的对象\n");
        return ERROR;
    }
    
//遍历A的关注集，放入数组
    BiTNode *temp = NULL;
    BiTree storeA[ARRAY_LENGTH];
    int indicator = 0;
    
    for (indicator = 0; indicator<ARRAY_LENGTH; indicator++) {
        storeA[indicator] = NULL;
    }
    indicator = 0;
    
    Push(stack, A->profile->Root_Spotted);
    while (!StackEmpty(stack)) {
        while (GetTop(stack, &temp) && temp) {
            Push(stack, temp->lchild);//向左走到尽头
        }
        Pop(stack, &temp);//空指针退栈
        if (!StackEmpty(stack)) {
            Pop(stack, &temp);
            storeA[indicator] = temp;
            indicator++;
            Push(stack, temp->rchild);
        }
    }
    
//    遍历B的关注集，寻找数组中是否有相同元素
    BiTree temp2 = NULL;
    indicator = 0;
    
    Push(stack, B->profile->Root_Spotted);
    while (!StackEmpty(stack)) {
        while (GetTop(stack, &temp) && temp) {
            Push(stack, temp->lchild);//向左走到尽头
        }
        Pop(stack, &temp);//空指针退栈
        if (!StackEmpty(stack)) {
            Pop(stack, &temp);
            temp2 = PointerFinder(storeA, ARRAY_LENGTH, temp->profile->name);
            if (temp2!=NULL) {
                mutualSpottedSet[indicator] = temp2;
                indicator++;
            }
            Push(stack, temp->rchild);
        }
    }
    return OK;
}

int mutualHobby(BiTree A, BiTree B){
    if (A == NULL) {
        printf("二叉树A不存在\n");
        return ERROR;
    }
    if (B == NULL) {
        printf("二叉树B不存在\n");
        return ERROR;
    }
    if (strcmp(A->profile->hobby, B->profile->hobby)==0) {
//        B与A有相同爱好
        return OK;
    }else{
//        B与A没有相同爱好
        return -1;
    }
}

int friends_Friend(BiTree Afriend, BiTree friends_FriendSet[]){
    if (Afriend == NULL) {
        printf("No such AVL tree\n");
        return ERROR;
    }
    if (Afriend->profile->Root_Friend == NULL) {
        printf("The friend has no friends\n");
        return ERROR;
    }
    
    int indicatorForFriendsfriend = 0;
    BiTNode *temp = NULL;
    Push(stack, Afriend->profile->Root_Friend);
    while (!StackEmpty(stack)) {
        while (GetTop(stack, &temp) && temp) {
            Push(stack, temp->lchild);//向左走到尽头
        }
        Pop(stack, &temp);//空指针退栈
        if (!StackEmpty(stack)) {
            Pop(stack, &temp);
            friends_FriendSet[indicatorForFriendsfriend] = temp;
            indicatorForFriendsfriend++;
            Push(stack, temp->rchild);
        }
    }
    return OK;
}




int DataGenerator2(int number){
    char ID[number][20], name[number][20], hobby[number][20];
    int i = 0, friend_num = -1, fans_num = -1, spotted_num = -1;
    int indicator = -1, indicator2 = -1;
    bool taller = false;
    BiTree temp[number];
    
    for (i = 0; i<number; i++) {
        for (indicator = 0; indicator<20; indicator++) {
            ID[i][indicator] = '\0';
            name[i][indicator] = '\0';
            hobby[i][indicator] = '\0';
        }
    }
    //随机生成ID、Name、Hobby 
    IDGenerator(number, ID);
    NameGenerator(number, 8, name);
    HobbyGenerator(number, hobby);
    
  
    for (i = 0; i<number; i++) {
        set_init(&temp[i]);
        strcpy(temp[i]->profile->ID, ID[i]);
        strcpy(temp[i]->profile->name, name[i]);
        strcpy(temp[i]->profile->hobby, hobby[i]);
    }
    
    srand((unsigned) time(NULL));
    
    for (i = 0; i<number; i++)
	{
        friend_num = rand()%20;//调整朋友集的数量
        for (indicator = 0; indicator < friend_num; indicator++)
		{
        Z: indicator2 = rand()%number;
            if (indicator2 == i) 
			{
			
                goto Z;
                
            }
        
            InsertAVLforSet(&(temp[i]->profile->Root_Friend), temp[indicator2], &taller);
            
        }
        
        fans_num = rand()%20;//调整粉丝集的数量
        for (indicator = 0; indicator < fans_num; indicator++) {
        C: indicator2 = rand()%number;
            if (indicator2 == i) {
                goto C;
            }
            InsertAVLforSet(&(temp[i]->profile->Root_Fans), temp[indicator2], &taller);
        }
        
        spotted_num = rand()%20;//调整关注集的数量
        for (indicator = 0; indicator < spotted_num; indicator++) {
        I: indicator2 = rand()%number;
            if (indicator2 == i) {
                goto I;
            }
            InsertAVLforSet(&(temp[i]->profile->Root_Spotted), temp[indicator2], &taller);
        }
    }
    
    //打出数据
    for (i = 0; i<1; i++) {
    	HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(h_console,FOREGROUND_BLUE| FOREGROUND_INTENSITY );
    	printf("the node is the %d node:",i);
    	SetConsoleTextAttribute(h_console,FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("ID：%s\tname：%s\thobby: %s\t\n",temp[i]->profile->ID,temp[i]->profile->name,temp[i]->profile->hobby);
        SetConsoleTextAttribute(h_console,FOREGROUND_GREEN| FOREGROUND_INTENSITY );
        printf("Friends Set(Set 1):");
        SetConsoleTextAttribute(h_console,FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        TraverseAVL(temp[i]->profile->Root_Friend);
        printf("\n");
        SetConsoleTextAttribute(h_console,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("Fans Set(Set 2):");
        SetConsoleTextAttribute(h_console,FOREGROUND_GREEN | FOREGROUND_BLUE| FOREGROUND_INTENSITY );
        TraverseAVL(temp[i]->profile->Root_Fans);
        printf("\n");
        SetConsoleTextAttribute(h_console,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("Spotted Set(Set 3):");
        SetConsoleTextAttribute(h_console,FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        TraverseAVL(temp[i]->profile->Root_Spotted);
        printf("\n\n");
        SetConsoleTextAttribute(h_console,FOREGROUND_GREEN | FOREGROUND_BLUE  | FOREGROUND_RED);
    }
    Save(temp, number);
    return OK;
}
