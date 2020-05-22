import java.util.ArrayList;
import java.util.Scanner;

public class abc {

    static class Info {
        public static ArrayList<Integer> data;

        public Info() {
            for (int i = 0; i < 3; i++) { // i<44
                data.set(i, 0);
            }
        }

        public static void setIndex(int index, int element) {
            data.set(index, element);
        }

        public static void print() {
            for (int i = 0; i < data.size(); i++) {
                System.out.print(data.get(i) + " ");
            }
        }

    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Info[] map = new Info[2]; //49
        for (int i=0; i<map.length; i++){
            // map[i] = new Info();
            while (sc.hasNextInt()) {
                int index = sc.nextInt();
                if (index != -1) map[i].setIndex(index, 1);
                else {
                    map[i].print();
                    break;
                }
            }
        }

        sc.close();
    }
}