import java.util.Objects;
import java.util.Scanner;

class TwoSum {
    public static int[] twoSum(int[] nums, int target) {
        for (int i = 0; i<nums.length; i++){
            for (int j = i+1; j<nums.length; j++){
                if (nums[i] + nums[j] == target){
                    return new int[] {i, j++};
                }
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }

    public static void main(String[] args) {
        int [] arr = new int[5];
        Scanner sc = new Scanner(System.in);
        for (int i=0; i<5; i++){
            arr[i] = sc.nextInt();
        }

        int target = sc.nextInt();
        sc.close();
        for (int i:twoSum(arr, target)){
            System.out.print(i + " ");        
        }   
    }
}
