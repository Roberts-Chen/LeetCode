package LeetCode1599;

public class Solution {
    public int minOperationsMaxProfit(int[] customers, int boardingCost, int runningCost) {
        // 无论当前有多少游客在等待登舱，都在下一次轮转时登舱
        // [0, 0, 0, 0, 0, 1, 3, 4, 5, 0, 0, 1, 3]
        // 求出所有的游客数量
        int customerQuantity = 0;
        for (int i = 0; i < customers.length; i++) {
            customerQuantity += customers[i];
        }
        int result = 0, index = 0, currentCustomers = 0, op = 1;
        int maxProfit = 0, maxProfitOp = 0;
        while (customerQuantity > 0) {
            if (index < customers.length) {
                currentCustomers += customers[index];
            }
            // System.out.println("currentCustomers: " + currentCustomers);
            if (currentCustomers < 4) {
                result += (boardingCost * currentCustomers - runningCost);
                customerQuantity -= currentCustomers;
                currentCustomers -= currentCustomers;
            } else {
                result += (boardingCost * 4 - runningCost);
                currentCustomers -= 4;
                customerQuantity -= 4;
            }
            if (result > maxProfit) {
                maxProfit = result;
                maxProfitOp = op;
            }
            // System.out.println("result: " + result);
            index++;
            op++;
        }
        // System.out.println("maxProfit: " + maxProfit);
        // System.out.println("maxProfitOps: " + maxProfitOp);
        return maxProfitOp == 0 ? -1 : maxProfitOp;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] customers = new int[]{10, 9, 6};
        int boardingCost = 6, runningCost = 4;
        int maxProfitOperations = solution.minOperationsMaxProfit(customers, boardingCost, runningCost);
        System.out.println(maxProfitOperations);
    }
}
