//
// Created by DELL on 2022/3/20.
//

#include "bitree.h"
BiThrTree pre;
void PreOrderTraverse(BiTree T)
{
    cout<<"start";
    if(T==NULL){
        cout<<"fail";
        return;
    }
    cout<<T->data;
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}
void CreateBiTree(BiTree *T){
    char ch;
    cin>>ch;
    if(ch=='#'){
        *T = NULL;
    }
    else{
        *T = (BiTree)malloc(sizeof (BiTNode));
//        if(!*T)exit(OVERFLOW);
        (*T)->data=ch;
        CreateBiTree(&((*T)->lchild));
        CreateBiTree(&((*T)->rchild));
    }
}


void InThreading(BiThrTree p)
{
    if(p)
    {
        InThreading(p->lchild);
        if(!p->lchild)
        {
            p->LTag=Thread;
            p->lchild=pre;
        }
        if(!p->rchild)
        {
            p->RTag=Thread;
            p->rchild=p;
        }
        pre=p;
        InThreading(p->rchild);
    }
}

Status InOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree  p;
    p = T->lchild;
    while(p != T){
        while(p->LTag == Link)p = p->lchild;
        cout<<p->data;
        while(p->RTag == Thread && p->rchild !=T)
        {
            p = p->rchild;
        }
        p = p->rchild;
    }
    return OK;
}
void printpre(){
    pre = (BiThrTree)malloc(sizeof (BiThrNode));
    cout<<pre<<endl;
}
void print2(){
    cout<<pre<<endl;
}