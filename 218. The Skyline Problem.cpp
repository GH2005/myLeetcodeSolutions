class Solution {
private:
    struct ListItem {
        int height;
        int buildingIdx;
        int xCoord;
        int beginOrEnd; // 0: end; 1: begin
        ListItem(int h, int idx, int x, int boe) :height(h), buildingIdx(idx), xCoord(x), beginOrEnd(boe) {}
        ListItem() {}
    };
    static bool ListItemCmp(ListItem& item1, ListItem& item2) {
        if (item1.xCoord == item2.xCoord) {
            if (item1.beginOrEnd == item2.beginOrEnd) {
                if (item1.beginOrEnd == 0) return item1.height > item2.height;
                else return item1.height < item2.height;
            }
            return item1.beginOrEnd < item2.beginOrEnd;
        }
        return item1.xCoord < item2.xCoord;
    }
    struct SetItem {
        int buildingIdx;
        int height;
        SetItem(int idx, int h) :buildingIdx(idx), height(h) {}
    };
    struct SetItemCmp {
        bool operator() (const SetItem& item1, const SetItem& item2) const {
    		if (item1.height == item2.height) return item1.buildingIdx < item2.buildingIdx;
    		return item1.height > item2.height;
        }
    };
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        // the response and the edge case
        vector<pair<int, int>> res;
        int cBuildings = buildings.size();
        if (cBuildings == 0) return res;
        res.reserve(cBuildings + 1);
        
        // construct the sorted list
        ListItem list[20000];
        for (int i = 0; i < cBuildings; i++) { // building i
            vector<int>& bd = buildings[i];
            list[2*i] = ListItem(bd[2], i, bd[0], 1);
            list[2*i+1] = ListItem(bd[2], i, bd[1], 0);
        }
        sort(list, list + 2*cBuildings, Solution::ListItemCmp);
        
        // go over the sorted list and fill the response
        set<SetItem, Solution::SetItemCmp> ongoingBuildings;
        // ongoingBuildings.begin() is always the currently highest
        ongoingBuildings.insert(SetItem(-1, 0));    // the ever-present gound-height building
        int lastHeight = 0;
        int listItemIdx = 0;
        while (listItemIdx < 2*cBuildings) {
            // all consecutive ListItems that have the same xCoord
            ListItem& theFirstItem = list[listItemIdx];
            int i = 0;
            for (i = listItemIdx; i < 2*cBuildings; i++) { // ListItem list[i]
                if (list[i].xCoord == theFirstItem.xCoord) {
                    ListItem& theItem = list[i];
                    if (theItem.beginOrEnd == 0) { // end
                        ongoingBuildings.erase(SetItem(theItem.buildingIdx, theItem.height));
                    }
                    else { // begin
                        ongoingBuildings.insert(SetItem(theItem.buildingIdx, theItem.height));
                    }
                }
                else {
                    break;
                }
            }
            listItemIdx = i;
            
            // whether to add a new point in res or not
            if (ongoingBuildings.begin()->height != lastHeight) {
                lastHeight = ongoingBuildings.begin()->height;
                res.push_back(pair<int, int>(theFirstItem.xCoord, lastHeight));
            }
        }
        
        // return
        return res;
    }
};
