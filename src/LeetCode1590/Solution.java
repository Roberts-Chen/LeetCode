package LeetCode1590;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class Solution {
    public int minSubarray(int[] nums, int p) {
        int n = nums.length;
        int x = 0;
        for (int i = 0; i < n; i++) {
            x = (x + nums[i]) % p;
        }
        if (x == 0) {
            return 0;
        }
        Map<Integer, Integer> map = new HashMap<>();
        int y = 0, result = nums.length;
        for (int i = 0; i < n; i++) {
            map.put(y, i);
            y = (y + nums[i]) % p;
            if (map.containsKey((y - x + p) % p)) {
                result = Math.min(result, i - map.get((y - x + p) % p) + 1);
            }
        }
        return result == nums.length ? -1 : result;
    }

    public static void main(String[] args) {
        Random random = new Random();
        int[] nums = new int[10000];
        for (int i = 0; i < 10000; i++) {
            nums[i] = random.nextInt();
        }
//        System.out.println(Arrays.toString(nums));
        int result = new Solution().minSubarray(new int[]{8, 32, 31, 18, 34, 20, 21, 13, 1, 27, 23, 22, 11, 15, 30, 4, 2}, 148);
        System.out.println(result);
    }
}
