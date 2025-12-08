# include <stdio.h>
# include <stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value){
    struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data= value;
    newNode->left= newNode->right=NULL;
    return newNode;
}


struct Node* insert (struct Node *root, int value){
    if (root== NULL){
        return createNode(value);
    }

    if (value<root->data){
        root->left= insert(root->left, value);
    }else if(value> root->data){
        root->right= insert(root->right, value);
    }
    return root;
}

// traversals
void inorder(struct Node *root){
    if (root==NULL) return;
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}

void preorder(struct Node *root){
    if (root==NULL) return;
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}

void display(struct Node *root){
    printf("BST elements(Inorder):");
    inorder(root);
    printf("\n");
}


void postorder(struct Node *root){
    if (root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}


int main(){
    struct Node *root= NULL;
    int choice, value;
    while (1){
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert into BST\n");
        printf("2. Inorder traversal\n");
        printf("3. Preorder traversal\n");
        printf("4. Postorder traversal\n");
        printf("5. Display BST\n");
        printf("6. EXIT!!!!\n");
        printf("Enter Your Choice\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the Value to insert: ");
            scanf("%d",&value);
            root= insert(root, value);
            break;
        case 2:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Inorder Traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 5:
            display(root);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!!! Try Ahain. \n");
            break;
        }
    }
    return 0;
}



