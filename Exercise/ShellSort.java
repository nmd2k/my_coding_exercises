import java.util.Scanner;
public class ShellSort {
    public static void sort(Comparable[] arr){
        int N = arr.length;
        int h = 1;
        while (h<N/3) h = h*3 +1;

        while (h>=1){
            for (int i=h; i<N; i++){
                for (int j=i; i>=h && less(arr[i], arr[j-h]); j-=h);{
                    exch(arr, i, j-h);
                }
            }
            h/=3;
        }
    }
    public static boolean less (Comparable a, Comparable b){
        return a.compareTo(b) < 0;
    }
    public static void exch (Comparable[] arr, Comparable i, Comparable j){
        Comparable temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        
    }
} 