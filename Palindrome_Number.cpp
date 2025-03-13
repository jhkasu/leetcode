class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers or numbers ending in 0 (except 0 itself) cannot be palindromes
        // Example: -121 is negative, 10 becomes 01 when reversed, so not a palindrome
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        // 0 is a palindrome by itself, so return true
        if (x == 0) return true;

        // Initialize variable to store the reversed number
        int reversed = 0;

        // Reverse half of the number by looping while x is greater than reversed
        // This reduces the number of operations by checking only half the digits
        while (x > reversed) {
            // Extract the last digit of x (e.g., 123 -> 3) using modulo 10
            reversed = reversed * 10 + x % 10;

            // Remove the last digit from x (e.g., 123 -> 12) by integer division by 10
            x /= 10;
        }

        // Check if the number is a palindrome
        // 1. x == reversed: For even digit numbers (e.g., 1221 -> x=12, reversed=12)
        // 2. x == reversed / 10: For odd digit numbers, ignore the middle digit (e.g., 12321 -> x=12, reversed=123, 123/10=12)
        return x == reversed || x == reversed / 10;
    }
};
