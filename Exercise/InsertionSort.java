public class InsertionSort {

    public static void sort(Comparable[] arr){
        int N = arr.length;
        for (int i=1; i<N; i++){
            for (int j=i; j>0; j--){
                if (less(arr[j], arr[j-1])) exch(arr, j, j-1);
                else break;
            }
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
}