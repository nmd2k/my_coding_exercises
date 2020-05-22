import java.util.Scanner;


public class Solution {
    static class StringA {
        private String str;
        private int count = 0;
    }
    public static void sort(StringA[] arr){
        int N = arr.length;
        for (int i=1; i<N; i++){
            for (int j=i; j>0; j--){
                if (less(arr[j].str, arr[j-1].str) {
                    exch(arr, j, j-1);
                    arr[j].count ++;
                }
                else break;
            }
        }
    }
    public static boolean less (String a, String b){
        return a.compareTo(b) < 0;
    }
    public static void exch (StringA[] arr, int i, int j){
        String temp = arr[i].str;
        arr[i].str = arr[j].str;
        arr[j].str = temp);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringA[] str = new StringA[12];

        for (int i=0; i<12; i++){
            str[i].str = sc.nextLine();
        }

        sort(str);

        for(StringA i:str){
            System.out.print(i.str + " ");
        }

        sc.close();
    }
}
/**
 * 
E
A
S
Y
Q
U
E
S
T
I
O
N
 */