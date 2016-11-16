class Solution {
private:
    inline string digit_to_str (int digit) {
        switch (digit) {
            case 1: return " One";
            case 2: return " Two";
            case 3: return " Three";
            case 4: return " Four";
            case 5: return " Five";
            case 6: return " Six";
            case 7: return " Seven";
            case 8: return " Eight";
            case 9: return " Nine";
            default: printf("error in digit_to_str"); return " !!!!!";
        }
    }
    inline string two_digits_to_str (int twoDigits) {
        int higherDigit = twoDigits / 10;
        int lowerDigit = twoDigits % 10;
        // 1 - 9
        if (twoDigits < 10) return this->digit_to_str(lowerDigit);
        // 10 - 19
        if (twoDigits < 20) {
            switch (twoDigits) {
                case 10: return " Ten";
                case 11: return " Eleven";
                case 12: return " Twelve";
                case 13: return " Thirteen";
                case 14: return " Fourteen";
                case 15: return " Fifteen";
                case 16: return " Sixteen";
                case 17: return " Seventeen";
                case 18: return " Eighteen";
                case 19: return " Nineteen";
                default: printf("error in 10-19 switch");
            }
        }
        // 20 - 99
        string leftPart;
        switch (higherDigit) {
            case 2: leftPart = " Twenty"; break;
            case 3: leftPart = " Thirty"; break;
            case 4: leftPart = " Forty"; break;
            case 5: leftPart = " Fifty"; break;
            case 6: leftPart = " Sixty"; break;
            case 7: leftPart = " Seventy"; break;
            case 8: leftPart = " Eighty"; break;
            case 9: leftPart = " Ninety"; break;
            default: printf("error in 20-99 switch");
        }
        if (lowerDigit > 0) return leftPart + this->digit_to_str(lowerDigit);
        else return leftPart;
    }
public:
    string numberToWords (int num) {
        // edge case
        if (num == 0) return "Zero";
        
        //
        // response construction
        //
        
        // phase strings
        string phase[4]; // phase 0: Billion; phase 1: Million ...
        for (int i = 3; i >= 0; i--) { // phase i
            // two lower digits
            int theTwoDigits = num % 100;
            num /= 100;
            string rightPart = theTwoDigits == 0? "": this->two_digits_to_str(theTwoDigits);
            // the only one "Hundred" digit
            int theOneDigit = num % 10;
            num /= 10;
            string leftPart = theOneDigit == 0? "": this->digit_to_str(theOneDigit) + " Hundred";
            // combine them and save
            phase[i] = leftPart + rightPart;
        }
        
        // combine phase strings
        string res = "";
        if (phase[0] != "") res += phase[0] + " Billion";
        if (phase[1] != "") res += phase[1] + " Million";
        if (phase[2] != "") res += phase[2] + " Thousand";
        if (phase[3] != "") res += phase[3];
        
        // show it
        return res.substr(1, res.size()-1);
    }
};
