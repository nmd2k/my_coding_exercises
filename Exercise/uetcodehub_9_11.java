import java.util.Scanner;
import java.util.*;
public class uetcodehub_9_11{
    public static boolean checkPy (int a, int b, int c){
        if (a+b > c && a+c > b && b+c > a){
            if (Math.sqrt(Math.pow(a, 2) + Math.pow(b, 2)) == c) return true;
            else if (Math.sqrt(Math.pow(b, 2) + Math.pow(c, 2)) == a) return true;
            else if (Math.sqrt(Math.pow(c, 2) + Math.pow(a, 2)) == b) return true;
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int count = 0;
        int []arr = new int[n];

        for (int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }

        List<Integer>  index = new int[n];
        for (int i=0; i<n; i++){
            index.get(i) = i;
        }

        for (int i=0; i<n-2; i++){
            for (int j=i+1; j<n-1; j++){
                for (int k=j+1; k<n; k++){
                    if (checkPy(arr[i], arr[j], arr[k]))
                        count ++;
                        break;

                }
            }
        }

        sort(arr);

        for (int i = 0; i < n; i++){
            int k = i + 2;
            for (int j = i + 1; j < n; j++){
                int x = arr[i]*arr[i] + arr[j]*arr[j];
                while (k<n && arr[k]*arr[k] < x){
                    k++;
                    if (arr[k]*arr[k] == x) count++;
                }
            }
        }

        sc.close();
        System.out.println(count);
    }
}