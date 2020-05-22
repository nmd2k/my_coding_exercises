import java.util.ArrayList;
import java.util.Scanner;

public class sortProblem {
    public static class Person{
        public int birth = 0;
        public int height = 0;

        public Person(int birth, int height){
            this.birth = birth;
            this.height = height;
        }

        public Person(){}

        public void setBirth(int birth) {
            this.birth = birth;
        }

        public void setHeight(int height) {
            this.height = height;
        }
        
        public int compareTo (Person other){
            if (this.birth < other.getBirth()) return 1;
            else if (this.birth > other.getBirth()) return -1;
            else {
                if (this.height > other.getHeight()) return 1;
                else if (this.height == other.getHeight()) return 0;
            }
            return -1;
        }

        public int getBirth(){
            return this.birth;
        }

        public int getHeight(){
            return this.height;
        }

    }

    public static void exch (ArrayList<Person> arr, int i, int j){
        Person temp = arr.get(i);
        arr.set(i, arr.get(j));
        arr.set(j, temp);
    }

    public static int partition(ArrayList<Person> a, int lo, int hi)
    {
        int i = lo, j = hi+1;
        while (true)
        {
            while (less(a.get(++i), a.get(lo)))
                if (i == hi) break;
            while (less(a.get(lo), a.get(--j)))
                if (j == lo) break;

            if (i >= j) break;
            exch(a, i, j);
        }
        exch(a, lo, j);
        return j;
    }

    private static boolean less(Person i, Person j) {
        return i.compareTo(j) < 0;
    }

    public static void sort(ArrayList<Person> a)
    {
       sort(a, 0, a.size() - 1);
    }
    
    public static void sort(ArrayList<Person> a, int lo, int hi)
    {
       if (hi <= lo) return;
        int j = partition(a, lo, hi);
        sort(a, lo, j-1);
        sort(a, j+1, hi);
    }

    public static void printPerson(Person a){
        System.out.print(a.getBirth() + " ");
        System.out.println(a.getHeight());
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int []a = new int[n];
        int []b = new int[n];

        for (int i=0; i<n; i++){
            a[i] = sc.nextInt();
        }
        for (int i=0; i<n; i++){
            b[i] = sc.nextInt();
        }

        ArrayList <Person> arr = new ArrayList<sortProblem.Person>();

        // Person[] arr = new Person[n];
        for (int i=0; i<n; i++){
            Person x = new Person(a[i], b[i]);
            arr.add(x);
        }

        ArrayList <Person> even = new ArrayList<sortProblem.Person>();
        ArrayList <Person> odd = new ArrayList<sortProblem.Person>();

        for (int i=0; i<n; i++){
            if (i==0||i%2==0){
                even.add(arr.get(i)); //even index equal -> odd position
            }
            else odd.add(arr.get(i));
        }

        sort(even);
        sort(odd);
        int index = 0;
        int jndex = 0;
        for (int i=0; i<n; i++){
            if (i==0 || i%2==0) printPerson(even.get(index++));
            else printPerson(odd.get(jndex++));
        }

        sc.close();
    }
}