#include <stdio.h>

// Fungsi utama
int main() {
    int i, j, n, t, max;
    int bu[10], wa[10], tat[10], ct[10];
    float awt = 0, att = 0, temp = 0;

    // Input jumlah proses
    printf("Enter the no of processes -- ");
    scanf("%d", &n);

    // Input burst time untuk setiap proses
    for (i = 0; i < n; i++) {
        printf("\nEnter Burst Time for process %d -- ", i + 1);
        scanf("%d", &bu[i]);
        ct[i] = bu[i];  // Menyimpan burst time ke ct
    }

    // Input ukuran time slice
    printf("\nEnter the size of time slice -- ");
    scanf("%d", &t);

    // Mencari burst time maksimum
    max = bu[0];
    for (i = 1; i < n; i++) {
        if (max < bu[i]) {
            max = bu[i];
        }
    }

    // Simulasi penjadwalan round-robin
    for (j = 0; j < (max / t) + 1; j++) {
        for (i = 0; i < n; i++) {
            if (bu[i] != 0) {
                if (bu[i] <= t) {
                    tat[i] = temp + bu[i];
                    temp += bu[i];
                    bu[i] = 0;
                } else {
                    bu[i] -= t;
                    temp += t;
                }
            }
        }
    }

    // Menghitung waiting time dan turnaround time
    for (i = 0; i < n; i++) {
        wa[i] = tat[i] - ct[i];
        att += tat[i];
        awt += wa[i];
    }

    // Menghitung rata-rata turnaround time dan waiting time
    float average_tat = att / n;
    float average_wt = awt / n;

    // Menampilkan hasil
    printf("\nThe Average Turnaround time is -- %f", average_tat);
    printf("\nThe Average Waiting time is -- %f ", average_wt);
    printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");

    for (i = 0; i < n; i++) {
        printf("\t%d \t %d \t\t %d \t\t %d \n", i + 1, ct[i], wa[i], tat[i]);
    }

    return 0;
}
