def main():
    # Inisialisasi variabel
    n = int(input("Masukkan jumlah proses --- "))
    p = list(range(1, n + 1))
    bt = [0] * n
    pri = [0] * n
    wt = [0] * n
    tat = [0] * n

    # Input burst time dan prioritas untuk setiap proses
    for i in range(n):
        print(f"Masukkan Burst Time & Prioritas Proses {i + 1} --- ", end="")
        bt[i], pri[i] = map(int, input().split())

    # Mengurutkan proses berdasarkan prioritas menggunakan bubble sort
    for i in range(n):
        for k in range(i + 1, n):
            if pri[i] > pri[k]:
                # Menukar prioritas
                pri[i], pri[k] = pri[k], pri[i]
                # Menukar burst time
                bt[i], bt[k] = bt[k], bt[i]
                # Menukar proses
                p[i], p[k] = p[k], p[i]

    # Inisialisasi waktu tunggu dan waktu turnaround
    wtavg = wt[0] = 0
    tatavg = tat[0] = bt[0]

    # Menghitung waktu tunggu dan waktu turnaround untuk setiap proses
    for i in range(1, n):
        wt[i] = wt[i - 1] + bt[i - 1]
        tat[i] = tat[i - 1] + bt[i]
        wtavg += wt[i]
        tatavg += tat[i]

    # Menghitung rata-rata waktu tunggu dan waktu turnaround
    average_wt = wtavg / n
    average_tat = tatavg / n

    # Menampilkan hasil
    print("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME")
    for i in range(n):
        print(f"{p[i]} \t\t {pri[i]} \t\t {bt[i]} \t\t {wt[i]} \t\t {tat[i]}")
    print(f"\nRata-rata Waiting Time is --- {average_wt}")
    print(f"Rata-rata Turnaround Time is --- {average_tat}")

if __name__ == "__main__":
    main()
