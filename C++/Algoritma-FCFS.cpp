#include<stdio.h>
#include<stdlib.h>

int main() {
    int bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;
    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("\nEnter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];
    for(i=1; i<n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for(i=0; i<n; i++)
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", i, bt[i], wt[i], tat[i]);
    printf("\nAverage Waiting Time -- %f", wtavg/n);
    printf("\nAverage Turnaround Time -- %f", tatavg/n);
    getchar();
    return 0;
}

/* 
#include<stdio.h>
#include<stdlib.h>

int main() {
    int bt[20], wt[20], tat[20], i, n; // Deklarasi variabel
    float wtavg, tatavg; // Deklarasi variabel untuk rata-rata

    printf("\nEnter the number of processes -- ");
    scanf("%d", &n); // Meminta jumlah proses kepada pengguna

    // Meminta burst time untuk setiap proses
    for(i=0; i<n; i++) {
        printf("\nEnter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
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
    printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for(i=0; i<n; i++)
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", i, bt[i], wt[i], tat[i]);
    printf("\nAverage Waiting Time -- %f", wtavg/n); // Mencetak rata-rata waktu tunggu
    printf("\nAverage Turnaround Time -- %f", tatavg/n); // Mencetak rata-rata turnaround time

    getchar(); // Menunggu user menekan tombol
    return 0; // Mengembalikan nilai 0 sebagai penanda bahwa program berakhir dengan sukses
}


*/
