
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL, *cur, *temp;
struct node* create(){
    cur = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &cur->data);
    cur->left = NULL;
    cur->right = NULL;
    if(root == NULL){
        root = cur;
    }
    else{
        temp = root;
        while(temp != NULL){
            if(cur->data < temp->data && temp->left == NULL){
                temp->left = cur;
                return root;
            }
            else if(cur->data < temp->data && temp->left != NULL){
                temp = temp->left;
            }
            else if(cur->data > temp->data && temp->right == NULL){
                temp->right = cur;
                return root;
            }
            else{
                temp = temp->right;
            }
        }
    }
}

//Pre order
void preorder(struct node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
//inorder
void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
//post order
void postorder(struct node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    int ch, ele;
    while(1){
        printf("1-Create\n2-Preorder\n3-Inorder\n4-Postorder\n5-Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                root = create();
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                exit(0);
        }
    }
}

OUTPUT:
1-Create
2-Preorder
3-Inorder
4-Postorder
5-Exit
Enter your choice:1 
78
1-Create
2-Preorder
3-Inorder
4-Postorder
5-Exit
Enter your choice:1
32
1-Create
2-Preorder
3-Inorder
4-Postorder
5-Exit
Enter your choice:1
60
1-Create
2-Preorder
3-Inorder
4-Postorder
5-Exit
Enter your choice:1
89
1-Create
2-Preorder
3-Inorder
4-Postorder
5-Exit
Enter your choice:1
46
1-Create
2-Preorder
3-Inorder
4-Postorder
5-Exit
Enter your choice:1
92
1-Create
2-Preorder
3-Inorder
4-Postorder
5-Exit
Enter your choice:1
53
1-Create
2-Preorder
3-Inorder
4-Postorder
5-Exit
Enter your choice:2
78 32 60 46 53 89 92 
1-Create
2-Preorder
3-Inorder
4-Postorder
5-Exit
Enter your choice:3
32 46 53 60 78 89 92 
1-Create
2-Preorder
3-Inorder
4-Postorder
5-Exit
Enter your choice:4
53 46 60 32 92 89 78 
1-Create
2-Preorder
3-Inorder
4-Postorder
5-Exit
Enter your choice:5
