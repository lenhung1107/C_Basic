#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
  char Ma[8], Ma_ks[4], thoi_gian[11];
   int so_nguoi, phong_ks, so_tre_em;
}elementType;

typedef struct node{
  elementType element;
  struct node *prev;
  struct node *next;
} node;

typedef node* doubleList;

//2. Tao doublelist rong~
void makeNullList(doubleList* root, doubleList* tail, doubleList* cur){
  *root = NULL;
  *tail = NULL;
  *cur = NULL;
  return;
}

//3. Tao node moi
node *makeNewNode(elementType ele){
  node *new = (node*)malloc(sizeof(node));
  new->element = ele;
  new->prev = NULL;
  new->next = NULL;
  return new;
}

//4. Them 1 phan tu vao cuoi list
void insertAtTail(elementType ele,doubleList *root, doubleList *tail, doubleList *cur){
  node *new = makeNewNode(ele);
  if(*tail == NULL){
    *root = new;
    *tail = new;
    *cur = new;
  }
  else{
    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;
    *cur = *tail;
  }
}

//6. Them 1 phan tu vao dau list
void insertAtHead(elementType ele, doubleList *root, doubleList *tail, doubleList *cur){
  node *new = makeNewNode(ele);
  if(*root == NULL){
    *root = new;
    *tail = new;
    *cur = new;
  }
  else{
    (*root)->prev = new;
    new->next = *root;
    new->prev = NULL;
    *root = new;
    *cur = new;
  }
}

void displayNode(node *p){
  printf("%s\n", (p->element).Ma_ks);
}
//8. Duyet doubleList tu cuoi list
void traverseListFromTail(node *tail){
  node *p;
  for (p = tail; p != NULL; p = p->prev){
    displayNode(p);
  }
}

//9. Duyet doubleList tu dau list
void traverseListFromRoot(node* root){
  node *p;
  for(p = root; p != NULL; p = p->next){
    displayNode(p);
  }
}

