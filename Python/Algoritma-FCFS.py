def main():
    # Inisialisasi array untuk burst time, waiting time, dan turnaround time
    bt = [0] * 20
    wt = [0] * 20
    tat = [0] * 20
    wtavg = 0  # Variabel untuk rata-rata waiting time
    tatavg = 0  # Variabel untuk rata-rata turnaround time

    # Meminta jumlah proses dari pengguna
    n = int(input("Enter the number of processes -- "))

    # Meminta burst time untuk setiap proses
    for i in range(n):
        bt[i] = int(input("\nEnter Burst Time for Process {} -- ".format(i)))

    # Menghitung waiting time dan turnaround time untuk setiap proses
    wt[0] = wtavg = 0
    tat[0] = tatavg = bt[0]
    for i in range(1, n):
        wt[i] = wt[i-1] + bt[i-1]
        tat[i] = tat[i-1] + bt[i]
        wtavg = wtavg + wt[i]
        tatavg = tatavg + tat[i]

    # Mencetak header tabel
    print("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME")

    # Mencetak data untuk setiap proses
    for i in range(n):
        print("\n\t P{} \t\t {} \t\t {} \t\t {}".format(i, bt[i], wt[i], tat[i]))

    # Menghitung dan mencetak rata-rata waiting time dan turnaround time
    print("\nAverage Waiting Time --", wtavg/n)
    print("Average Turnaround Time --", tatavg/n)

if __name__ == "__main__":
    main()
