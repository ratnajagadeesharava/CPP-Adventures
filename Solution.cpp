#include "Solution.hpp"
#include <algorithm>
#include <stack>
#include <unordered_map>

namespace CPP_adventures {

    ListNode* Solution::sortList(ListNode* head) {
        if (head == NULL) return head;

        if (head->next == NULL)return head;
        return divideAndConquer(head);
    }

    ListNode* Solution::divideAndConquer(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* mid = findMid(head);
        if (mid == nullptr)return head;

        ListNode* secondPart = mid->next;
        mid->next = nullptr;
        secondPart = divideAndConquer(secondPart);
        head = divideAndConquer(head);
        
        return MergeList(head,secondPart);
    }
    ListNode* Solution::MergeList(ListNode* head, ListNode* mid) {
        ListNode* temp = new ListNode();
        ListNode* result = temp;
        if (head == nullptr)return mid;
        if (mid == nullptr)return head;

        while (head != nullptr && mid != nullptr) {
            if (head->val <= mid->val) {
                temp->next = head;
                head = head->next;
            }
            else {
                temp->next = mid;
                mid = mid->next;
            }

            temp = temp->next;
        }
        if (head != nullptr) {
            temp->next = head;
        }
        if(mid!=nullptr){
            temp->next = mid;
        }
        return result->next;
    }

    ListNode* Solution::findMid(ListNode* head) {
        if (head == nullptr)return head;
        ListNode* fast = head;
        while (head != nullptr && fast != nullptr && fast->next !=nullptr) {
            
            fast = fast->next->next;
            if (fast != nullptr&& fast->next != nullptr) {
                head = head->next;
            }
        }
        return head;
    }

