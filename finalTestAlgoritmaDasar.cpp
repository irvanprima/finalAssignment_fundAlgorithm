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
    
    
    // char spinner[] = {'/', '-', '\\', '|'}; // Pola animasi
    const char* spinner[] = {".    ", "..   ", "...  ", " o   ", " O   ", "  o  ", "   o ", "    ."};
    int spinnerSize = sizeof(spinner) / sizeof(spinner[0]);
    int Gold = 0;

    string ikanCommon [5] = {"Ikan Cupang", "Ikan Lele", "Ikan Bawal", "Ikan Bandeng", "Ikan Teri"};
    string ikanRare [4] = {"Ikan Salmon", "Ikan Kerapu", "Ikan Kakap", "Ikan Arwana"};
    string ikanSuperRare [3] = {"ikan Marlin", "Ikan Selayar", "Ikan Hiu"};
    string ikanLegendary [2] = {"Ikan Paus", "Ikan Megalodon"};

    int jumlahIkanCommon = 0;
    int jumlahIkanRare = 0;
    int jumlahIkanSuperRare = 0;
    int jumlahIkanLegendary = 0;

    int umpan = 7;

    clearScreen();
    system("cls");
    cout << "1. Start New Game" << endl;
    cout << "2. Continue Game" << endl;
    cout << "ketik '1'atau '2', lalu tekan enter" << endl;

    cin >> pilihan;
    if (pilihan == '1' || pilihan == '1.')
    {
        cout << "oke bang, lanjut\n" << endl;

    }else{
        cout << "\nmaaf bang fitur ini belum ada" << endl;
        system("pause");
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

    clearScreen(); 
    system("cls");

    cout << "Oke bang "<< nama << ", lanjut"  << endl;
    system("pause");
    while (true)
    {
        system("cls");
        clearScreen();
        cout << "MAIN MENU"<< endl;
        cout << "===============================" << endl;

        cout << "1. Nama kamu = " << nama << endl;
        cout << "2. Gold = " << Gold << endl;
        cout << "3. jumlah umpan kamu = " << umpan << endl;

        cout << "\n4. Jumlah ikan common = " << jumlahIkanCommon << endl;
        cout << "5. Jumlah ikan Rare = " << jumlahIkanRare << endl;
        cout << "6. Jumlah ikan Super Rare = " << jumlahIkanSuperRare << endl;
        cout << "7. Jumlah ikan Legendary = " << jumlahIkanLegendary << endl;

        cout << "\n8. Save" << endl;
        cout << "9. quit\n" << endl;

        cout << "ketik '8' untuk save. Ketik '9' untuk quit, lalu tekan enter" << endl;

        cin >> pilihan;
        if (pilihan == '8' || pilihan == '8.'){
            cout << "\nmaaf bang fitur ini belum ada" << endl;

        } else if(pilihan == '9' || pilihan == '9.'){
            cout << "\noke bang, bye bye" << endl;
            system("pause");
            return 0;
        }

        system("pause");
        clearScreen();
        system("cls");
        do {           
                clearScreen();
                system("cls");     
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
                
                for (int i = 0; i < 25; i++) { // 25 iterasi = 5 detik (200ms x 25)
                cout << "\r" << spinner[i % spinnerSize] << std::flush;
                this_thread::sleep_for(chrono::milliseconds(300));
                }

                cout << "\n\numpan anda di gigit !!! (tekan enter)...\n";

                // Tunggu sampai user menekan Enter
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cin.get();
    
                string* arrays[] = {ikanCommon, ikanRare, ikanSuperRare, ikanLegendary};
                int ukuran[] = {5, 4, 3, 2}; // Ukuran masing-masing array                
                srand(time(0));

                //acak jenis rarity
                int acakJenisRarity = rand() % 4; 
                //acak jenis ikan
                int acakIkan = rand() % ukuran[acakJenisRarity]; 
                string ikan = arrays[acakJenisRarity][acakIkan];

                if (acakJenisRarity == 0) {
                    jumlahIkanCommon++;
                    Gold += 4;
                    umpan--;
                    cout << "Anda mendapatkan ikan Common!\n" << ikan;
                    cout << ", Gold +4!\n\n";
                    cout << "sisa umpan kamu = " << umpan << endl;
                } else if (acakJenisRarity == 1) {
                    jumlahIkanRare++;
                    Gold += 7;
                    umpan--;
                    cout << "Anda mendapatkan ikan Rare!\n" << ikan;
                    cout << ", Gold +7!\n\n";
                    cout << "sisa umpan kamu = " << umpan << endl;
                } else if (acakJenisRarity == 2) {
                    jumlahIkanSuperRare++;
                    Gold += 7;
                    umpan--;
                    cout << "Anda mendapatkan ikan Super Rare!\n" << ikan;
                    cout << ", Gold +20!!\n\n";
                    cout << "sisa umpan kamu = " << umpan << endl;
                }else if (acakJenisRarity == 3) {
                    jumlahIkanLegendary++;
                    Gold += 100;
                    umpan--;
                    cout << "Anda mendapatkan ikan Legendary!\n" << ikan;
                    cout << ", Gold +100!!!\n\n";
                    cout << "sisa umpan kamu = " << umpan << endl;
                }else{
                    cout << "umpan anda dibawa lari ikan" << endl;
                }

                cout << "\nMau mancing lagi? (y/n): ";
                cin >> lanjutMancing;

            } while (lanjutMancing == 'y' || lanjutMancing == 'Y');
    }
    
    system("pause");
    return 0;
}
