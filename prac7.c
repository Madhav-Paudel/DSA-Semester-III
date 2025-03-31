// Implementation of Binary Search Tree in C
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

struct bst {
    struct bst *left;
    int data;
    struct bst *right;
};

typedef struct bst node;
node *insrt(node *, int);
void pre_order(node *);
void search(node *, int);
node *del(node *, int);
node *findmin(node *);

int main() {
    int n, num, choice;
    node *root = NULL, *temp;
    while (1) {
        printf("\n1.Create a binary search tree:");
        printf("\n2.Preorder Traversal:");
        printf("\n3.Search a node value:");
        printf("\n4.Delete a node:");
        printf("\n5.Find min node:");
        printf("\n6.Exit:");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter a data:");
                scanf("%d", &num);
                root = insrt(root, num);
                break;

            case 2:
                if (root == NULL)
                    printf("\nThe tree is empty:");
                else
                    pre_order(root);
                break;
            case 3:
                printf("\nEnter a number to search:");
                scanf("%d", &num);
                search(root, num);
                break;
            case 4:
                if (root == NULL) {
                    printf("\nTree is empty:");
                } else {
                    printf("\nEnter the number to delete:");
                    scanf("%d", &num);
                    root = del(root, num);
                }
                break;

            case 5:
                temp = findmin(root);
                if (temp == NULL)
                    printf("\nThe tree is empty:");
                else
                    printf("\nThe minimum node is %d", temp->data);
                break;
            case 6:
                exit(0);
            default:
                printf("The choice you entered is not valid");
        }
    }
    return 0;
}

node *insrt(node *r, int num) {
    if (r == NULL) {
        r = (node *)malloc(sizeof(node));
        r->data = num;
        r->left = r->right = NULL;
    } else if (num < r->data) {
        r->left = insrt(r->left, num);
    } else if (num > r->data) {
        r->right = insrt(r->right, num);
    } else if (num == r->data) {
        printf("\nThis node already exist in the tree:");
    }
    return r;
}

void pre_order(node *root) {
    if (root != NULL) {
        printf("%d\n", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void search(node *root, int num) {
    if (root == NULL) {
        printf("\nSearch Unsuccessful!\nTry other value");
        return;
    } else if (num == root->data) {
        printf("\nSearch Successful!\nNumber %d is Found!", num);
        return;
    } else if (num < root->data) {
        search(root->left, num);
    } else
        search(root->right, num);
}
node *del(node *r, int num) {
    node *temp, *root = r;
    if (root == NULL)
        return root;
    else if (num < root->data) // Search in left subtree
        root->left = del(root->left, num);
    else if (num > root->data) // Search in right subtree
        root->right = del(root->right, num);
    else if (root->left != NULL && root->right != NULL) //If both the subtrees are present
    {
        temp = findmin(root->right);
        root->data = temp->data;
        root->right = del(root->right, root->data); // Corrected line: pass `root->right` and `root->data`
    } else //If one of the subtree is null
    {
        temp = root;
        if (root->left == NULL)
            root = root->right;
        else if (root->right == NULL)
            root = root->left;
        free(temp);
    }
    return root;
}

node *findmin(node *root) {
    node *temp;
    temp = root;
    if (temp == NULL)
        return NULL;
    if (temp->left == NULL)
        return (temp);
    else
        return (findmin(temp->left));
}