    int Solution::findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)return 0;
        if (n == 2) return nums[0] > nums[1] ? 0 : 1;
        return peakElement(nums, 0, n, n);
    }

    int Solution::peakElement(vector<int>&nums, int low, int high, int n) {
        if (low == high) {
            return low;
        }
        
        int mid = (low + high) / 2;
		if (mid == 0)return 0;
		if (mid == n - 1)return n - 1;
        if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
            return mid;
        }
        if (nums[mid] < nums[mid + 1])return peakElement(nums, mid + 1, high, n);
        else return peakElement(nums, low, mid, n);
    }
    /*int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4)return 0;
        sort(nums.begin(), nums.end());

        return min(k, l);
    }*/
    int maxProduct(vector<int>& nums) {
		vector<vector<int>> dp;
		int n = nums.size();
		
		int max_prod = INT_MIN;
		for (int i = 0; i < n; i++)
        {
			dp.push_back(vector<int>());
            int prod = 1;
            for (int j = i; j < n; j++) {
				prod *= nums[j];
				dp[i].push_back(prod);
				max_prod = max(max_prod, prod);
            }
		}
        return max_prod;
    }

    void sortColors(vector<int>& nums) {
		int n = nums.size();
		int front = 0;
        int back = n - 1;
        while (front < back) {
            if (nums[front] == 0) {
				front++;
				continue;
			}
            else if (nums[back] == 2) {
                while (back < front) {

                }
            }
            
        }
    }

    static int hamDistance(string s1, string s2, int m) {
        int count = 0;
        for (int i = 0; i < m; i++) {
            if (s1[i] != s2[i])count++;
        }
        return count;
    }
    static void hammingDistance() {
        string s1, s2;
        int n, m;
        cin >> n;
        cin >> m;
        cin >> s1;
        cin >> s2;
        int count = m;

        int k = n - m + 1;
        for (int i = 0; i < k; i++) {
            count = min(count, hamDistance(s1.substr(i, m), s2,m));
        }
        cout << (count) << endl;
    }

    int longestCommonSubsequence(string text1, string text2) 
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = (i > 0 && j > 0) ? dp[i - 1][j - 1] + 1 : 1;
                } else {
                    dp[i][j] = max((i > 0) ? dp[i - 1][j] : 0, (j > 0) ? dp[i][j - 1] : 0);
                }
            }
        }
        return dp[n - 1][m - 1];
    }

    int Solution::maxSumSubArray(vector<int>& nums)
    {
		
        
        
            int n = nums.size();
            if (n == 1) return nums[0];
            int maxSum = INT_MIN;
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += nums[i];
                maxSum = max(maxSum, sum);
                //if sum is negative then reset it because it will not be useful as it is from start and making the next max sum smaller
                sum = max(sum, 0);
            }
            return maxSum;
    }
    static int redundantArray(int n, vector<int> nums) {
        int cost = n * n;
        for (int i = 1; i <= n; i++) {
            int lc = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) {
                    continue;
                }
                else {
                    lc += i;
                }
            }
            cost = min(cost, lc);
        }
        return cost;
    }

    static void solve() {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            v.push_back(k);
        }
        cout << redundantArray(n, v) << endl;
    }

    int numberOfSubmatrices(vector<vector<char>>& grid)
    {
        vector<vector<vector<int>>> dp;
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            dp.push_back(vector<vector<int>>());
            for (int j = 0; j < n; j++) {
                dp[i].push_back({0,0});
            }
        }
        if(grid[0][0]=='X')
		{
			dp[0][0][0] = 1;
		}
        else if (grid[0][0] == 'Y')
        {
            dp[0][0][1] = 1;
        }

        for (int i = 1; i < m; i++) {
       
            if (grid[i][0] == 'X') {
                dp[i][0][0] = 1+dp[i-1][0][0];
                dp[i][0][1] = dp[i-1][0][1];
            }
            else if (grid[i][0] == 'Y') {
				dp[i][0][1] = 1+dp[i-1][0][1];
                dp[i][0][0] = dp[i-1][0][0];
			}
            else {
                				dp[i][0][0] = dp[i-1][0][0];
				dp[i][0][1] = dp[i-1][0][1];
            }
            if(dp[i][0][0]==dp[i][0][1] && dp[i][0][0]!=0)
			{
				count++;
			}
        }
        for (int i = 1; i < n; i++) {
			if (grid[0][i] == 'X') {
				dp[0][i][0] = 1+dp[0][i-1][0];
                dp[0][i][1] = dp[0][i - 1][1];
			}
			else if (grid[0][i] == 'Y') {
				dp[0][i][1] = 1+dp[0][i-1][1];
                dp[0][i][0] = dp[0][i - 1][0];
			}
            else {
                				dp[0][i][0] = dp[0][i-1][0];
				dp[0][i][1] = dp[0][i-1][1];
            }
            if(dp[0][i][0]==dp[0][i][1] && dp[0][i][1] !=0)
                {
                count++;
				}
		}
        /*for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "(" << dp[i][j][0] << "," << dp[i][j][1] << ") " << " ";
            }
            cout << endl;
        }*/
        for(int i=1;i<m;i++)
		{
			for(int j=1;j<n;j++)
			{
				if(grid[i][j]=='X')
				{
					dp[i][j][0] = 1+dp[i-1][j][0]+dp[i][j-1][0]-dp[i-1][j-1][0];
                    dp[i][j][1] = dp[i - 1][j][1] + dp[i][j - 1][1] - dp[i - 1][j - 1][1];
				}
				else if(grid[i][j]=='Y')
				{
					dp[i][j][1] = 1+dp[i-1][j][1]+dp[i][j-1][1]-dp[i-1][j-1][1];
                    dp[i][j][0] = dp[i - 1][j][0] + dp[i][j - 1][0] - dp[i - 1][j - 1][0];
				}
                else {
                    dp[i][j][0] = dp[i - 1][j][0] + dp[i][j - 1][0] - dp[i - 1][j - 1][0];
					dp[i][j][1] = dp[i - 1][j][1] + dp[i][j - 1][1] - dp[i - 1][j - 1][1];
                }
                if(dp[i][j][0]==dp[i][j][1] && dp[i][j][0] !=0)
				{
					count++;
				}
				
			}
		}

        /*for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<"(" << dp[i][j][0]<<","<<dp[i][j][1] << ") " << " ";
			}
			cout<<endl;
		}*/
        return count;
    }
    int numberOfSubmatrices1(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i = 1, cxh = 0, cyh = 0, cxv = 0, cyv = 0, count = 0, cx = 0, cy = 0;   
        if(grid[0][0]=='X')
        {
            cxh++;
            cx = 1;
            cxv = 1;
        }
		else if(grid[0][0]=='Y')
        {
			cyh++;
			cy = 1;
			cyv = 1;
		}
        
        while (i < m && i < n) {
            int cx1 = 0, cy1 = 0;
            int cxh1 = 0, cyh1 = 0;
            int cxv1 = 0, cyv1 = 0;
            if (grid[i][0] == 'X') {
                cxv++;
                cx1++;
                cxv1++;
            }
            else if (grid[i][0] == 'Y') {
                cyv++;
                cy1++;
                cyv1++;
            }
            
            if (grid[0][i] == 'X') {
                cxh++;
                cx1++;
                cxh1++;
            }
            else if (grid[0][i] == 'Y') {
                cyh++;
                cy1++;
                cyh1++;
            }
            count = (cxh == cyh) && (cxh != 0) ? count + 1 : count;
            count = (cxv == cyv) && (cxv != 0) ? count + 1 : count;
            
            for (int k = 1; k < i; k++) {
                if (grid[k][i] == 'X')
                    cxh1++;
                else if (grid[k][i] == 'Y')
                    cyh1++;
            }
            
            for (int k = 1; k < i; k++) {
                if (grid[i][k] == 'X')
                    cxv1++;
                else if (grid[i][k] == 'Y')
                    cyv1++;
            }
            if(i!=1)
            count = ((cxh1 + cx == cy + cyv1) && (cxh1 + cx != 0)) || ((cyv1 + cy == cxv1 + cx) && (cxv1 + cx != 0)) ? count + 1 : count;
            if (grid[i][i] == 'X')
                cx++;
            else if (grid[i][i] == 'Y')
                cy++;
            
            cx = cx + cxh1+ cxv1;
            cy = cy + cyh1+cyv1;
            count = (cx == cy) && (cx != 0) ? count + 1 : count;
            i++;
        }
        if (m == n)return count;
        if (m > n) {
            
             if(grid[i][0]=='X')
			{
				cxv++;
				cx++;
			}
			else if(grid[i][0]=='Y')
			{
				cyv++;
				cy++;
			}
             count = (cxv == cyv) && (cxv != 0) ? count + 1 : count;
            
            
            for (int j=1; j < n; j++) {
                if (grid[i][j] == 'X') {
                    					cx++;

				}
                else if (grid[i][j] == 'Y') {
                    cy++;
                }
            }
        }
        else {
            
             if (grid[0][i] == 'X')
            {
                cxh++;
                cx++;
            }
            else if (grid[0][i] == 'Y')
			{
				cyh++;
                cy++;
			}
             count = (cxh == cyh) && (cxh != 0) ? count + 1 : count;
            for (int j = 1; j < m; j++) {
                if (grid[j][i] == 'X') {
                    cx++;
                }
                else if (grid[j][i] == 'Y') {
                    cy++;
                }
            }
        }

        count = (cx == cy)&&(cx!=0) ? count + 1 : count;
        return count;
    }

    bool get(long long i) {
		if(i>= 327937
            )
		return true;
        return false;
	}

    long long find(long long min, long long max) {
        if (max == -1) {
            cout << min << endl;
            if (get(min)) {
                 
                return find(min / 2, min);
            }
            return find(min * 2, -1);
        }
        else {
            cout << min << " " << max << endl;
            if (min >= max)return max;
            long long mid = (min + max) / 2;

            if (get(mid)) {
                return find(min, mid);
            }
            else {
                return find(mid+1, max);
            }
        }
    }
    long long firstOne()
    {
        // Write your code here.
      
        if (get(0))return 0;
        return find(1, -1);


    }
    int recyclePens(int n, int r, int k, int c) {
        if (n == 0) {
            return 0;
        }
        if (n * k + r < c)return 0;
        // Write your code here.
        if (r >= c) {
            int f = r / c;
            if (f >= n)return n;
            else {
                cout<<f<<endl;
                return f + recyclePens(n - f, r - (f * c), k, c);
            }
        }
        else {
            int s = c-r;
            s = s / k;
            if(s*k<c-r)
            s++;
            //cout << s << endl;
            return recyclePens(n - s, r + (s * k), k, c);
        }
    }
    int checkreverse(stack<char> &st, int x, int y, bool ab) {
        char prev = st.top();
        st.pop();
        int count = 0;
        while (!st.empty()) {
            char t = st.top();
            if (ab) {
                if (t == 'b' && prev == 'a') {
                    count += y;
                    st.pop();
                }

            }
            else {
                if (t == 'a' && prev == 'b') {
                    count += x;
                    st.pop();
                }
            }
            if(!st.empty()){
                prev = st.top();
                st.pop();
            }
        }
        return count;
    }
    int maximumGain(string s, int x, int y) {
        int l = s.size();
        if (l <= 1)return 0;
        bool ab = x > y;
        stack<char> st;
        int count = 0;
        for (int i = 0; i < l; i++) {
            if (s[i] == 'a' || s[i] == 'b') {
                if (!st.empty()) {
                    char t = st.top();
                    if (ab) {
                        if (s[i] == 'b' && t == 'a') {
                            st.pop();
                            count += x;
                        }
                        else
                            st.push(s[i]);
                    }
                    else {
                        if (s[i] == 'a' && t == 'b') {
                            st.pop();
                            count += y;
                        }
                        else
                            st.push(s[i]);
                    }
                }
                else {
                    st.push(s[i]);
                }
            }
            else {

                if (!st.empty()) {

                    string s = "";
                    while (!st.empty()) {
                        s += st.top();
                        st.pop();
                    }
                    count += maximumGain(s, x, y);
                }
            }
        }
        if (!st.empty()) {
            string s = "";
            while (!st.empty()) {
                s += st.top();
                st.pop();
            }
            count += maximumGain(s, x, y);
        }
        return count;
    }
    vector<int> survivedRobotsHealths(vector<int>& positions,
        vector<int>& healths, string directions)
    {
        int l = positions.size();
        unordered_map<int, int> umap;
        if (l <= 1) return healths;
        stack<int> st;
        for (int i = 0; i < l; i++)
        {
            umap[positions[i]] = i;
        }
        sort(positions.begin(), positions.end());

        for (int i = 0; i < l; i++)
        {
            if (st.empty())
            {
                st.push(positions[i]);
            }
            else
            {
                int t = st.top();
                char direction = directions[umap[t]];
                int p1 = umap[t];
                int p2 = umap[positions[i]];
                if (direction == 'R')
                {
                    char currentDirection = directions[p2];
                    if (currentDirection == 'L')
                    {
                        int h1 = healths[p1];
                        int h2 = healths[p2];
                        if (h1 == h2)
                        {
                            st.pop();
                        }
                        else if (h1 > h2)
                        {
                            healths[p1]--;
                        }
                        else
                        {
                            healths[p2]--;
                            st.pop();
                            if(!st.empty()){
                                t = st.top();
                                p1 = umap[t];
                                h2 = healths[p2];
                                h1 = healths[p1];
                                direction = directions[p1];
                                bool flag = false;
                                while (direction == 'R' && !st.empty()) {
                                    if (h1 == h2) {
                                        st.pop();
                                        flag = true;
                                        break;
                                    }
                                    else if (h1 > h2) {
                                        healths[p1]--;
                                        flag = true;
                                        break;
                                    }
                                    else {
                                        st.pop();
                                        if (!st.empty())
                                        {
                                            
                                            t = st.top();
                                            p1 = umap[t];
                                            h1 = healths[p1];
                                            direction = directions[p1];
                                        }
                                        h2--;

                                        healths[p2]--;
                                    }
                                }
                                if (!flag)
                                    st.push(positions[i]);
                            }
                    else
                    {
                        st.push(positions[i]);
                    }
                        }
                    }
                    else
                    {
                        st.push(positions[i]);
                    }
                }
                else
                {
                    st.push(positions[i]);
                }
            }
        }
        vector<int> finalHealth;
        vector<int> s;
        while (!st.empty())
        {
            s.push_back(umap[st.top()]);
            st.pop();
        }
        sort(s.begin(), s.end());
        for (int i : s) {
            finalHealth.push_back(healths[i]);
        }
        return finalHealth;
    }
  
    void Solution::callMethod()
    {
        //[1,40][10,11]"RL"
        vector<int> positions = { 11,44,16 };
        vector<int> healths = { 1,20,17 };
        string directions = "RLR";
        vector<int> result = survivedRobotsHealths(positions, healths, directions);
        for (int i : result) {
			cout << i << " ";
		}
        
    }
}