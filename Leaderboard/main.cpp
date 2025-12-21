#include "leaderboard.h"
#include <iostream>
using namespace std;

int main() {
    BinTree tree;
    createTree(tree);
    //Dummy
    // leaderboard p1, p2, p3, p4, p5;
    // p1 = {3000, "user001", "GamerPro99", tentukanLevel(3000), tentukanRank(3000)};
    // p2 = {2450, "user005", "SkillMaster", tentukanLevel(2450), tentukanRank(2450)};
    // p3 = {1280, "user012", "NoobSlayerX", tentukanLevel(1280), tentukanRank(1280)};
    // p4 = {3500, "user030", "CasualPlay", tentukanLevel(3500), tentukanRank(3500)};
    // p5 = {500, "user150", "Newbie_G", tentukanLevel(500), tentukanRank(500)};
    
    // insertNode(tree, alokasi(p1));
    // insertNode(tree, alokasi(p2));
    // insertNode(tree, alokasi(p3));
    // insertNode(tree, alokasi(p4));
    // insertNode(tree, alokasi(p5));

    int choice;
    do {
        cout << "==========================================================================\n";
        cout << "  |                        MENU LEADERBOARD BST                        |\n";
        cout << "==========================================================================\n";
        cout << "  | 1. Tambah Pemain                                                   |\n";
        cout << "  | 2. Tampilkan Leaderboard (Score Tertinggi -> Terendah)             |\n";
        cout << "  | 3. Cari Pemain berdasarkan ID                                      |\n";
        cout << "  | 4. Cari Pemain berdasarkan Username                                |\n";
        cout << "  | 5. Cari Pemain berdasarkan Score                                   |\n";
        cout << "  | 6. Hapus Pemain berdasarkan ID                                     |\n";
        cout << "  | 7. Hapus Pemain berdasarkan Username                               |\n";
        cout << "  | 8. Update Score                                                    |\n";
        cout << "  | 9. Tampilkan Jumlah Pemain                                         |\n";
        cout << "  | 0. Keluar                                                          |\n";
        cout << "==========================================================================\n";
        cout << "Pilih menu: ";
        cin >> choice;
        cout << "==========================================================================\n";
        cout << endl;

        switch(choice) {
            case 1:{
                leaderboard p = inputPlayer();
                insertNode(tree, alokasi(p));
                cout << "   >> Pemain berhasil ditambahkan!\n";
                cout << "==========================================================================" << endl;
                cout << endl;
                break;
            }
            case 2:
                // cout << "\n=== Leaderboard ===\n";
                printHeader();
                printLeaderboard(tree);
                cout << "==========================================================================" << endl;
                cout << endl;
                break;
            case 3: {
                string id;
                cout << "==========================================================================" << endl;
                cout << "Masukkan ID pemain yang dicari: ";
                cin >> id;
                printHeader();
                searchById(tree,id);
                cout << "==========================================================================" << endl;
                cout << endl;
                break;
            }
            case 4: {
                string uname;
                cout << "==========================================================================" << endl;
                cout << "Masukkan Username pemain yang dicari: ";
                cin >> uname;
                printHeader();
                searchByUsername(tree, uname);
                cout << "==========================================================================" << endl;
                cout << endl;
                break;
            }
            case 5:{
                int minScore, maxScore;
                cout << "==========================================================================" << endl;
                cout << "Masukkan Range score minimumnya: ";
                cin >> minScore;
                cout << "Masukkan Range score maximumnya: ";
                cin >> maxScore;
                // searchByScore(tree, score);
                printHeader();
                searchByRange(tree, minScore, maxScore);
                cout << "==========================================================================" << endl;
                cout << endl;
                break;
            }
            case 6:{
                string idDelete;
                cout << "==========================================================================" << endl;
                cout << "Masukkan ID pemain yang ingin dihapus: ";
                cin >> idDelete;
                if (deleteById(tree, idDelete)) {
                    cout << ">> Pemain dengan ID " << idDelete << " berhasil dihapus.\n";
                }else{
                    cout << ">> Pemain dengan ID " << idDelete << " tidak ditemukan.\n";
                }
                cout << "==========================================================================" << endl;
                cout << endl;
                break;
            }
            case 7:{
                string UDelete;
                cout << "==========================================================================" << endl;
                cout << "Masukkan Username pemain yang ingin dihapus: ";
                cin >> UDelete;
                if (deleteByUsername(tree, UDelete)){
                    cout << ">> Pemain dengan username "<< UDelete << " berhasil dihapus.\n";
                }else{
                    cout << ">> Pemain dengan username "<< UDelete << " tidak ditemukan.\n";
                }
                cout << "==========================================================================" << endl;
                cout << endl;
                break;
            }
            case 8:{
                string usname;
                int skorbaru;
                cout << "==========================================================================" << endl;
                cout << "Masukkan Username yang ingin di Update scorenya: ";
                cin >> usname;
                cout << "Masukkan score baru                            : ";
                cin >> skorbaru;
                if(updateScoreByUsername(tree, usname, skorbaru)){
                    cout << "Score berhasil di Update" << endl;
                }else{
                    cout << "Score gagal di Update" << endl;
                }
                cout << "==========================================================================" << endl;
                cout << endl;
                break;
            }
            case 9:
                cout << "==========================================================================" << endl;
                cout << "Jumlah pemain: " << countPlayers(tree) << endl;
                cout << "==========================================================================" << endl;
                cout << endl;
                break;
            case 0:
                cout << "Keluar...\n";
                break;
                default:
                cout << "Pilihan tidak valid!\n";
            }
            
        } while (choice != 0);
    // Tambahkan baris di bawah ini:
    cin.ignore(); // Membersihkan sisa newline di buffer
    cout << "Tekan ENTER untuk keluar...";
    cin.get();
    return 0;
}
