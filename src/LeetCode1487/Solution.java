package LeetCode1487;

import java.util.HashMap;
import java.util.Map;

public class Solution {
    public String[] getFolderNames(String[] names) {
        Map<String, Integer> dir = new HashMap<>();
        String[] curNames = new String[names.length];
        for (int i = 0; i < names.length; i++) {
            // if (i == 186) {
            //     System.out.println(dir);
            // }
            if (dir.containsKey(names[i])) {
                int freq = dir.get(names[i]);
                dir.put(names[i], freq + 1);
                String currentString = names[i];
                currentString = currentString + "(" + freq + ")";
                while (dir.containsKey(currentString)) {
                    freq = freq + 1;
                    currentString = names[i] + "(" + freq + ")";
                }
                dir.put(currentString, 1);
                curNames[i] = currentString;
            } else {
                dir.put(names[i], 1);
                curNames[i] = names[i];
            }
        }
        System.out.println(dir);
        return curNames;
    }
}
