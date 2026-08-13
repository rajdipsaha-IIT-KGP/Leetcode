class Solution {
public:
   struct Node {
        int pre = 0; 
        int suf = 0;
        int maxLen = 0;
        char leftChar = 0;
        char rightChar = 0;

        Node() {}
        Node(int pre, int suf, int maxLen, char leftChar, char rightChar) {
            this->pre = pre;
            this->suf = suf;
            this->maxLen = maxLen;
            this->leftChar = leftChar;
            this->rightChar = rightChar;
        }
    };
    int n;
    vector<Node>segmentTree;
    
    Node merge(Node &lefChild,Node &rightChild,int leftLen,int rightLen){
        Node res;

        res.leftChar = lefChild.leftChar;
        res.rightChar = rightChild.rightChar;

        res.pre = lefChild.pre;
        if(lefChild.pre == leftLen && lefChild.rightChar == rightChild.leftChar){
            res.pre = lefChild.pre + rightChild.pre;
        }

        res.suf = rightChild.suf;
        if(rightChild.suf == rightLen && lefChild.rightChar == rightChild.leftChar){
            res.suf = lefChild.suf + rightChild.suf;
        }

        res.maxLen = max(lefChild.maxLen,rightChild.maxLen);

        if(lefChild.rightChar == rightChild.leftChar){
            res.maxLen = max(res.maxLen,lefChild.suf+rightChild.pre);
        }
        return res;
    }

    void buildSegmentTree(string &s,int l,int r,int i){
        if(l == r){
            segmentTree[i] = {1,1,1,s[l],s[l]};
            return;
        }
        int mid = l + (r - l) / 2;

        buildSegmentTree(s,l,mid,2 * i + 1);
        buildSegmentTree(s,mid+1,r,2 * i + 2);

        segmentTree[i] = merge(segmentTree[2*i+1],segmentTree[2*i+2],mid - l + 1,r - mid );

    }

    void updateSegmentTree(string &s,int l,int r,int i,int pos,char ch){
        if(l == r){
            segmentTree[i] = {1,1,1,ch,ch};
            return;
        }
        int mid = l + (r - l) / 2;
        if(pos <= mid){
            updateSegmentTree(s,l,mid,2*i+1,pos,ch);
        } else {
            updateSegmentTree(s,mid + 1,r,2*i+2,pos,ch);
        }
        segmentTree[i] = merge(segmentTree[2*i+1],segmentTree[2*i+2],mid-l+1,r-mid);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
         n = s.size();
         segmentTree.resize(4*n,Node());

         buildSegmentTree(s,0,n-1,0);
         vector<int>result;
        
        for(int i = 0 ; i < queryIndices.size() ; i++){
           updateSegmentTree(s,0,n-1,0,queryIndices[i],queryCharacters[i]);
           result.push_back(segmentTree[0].maxLen);
        }
        return result;
    }
};