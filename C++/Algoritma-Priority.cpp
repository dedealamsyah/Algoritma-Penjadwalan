#include <stdio.h>

// Fungsi utama
int main() {
    int p[20], bt[20], pri[20], wt[20], tat[20];
    int i, k, n, temp;
    float wtavg, tatavg;

    // Input jumlah proses
    printf("Masukkan jumlah proses --- ");
    scanf("%d", &n);

    // Input burst time dan prioritas untuk setiap proses
    for (i = 0; i < n; i++) {
        p[i] = i + 1;  // Menginisialisasi array proses dengan angka urut
        printf("Masukkan Burst Time & Prioritas Proses %d --- ", i + 1);
        scanf("%d %d", &bt[i], &pri[i]);
    }

    // Mengurutkan proses berdasarkan prioritas menggunakan bubble sort
    for (i = 0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
            if (pri[i] > pri[k]) {
                // Menukar prioritas
                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;

                // Menukar burst time
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                // Menukar proses
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }

    // Inisialisasi waktu tunggu dan waktu turnaround
    wtavg = wt[0] = 0;
    tatavg = tat[0] = bt[0];

    // Menghitung waktu tunggu dan waktu turnaround untuk setiap proses
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    // Menampilkan hasil
    printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    for (i = 0; i < n; i++) {
        printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ", p[i], pri[i], bt[i], wt[i], tat[i]);
    }
    printf("\nRata-rata Waiting Time is --- %f", wtavg / n);
    printf("\nRata-rata Turnaround Time is --- %f", tatavg / n);

    return 0;
}
