#include <iostream>
#include <thread> 
#include <chrono> 
#include <conio.h> 
#include <cstdlib> 
#include <ctime>   

#include <cstdlib> 

using namespace std;
void clearScreen() {
    cout << "\033[2J\033[H"; // bersihkan kode sebelumnya jika dibuka di VS code
}

 
int main(int argc, char const *argv[])
{
    char pilihan;
    char lanjutMancing;
    char inputChar;
    string nama;
    string paketPemancingan;
    

    string tempatPemancingan;
    int level = 0;
    int Gold = 0;
    int ikanCommon = 0;
    int ikanRare = 0;
    int ikanSuperRare = 0;
    int ikanLegendary = 0;
    int umpan = 7;

    string mantab; //mulai mancing

    clearScreen();
    cout << "1. Start New Game" << endl;
    cout << "2. Continue Game" << endl;
    cout << "ketik '1'atau '2', lalu tekan enter" << endl;

    // cout << "Halo bang, apakah mau mancing hari ini??" << endl;
    // cout << "jika iya tekan 'y', jika tidak tekan 'n'" << endl;

    cin >> pilihan;
    if (pilihan == '1' || pilihan == '1.')
    {
        cout << "oke bang, lanjut\n" << endl;

    }else{
        cout << "\nmaaf bang fitur ini belum ada" << endl;
        system("pause");
        // cout << "\noke bang, bye bye" << endl;
        // system("pause");
        // return 0;
    }

    //jika masuk ke new game
    clearScreen();
    cout << "Namanya siapa bang??" << endl;
    cin >> nama;

    // #ifdef _WIN32
    //     system("cls"); // Windows
    // #else
    //     system("clear"); // Linux/MacOS
    // #endif

    system("cls");
    clearScreen(); 

    cout << "Oke bang "<< nama << ", lanjut"  << endl;
    system("pause");
    while (true)
    {
        system("cls");
        clearScreen();
        cout << "MAIN MENU"<< endl;
        cout << "===============================" << endl;

        cout << "Nama kamu = " << nama << endl;
        cout << "Gold = " << Gold << endl;
        cout << "jumlah umpan kamu = " << umpan << endl;

        cout << "\nJumlah ikan common " << ikanCommon << endl;
        cout << "Jumlah ikan Rare " << ikanRare << endl;
        cout << "Jumlah ikan Super Rare " << ikanSuperRare << endl;
        cout << "Jumlah ikan Legendary " << ikanLegendary << endl;

        cout << "\nSave" << endl;
        cout << "quit" << endl;

        system("pause");
        system("cls");
        clearScreen();
        do {
                cout << "Lempar umpan (tekan spasi)...\n";

                // Tunggu sampai user menekan spasi
                while (true) {
                    inputChar = _getch(); // Baca satu karakter tanpa Enter
                    if (inputChar == ' ') {
                        break; // Keluar loop jika spasi ditekan
                    } else {
                        cout << "Harap tekan spasi untuk melanjutkan!\n";
                    }
                }

                // Tunggu 6 detik sebelum umpan digigit
                this_thread::sleep_for(chrono::seconds(6));
                cout << "umpan anda di gigit (tekan enter)...\n";

                // Tunggu sampai user menekan Enter
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan buffer
                cin.get();

                srand(time(0));
                int randomNumber = rand() % 100 + 1;
                if (randomNumber <= 80) {
                    cout << "Anda mendapatkan ikan Common!\n";
                    cout << "Gold +4!\n";
                    ikanCommon++;
                    Gold =+ 4;
                } else if (randomNumber <= 99) {
                    cout << "Anda mendapatkan ikan Rare!\n";
                    ikanRare++;
                    Gold =+ 7;
                } else {
                    // cout << "Anda mendapatkan ikan Legendary!\n";
                    // ikanLegendary++;
                }

                cout << "\nMau mancing lagi? (y/n): ";
                cin >> lanjutMancing;

            } while (lanjutMancing == 'y' || lanjutMancing == 'Y');
    }

        


        

    // cout << "Pilih paket pemancingan yang mana bang??" << endl;
    
    // if (level >= 0 && level <=2)
    // {
    //     cout << "A. paket pemula\n"<< endl;
    //     cout << "ketik 'A' untuk memilih. Paket lain akan terbuka sejalan dengan level mu bang"<< endl;
    // }else if (level = 3 && level <=10 ){
    //     cout << "A. paket pemula"<< endl;
    //     cout << "B. paket pro\n"<< endl;        
    //     cout << "ketik 'A', 'B' untuk memilih. Paket lain akan terbuka sejalan dengan level mu bang"<< endl;
    // }else if (level >= 11){
    //     cout << "A. paket pemula"<< endl;
    //     cout << "B. paket pro"<< endl;
    //     cout << "C. paket sultan\n"<< endl;    
    //     cout << "ketik 'A', 'B', dan 'C' untuk memilih. Semua paket sudah terbuka bang"<< endl;
    // }
    // cin >> paketPemancingan;
    // cout <<"=========================\n"<< endl;
     
    // //cout << "\nOke bang "<< nama << endl;
    // cout << "oke bang " << nama << " pilih paket " << paketPemancingan << " nih" << endl;
    // cout << "Pilih tempat pemancingan sekarang bang" << endl;
    
    // if (level >= 0 && level <=2)
    // {
    //     cout << "1. empang\n"<< endl;
    //     cout << "ketik '1' untuk memilih. tempat pemancingan lain akan terbuka sejalan dengan level mu bang"<< endl;
    // }else if (level == 3 && level <=10 ){
    //     cout << "1. empang"<< endl;
    //     cout << "2. waduk\n"<< endl;        
    //     cout << "3. kali opak\n"<< endl;        
    //     cout << "ketik '1', '2', '3' untuk memilih. tempat pemancingan lain akan terbuka sejalan dengan level mu bang"<< endl;
    // }else if (level >= 11){
    //     cout << "1. empang"<< endl;
    //     cout << "2. waduk\n"<< endl;        
    //     cout << "3. kali opak\n"<< endl;  
    //     cout << "3. Pantai peyuyon\n"<< endl;  
    //     cout << "3. Samudra pasifik\n"<< endl;  
    //     cout << "ketik '1', '2', dan '3' untuk memilih. Semua tempat pemancingan sudah terbuka bang"<< endl;
    // }

    // cin >> tempatPemancingan;
    // cout << "oke bang " << nama << " pilih tempatnya di " << paketPemancingan << endl;
    

    // cout << "\n\n===============================" << endl;
    // cout << "MAIN MENU\n"<< endl;

    // cout << "Nama kamu " << nama << endl;
    // cout << "level " << level << endl;
    // cout << "Paket pemancingan yang kamu pilih : " << paketPemancingan << endl;
    // cout << "Tempat pemancingan yang kamu pilih : " << tempatPemancingan << endl;

    // cout << "Jumlah ikan common " << ikanCommon << endl;
    // cout << "Jumlah ikan Rare " << ikanRare << endl;
    // cout << "Jumlah ikan Super Rare " << ikanSuperRare << endl;
    // cout << "Jumlah ikan Legendary " << ikanLegendary << endl;

    // cout << "\n\nketik 'mantab' untuk mulai mancing "<< endl;
    // cin >> mantab;
   
    // if (mantab == "mantab") {
    //     do {
    //         cout << "Lempar umpan (tekan spasi)...\n";

    //         // Tunggu sampai user menekan spasi
    //         while (true) {
    //             inputChar = _getch(); // Baca satu karakter tanpa Enter
    //             if (inputChar == ' ') {
    //                 break; // Keluar loop jika spasi ditekan
    //             } else {
    //                 cout << "Harap tekan spasi untuk melanjutkan!\n";
    //             }
    //         }

    //         // Tunggu 6 detik sebelum umpan digigit
    //         this_thread::sleep_for(chrono::seconds(6));
    //         cout << "umpan anda di gigit (tekan enter)...\n";

    //         // Tunggu sampai user menekan Enter
    //         cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan buffer
    //         cin.get();

    //         srand(time(0));
    //         int randomNumber = rand() % 100 + 1;
    //         if (randomNumber <= 80) {
    //             cout << "Anda mendapatkan ikan Common!\n";
    //             ikanCommon++;
    //         } else if (randomNumber <= 99) {
    //             cout << "Anda mendapatkan ikan Rare!\n";
    //             ikanRare++;
    //         } else {
    //             cout << "Anda mendapatkan ikan Legendary!\n";
    //             ikanLegendary++;
    //         }

    //         cout << "\nMau mancing lagi? (y/n): ";
    //         cin >> lanjutMancing;

    //     } while (lanjutMancing == 'y' || lanjutMancing == 'Y');

    //     cout << "\nStatus Akhir\n";
    //     cout << "Nama: " << nama << "\n";
    //     cout << "Level: " << level << "\n";
    //     cout << "Ikan Common: " << ikanCommon << "\n";
    //     cout << "Ikan Rare: " << ikanRare << "\n";
    //     cout << "Ikan Legendary: " << ikanLegendary << "\n";
    // } else {
    //     cout << "Input salah, program berhenti.\n";
    // }
    

    
    system("pause");
    return 0;
}
