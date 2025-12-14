#include <iostream>
#include "leaderboard.h"
using namespace std;

int main() {
    BinTree tree;
    createTree(tree);
    //Dummy
    leaderboard p1, p2, p3, p4, p5;
    p1 = {3000, "user001", "GamerPro99", tentukanLevel(3000), tentukanRank(3000)};
    p2 = {2450, "user005", "SkillMaster", tentukanLevel(2450), tentukanRank(2450)};
    p3 = {1280, "user012", "NoobSlayerX", tentukanLevel(1280), tentukanRank(1280)};
    p4 = {3500, "user030", "CasualPlay", tentukanLevel(3500), tentukanRank(3500)};
    p5 = {500, "user150", "Newbie_G", tentukanLevel(500), tentukanRank(500)};
    
    insertNode(tree, alokasi(p1));
    insertNode(tree, alokasi(p2));
    insertNode(tree, alokasi(p3));
    insertNode(tree, alokasi(p4));
    insertNode(tree, alokasi(p5));

    int choice;
    do {
        cout << "\n===== MENU LEADERBOARD BST =====\n";
        cout << "1. Tambah Pemain\n";
        cout << "2. Tampilkan Leaderboard (Score Tertinggi -> Terendah)\n";
        cout << "3. Cari Pemain berdasarkan ID\n";
        cout << "4. Cari Pemain berdasarkan Username\n";
        cout << "5. Cari Pemain berdasarkan Score\n";
        cout << "6. Hapus Pemain berdasarkan ID\n";
        cout << "7. Hapus Pemain berdasarkan Username\n";
        cout << "8. Update Score\n";
        cout << "9. Tampilkan Jumlah Pemain\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;

        switch(choice) {
            case 1:{
                leaderboard p = inputPlayer();
                insertNode(tree, alokasi(p));
                cout << ">> Pemain berhasil ditambahkan!\n";
                break;
            }
            case 2:
                cout << "\n=== Leaderboard ===\n";
                printLeaderboard(tree);
                break;
            case 3: {
                string id;
                cout << "Masukkan ID pemain yang dicari: ";
                cin >> id;
                searchById(tree,id);
                break;
            }
            case 4: {
                string uname;
                cout << "Masukkan Username pemain yang dicari: ";
                cin >> uname;
                searchByUsername(tree, uname);
                break;
            }
            case 5:{
                int score;
                cout << "Masukkan Score pemain yang dicari: ";
                cin >> score;
                searchByScore(tree, score);
                break;
            }
            case 6:{
                string idDelete;
                cout << "Masukkan ID pemain yang ingin dihapus: ";
                cin >> idDelete;
                if (deleteById(tree, idDelete))
                    cout << ">> Pemain dengan ID " << idDelete << " berhasil dihapus.\n";
                    else
                    cout << ">> Pemain dengan ID " << idDelete << " tidak ditemukan.\n";
                break;
            }
            case 7:{
                string UDelete;
                cout << "Masukkan ID pemain yang ingin dihapus: ";
                cin >> UDelete;
                if (deleteByUsername(tree, UDelete))
                    cout << ">> Pemain dengan username "<< UDelete << " berhasil dihapus.\n";
                    else
                    cout << ">> Pemain dengan username "<< UDelete << " tidak ditemukan.\n";
                break;
            }
            case 8:{
                string usname;
                int skorbaru;
                cout << "Masukkan Username yang ingin di Update scorenya: ";
                cin >> usname;
                cout <<  "Masukkan score baru: ";
                cin >> skorbaru;
                if(updateScoreByUsername(tree, usname, skorbaru)){
                    cout << "Score berhasil di Update" << endl;
                }else{
                    cout << "Score gagal di Update" << endl;
                }
                break;
            }
            case 9:
                cout << "Jumlah pemain: " << countPlayers(tree);
                break;
            case 0:
                cout << "Keluar...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
        
    } while (choice != 0);

    return 0;
}
