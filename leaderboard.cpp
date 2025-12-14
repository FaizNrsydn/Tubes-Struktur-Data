#include "leaderboard.h"
#include <iostream>
using namespace std;

bool isEmpty(BinTree tree){
    return tree == Nil;
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(leaderboard info){
    node nodeBaru = new BST;
    nodeBaru->info.score = info.score;
    nodeBaru->info.id = info.id;
    nodeBaru->info.username = info.username;
    nodeBaru->info.level = info.level;
    nodeBaru->info.rank = info.rank;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->info.score << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->info.score < tree->info.score){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->info.score > tree->info.score){
        insertNode(tree->right, nodeBaru);
    }else{
        insertNode(tree->right, nodeBaru);
    }
}

void preOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    cout << tree->info.score << endl;
    cout << tree->info.id << endl;
    cout << tree->info.username << endl;
    cout << tree->info.level << endl;
    cout << tree->info.rank << endl;
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->info.score << endl;
    cout << tree->info.id << endl;
    cout << tree->info.username << endl;
    cout << tree->info.level << endl;
    cout << tree->info.rank << endl;
    inOrder(tree->right);
}

void postOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->info.score << endl;
    cout << tree->info.id << endl;
    cout << tree->info.username << endl;
    cout << tree->info.level << endl;
    cout << tree->info.rank << endl;
}

void levelOrder(BinTree tree){
}

void printLeaderboard(BinTree tree){
    if(tree == Nil){
        return;
    }
    printLeaderboard(tree->right);
    cout << tree->info.score << endl;
    cout << tree->info.id << endl;
    cout << tree->info.username << endl;
    cout << tree->info.level << endl;
    cout << tree->info.rank << endl;
    printLeaderboard(tree->left);
}

// void printTopN(BinTree tree, int n){

// }

int tentukanLevel(int score){
    return (score/500) + 1;
}

string tentukanRank(int score){
    if (score >= 3000){
        return "platinum";
    }else if (score >= 2000){
        return "Gold";
    }else if (score >= 1000){
        return "Silver";
    }else{
        return "Bronze";
    }
}

leaderboard inputPlayer() {
    leaderboard p;
    cout << "\n=== Input Data Pemain ===\n";
    cout << "ID            : ";
    cin >> p.id;
    cout << "Username      : ";
    cin >> p.username;
    cout << "Score         : ";
    cin >> p.score;
    p.level = tentukanLevel(p.score);
    p.rank = tentukanRank(p.score);
    return p;
}