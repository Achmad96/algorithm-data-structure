package src;

import java.util.Scanner;

public class SpiralForLoop {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Input the number: ");
        int n = input.nextInt();
        int[][] arrs = new int[n][n];
        int number = 1;

        int startRow = 0;
        int endRow = n - 1;

        int startCol = 0;
        int endCol = n - 1;

        while (number <= n * n) {
            // bot to top
            for (int i = endRow; i >= startRow; i--) {
                arrs[i][startCol]= number;
                number++;
            }
            startCol++;

            // left to right
            for (int i = startCol; i <= endCol; i++) {
                arrs[startRow][i] = number;
                number++;
            }
            startRow++;

            // top to bottom
            for (int i = startRow; i <= endCol; i++) {
                arrs[i][endCol]=number;
                number++;
            }
            endCol--;

            // right to left
            for (int i = endCol; i >= startCol; i--) {
                arrs[endRow][i] = number;
                number++;
            }
            endRow--;
        }
        
        for (int i = 0; i < arrs.length; i++) {
            for (int j = 0; j < arrs[i].length; j++) {
                System.out.printf("%3d", arrs[i][j]);
            }
            System.out.println();
        }
        input.close();
    }
}
