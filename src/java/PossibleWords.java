/*
*
* Beberapa anak tidak dapat mengucapkan semua huruf, beberapa di antaranya terkadang mereka ucapkan dengan benar dan terkadang salah.
* Naufal kadang-kadang mengucapkan T padahal aslinya K, tapi dia tidak pernah bilang K untuk huruf T.
* Demikian pula, dia kadang-kadang mengatakan D untuk G. Dan untuk huruf R, dia kadang-kadang mengatakan L dan kadang-kadang F.
* Tentu saja dia mengucapkan huruf itu dengan benar.
* Ayah Naufal selalu memikirkan berapa banyak arti kata yang diucapkan putranya (tidak masalah jika itu kata bahasa asli atau tidak).
*
* Tugas
* Tulislah sebuah program yang membaca dari input standar kata-kata yang diucapkan Naufal
* menghitung berapa banyak kata berbeda yang dapat diartikan menulis hasilnya pada output standar
*
* Input
* Satu bari sebuah kata yang diucapkan oleh Naufal.
* Hanya 26 huruf kapital yang digunakan. Panjang kata paling banyak 20.
*
* Output
* Tuliskan bilangan bulat dalam satu baris dengan bilangan bulat tunggal,
* yang menunjukkan jumlah kata yang dapat diartikan oleh kata Naufal.

* Contoh
* Input: MATAN
* Output: 2
*
* Input: MAKAN
* Output: 1
*/

package src;

import java.util.Scanner;
public class PossibleWords {
    public static void main(String[] args) {
        final Scanner input = new Scanner(System.in);
        System.out.print("Masukkan kata: ");
        final String kata = input.nextLine().toLowerCase();
        final int numberOfInterpretableWords = countPossibleWords(kata);
        System.out.println(numberOfInterpretableWords);
        input.close();
    }

    public static int countPossibleWords(String kata) {
        final boolean kataContainsPossibleWords = checkKataContainPossibleWords(kata);
        int possibilityNumber = kataContainsPossibleWords ? 0 : 1;
        if (kataContainsPossibleWords) {
            return possibilityNumber;
        }
        for (int i = 0; i < kata.length(); i++) {
            char huruf = kata.charAt(i);
            if (huruf == 't' || huruf == 'd' || huruf == 'l' || huruf == 'f') {
                possibilityNumber += 2;
            } else if (huruf == 'r') {
                possibilityNumber += 3;
            }
        }
        return possibilityNumber;
    }

    public static boolean checkKataContainPossibleWords(String kata) {
        return kata.contains("t") ||  kata.contains("d") || kata.contains("l") || kata.contains("f") || kata.contains("r");
    }
}