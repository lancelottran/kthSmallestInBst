//
//
// Definition for binary tree:
// typedef struct tree_##name {
//   type value;
//   struct tree_##name *left;
//   struct tree_##name *right;
// } tree_##name;
//
// tree_##name *alloc_tree_##name(type v) {
//   tree_##name *t = calloc(1, sizeof(tree_##name));
//   t->value = v;
//   return t;
// }
int kthSmallestInBST(tree_integer * t, int k) {
    tree_integer * curr = t;
    tree_integer * prev;
    int count = 0;
    
    while(curr != NULL){
        if(curr->left == NULL){
            count++;
            if(count == k) return curr->value;
            curr = curr->right;
        }
        else{
            prev = curr->left;
            while(prev->right != NULL && curr != prev->right)
                prev = prev->right;
            
            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }else{
                count++;
                prev->right = NULL;
                if(count == k) return curr->value;
                curr = curr->right;
            }
        }
    }
    
    return k;
}
