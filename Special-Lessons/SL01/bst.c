#include <stdio.h>
#include <stdlib.h>

/* Un albero binario di ricerca ha le seguenti proprietà:
 * - Il sottoalbero sinistro di un nodo x contiene soltanto i nodi con chiavi
 *   minori della chiave del nodo x
 * - Il sottoalbero destro di un nodo x contiene soltanto i nodi con chiavi
 *   maggiori della chiave del nodo x
 * - Il sottoalbero destro e il sottoalbero sinistro devono essere entrambi
 *   due alberi binari di ricerca. */

struct node
{
    int val;
    struct node *left, *right;
};

/* Add a new node, if root is NULL returns the new root
 * (the first inserted node) otherwise it just return the
 * root passed by the user in the input */
struct node *add(struct node *root, int val)
{
    struct node *saved_root = root;
    struct node *new = malloc(sizeof(*new));

    new->left = new->right = NULL;
    new->val = val;

    if (root == NULL)
        return new;

    while (1)
    {
        if (val > root->val)
        {
            if (root->right == NULL)
            {
                root->right = new;
                return saved_root;
            }
            root = root->right;
        }
        else
        {
            if (root->left == NULL)
            {
                root->left = new;
                return saved_root;
            }
            root = root->left;
        }
    }
}

void print_sorted(struct node *root)
{
    if (root == NULL)
        return;
    print_sorted(root->left);
    printf("%d\n", root->val);
    print_sorted(root->right);
}

void free_three(struct node *root) {
    if (root == NULL)
        return;
    free_three(root->left);
    free_three(root->right);
    free(root);

}

int main(void)
{
    struct node *root = NULL;

    root = add(root, 20);
    root = add(root, 10);
    root = add(root, 5);
    root = add(root, 20);
    root = add(root, 20);
    root = add(root, 100);
    root = add(root, 40);
    root = add(root, 33);

    print_sorted(root);

    free_three(root);

    return 0;
}