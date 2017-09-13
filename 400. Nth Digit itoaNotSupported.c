    int findNthDigit(int n) {
        char buffer[11] = {};
        int num = 1;
        char digit = 0;
        int pos = 0;
        while (0 < n)
        {
            if (buffer[pos] == '\0')
                itoa(num++, buffer, 10), pos = 0;
            digit = buffer[pos++];
            n--;
        }
        return digit - '0';
    }
