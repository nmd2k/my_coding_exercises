import java.util.Scanner;

public class findBiggestNumber {
    private class Node {
        int data;
        Node next;
        Node(int _data, Node _next){
            this.data = _data;
            this.next = _next;
        }
    }
    
    private Node head = null;
    
    public boolean isEmpty(){
        return head == null;
    }

    public void push(int data){
        head = new Node(data, head);
    } 

    public void pop(){
        head = head.next;
    }

    public int getHead(){
        if (isEmpty()) return 10000;
        return head.data;
    }
    public static void main(String[] args) {
        findBiggestNumber test_stack = new findBiggestNumber();
        findBiggestNumber min = new findBiggestNumber();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while (n-- >0){
            int choice = sc.nextInt();
            if (choice == 1) {
                int data = sc.nextInt();
                test_stack.push(data);
                if (min.getHead() >= data) min.push(data);
            }
            else if (choice == 2){
                int data = test_stack.getHead();
                if (data == min.getHead()) min.pop();
                test_stack.pop();
            }
            else System.out.println(min.getHead());
        }
        sc.close();
    }
}