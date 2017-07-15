class Solution {// KMP algorithm
public:
	int strStr(string haystack, string needle) {
		int lenHay = haystack.size(), lenP = needle.size();
		if (lenP == 0) return 0;
		if (lenHay == 0) return -1;
		vector<int> next(lenP);
		next[0] = -1;
		for (int bottom = 1, top = 0; bottom < lenP; bottom++)
		{
			next[bottom] = top;
			if (needle[bottom] == needle[top]) top++;
			else
			{
				while (top != -1 && needle[bottom] != needle[top])
					top = next[top];
				top++;
			}
		}
		for (int i = 0; i < lenP; i++) printf(" %d", next[i]);
		// find the pattern in the haystack
		for (int top = 0, bottom = 0; top < lenHay;)
		{
			if (haystack[top] == needle[bottom])
			{
				top++, bottom++;
				if (lenP <= bottom) return top - lenP;
			}
			else if (next[bottom] == -1) top++;
			else bottom = next[bottom];
		}
		return -1;
	}
};
