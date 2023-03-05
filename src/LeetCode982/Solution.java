package LeetCode982;

import java.util.HashMap;

public class Solution {
    public int countTriplets(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums.length; j++) {
                int res = nums[i] & nums[j];
                map.put(res, map.getOrDefault(res, 0) + 1);
            }
        }
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            for (Integer it : map.keySet()) {
                if ((it & nums[i]) == 0) {
                    result += map.get(it);
                }
            }
        }
        return result;
    }
}
