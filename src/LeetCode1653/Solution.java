package LeetCode1653;

import java.util.Arrays;

public class Solution {

    public int minimumDeletions(String s) {
        int[] pre = new int[s.length()];
        int[] suc = new int[s.length()];
        char[] characters = s.toCharArray();
        pre[0] = 0;
        suc[characters.length - 1] = 0;
        for (int i = 1; i < characters.length; i++) {
            if (characters[i] == characters[i - 1]) {
                pre[i] = pre[i - 1] + 1;
            } else {
                pre[i] = 0;
            }
            if (characters[characters.length - i - 1] == characters[characters.length - i]) {
                suc[characters.length - i - 1] = suc[characters.length - i] + 1;
            } else {
                suc[characters.length - i - 1] = 0;
            }
        }
        System.out.println("pre: " + Arrays.toString(pre));
        System.out.println("suc: " + Arrays.toString(suc));
        // 遍历数组，当i < j，且a[i] = 'b', a[j] = 'a'时，如果pre[i] < suc[j]，删除[i - pre[i], i]的'b'字符
        // 如果pre[i] > suc[j]，删除[j, j + suc[j]]的'a'字符
        int result = 0;
        for (int i = 1; i < characters.length; ) {
            if (characters[i] == 'a' && characters[i - 1] == 'b') {
                if (pre[i - 1] > suc[i]) {
                    result += (suc[i] + 1);
                    i = i + suc[i] + 1;
                } else if (pre[i - 1] <= suc[i]) {
                    result += (pre[i - 1] + 1);
                    i = i + suc[i] + 1;
                }
            } else {
                i++;
            }
        }
        return result;
    }

    public int minimumDeletions2(String s) {
        char[] array = s.toCharArray();
        int left = 0, right = 0;
        for (int i = array.length - 1; i >= 0; i--) {
            right += ((array[i] == 'a') ? 1 : 0);
        }
        System.out.println(right);
        int result = Integer.MAX_VALUE;
        for (int i = 0; i < array.length; i++) {
            left += ((array[i] == 'b') ? 1 : 0);
            right -= ((array[i] == 'a') ? 1 : 0);
            result = Math.min(result, left + right);
        }
        System.out.println(left);
        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int result = solution.minimumDeletions2("ba");
        System.out.println("result: " + result);
    }
}
