#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#define Nill NULL

#include <iostream>
using namespace std;


struct leaderboard{
    int score;
    string id;
    string username;
    int level;
    string rank;
};

typedef struct BST *node;
struct BST{
    leaderboard info;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(leaderboard info);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, leaderboard info);
void inOrder(BinTree tree);
void postOrder(BinTree tree);
void preOrder(BinTree tree);
void levelOrder(BinTree tree);
void printLeaderboard(BinTree tree);
void printTopN(BinTree tree, int n);

void searchById(BinTree tree, int id);
void searchByUsername(BinTree tree, string username);
void searchByScore(BinTree tree, int score);

bool deleteById(BinTree &tree, int id);
bool deleteByUsername(BinTree &tree, string username);

void updateRank(BinTree tree);                
int countTotalScore(BinTree tree);                
int countPlayers(BinTree tree);  

#endif