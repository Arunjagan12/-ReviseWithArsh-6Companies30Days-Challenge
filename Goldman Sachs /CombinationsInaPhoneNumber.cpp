class Solution {
public:
void backtrack(const vector<string>& mapping, const string& digits, int index, string& current, vector<string>& result) {
    // If the current combination is of the required length, add it to the result
    if (index == digits.length()) {
        result.push_back(current);
        return;
    }

    // Get the letters corresponding to the current digit
    string letters = mapping[digits[index] - '0'];

    // Iterate through each letter and recursively generate combinations
    for (char letter : letters) {
        // Append the current letter to the combination
        current.push_back(letter);
        // Recur for the next digit
        backtrack(mapping, digits, index + 1, current, result);
        // Backtrack: remove the last letter to try the next one
        current.pop_back();
    }
}

    vector<string> letterCombinations(string digits) {
          if (digits.empty()) return {};

    // Mapping of digits to letters
    vector<string> mapping = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> result;
    string current = "";

    backtrack(mapping, digits, 0, current, result);

    return result;
    }
};
