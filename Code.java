//
// Definition for binary tree:
// class Tree<T> {
//   Tree(T x) {
//     value = x;
//   }
//   T value;
//   Tree<T> left;
//   Tree<T> right;
// }
int kthSmallestInBST(Tree<Integer> t, int k) {
    Tree<Integer> curr = t, pre = null;
    
    int count = 0;
    
    while(curr != null)
    {           
        if(curr.left == null)
        {
            count++;
            if(count == k) return curr.value;
            curr = curr.right;
        }
        else{
            pre = curr.left;
            while(pre.right != null && curr != pre.right)
                pre = pre.right;
            
            if(pre.right == null)
            {
                pre.right = curr;
                curr = curr.left;   
            }
            else{
                count++;
                pre.right = null;
                if(count == k) return curr.value;
                curr = curr.right;
            }
        }
        
            
    }
    
    return k;
}
