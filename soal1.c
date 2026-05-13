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

void print_balance_sequences (int n){
    char sequence[2*n + 1];
    sequence[2*n] = '\0'; 

    void backtrack(int open, int close) {
        if (open == n && close == n) {
            printf("%s\n", sequence);
            return;
        }
        if (open < n) {
            sequence[open + close] = '(';
            backtrack(open + 1, close);
        }
        if (close < open) {
            sequence[open + close] = ')';
            backtrack(open, close + 1);
        }
    }

    backtrack(0, 0);
}

int main (){
    // memnerima input 
    int n;
    if (scanf("%d", &n) != 1){
        return 0;
    }
    // print hasil
    print_balance_sequences(n);

    // print total
    printf("TOTAL %d\n", total_balance_sequences(n));
    return 0;
}

/*Reference 
[1] https://cp-algorithms.com/combinatorics/bracket_sequences.html 
[2] https://prepinsta.com/c-program/generate-all-combinations-of-balanced-parentheses/  
*/
