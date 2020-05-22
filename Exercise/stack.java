import java.util.Scanner;

public class stack {
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
        if (isEmpty()) return 0;
        return head.data;
    }
    public static void main(String[] args) {
        stack test_stack = new stack();
        stack biggest = new stack();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while (n-- >0){
            int choice = sc.nextInt();
            if (choice == 1) {
                int data = sc.nextInt();
                test_stack.push(data);
                if (biggest.getHead() < data) biggest.push(data);
            }
            else if (choice == 2){
                int data = test_stack.getHead();
                if (data == biggest.getHead()) biggest.pop();
                test_stack.pop();
            }
            else System.out.println(biggest.getHead());
        }
        sc.close();
    }
}