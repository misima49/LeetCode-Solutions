/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    void spiralOrder(vector<vector<int> >& matrix, ListNode* head)
    {
        int m = matrix.size(), n = matrix[0].size();

        if (m == 0)
            return;

        vector<vector<bool> > seen(m, vector<bool>(n, false));
        int dr[] = { 0, 1, 0, -1 };
        int dc[] = { 1, 0, -1, 0 };

        int x = 0, y = 0, di = 0;

        for (int i = 0; i < m * n; i++) {
            if(head) {
                matrix[x][y] = head->val;
                head = head->next;
            } else {
                matrix[x][y] = -1;
            }
            seen[x][y] = true;
            int newX = x + dr[di];
            int newY = y + dc[di];

            if (0 <= newX && newX < m && 0 <= newY && newY < n
                && !seen[newX][newY]) {
                x = newX;
                y = newY;
            }
            else {
                di = (di + 1) % 4;
                x += dr[di];
                y += dc[di];
            }
        }
    }
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n));
        spiralOrder(ans, head);
        return ans;
    }
};