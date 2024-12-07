#include <iostream>
#include <thread> 
#include <chrono> 
#include <conio.h> 
#include <cstdlib> 
#include <ctime>   
#include <cstdlib> 
#include <fstream>
#include <vector>
#include <sstream> 

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

    struct Ikan {
    string nama;
    string rarity;
    };
    vector<Ikan> daftarIkan;
    
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
    bool isDataLoaded = false; // Menandai apakah data berhasil dimuat atau tidak
    while (true)
    {
        cin >> pilihan;
        if (pilihan == '1' || pilihan == '1.')
        {
            cout << "oke bang, lanjut\n" << endl;
            system("pause");
            break;

        } else if (pilihan == '2' || pilihan == '2.'){
            ifstream file("account.txt", ios::in);
            if (!file.is_open()) {
                cout << "\nFile data tidak ditemukan. Mulai game baru terlebih dahulu.\n";
                system("pause");
                continue;
            }

            // Menampilkan daftar nama pemain yang disimpan
            vector<string> daftarNamaPemain;
            string line;
            while (getline(file, line)) {
                if (line.substr(0, 4) == "Nama") {
                    string namaPemain = line.substr(7);
                    daftarNamaPemain.push_back(namaPemain);
                }
            }

            // Menampilkan daftar nama pemain dan meminta pengguna untuk memilih pemain
            cout << "\nDaftar Pemain yang Tersimpan:\n";
            for (int i = 0; i < daftarNamaPemain.size(); ++i) {
                cout << i + 1 << ". " << daftarNamaPemain[i] << endl;
            }

            cout << "\nPilih nomor pemain yang ingin dilanjutkan: ";
            int pilihPemain;
            cin >> pilihPemain;

            // Mencari pemain yang dipilih dan memuat data
            file.clear();
            file.seekg(0, ios::beg);
            bool found = false;
            while (getline(file, line)) {
                size_t pos = line.find("=");
                if (pos != string::npos) {
                    string key = line.substr(0, pos - 1);
                    string value = line.substr(pos + 2);

                    if (key == "Nama" && value == daftarNamaPemain[pilihPemain - 1]) {
                        nama = value;
                        found = true;
                    }
                }

                if (found) {
                    if (line.substr(0, 4) == "Gold") {
                        Gold = stoi(line.substr(6));
                    } else if (line.substr(0, 12) == "Jumlah umpan") {
                        umpan = stoi(line.substr(15));
                    } else if (line.substr(0, 18) == "Jumlah ikan common") {
                        jumlahIkanCommon = stoi(line.substr(21));
                    } else if (line.substr(0, 17) == "Jumlah ikan rare") {
                        jumlahIkanRare = stoi(line.substr(20));
                    } else if (line.substr(0, 25) == "Jumlah ikan super rare") {
                        jumlahIkanSuperRare = stoi(line.substr(28));
                    } else if (line.substr(0, 23) == "Jumlah ikan legendary") {
                        jumlahIkanLegendary = stoi(line.substr(26));
                    } else if (line.substr(0, 13) == "Daftar ikan =") {
                        string ikanData = line.substr(14);
                        stringstream ss(ikanData);
                        string ikanItem;
                        while (getline(ss, ikanItem, ';')) {
                            size_t sep = ikanItem.find(",");
                            if (sep != string::npos) {
                                string namaIkan = ikanItem.substr(0, sep);
                                string rarityIkan = ikanItem.substr(sep + 1);
                                daftarIkan.push_back({namaIkan, rarityIkan});
                            }
                        }
                    }
                }
            }

            file.close();
            if (found) {
                cout << "\nData berhasil dimuat. Selamat datang kembali, " << nama << "!\n";
                isDataLoaded = true;
                system("pause");
            } else {
                cout << "Pemain tidak ditemukan.\n";
                system("pause");
            }
            break;
        }
        else {
            cout << "\nmasukan angka pilihan '1' atau '2', lanjut tekan 'enter'" << endl;
            cin.ignore(); 
            cin.get();
        }
    }

    // Jika data tidak dimuat, masuk ke mode "New Game"
    if (!isDataLoaded) {
        clearScreen();
        cout << "Namanya siapa bang??" << endl;
        cin >> nama;
    }


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

       if (daftarIkan.empty()) {
            cout << "Belum ada ikan yang ditangkap.\n";
        } else {
            cout << "Daftar ikan yang sudah ditangkap:\n";
            for (const auto& ikan : daftarIkan) {
                cout << "- " << ikan.nama << " (" << ikan.rarity << ")" << endl;
            }
        }
    

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
            
        }else if (pilihan == '3' || pilihan == '3.') {
            ifstream inFile("account.txt");
            if (!inFile.is_open()) {
                cout << "Error: Tidak dapat membuka file untuk membaca data." << endl;
                system("pause");
                continue;
            }

            // Memuat semua data pemain dari file ke dalam memori
            vector<string> fileData;
            string line;
            bool isUpdated = false;

            while (getline(inFile, line)) {
                if (line.substr(0, 4) == "Nama" && line.substr(7) == nama) {
                    // Pemain yang sama ditemukan, update data
                    fileData.push_back("Nama = " + nama);
                    fileData.push_back("Gold = " + to_string(Gold));
                    fileData.push_back("Jumlah umpan = " + to_string(umpan));
                    fileData.push_back("Jumlah ikan common = " + to_string(jumlahIkanCommon));
                    fileData.push_back("Jumlah ikan rare = " + to_string(jumlahIkanRare));
                    fileData.push_back("Jumlah ikan super rare = " + to_string(jumlahIkanSuperRare));
                    fileData.push_back("Jumlah ikan legendary = " + to_string(jumlahIkanLegendary));
                    
                    // Tambahkan daftar ikan
                    string daftarIkanStr = "Daftar ikan = ";
                    for (const auto& ikan : daftarIkan) {
                        daftarIkanStr += ikan.nama + "," + ikan.rarity + ";";
                    }
                    fileData.push_back(daftarIkanStr);

                    // Lewati data pemain lama yang ada di file
                    while (getline(inFile, line) && !line.empty()) {}
                    isUpdated = true;
                } else {
                    // Tambahkan baris lain tanpa perubahan
                    fileData.push_back(line);
                }
            }

            inFile.close();

            if (!isUpdated) {
                // Jika data pemain belum ada, tambahkan data baru
                fileData.push_back("Nama = " + nama);
                fileData.push_back("Gold = " + to_string(Gold));
                fileData.push_back("Jumlah umpan = " + to_string(umpan));
                fileData.push_back("Jumlah ikan common = " + to_string(jumlahIkanCommon));
                fileData.push_back("Jumlah ikan rare = " + to_string(jumlahIkanRare));
                fileData.push_back("Jumlah ikan super rare = " + to_string(jumlahIkanSuperRare));
                fileData.push_back("Jumlah ikan legendary = " + to_string(jumlahIkanLegendary));
                
                string daftarIkanStr = "Daftar ikan = ";
                for (const auto& ikan : daftarIkan) {
                    daftarIkanStr += ikan.nama + "," + ikan.rarity + ";";
                }
                fileData.push_back(daftarIkanStr);
            }

            // Tulis ulang seluruh file dengan data baru
            ofstream outFile("account.txt", ios::trunc); // Mode truncate untuk menimpa file
            if (!outFile.is_open()) {
                cout << "Error: Tidak dapat membuka file untuk menulis data." << endl;
                system("pause");
                continue;
            }

            for (const string& dataLine : fileData) {
                outFile << dataLine << endl;
            }

            outFile.close();

            cout << "Data pemain berhasil disimpan!" << endl;
            system("pause");

        }else if(pilihan == '4' || pilihan == '4.'){
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
                    this_thread::sleep_for(chrono::milliseconds(180));
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
                        string ikan = arrays[0][rand() % ukuran[0]];
                        daftarIkan.push_back({"Common", ikan});
                        jumlahIkanCommon++;
                        Gold += 4;
                        umpan--;                        
                        cout << "Anda mendapatkan ikan Common!\n" << ikan;
                        cout << ", Gold +4!\n\n";
                    } else if (peluangStrike < 75) { // 10% Rare
                        string ikan = arrays[1][rand() % ukuran[1]];
                        daftarIkan.push_back({"Rare", ikan});
                        jumlahIkanRare++;
                        Gold += 7;
                        umpan--;                        
                        cout << "Anda mendapatkan ikan Rare!\n" << ikan;
                        cout << ", Gold +7!\n\n";
                    } else if (peluangStrike < 79) { // 4% Super Rare
                        string ikan = arrays[2][rand() % ukuran[2]];
                        daftarIkan.push_back({"SuperRare", ikan});
                        jumlahIkanSuperRare++;
                        Gold += 20;
                        umpan--;                        
                        cout << "Anda mendapatkan ikan Super Rare!\n" << ikan;
                        cout << ", Gold +20!!\n\n";
                    } else if (peluangStrike < 80) { // 1% Legendary
                        string ikan = arrays[3][rand() % ukuran[3]];
                        daftarIkan.push_back({"Legendary", ikan});
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
