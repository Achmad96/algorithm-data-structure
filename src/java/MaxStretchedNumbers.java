package src;

/*
 * Diberikan sebuah array dan bilangan bulat k, tentukan nilai maksimum untuk setiap subarray yang berdekatan dengan ukuran k.
 *
 * Input
 * angka n yang menunjukkan jumlah elemen dalam array kemudian setelah baris isian array dan kemudian k di baris baru.
 *
 * Output
 * Array keluaran
 *
 * Contoh
 * Input:
 * Masukkan panjang array: 9
 * Masukkan batas-batas: 3
 *
 * isi index ke-0: 1
 * isi index ke-1: 2
 * isi index ke-2: 3
 * isi index ke-3: 1
 * isi index ke-4: 4
 * isi index ke-5: 5
 * isi index ke-6: 2
 * isi index ke-7: 3
 * isi index ke-8: 6
 *
 * Output:
 * 3 3 4 5 5 5 6
 */

import java.util.Arrays;
import java.util.Scanner;
public class MaxStretchedNumbers {

    public static void main(String[] args) {
        final Scanner input = new Scanner(System.in);
        System.out.print("Masukkan panjang array: ");
        final int[] numbers = new int[input.nextInt()];

        System.out.print("Masukkan batas-batas: ");
        final int k = input.nextInt();

        for (int i = 0; i < numbers.length; i++) {
            System.out.printf("isi index ke-%d: ", i);
            numbers[i] = input.nextInt();
        }

        input.close();
        System.out.println(getMaxFromEachNumbers(numbers, k));
    }

    public static String getMaxFromEachNumbers(int[] num, int k){
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < num.length - (k - 1); i++) {
            int t = 0;
            int[] nums = new int[k];
            for (int j = i; j < i + k; j++) {
                nums[t] = num[j];
                t++;
            }
            result.append(Arrays.stream(nums).max().getAsInt());
            if ( i != num.length - k) result.append( ", ");
        }
        return result.toString();
    }
}