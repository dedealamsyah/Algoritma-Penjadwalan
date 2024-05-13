#include<stdio.h>
#include<stdlib.h>

int main() {
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp; // Deklarasi variabel
    float wtavg, tatavg; // Deklarasi variabel untuk rata-rata

    // Membersihkan layar
    system("clear");

    // Meminta jumlah proses kepada pengguna
    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);

    // Meminta burst time untuk setiap proses dan menyimpan indeks proses ke dalam array p
    for(i=0; i<n; i++) {
        p[i] = i;
        printf("Enter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }

    // Mengurutkan burst time dan indeks proses menggunakan bubble sort
    for(i=0; i<n; i++) {
        for(k=i+1; k<n; k++) {
            if(bt[i] > bt[k]) {
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }

    wt[0] = wtavg = 0; // Inisialisasi waktu tunggu pertama
    tat[0] = tatavg = bt[0]; // Inisialisasi turnaround time pertama

    // Menghitung waktu tunggu dan turnaround time untuk setiap proses
    for(i=1; i<n; i++) {
        wt[i] = wt[i-1] + bt[i-1]; // Menghitung waktu tunggu
        tat[i] = tat[i-1] + bt[i]; // Menghitung turnaround time
        wtavg = wtavg + wt[i]; // Menghitung total waktu tunggu
        tatavg = tatavg + tat[i]; // Menghitung total turnaround time
    }

    // Mencetak hasil perhitungan
    printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for(i=0; i<n; i++)
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);
    printf("\nAverage Waiting Time -- %f", wtavg/n); // Mencetak rata-rata waktu tunggu
    printf("\nAverage Turnaround Time -- %f", tatavg/n); // Mencetak rata-rata turnaround time

    getchar(); // Menunggu user menekan tombol
    return 0; // Mengembalikan nilai 0 sebagai penanda bahwa program berakhir dengan sukses
}
