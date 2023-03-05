package LeetCodeMSJD0502;

public class Solution {
    public String printBin(double num) {
        StringBuilder builder = new StringBuilder();
        while (num != 0 && builder.length() <= 33) {
            double cur = num * 2;
            if (cur >= 1) {
                builder.append("1");
                num = cur - 1;
            } else {
                builder.append("0");
                num = cur;
            }
        }
        if (builder.length() > 32) {
            return "ERROR";
        }
        builder.insert(0, "0.");
        return builder.toString();
    }
}
