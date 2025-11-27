#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#define Nill NULL

using namespace std;

const int MAX = 10;

typedef struct BST *node;
struct BST{
    int id;
    char nama[MAX];
    char username[MAX];
    int score;
    int level;
    int rank;

    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int id);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);
void preOrder(BinTree tree);
void levelOrder(BinTree tree);

void searchByid(BinTree);
void searchByusername();
void searchByrank();
#endif