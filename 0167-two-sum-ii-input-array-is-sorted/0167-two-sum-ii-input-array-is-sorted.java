class Solution {
    public int[] twoSum(int[] numbers, int target) {
                int left = 0;
        int right = numbers.length - 1;
        int tmp;
        while (left < right)
        {
            if (numbers[left] + numbers[right] == target) break;
            tmp = target - numbers[right];
            while (numbers[left] < tmp) left++;
            if (numbers[left] + numbers[right] == target) break;
            tmp = target - numbers[left];
            while (numbers[right] > tmp) right--;
        }
        return new int[]{left + 1, right + 1};
    }
}