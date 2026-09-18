#include <iostream>
using namespace std;

int main() {
    char pesan[1000];
    
    cout << "Masukkan pesan: ";
    cin.getline(pesan, 1000);
    
    int length = 0;
    while (pesan[length] != '\0') {
        length++;
    }
    
    char pesan_hasil[1000];
    
    pesan_hasil[0] = pesan[0];
    
    for (int i = 1; i < length; i++) {
        char saat_ini = pesan[i];
        char sebelumnya = pesan[i - 1];
        
        bool is_saat_ini_alpha = (saat_ini >= 'A' && saat_ini <= 'Z') || (saat_ini >= 'a' && saat_ini <= 'z');
        bool is_sebelumnya_alpha = (sebelumnya >= 'A' && sebelumnya <= 'Z') || (sebelumnya >= 'a' && sebelumnya <= 'z');
        
        if (is_saat_ini_alpha && is_sebelumnya_alpha) {
            int shift = 0;
            if (sebelumnya >= 'A' && sebelumnya <= 'Z') {
                shift = sebelumnya - 'A' + 1;
            } else if (sebelumnya >= 'a' && sebelumnya <= 'z') {
                shift = sebelumnya - 'a' + 1;
            }
            
            if (saat_ini >= 'A' && saat_ini <= 'Z') {
                pesan_hasil[i] = 'A' + (saat_ini - 'A' + shift) % 26;
            } 

            else if (saat_ini >= 'a' && saat_ini <= 'z') {
                pesan_hasil[i] = 'a' + (saat_ini - 'a' + shift) % 26;
            }
        } else {
            pesan_hasil[i] = saat_ini;
        }
    }
    

    pesan_hasil[length] = '\0';
    cout << "Pesan Hasil: " << pesan_hasil << endl;
    
    return 0;
}