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
    char beliUmpan;
    char lanjutMancing;
    char inputChar;
    string nama;
    
    
    // char spinner[] = {'/', '-', '\\', '|'}; // Pola animasi
    const char* spinner[] = {".    ", "..   ", "...  ", " o   ", " O   ", "  o  ", "   o ", "    ."};
    int spinnerSize = sizeof(spinner) / sizeof(spinner[0]);
    int Gold = 10;

    string ikanCommon [5] = {"Ikan Cupang", "Ikan Lele", "Ikan Bawal", "Ikan Bandeng", "Ikan Teri"};
    string ikanRare [4] = {"Ikan Salmon", "Ikan Kerapu", "Ikan Kakap", "Ikan Arwana"};
    string ikanSuperRare [3] = {"ikan Marlin", "Ikan Selayar", "Ikan Hiu"};
    string ikanLegendary [2] = {"Ikan Paus", "Ikan Megalodon"};

    int jumlahIkanCommon = 0;
    int jumlahIkanRare = 0;
    int jumlahIkanSuperRare = 0;
    int jumlahIkanLegendary = 0;

    int umpan = 5;

    clearScreen();
    system("cls");
    cout << "1. Start New Game" << endl;
    cout << "2. Continue Game" << endl;
    cout << "ketik '1'atau '2', lalu tekan enter\n" << endl;

    // cin >> pilihan;
    while (true)
    {
        cin >> pilihan;
        if (pilihan == '1' || pilihan == '1.')
        {
            cout << "oke bang, lanjut\n" << endl;
            system("pause");
            break;

        }else if (pilihan == '2' || pilihan == '2.')
        {
            cout << "\nmaaf bang fitur ini belum ada" << endl;
            system("pause");
            break;
        }
        else{
            cout << "\nmasukan angka pilihan '1' atau '2', lanjut tekan 'enter'" << endl;
            // system("pause");
            cin.ignore(); 
            cin.get();
        }
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

    cout << "Oke bang "<< nama << ", lanjut\n"  << endl;
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

        cout << "\nJumlah ikan common = " << jumlahIkanCommon << endl;
        cout << "Jumlah ikan Rare = " << jumlahIkanRare << endl;
        cout << "Jumlah ikan Super Rare = " << jumlahIkanSuperRare << endl;
        cout << "Jumlah ikan Legendary = " << jumlahIkanLegendary << endl;

        cout << "===============================" << endl;
        cout << "\n1. Mulai Mancing" << endl;
        cout << "2. Beli umpan" << endl;
        cout << "3. Save" << endl;
        cout << "4. Quit\n" << endl;

        cout << "Ketik '1' untuk mulai mancing.\nKetik '2' beli umpan.\nKetik '3' untuk save.\nKetik '4' untuk quit, lalu tekan enter\n" << endl;
        //cout << "<< ";

        cin >> pilihan;
        if (pilihan == '2' || pilihan == '2.')
        {
            cout << "TOKO UMPAN" << endl;
            cout << "================" << endl;
            cout << "Umpan 5 buah = 10 Gold" << endl;
            cout << "Umpan 10 buah = 18 Gold" << endl;
            cout << "Umpan 20 buah = 35 Gold" << endl;

            cin >> beliUmpan;
            if (beliUmpan == '5')
            {
                cout << "oke bang kamu beli 5 buah umpan" << endl;
                umpan += 5;
                system("pause");
                continue;
            }
            

        }else if (pilihan == '3' || pilihan == '3.'){
            cout << "\nmaaf bang fitur ini belum ada" << endl;
            system("pause");

        } else if(pilihan == '4' || pilihan == '4.'){
            cout << "\noke bang, bye bye" << endl;
            system("pause");
            return 0;
        }else if (pilihan == '1' || pilihan == '1.')
        {                        
            if (umpan == 0){
            cout << "\nUmpan kamu habis, silahkan beli umpan terlebih dahulu" << endl;
            system("pause");
            continue;
            }

            // system("pause");
            clearScreen();
            system("cls");
            do {           
                    clearScreen();
                    system("cls");     

                    if (umpan == 0){
                    cout << "Umpan kamu habis, silahkan beli umpan terlebih dahulu" << endl;
                    system("pause");
                    break;
                    }

                    cout << "Lempar umpan (tekan spasi)...\n";

                    // Tunggu sampai user menekan spasi
                    while (true) {
                        inputChar = _getch(); // Baca satu karakter tanpa Enter
                        if (inputChar == ' ') {
                            break; // Keluar loop jika spasi ditekan
                        }else {
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
                    int ukuran[] = {5, 4, 3, 2};                 
                    srand(time(0));

                    //acak jenis rarity
                    int acakJenisRarity = rand() % 4; 
                    //acak jenis ikan
                    int acakIkan = rand() % ukuran[acakJenisRarity]; 
                    string ikan = arrays[acakJenisRarity][acakIkan];

                    int peluangStrike = rand() % 100;

                    if (peluangStrike < 65) { // 65% Common
                        int acakIkan = rand() % ukuran[0];
                        string ikan = arrays[0][acakIkan];
                        jumlahIkanCommon++;
                        Gold += 4;
                        umpan--;
                        cout << "Anda mendapatkan ikan Common!\n" << ikan;
                        cout << ", Gold +4!\n\n";
                    } else if (peluangStrike < 75) { // 10% Rare
                        int acakIkan = rand() % ukuran[1];
                        string ikan = arrays[1][acakIkan];
                        jumlahIkanRare++;
                        Gold += 7;
                        umpan--;
                        cout << "Anda mendapatkan ikan Rare!\n" << ikan;
                        cout << ", Gold +7!\n\n";
                    } else if (peluangStrike < 79) { // 4% Super Rare
                        int acakIkan = rand() % ukuran[2];
                        string ikan = arrays[2][acakIkan];
                        jumlahIkanSuperRare++;
                        Gold += 20;
                        umpan--;
                        cout << "Anda mendapatkan ikan Super Rare!\n" << ikan;
                        cout << ", Gold +20!!\n\n";
                    } else if (peluangStrike < 80) { // 1% Legendary
                        int acakIkan = rand() % ukuran[3];
                        string ikan = arrays[3][acakIkan];
                        jumlahIkanLegendary++;
                        Gold += 100;
                        umpan--;
                        cout << "Anda mendapatkan ikan Legendary!\n" << ikan;
                        cout << ", Gold +100!!!\n\n";
                    } else { // 20% Umpan dibawa lari
                        umpan--;
                        cout << "Umpan Anda dibawa lari ikan!\n\n";
                    }

                    cout << "\nMau mancing lagi? (y/n): ";
                    cin >> lanjutMancing;

                } while (lanjutMancing == 'y' || lanjutMancing == 'Y');
        }
    }
        
    system("pause");
    return 0;
}
