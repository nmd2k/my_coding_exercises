import java.util.ArrayList;

public class AddTwoNumber {
    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int num1 = 0, num2 = 0;
        for (ListNode index = l1; index!=null; index=index.next){
            num1 += 10*index.val;
        }

        for (ListNode index = l2; index!=null; index=index.next){
            num2 += 10*index.val;
        }

        int sum = num1 + num2;
        ArrayList <Integer> arr = new ArrayList<>();
        while (sum>0){
            int x = sum%10;
            arr.add(x);
            sum /= 10;
        }

        ListNode rs = new ListNode (arr.get(0));
        rs.next = null;

        for (int i=1; i<arr.size(); i++){
            ListNode newNode = new ListNode (arr.get(i));
            newNode.next = rs;
            rs = newNode;
        }

        return rs;
    }
}