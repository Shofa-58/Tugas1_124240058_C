#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>

using namespace std;

int pilihmenu, cari_kode, i = 0;
char menu_kembali = 'y' || 'Y';
string cari_nama;

bool found;

struct Toko
{
    string nama;
    int kode;
    int harga;
};
Toko Toko_Roti[] = {
    {"Roti Coklat", 110, 10000},
    {"Bolu Kukus", 155, 8000},
    {"Roti Buaya", 152, 40000},
    {"Bolu Karamel", 125, 15000},
    {"Brownies Vanila", 130, 12000},
    {"Kue Ultah", 150, 14000}};

int jumlah_data = sizeof(Toko_Roti) / sizeof(*Toko_Roti);

int quick_sort(int array[], int awal, int akhir)
{
    int low = awal, high = akhir;
    int pivot = array[(awal + akhir) / 2];
    int temp;
    do {
        while(array[low] < pivot)
            low++;
        while(array[high] > pivot)
            high--;
        if (low <= high) {
            swap(array[low], array[high]);
            low++;
            high--;
        }
    } while (low <= high);
    if(awal < high)
        quick_sort(array, awal, high);
    if(low < akhir)
        quick_sort(array, low, akhir);
        return 0;
}

void Tampil_data()
{

    cout << "=== TAMPIL DATA ===" << endl;
    cout << right << setfill('-') << setw(80) << " " << endl;
    cout << left << setfill(' ') << setw(6) << "  No" << "|" 
         << setfill(' ') << setw(21) << "        Nama" << "|"
         << setfill(' ') << setw(7) << "  Kode" << "|"
         << setfill(' ') << setw(10) << "   Harga" << "|" << endl;
         
    cout << right << setfill('-') << setw(80) << " " << endl;
    Toko *ptr = Toko_Roti;
    for (int i = 0; i <= jumlah_data - 1; i++) {
        cout << left << "  " << setfill(' ') << setw(4) << i + 1 << "| "
             << setfill(' ') << setw(20) << (*(ptr + i)).nama << "| "
             << setfill(' ') << setw(6) << (*(ptr + i)).kode << "| "
             << setfill(' ') << setw(9) << (*(ptr + i)).harga << "| " << endl;
    }

}

void Sequential_search()
{
    Toko *ptr = Toko_Roti;
    cout << "=== MENCARI DATA ROTI ===" << endl;
    cout << "Masukkan data roti yang ingin dicari (berdasarkan kode) : ";
    cin >> cari_kode;
    found = false;
    int i = 0;
    while ((i < jumlah_data) && (!found))
    {
        if (Toko_Roti[i].kode == cari_kode)
            found = true;
        else
            i = i + 1;
    }
    if (found)
    {
        cout << cari_kode << " ditemukan pada index array ke-" << i << endl;
        cout << "\nData Roti :" << endl;
        cout << "1. Nama roti  : "<< (*(ptr + i)).nama << endl;
        cout << "2. Kode roti  : "<< (*(ptr + i)).kode<<endl;
        cout << "3. Harga roti : "<< (*(ptr + i)).harga<<endl;
    }
    else
    {
        cout << cari_kode << " tidak ada dalam data array tersebut";
    }
    return;
}

void Sorting_bubble_sort_nama()//untuk mengurutkan data berdasarkan nama, agar pencarian berdasarkan nama dapat berjalan
{
    for (int i = 0; i < jumlah_data - 1; i++){//Bubble Sort
        for (int j = 0; j < jumlah_data - 1 - i; j++){
            if(Toko_Roti[j].nama > Toko_Roti[j+1].nama){
                swap(Toko_Roti[j],Toko_Roti[j+1]);
            };
    }
}
}

void Binary_search()
{
    Toko *ptr = Toko_Roti;
    cout << "=== MENCARI DATA DATA ===" << endl;
    cout << "Masukkan data yang ingin dicari (berdasarkan nama) : ";
    cin.ignore();
    getline(cin, cari_nama);
    found = false;
    int i = 0, j = jumlah_data, k;

    while ((!found) && (i <= j))
    {
        k = (i + j) / 2;
        if (cari_nama == Toko_Roti[k].nama)
            found = true;
        else if (cari_nama < Toko_Roti[k].nama)
            j = k - 1; // i tetap
        else
            i = k + 1; // j tetap
    }
    if (found)
    {
        cout << cari_nama << " ditemukan pada index array ke-" << k << endl;
        cout << "\nData Roti :" << endl;
        cout << "1. Nama roti  :" <<(*(ptr + k)).nama<< endl;
        cout << "2. Kode roti  :" <<(*(ptr + k)).kode<< endl;
        cout << "3. Harga roti :" <<(*(ptr + k)).harga<< endl;
    }
    else
    {
        cout << cari_nama << " tidak ada dalam Array tersebut";
    }
    return;
}

void Sorting_quick_sort()
{
    int harga_temp[jumlah_data];

    for (int i = 0; i < jumlah_data; i++) {
        harga_temp[i] = Toko_Roti[i].harga;
    }

    quick_sort(harga_temp, 0, jumlah_data - 1);

    //membuat deklarasi temporal dari struct untuk menyamakan nilai antara harga struct temp dan harha pada struct asli
    Toko temp[jumlah_data];
    for (int i = 0; i < jumlah_data; i++){
        for (int j = 0; j < jumlah_data; j++) {
            if (harga_temp[i] == Toko_Roti[j].harga) {
                temp[i] = Toko_Roti[j];
                break;
            }
        }
    }

    for (int i = 0; i < jumlah_data; i++) {
        Toko_Roti[i] = temp[i];
    }

    cout<<"Data telah di urutkan \nSilahkan Buka 'Tampil Data' Kembali"<<endl;
}

void Sorting_bubble_sort()
{
    for (int i = 0; i < jumlah_data - 1; i++){//Bubble Sort
        for (int j = 0; j < jumlah_data - 1 - i; j++){
            if(Toko_Roti[j].harga < Toko_Roti[j+1].harga){
                swap(Toko_Roti[j],Toko_Roti[j+1]);
            };
    }
}
cout<<"Data telah di urutkan \nSilahkan Buka 'Tampil Data' Kembali"<<endl;
}

int main()
{
    do
    {
        cout << "\n";
        cout << "MENU PILIHAN :" << endl;
        cout << "1. Menampilkan Roti" << endl;
        cout << "2. Mencari Roti (berdasarkan kode)" << endl;
        cout << "3. Mencari Roti (berdasarkan nama)" << endl;
        cout << "4. Mengurutkan Data Roti (Ascending)" << endl;
        cout << "5. Mengurutkan Data Roti (Descending)" << endl;
        cout << "6. Menutup Program" << endl;
        cout << "memilih : ";
        cin >> pilihmenu;

        switch (pilihmenu)
        {
        case 1:
        {
            Tampil_data();
            break;
        }

        case 2:
        {
            Sequential_search();
            break;
        }

        case 3:
        {
            Sorting_bubble_sort_nama();
            Binary_search();
            break;
        }

        case 4:
        {
            Sorting_quick_sort();
            Tampil_data();
            break;
        }

        case 5:
        {
            Sorting_bubble_sort();
            Tampil_data();
            break;
        }

        case 6:
        {
            cout << "Terima Kasih Telah Menggunakan Program Kami" << endl;
            exit(0);
            break;
        }
        }
        cout << "\nKembali Ke menu ? (y/n) : ";
        cin >> menu_kembali;
    } while (menu_kembali == 'y' || menu_kembali == 'Y');
}
