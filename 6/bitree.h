//
// Created by DELL on 2022/3/20.
//
#ifndef DATA_STRUCTURE_BITREE_H
#define DATA_STRUCTURE_BITREE_H
#include"../status.h"

typedef struct BiTNode /*结点结构*/
{
    char data;/*结点数据*/
    struct BiTNode *rchild;
    struct BiTNode *lchild;/*左右孩子指针*/
}BiTnode, *BiTree;
void PreOrderTraverse(BiTree T);
void CreateBiTree(BiTree *T);



/*线索二叉树*/
typedef enum{Link,Thread}PointerTag;/*Link表示子结点为孩子指针，Thread表示为线索*/

typedef struct BiThrNode
{
    char data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
}BiThrNode,*BiThrTree;
extern BiThrTree pre;
void printpre();
void print2();
void InThreading(BiThrTree p);
Status InOrderTraverse_Thr(BiThrTree T);
#endif //DATA_STRUCTURE_BITREE_H
