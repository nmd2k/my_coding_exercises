import java.util.Scanner;
public class addOperator{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        str += "+";
        sc.close();

        char [] input = str.toCharArray();

        int something = 0;
        String temp = "0";

        for (int i=0; i<input.length; i++){
            // if (input[i] == '+') {
            //     int number = Integer.parseInt(temp); 
            //     something += number; 
            //     temp = "0";
            // }
            if (input[i] == '-') {
                int number = Integer.parseInt(temp);
                something -= number;
                temp = "0";
            }
            else {temp += String.valueOf(input[i]);}
        }
        System.out.println(something);
    }
}