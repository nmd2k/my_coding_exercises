import java.util.Scanner;
public class queue {
    private class Node {
        int data;
        Node next;
        Node(int _data, Node _next){
            this.data = _data;
            this.next = _next;
        }
    }
    
    private Node first, last;
    private int max, count = 0;
    
    public boolean isEmpty(){
        return first == null;
    }

    public void enqueue(int data){
        Node newLast = new Node(data, null);
        if (isEmpty()) {
            count++;
            last = newLast; 
            first = last;
        }
        else {
            count++;
            last.next = newLast;
            last = newLast;
        }
    } 

    public void dequeue(){
        first = first.next;
        count--;
        if (isEmpty()) last = null;
    }

    public int getFirst(){
        return first.data;
    }

    public int getLength(){
        return count;
    }
    
    public void setMax(int _max){
        max = _max;
    }

    public int getMax(){
        return max;
    }

    // public int getSum(){
    //     int sum = 0;
    //     for (Node index = first; index != null; index = index.next){
    //         sum += index.data;
    //     }
    //     return sum;
    // }

    // public static void main(String[] args) {
    //     queue test_queue = new queue();
    //     Scanner sc = new Scanner(System.in);
    //     int n, d, a1,  = sc.nextInt();
    //     int d = sc.nextInt();
    //     int a1 = sc.nextInt();
    //     int x = sc.nextInt();
    //     int y = sc.nextInt();
    //     int m = sc.nextInt();

    //     test_queue.setMax(d);
    //     int arr[] = new int[n];
    //     arr[0] = a1;
    //     for (int i=1; i<n; i++){
    //         arr[i] = ((arr[i-1]*x+y)%m) + 1;
    //     }
    //     int c[] = new int[n];
    //     int t[] = new int[n];
    //     for (int i=0; i<n; i++){
    //         if (i==0) {test_queue.enqueue(arr[i]);}
    //         else if (arr[i] + t[i-1] > d){
    //             test_queue.dequeue();
    //             test_queue.enqueue(arr[i]);
    //         }
    //         else {
                
    //             test_queue.enqueue(arr[i]);
    //         }
    //         c[i] = test_queue.getLength();
    //         t[i] = test_queue.getSum();
    //     }
    //     int c_sum = 0, t_sum = 0;
    //     for (int i=0; i<n; i++){
    //         c_sum += c[i];
    //         t_sum += t[i];
    //     }
    //     System.out.println(c_sum);
    //     System.out.println(t_sum);
    //     sc.close();
    // }
}