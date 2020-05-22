import java.util.Scanner;

public class sumOfThree {
    public static int sum(int []arr, int index1, int index2){
        int rs = 0;
        for (int i=index1; i<index2; i++){
            rs += arr[i];
        }
        return rs;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int []arr = new int[n];
        for (int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        sc.close();
        boolean equal = false;
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                int x = sum(arr, 0, i);
                int y = sum(arr, i, j);
                int z = sum(arr, j, n);
                if (x == y && y == z) { equal = true; break;}
            }
        }

        if (equal) System.out.print("YES");
        else System.out.print("NO");
    }
}

// public class sumOfThree {
//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         int n = sc.nextInt(),tong=0;
//         int[] arr = new int[n];
//         for(int i=0;i<n;i++)
//         {
//             arr[i] = sc.nextInt();
//             tong+=arr[i];
//         }
//         boolean equal = false;
//         int x = 0, y = 0, z = 0;

//         for (int i = 0; i < n-1; i++) {
//             x+=arr[i];
//             y=0;
//             for (int j = n-1; j > 0; j--) {
//                 y+=arr[j];
//                 z = tong - x -y;
//                 if (y > x) break;
//                 if (x == y && y == z) {
//                     equal = true;
//                     break;
//                 }
//             }
//             if (equal) break;
//         }
//         if (equal) System.out.println("YES");
//         else System.out.println("NO");

//         sc.close();
//     }
// }