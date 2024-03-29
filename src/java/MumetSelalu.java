package src.java;

/**
 * @author Achmad raihan
 */
public class MumetSelalu {
    /**
     * @param args
     */
    public static void main(String[] args) {
        final int n = 7;
        final int[][] arrs = new int[n][n];

        int number = 1;

        int startRow = 0;
        int endRow = n - 1;

        int startCol = 0;
        int endCol = n - 1;

        // bottom to top
        for (int i = endRow; i >= startRow; i--) {
            arrs[i][startRow] = number;
            number++;
        }
        startCol++;

        // startCol += 1 then left to right
        for (int i = startCol; i <= endCol; i++) {
            arrs[startRow][i] = number;
            number++;
        }
        startRow++;

        // row += 1 then top to bottom
        for (int i = startRow; i <= endRow; i++) {
            arrs[i][endCol] = number;
            number++;
        }
        endCol--;

        // endCol -= 1 then bot to top
        for (int i = endRow; i >= startRow; i--) {
            arrs[i][endCol] = number;
            number++;
        }
        endCol--;

        // endCol -= 1 then right to left
        for (int i = endCol; i >= startCol; i--) {
            arrs[startRow][i] = number;
            number++;
        }
        startRow++;

        // startRow += 1 then top to bottom
        for (int i = startRow; i <= endRow; i++) {
            arrs[i][startCol] = number;
            number++;
        }
        startCol++;

        // startCol += 1 then bottom to top
        for (int i = endRow; i >= startRow; i--) {
            arrs[i][startCol] = number;
            number++;
        }
        startCol++;

        // startCol += 1 then left to right
        for (int i = startCol; i <= endCol; i++) {
            arrs[startRow][i] = number;
            number++;
        }
        startRow++;

        // startRow += 1 then top to bottom
        for (int i = startRow; i <= endRow; i++) {
            arrs[i][endCol] = number;
            number++;
        }
        endCol--;

        // startCol += 1 then bottom to top
        for (int i = endRow; i >= startRow; i--) {
            arrs[i][startCol] = number;
            number++;
        }
        endRow -= 3;
        printArray(arrs);
    }

    public static void printArray(int[][] arrs) {
        for (int[] arr : arrs) {
            for (int j = 0; j < arr.length; j++) {
                System.out.printf("%3d", arr[j]);
            }
            System.out.println();
        }
    }
}