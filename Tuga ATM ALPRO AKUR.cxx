#include <stdio.h>
#include <stdlib.h>

int main() {
    // Inisialisasi PIN awal
    int pin = 100602;
    // Inisialisasi saldo awal
    float balance = 99879467;
    // Inisialisasi variabel-variabel lain yang dibutuhkan
    int choice, login_attempt = 0;
    int transfer_account_number;
    float transfer_amount, top_up_dana, top_up_gopay, withdrawal_amount;

    // Loop while untuk mengulang login hingga maksimal 3 kali percobaan
    while (login_attempt < 3) {
        // Meminta pengguna memasukkan PIN
        int input_pin;
        printf("Enter PIN: ");
        scanf("%d", &input_pin);
        
        // Jika PIN benar, tampilkan menu opsi
        if (input_pin == pin) {
            printf("Login berhasil!\n");
            while (1) {
                printf("\nATM Menu\n");
                printf("1. Lihat Saldo\n");
                printf("2. Isi Saldo\n");
                printf("3. Penarikan\n");
                printf("4. Transfer\n");
                printf("5. Top Up\n");
                printf("6. Keluar\n");
                printf("Masukkan Pilihan Anda: ");
                scanf("%d", &choice);
                
                // Switch case untuk setiap opsi pada menu
                switch (choice) {
                    case 1:
                        printf("Saldo Anda Saat Ini: %.2f\n", balance);
                        break;
                    case 2:
                        printf("Masukkan Jumlah Deposit Saldo: ");
                        float deposit_amount;
                        scanf("%f", &deposit_amount);
                        balance += deposit_amount;
                        printf("Setoran Berhasil  Saldo Baru Anda adalah: %.2f\n", balance);
                        break;
                    case 3:
                        printf("Masukkan Jumlah Yang Akan Ditarik: ");
                        scanf("%f", &withdrawal_amount);
                        if (withdrawal_amount > balance) {
                            printf("Insufficient funds.\n");
                        } else {
                            balance -= withdrawal_amount;
                            printf("Penarikan Sukses. Saldo Kamu Saat Ini Adalah: %.2f\n", balance);
                        }
                        break;
                    case 4:
                        printf("Masukkan Nomor Rekening Yang Akan Ditransfer: ");
                        scanf("%d", &transfer_account_number);
                        printf("Masukkan Jumlah Yang Akan Ditransfer: ");
                        scanf("%f", &transfer_amount);
                        if (transfer_amount > balance) {
                            printf("Insufficient funds.\n");
                        } else {
                            balance -= transfer_amount;
                            printf("Transfer Sukses. Saldo Kamu Saat Ini Adalah: %.2f\n", balance);
                        }
                        break;
                    case 5:
                        printf("Top up menu\n");
                        printf("1. Dana\n");
                        printf("2. GoPay\n");
                        printf("Masukan Pilihan Anda: ");
                        int top_up_choice;
                        scanf("%d", &top_up_choice);
                        switch (top_up_choice) {
                            case 1:
                                printf("Masukkan Jumlah Top Up: ");
                                scanf("%f", &top_up_dana);
                                printf("Masukkan PIN: ");
                                scanf("%d", &pin);
                                printf("Top up Berhasil. Saldo Kamu Saat Ini Adalah: %.2f\n", balance + top_up_dana);
                                break;
                            case 2:
                                printf("Masukkan Jumlah Top Up: ");
                                scanf("%f", &top_up_gopay);
                                printf("Masukkan PIN: ");
                                scanf("%d", &pin);
                                printf("Top Up Berhasil. Saldo Anda Saat Ini Adalah: %.2f", balance += top_up_gopay);
                                printf("Top Up Berhasil. Saldo Kamu Saat Ini Adalah: %.2f\n", balance);
                                break;
                            default:
                                printf("Opsi Tidak Valid.\n");
                                break;
                        }
                        break;
                    case 6:
                        // Keluar dari menu dan kembali ke menu login
                        printf("Logout Berhasil.\n");
                        login_attempt = 3;
                        break;
                    default:
                        printf("Invalid option.\n");
                        break;
                }
            }
        } else {
            // Jika PIN salah, tampilkan pesan error dan tingkatkan jumlah percobaan
            printf("PIN Salah. Mohon Ulangi Kembali.\n");
            login_attempt++;
        }
    }
    // Jika sudah 3 kali percobaan login dan masih gagal, keluar dari program
    if (login_attempt == 3) {
        printf("Terlalu Banyak Usaha Yang Dilakukan . ATM Terkunci.\n");
    }
    return 0;
}