class Solution {
public:
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
       sort(boxTypes.begin(), boxTypes.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] > b[1];
             });


        int totalvalue=0;
        for(auto &box : boxTypes){
            int boxes = box[0];
            int units = box[1];

            if(truckSize >= boxes){
                totalvalue += boxes*units;
                truckSize = truckSize-boxes;
            }
            else{
                totalvalue+= truckSize*units;
                break;
            }
        }    
        return totalvalue; 
    }
};