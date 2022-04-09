#include <bits/stdc++.h>

using namespace std;

template<class T>
    class binaryTree {
        private:
            typedef struct treeNode {
                T val;
                struct treeNode *ls, *rs; 
            } node;
            node* root = NULL;
            node* temp = NULL;
            bool findinner(T x, node* opers, node* contre) {
                if (!opers) {
                    this->temp = contre;
                    return false;
                }
                if (opers->val == x) {
                    this->temp = opers;
                    return true;
                }
                else if (opers->val < x) 
                    return findinner(x, opers->rs, opers);
                else 
                    return findinner(x, opers->ls, opers);
            }
            bool deleteaiminner(node** temp) {
                node *q = (*temp)->ls; 
                node *p = *temp;
                if (!((*temp)->rs)) { // 若右子树不存在
                    *(temp) = ((*temp)->ls);
                    free(p);
                } else if (!((*temp)->ls)) {
                    *(temp) = ((*temp)->rs);
                    free(p);
                } else {
                    while (q->rs) {
                        p = q, q = q->rs;
                    }
                    (*temp)->val = q->val; // p就是temp的左儿子和p不是temp的左儿子有不一样的情况
                    if (q == (*temp)->ls) {
                        (*temp)->ls = q->ls;
                    } else {
                        p->rs = q->ls;
                    }
                    free(q);
                }
                return true;
            }
            bool deletehard(node** t, T x) {
                if (!*t)
                    return false;
                else {
                    if ((*t)->val == x)
                        return deleteaiminner(t);
                    else if (x < (*t)->val)
                        return deletehard(&((*t)->ls), x);
                    else {
                        return deletehard(&((*t)->rs), x);
                    }
                }
            }
            bool insertinner(T x) {
                this->temp = NULL;
                if (!findinner(x, this->root, NULL)) { // 如果查找失败
                    node* arts = (node*)malloc(sizeof(node));
                    arts->val = x;
                    arts->ls = arts->rs = NULL;
                    if (!(this->root))
                        this->root = arts;
                    else if (this->temp->val < x)
                        this->temp->rs = arts;
                    else 
                        this->temp->ls = arts;
                    return true;
                } else { 
                    return false;
                }
            }
            void enorgicinner(node* temp) {
                if (!temp)
                    return;
                enorgicinner(temp->ls);
                cout << temp->val << " ";
                enorgicinner(temp->rs);
            }
        public:
            bool find(T x) {
                return findinner(x, this->root, NULL);
            }
            bool insert(T x) {
                return insertinner(x);
            }
            void insert(T x[], int n) {
                for (int i = 0; i < n; i++)
                    insertinner(x[i]);
            }
            void enorgic() {
                enorgicinner(this->root);
            }
            bool detele(T x) {
                return deletehard(&(this->root), x);
            }
    };

binaryTree<int> test;

int main() {
    srand(5);
    int arr[] = {62, 58, 88, 73, 99, 93, 47, 51, 49, 56, 50, 48, 35, 29, 37, 36};
    test.insert(arr, 16);
    for (int i = 0; i < 16; i++) {
        test.insert(arr, 16);
        test.detele(arr[i]);
        test.enorgic();
        putchar('\n');
    }
    // test.insert(arr, 16);
    // test.detele(62);
    // test.detele(58);
    // test.enorgic();
    return 0;
}