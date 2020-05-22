import java.util.Scanner;

public class uetcodehub_2_10 {
    public static void sort(int[] a, int[] b, int pos, int sorted, boolean ascending){
        for (int i=1; i<pos; i++){
            for (int j=i; j>sorted; j--){
                boolean less = less(a[j], a[j-1], b[j], b[j-1]);
                if ((less == true && ascending == true) || (less == false && ascending == false)) {
                    exch(a, j, j-1);
                    exch(b, j, j-1);
                }
                else break;
            }
        }
    }
    
    public static boolean less (int a, int b, int x, int y){
        if (y<0) { x = -x; y = -y;}
        if (b<0) { b = -b; a = -a;}
        return a*y < b*x;
    }

    public static void exch (int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int [n];
        int[] b = new int [n];
        int[] arr = new int[4];

        for (int i=0; i<n; i++){a[i] = sc.nextInt();}

        for (int i=0; i<n; i++){b[i] = sc.nextInt();}

        for (int i=0; i<4; i++){
            arr[i] = sc.nextInt();
        }

        int sorted = 0;
        for (int i=0; i<4; i++){
            if (i == 0 || i == 2){
                sort(a, b, arr[i] + sorted, sorted, true); 
            }
            else sort(a, b, arr[i] + sorted, sorted, false);
            sorted += arr[i];
        }

        for (int i=0; i<n; i++){
            System.out.print(a[i] + "/" + b[i]);
            if (i!=n-1) System.out.print(",");
        }
        sc.close();
    }
}