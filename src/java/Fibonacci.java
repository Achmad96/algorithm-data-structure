package src;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Fibonacci {
  public static void main(String[] args) {
    final Scanner input = new Scanner(System.in);
    System.out.print("Masukkan panjang: ");
    final int n = input.nextInt();
    System.out.println(Arrays.toString(getFibonacciNumbers(n)));
    input.close();
  }

  public static int[] getFibonacciNumbers(int n) {
    final ArrayList<Integer> list = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      list.add(getFibonacciRecursive(i));
    }
    return list.stream().mapToInt(Integer::intValue).toArray();
  }

  public static int getFibonacciRecursive(int n) {
    if (n == 0 || n == 1) return n;
    return getFibonacciRecursive(n - 1) + getFibonacciRecursive(n - 2);
  }
}