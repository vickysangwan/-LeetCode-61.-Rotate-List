/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void addValue(ListNode* head,vector<int> &values)
    {
        while(head!=NULL)
        {
            values.push_back(head->val);
            head=head->next;
        }
    }
    void rotate(vector<int> &values,int low,int high)
    {
        while(low<=high)
        {
            int temp=values[low];
            values[low]=values[high];
            values[high]=temp;
            high--;
            low++;
        }
    }
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head==NULL)
        {
            return NULL;
        }
        else if(head->next==NULL)
        {
            return head;
        }
        else
        {
        vector<int> values;
        addValue(head,values);
        if(k<values.size())
        {
            rotate(values,0,values.size()-1);
            rotate(values,0,k-1);
            rotate(values,k,values.size()-1);
        }
        else if(k>values.size())
        {
            rotate(values,0,values.size()-1);
            int d=k%values.size();
            rotate(values,0,d-1);
            rotate(values,d,values.size()-1);
        }
        ListNode* root=NULL;
        for(int i=0;i<values.size();i++)
        {
            ListNode* temp=new ListNode();
            temp->val=values[i];
            temp->next=NULL;
            if(root==NULL)
            {
                root=temp;
            }
            else
            {
                ListNode* ptr=root;
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=temp;
            }
        }
        return root;
        }
    }
};
