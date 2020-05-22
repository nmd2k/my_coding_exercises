import java.util.Scanner;
public class SelectionSort {
    public static void sort(int[] arr){
        for (int i=0; i<arr.length; i++){
            for (int j=i+1; j<arr.length; j++){
                
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n-1];
        for (int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        sc.close();
        sort(arr);
        for (int i=0; i<n; i++){
            System.out.print(arr[i] + ' ');
        }
    }
}