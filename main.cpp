#include "head.h"

using namespace std;

struct Node{//CT节点
    int m[pmax];
    struct Node* parent;    //指向父节点的指针
    int t;
    int flag;

    Node(){
        memset(m, 0, sizeof(m));
        parent = NULL;
        t = 0;
        flag = 0;
    }
}Tree[nmax];

bool repeat(int i){// true为判断M是重复节点
    for(int j = 0; j < np; ++ j){
        if(M[j] != Tree[i].m[j]) return false;
    }
    return true;    // M(j) == m(j),    j=1,2,...np
}

bool check(int i){// true为判断ti可发生
    for (int j = 0; j < np; ++j) {
        if(M[j] < O2[i][j]) return false;
    }
    return true;    //M[ti> 充要条件:M(j)>=aij j=1,2,...,np
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int  cases = 0;

    /* 输入库所个数np和变迁个数nt， 0 0结束输入 */
    while (~scanf("%d %d", &np, &nt) && (np!=0 || nt!=0)){
        printf("Case %d:\n", ++cases);
        int CR = 0; // 1-可覆盖树,0-可达树
        int k = 0; // CT中节点个数

        /* 数据重置 */
        memset(Tree, 0, sizeof(Tree));
        memset(A, 0, sizeof(A));
        memset(O1, 0, sizeof(O1));
        memset(O2, 0, sizeof (O2));
        memset(M0, 0, sizeof(M0));
        memset(M, 0, sizeof(M));
        memset(M1, 0, sizeof(M1));

        /* 输入关联矩阵A和初始标识M0 */
        for (int i = 0; i < nt; ++i) {
            for (int j = 0; j < np; ++j) {
                scanf("%d", &A[i][j]);
                if (A[i][j] == 1)   O1[i][j] = A[i][j];
                if (A[i][j] == -1)   O2[i][j] = -A[i][j];
            }
        }// 关联矩阵

        Node *head; // 头节点
        head = (Node*)malloc(sizeof(struct Node));
        head->parent = NULL;
        Tree[k].parent = head;  //根节点
        for (int i = 0; i < np; ++i) {
            scanf("%d", &M0[i]);
            Tree[k].m[i] = M0[i];
        }//初始标识
        k ++;

        /* 1.是否存在一个新=0的节点，任选一个新节点作为当前节点=M */
        while(1){
            int nnew = -1;  //当前节点（标识）下标
            for (int i = 0; i < k; ++i) {
                if(Tree[i].flag == 0){
                    nnew = i;
                    break;
                }
            }
            if(nnew == -1) break;

            /* 将任意一个新节点设为当前节点 */
            for (int i = 0; i < np; ++i) {
                M[i] = Tree[nnew].m[i];
            }

            int rep = 0;
            Node* q = Tree[nnew].parent;
            while(q->parent != NULL){
                int f = 0;
                for (int j = 0; j < np; ++j) {
                    if(M[j] != q->m[j]) f = 1;
                }
                if(f == 0){
                    Tree[nnew].flag = 1;
                    rep = 1;
                    break;
                }
                q = q->parent;
            }
            if(rep == 1){
                continue;
            }

            int dead = -1;
            for (int i = 0; i < nt; ++i) {
                if(check(i)){
                    dead = i;
                    break;
                }
            }
            if (dead == -1){
                Tree[nnew].flag = -1;
                continue;
            }

            /* 对每一个可以发生的ti */
            for (int i = 0; i < nt; ++i) {// 遍历每一个变迁t
                if(check(i)){//ti可发生，即处于enabled状态
                    for (int j = 0; j < np; ++j) {
                        if(M[j] == 'w') M1[j] = M[j];
                        else M1[j] = M[j] + A[i][j];
                        Tree[k].m[j] = M1[j];
                    }

                    Node* p = &Tree[nnew];
                    while(p->parent != NULL){
                        int f = 0;
                        for (int j = 0; j < np; ++j) {
                            if(p->m[j] > M1[j]){
                                f = -1; //不满足条件
                                break;
                            }
                        }
                        if(f == 0){
                            for (int j = 0; j < np; ++j) {
                                if(p->m[j] < M1[j]){
                                    Tree[k].m[j] = 'w';
                                    CR = 1;//
                                }
                            }
                        }
                        p = p->parent;
                    }//判断是否有无穷w

                    /* 插入新节点 */
                    Tree[k].parent = &Tree[nnew];//有向弧
                    Tree[k].t = i+1;
                    Tree[nnew].flag = 2;
                    k ++;//节点个数更新
                }
            }// 创建新节点，继续循环
        }//没有新节点时中止循环

        /* 输出结果 */
        if(CR == 0)
            printf("reachability tree! ");
        else
            printf("coverability tree! ");
        printf("of %d ", k);

        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < np; ++j) {
                if(j == 0) printf("M%d=[", i);
                if (Tree[i].m[j] != 'w') printf("%d",Tree[i].m[j]);
                else
                    printf("%c", Tree[i].m[j]);
                if(j != np-1) printf(",");
                else
                    printf("]");
            }

            if(Tree[i].t != 0) printf(" t%d", Tree[i].t);

            if(Tree[i].parent != head)
                for (int j = 0; j < np; ++j) {
                    if(j == 0) printf(" parent = [");
                    if (Tree[i].parent->m[j]!= 'w')
                        printf("%d",Tree[i].parent->m[j]);
                    else
                        printf("%c", Tree[i].parent->m[j]);
                    if(j != np-1)   printf(",");
                    else printf("]");
                }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
