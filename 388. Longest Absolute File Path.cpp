class Solution {
public:
    int lengthLongestPath(string input) {
        // preparation
        int sfMaxLen = 0;
        input.append(1, '\n');
        
        // one time pass
        int start = 0;
        vector<string> pathElements;
        while (start < input.size()) {// each path element
            // compute number of tabs and remove path elements
            int cTabs = 0;
            while (input[start] == '\t') {
                cTabs++;
                start++;
            }
            pathElements.resize(cTabs);
            
            // directory or file
            int posNewLine = input.find('\n', start);
            string theElement = input.substr(start, posNewLine - start);
            if (theElement.find('.') != string::npos) {// file
                int pathLen = 0;
                for (int i = 0; i < pathElements.size(); i++) {
                    pathLen += pathElements[i].size() + 1;
                }
                pathLen += theElement.size();
                if (pathLen > sfMaxLen) sfMaxLen = pathLen;
            }
            else {// directory
                pathElements.push_back(theElement);
            }
            
            // update for the next iteration
            start = posNewLine + 1;
        }
        
        // return
        return sfMaxLen;
    }
};
