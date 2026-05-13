/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 5
 *   Hari dan Tanggal    : Rabu, 13 Mei 2026
 *   Nama (NIM)          : Kyrie Eleison Jacob Pakpahan (13224006)
 *   Nama File           : soal1.c
 *   Deskripsi           : Program untuk menerima input n banyak string yang kemudian, menghasilkan banyak bracket sequence yang mungkin
 *                          dengan n pasang kurung buka dan tutup dan banyak kemungkinan yang didapatkan. Program ini menggunakan backtracking untuk menghasilkan semua kemungkinan bracket sequence yang valid, dan menghitung totalnya. 
 *                         
 * 
 */

/*
Format Input

n
*/

/*Format Output

string
....
TOTAL x 
*/

/*
Testcase Input
3

Testcase Output
((())) 
(()())
(())()
()(())
()()()
TOTAL 5 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// fungsi untuk menghitung total banyaknya balanced bracket sequence yang mungkin dengan n pasang kurung buka dan tutup
int total_balance_sequences (int n){
    // rumus catalan
    if (n == 0) {
        return 1;
    }

    int total = 0;
    for (int i = 0; i < n; i++){
        total = total+(total_balance_sequences(i) * total_balance_sequences(n-1-i));
    }
    return total;
}

// fungsi untuk print hasil dari banyak bracket sequence yang mungkin dengan n pasang kurung buka dan tutup, dengan menggunakan backtracking untuk menghasilkan semua kemungkinan bracket sequence yang valid
void print_balance_sequences (int n, int k){
    char *str = (char *)malloc((2*n + 1) * sizeof(char));
    str[2*n] = '\0'; // null-terminate the string

    void backtrack(int open, int close, int index) {
        if (index == 2*n) {
            printf("%s\n", str);
            return;
        }
        if (open < n) {
            str[index] = '(';
            backtrack(open + 1, close, index + 1);
        }
        if (close < open) {
            str[index] = ')';
            backtrack(open, close + 1, index + 1);
        }
    }

    backtrack(0, 0, 0);
    free(str);
}

int main (){
    // memnerima input 
    int n;
    if (scanf("%d", &n) != 1){
        return 0;
    }
    // print hasil dari banyak bracket sequence yang mungkin dengan n pasang kurung buka dan tutup
    print_balance_sequences(n, 0);
    // print total banyaknya balanced bracket sequence yang mungkin dengan n pasang kurung buka dan tutup
    printf("TOTAL %d\n", total_balance_sequences(n));
    return 0;
}

/*Reference 
https://cp-algorithms.com/combinatorics/bracket_sequences.html 
*/
