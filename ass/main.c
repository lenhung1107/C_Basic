#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"
#include <time.h>
node* root,*tail, * cur;

int size = 0;
treeType tree;

void read_input() {
    elementType log;
    FILE *p = fopen("booking_orders.txt", "r");
    fscanf(p,"%d", &size);
    printf("So luong yeu cau: %d\n", size);
    while(fscanf(p,"%s %d %d %s %s %d", log.Ma, &log.so_nguoi, &log.phong_ks, log.Ma_ks, log.thoi_gian, &log.so_tre_em) != EOF) {
        insertAtTail(log, &root, &tail, &cur);
    }
    // traverseListFromRoot(root);
}
void yeu_cau_khong_hop_le(int *count) {
    node *p;
    int _count;
  for(p = root; p != NULL; p = p->next){
    if(p->element.so_nguoi == p->element.so_tre_em) {
        _count++;
    }
  }
  *count = _count;
}

void chen_vao_cay() {
    node *p;
    for(p = root; p != NULL; p = p->next){
        insertNode(p->element, &tree);
    }
}

int main()
{
    char choice;

    while(1){
    printf("Chuong trinh quan ly dat phong\n"
       "Vui long chon mot trong cac chuc nang sau\n"
	   "[1] Doc du lieu tu file log\n"
	   "[2] Kiem tra so luong yeu cau khong hop le\n"
	   "[3] Tra cuu theo ma yeu cau\n"
	   "[4] Thay doi yeu cau\n"
	   "[5] Huy yeu cau\n"
	   "[6] Luu danh sach yeu cau ra file\n"
       "[7] Thong ke khach san duoc uu thich nhat\n"
       "[0] Quit\n");

    fflush(stdin);
    printf("Input your choice: ");
    scanf("%c", &choice);

    while(choice > '7' || choice < '0'){
      fflush(stdin);
      printf("Ivalid! Input your choice: ");
      scanf("%c", &choice);
    }
    
    switch(choice){
    case '0':{
      exit(1);
      break;
    }
    case '1':{
        read_input();
        chen_vao_cay();
      break;
    }

    case '2':{
        int count = 0;
        yeu_cau_khong_hop_le(&count);
        printf("So yeu cau khong hop le: %d\n",count);
      break;
    }

    case '3':{
        char code[8];
        printf("Nhap ma yeu cau: ");
        scanf("%s",code);
        treeType node = search(code, tree);
        if(node == NULL) {
            printf("ma yeu cau khong dung\n");
        } else {
            printf("%s %d %d %s %s %d\n", node->element.Ma, node->element.so_nguoi, node->element.phong_ks, node->element.Ma_ks, node->element.thoi_gian, node->element.so_tre_em);
        }
      break;
    }

    case '4':{

      break;
    }

    case '5':{
        char code[8];
        printf("Nhap ma yeu cau: ");
        scanf("%s",code);
        treeType node = search(code, tree);
        if(node == NULL) {
            printf("Yeu cau khong ton tai. Huy khong thanh cong\n");
        } else {
            deleteNode(code, &tree);
            printf("Huy thanh cong\n");
        }
        // preOrderPrint(tree);
      break;
    }

    case '6':{
      
      break;
    }
    case '7':{
      
      break;
    }
    
    }
  }
    return 0;
}