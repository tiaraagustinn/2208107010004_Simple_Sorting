•	Kode program dimulai dengan mendefinisikan beberapa fungsi yang akan digunakan dalam program. Fungsi-fungsi tersebut adalah:
1)	Fungsi generateRandomNumbers() adalah sebuah fungsi untuk mengisi array dengan bilangan bulat acak. Ini dilakukan dengan menghasilkan bilangan bulat dari 1 hingga n terlebih dahulu, kemudian mengacak urutannya.
2)	Fungsi bubbleSort() adalah sebuah fungsi untuk mengurutkan array dengan bubble sort. Bubble Sort membandingkan dua elemen berdekatan dan menukar mereka jika urutannya salah. Hal ini dilakukan secara berulang hingga tidak ada lagi pertukaran yang perlu dilakukan.
3)	Fungsi selectionSort() adalah sebuah fungsi untuk mengurutkan array dengan selection sort. Selection Sort mencari elemen terkecil dalam setiap iterasi dan menukarnya dengan elemen pertama, kemudian mencari elemen terkecil kedua, dan seterusnya.
4)	Fungsi insertionSort() adalah sebuah fungsi untuk mengurutkan array dengan insertion sort.  Insertion Sort bekerja dengan memilih satu elemen pada suatu waktu dan menempatkannya pada posisi yang tepat dalam array yang telah diurutkan sebelumnya.
5)	Fungsi saveToFile() adalah sebuah fungsi untuk menyimpan isi array ke dalam file dengan nama yang ditentukan. Fungsi ini membuka file, menulis setiap elemen array ke dalam file, dan kemudian menutup file.
   
•	Selain fungsi-fungsi tersebut, terdapat pula fungsi-fungsi bantu seperti printTableHeader dan printTableRow, yang digunakan untuk mencetak header dan baris tabel pada output.

•	Kemudian ada fungsi main yang merupakan fungsi utama dari program. Di dalam fungsi ini, terdapat tiga perulangan for, masing-masing untuk menguji ketiga jenis algoritma pengurutan (bubble sort, selection sort, dan insertion sort) terhadap beberapa ukuran data yang berbeda.
1)	Setiap kali loop dijalankan, dilakukan alokasi memori dinamis untuk array yang akan diurutkan, kemudian diisi dengan bilangan acak menggunakan fungsi generateRandomNumbers().
2)  Sebelum melakukan pengurutan, array yang belum diurutkan disimpan ke dalam sebuah file teks dengan nama yang sesuai.
3)	Waktu eksekusi pengurutan diukur menggunakan fungsi clock().
4)	Hasil waktu eksekusi tersebut dicetak sebagai baris tabel menggunakan fungsi printTableRow.
5)	Setelah pengurutan selesai, array yang telah diurutkan juga disimpan ke dalam sebuah file teks.
6)	Pengurutan selesai, memori yang dialokasikan untuk array dibebaskan dengan menggunakan free.
   
fungsi main dipanggil di akhir program untuk menjalankan semua proses di atas.

•	Kode program dijalankan dengan melakukan compile:

gcc nama_file.c -o nama_file

./nama_file

Yang kemudian program akan dijalankan dan membuat beberapa file dengan ekstension .txt yang diperlukan.
