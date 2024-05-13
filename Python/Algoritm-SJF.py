def main():
    # Deklarasi variabel
    p = [0] * 20
    bt = [0] * 20
    wt = [0] * 20
    tat = [0] * 20
    wtavg = 0  # Variabel untuk rata-rata waiting time
    tatavg = 0  # Variabel untuk rata-rata turnaround time
    temp = 0  # Variabel sementara untuk pertukaran

    # Meminta jumlah proses kepada pengguna
    n = int(input("\nEnter the number of processes -- "))

    # Meminta burst time untuk setiap proses dan menyimpan indeks proses ke dalam array p
    for i in range(n):
        p[i] = i
        bt[i] = int(input("Enter Burst Time for Process {} -- ".format(i)))

    # Mengurutkan burst time dan indeks proses menggunakan bubble sort
    for i in range(n):
        for k in range(i+1, n):
            if bt[i] > bt[k]:
                temp = bt[i]
                bt[i] = bt[k]
                bt[k] = temp
                temp = p[i]
                p[i] = p[k]
                p[k] = temp

    # Menghitung waktu tunggu dan turnaround time untuk setiap proses
    wt[0] = wtavg = 0  # Inisialisasi waktu tunggu pertama
    tat[0] = tatavg = bt[0]  # Inisialisasi turnaround time pertama
    for i in range(1, n):
        wt[i] = wt[i-1] + bt[i-1]  # Menghitung waktu tunggu
        tat[i] = tat[i-1] + bt[i]  # Menghitung turnaround time
        wtavg = wtavg + wt[i]  # Menghitung total waktu tunggu
        tatavg = tatavg + tat[i]  # Menghitung total turnaround time

    # Mencetak hasil perhitungan
    print("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME")
    for i in range(n):
        print("\n\t P{} \t\t {} \t\t {} \t\t {}".format(p[i], bt[i], wt[i], tat[i]))
    print("\nAverage Waiting Time --", wtavg/n)  # Mencetak rata-rata waktu tunggu
    print("Average Turnaround Time --", tatavg/n)  # Mencetak rata-rata turnaround time

    input()  # Menunggu user menekan tombol
    return 0  # Mengembalikan nilai 0 sebagai penanda bahwa program berakhir dengan sukses

if __name__ == "__main__":
    main()
