package LeetCode110;

import common.TreeNode;

import java.util.*;

/**
 *
 * <a href="https://leetcode.cn/problems/balanced-binary-tree/description/">110. 平衡二叉树</a>
 */
public class Solution {
    private boolean bal;
    public boolean isBalanced(TreeNode root) {
        bal = true;
        // 递归式的遍历方式，深度优先搜索
        // computeSubtreeHeight(root);
        // 迭代式遍历方式，深度优先搜索
        Deque<TreeNode> stack = new ArrayDeque<>();
        Deque<Integer> subTreeQueue = new ArrayDeque<>();
        stack.push(root);
        while (stack.isEmpty()) {
            TreeNode node = stack.peek();
            if (node.left == null && node.right == null) {
                subTreeQueue.push(0);
            }
            if (node.right != null) {
                stack.push(node.right);
            }
            if (node.left != null) {
                stack.push(node.left);
            }
        }
        return bal;
    }

    public void helper(TreeNode root) {
        Deque<TreeNode> stack = new ArrayDeque<>();
        Deque<Integer> queue = new ArrayDeque<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            if (root.right != null) {
                stack.push(root.right);
            }
            if (root.left != null) {
                stack.push(root.left);
            }
            queue.offer(root.val);
        }
        System.out.println(queue);
    }

    /**
     *
     * @param root
     * @return
     */
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        if (root == null) {
            return res;
        }

        Deque<TreeNode> stack = new LinkedList<TreeNode>();
        TreeNode prev = null;
        while (root != null || !stack.isEmpty()) {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }
            root = stack.pop();
            if (root.right == null || root.right == prev) {
                res.add(root.val);
                prev = root;
                root = null;
            } else {
                stack.push(root);
                root = root.right;
            }
        }
        return res;
    }

    public int computeSubtreeHeight(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (bal) {
            int leftSubtreeHeight = computeSubtreeHeight(root.left);
            int rightSubtreeHeight = computeSubtreeHeight(root.right);
            if (Math.abs(leftSubtreeHeight - rightSubtreeHeight) > 1) {
                bal = false;
            }
            return Math.max(leftSubtreeHeight, rightSubtreeHeight) + 1;
        } else {
            return 0;
        }
    }
}
