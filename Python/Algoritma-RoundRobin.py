def main():
    # Inisialisasi variabel
    n = int(input("Enter the no of processes -- "))
    bu = [0] * 10
    wa = [0] * 10
    tat = [0] * 10
    ct = [0] * 10
    max_burst = 0
    awt = 0.0
    att = 0.0
    temp = 0.0

    # Input burst time untuk setiap proses
    for i in range(n):
        bu[i] = int(input(f"Enter Burst Time for process {i + 1} -- "))
        ct[i] = bu[i]

    # Input ukuran time slice
    t = int(input("Enter the size of time slice -- "))

    # Mencari burst time maksimum
    max_burst = max(bu[:n])

    # Simulasi penjadwalan round-robin
    for j in range((max_burst // t) + 1):
        for i in range(n):
            if bu[i] != 0:
                if bu[i] <= t:
                    tat[i] = temp + bu[i]
                    temp += bu[i]
                    bu[i] = 0
                else:
                    bu[i] -= t
                    temp += t

    # Menghitung waiting time dan turnaround time
    for i in range(n):
        wa[i] = tat[i] - ct[i]
        att += tat[i]
        awt += wa[i]

    # Menghitung rata-rata turnaround time dan waiting time
    average_tat = att / n
    average_wt = awt / n

    # Menampilkan hasil
    print(f"\nThe Average Turnaround time is -- {average_tat}")
    print(f"\nThe Average Waiting time is -- {average_wt}")
    print("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME")

    for i in range(n):
        print(f"\t{i + 1} \t {ct[i]} \t\t {wa[i]} \t\t {tat[i]}")

if __name__ == "__main__":
    main()
