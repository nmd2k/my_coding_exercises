import java.util.*;

public class SortPeople {
    static class Node {
        public int year;
        public String name;
    }

    private static boolean less(Node a, Node b) {
        int year1 = a.year;
        int year2 = b.year;
        String name1 = a.name;
        String name2 = b.name;
        int n = name1.length();
        int m = name2.length();

        if (year1 != year2) return year1 > year2;
        else {
            if (n<m){
                for (int i=0; i<n; i++){
                    if (name1.charAt(i)!=name2.charAt(i)) return name1.charAt(i) < name2.charAt(i);
                }
            }
            else {
                for (int i=0; i<m; i++){
                    if (name1.charAt(i)!=name2.charAt(i)) return name1.charAt(i) < name2.charAt(i);
                }
            }
            if (n != m) return n < m;
        }
        return false;
    }
    
    public static void exch (Node[] a, int i, int j){
        int temp = a[i].year;
        a[i].year = a[j].year;
        a[j].year = temp;
        
        String stemp = a[i].name;
        a[i].name = a[j].name;
        a[j].name = stemp;
    }

    public static int partition(Node[] a, int lo, int hi)
    {
        int i = lo, j = hi+1;
        while (true)
        {
            while (less(a[++i], a[lo]))
                if (i == hi) break;
            while (less(a[lo], a[--j]))
                if (j == lo) break;
            if (i >= j) break;
            exch(a, i, j);
        }
        exch(a, lo, j);
        return j;
    }

    public static void sort(Node [] a)
    {
       sort(a, 0, a.length - 1);
    }
    
    public static void sort(Node[]a, int lo, int hi)
    {
       if (hi <= lo) return;
        int j = partition(a, lo, hi);
        sort(a, lo, j-1);
        sort(a, j+1, hi);
    }
    
    public static void main(String arg[]) {
        Scanner in = new Scanner(System.in);
        
        int n = in.nextInt();

        Node[] a = new Node[n];
        String b[] = new String[n];

        for (int i = 0; i < n; ++i) {
            a[i].year = in.nextInt();
        }
        for (int i=0; i<n; i++){
            a[i].name = in.next();
        }
        
        // insertion_sort(a, b, true);
        // insertion_sort(a, b, false);
        Node[] odd = new Node[(n+1)/2];
        Node[] even = new Node[n/2];
 
        for (int i = 0; i < n; i++) {
            if (i%2 == 0) odd[i/2] = a[i];
            if (i%2 != 0) even[i/2] = a[i];
        }
        
        sort(odd);
        sort(even);
        
        for (int i = 0; i < n; ++i){
            if (i%2==0) System.out.println(odd[i/2].year + " " + odd[i/2].name);
            else System.out.println(even[i/2].year + " " + even[i/2].name);
        }
    }
}