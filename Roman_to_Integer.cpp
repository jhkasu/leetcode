class Solution {
public:
    int romanToInt(string s) {
        // Create an array to map Roman numeral characters to their integer values
        // Using an array of size 26 (for letters A-Z), where each index corresponds to a letter
        // Example: 'I' - 'A' = 8, so arr[8] = 1 (value of 'I')
        int arr[26];

        // Assign values to Roman numeral characters
        arr['I' - 'A'] = 1;   // 'I' = 1
        arr['V' - 'A'] = 5;   // 'V' = 5
        arr['X' - 'A'] = 10;  // 'X' = 10
        arr['L' - 'A'] = 50;  // 'L' = 50
        arr['C' - 'A'] = 100; // 'C' = 100
        arr['D' - 'A'] = 500; // 'D' = 500
        arr['M' - 'A'] = 1000;// 'M' = 1000

        // Initialize the result (final integer value)
        int res = 0;

        // Initialize prev to track the value of the previous numeral
        // Start with 0 since we process from right to left
        int prev = 0;

        // Loop through the string from right to left (reverse order)
        // This helps determine whether to add or subtract each numeral
        for (int i = s.length() - 1; i >= 0; i--) {
            // Get the integer value of the current Roman numeral
            // s[i] - 'A' maps the character to its index in arr
            int curr = arr[s[i] - 'A'];

            // If the current value is greater than or equal to the previous value,
            // add it to the result (e.g., in "VI" = 5 + 1, V > I)
            if (curr >= prev) {
                res += curr;
            }
            // If the current value is less than the previous value,
            // subtract it (e.g., in "IV" = 5 - 1, I < V)
            else {
                res -= curr;
            }

            // Update prev to the current value for the next iteration
            prev = curr;
        }

        // Return the final integer value
        return res;
    }
};
