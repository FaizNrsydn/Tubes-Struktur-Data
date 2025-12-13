#include <iostream>
#include "leaderboard.h"
using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int choice;
    do {
        cout << "\n===== MENU LEADERBOARD BST =====\n";
        cout << "1. Tambah Pemain\n";
        cout << "2. Tampilkan Leaderboard (Score Tertinggi -> Terendah)\n";
        cout << "3. Cari Pemain berdasarkan ID\n";
        cout << "4. Cari Pemain berdasarkan Username\n";
        cout << "5. Hapus Pemain berdasarkan ID\n";
        cout << "6. Tampilkan Total Score Semua Pemain\n";
        cout << "7. Tampilkan Jumlah Pemain\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;

        switch(choice) {
            case 1: {
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
                cout << "Masukkan ID pemain: ";
                cin >> id;
                // searchById(tree, stoi(id));
                break;
            }

            case 4: {
                string uname;
                cout << "Masukkan Username pemain: ";
                cin >> uname;
                // searchByUsername(tree, uname);
                break;
            }

            case 5: {
                string id;
                cout << "Masukkan ID pemain yang ingin dihapus: ";
                cin >> id;
                // if (deleteById(tree, stoi(id)))
                //     cout << ">> Pemain berhasil dihapus.\n";
                // else
                //     cout << ">> Pemain tidak ditemukan.\n";
                // break;
            }

            case 6:
                cout << "Total Score semua pemain: "; 
                    // << countTotalScore(tree) << endl;
                break;

            case 7:
                cout << "Jumlah pemain: "; 
                    // << countPlayers(tree) << endl;
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
