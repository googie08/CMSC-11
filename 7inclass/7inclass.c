#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *left;
    struct node *right;
};

void insert(struct node *, int);
void print(struct node *);

int main(){
    struct node tree;
    tree.left = NULL;
    tree.right = NULL;

    printf("n: ");
    scanf("%d", &tree.val);

    while(true) {
        int val;
        printf("n: ");
        scanf("%d", &val);

        insert(&tree, val);
        print(&tree);
        printf("\n");
    }

    return 0;
}

void insert(struct node *current, int val){
    if(val < current->val){
        if(current->left == NULL) {
            struct node *newNode = (struct node*) malloc(sizeof(struct node));
            newNode->val = val;
            newNode->left = NULL;
            newNode->right = NULL;

            current->left = newNode;
        }
        else insert(current->left, val);
    }

    else if(val > current->val){
        if(current->right == NULL) {
            struct node *newNode = (struct node*) malloc(sizeof(struct node));
            newNode->val = val;
            newNode->left = NULL;
            newNode->right = NULL;

            current->right = newNode;
        }
        else insert(current->right, val);
    }
}

void print(struct node *current){
    if(current->left != NULL)
        print(current->left);

    printf("%d ", current ->val);

    if(current->right == NULL)
        return;
    else
        print(current->right);
}
