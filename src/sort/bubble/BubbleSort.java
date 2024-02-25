package sort.bubble;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class BubbleSort {
    /**
     * 冒泡排序算法
     * @param list 待排序数组
     * @return 已排序数组
     */
    public static List<Integer> sort(List<Integer> list) {
        Integer[] array = new Integer[list.size()];
        array = list.toArray(new Integer[0]);
        for (int j = 0; j < list.size(); j++) {
            for (int i = 0; i < list.size() - 1; i++) {
                if (array[i] > array[i + 1]) {
                    int temp = array[i + 1];
                    array[i + 1] = array[i];
                    array[i] = temp;
                }
            }
        }
        return Arrays.asList(array);
    }

    public static void main(String[] args) {
        List<Integer> sorted = BubbleSort.sort(Arrays.asList(7, 9, 2, 4, 1, 3));
        System.out.println(sorted);
    }
}
