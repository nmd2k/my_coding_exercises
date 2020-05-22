int [] arr = new int[5];
        Scanner sc = new Scanner(System.in);
        for (int i=0; i<5; i++){
            arr[i] = sc.nextInt();
        }

        int target = sc.nextInt();
        sc.close();
        System.out.print(twoSum(arr, target));