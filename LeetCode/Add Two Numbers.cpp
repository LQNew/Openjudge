/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//利用了大整数加法的思路，同时构建链表时用的是尾插法，最重要的是要有个标识头结点，不然程序写起来很不舒服！！
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> a;
        vector<int> b;
        while(l1!=NULL){
            a.push_back(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL){
            b.push_back(l2->val);
            l2=l2->next;
        }
        int size_a=a.size();
        int size_b=b.size();
        ListNode* front=new ListNode(0);
        ListNode* res=front;
        //判别哪个是更大的数，位数更高
        if(size_a>size_b){
            for(int i=0;i<size_b;i++) a[i]+=b[i];
            for(int i=0;i<size_a-1;i++){
                a[i+1]+=a[i]/10;
                a[i]=a[i]%10;
                ListNode* p=new ListNode(a[i]);
                res->next=p;
                res=p;
            }
            if(a[size_a-1]>=10){
                a.push_back(a[size_a-1]/10);
                a[size_a-1]=a[size_a-1]%10;
                ListNode* p=new ListNode(a[size_a-1]);
                res->next=p;
                res=p;
                ListNode* p1=new ListNode(a[size_a]);
                res->next=p1;
            }
            else{
                ListNode* p=new ListNode(a[size_a-1]);
                res->next=p;
                res=p;
            }
            res=front->next;
            return res;
        }
        else{
            for(int i=0;i<size_a;i++) b[i]+=a[i];
            for(int i=0;i<size_b-1;i++){
                b[i+1]+=b[i]/10;
                b[i]=b[i]%10;
                ListNode* p=new ListNode(b[i]);
                res->next=p;
                res=p;
            }
            if(b[size_b-1]>=10){
                b.push_back(b[size_b-1]/10);
                b[size_b-1]=b[size_b-1]%10;
                ListNode* p=new ListNode(b[size_b-1]);
                res->next=p;
                res=p;
                ListNode* p1=new ListNode(b[size_b]);
                res->next=p1;
            }
            else{
                ListNode* p=new ListNode(b[size_b-1]);
                res->next=p;
                res=p;
            }
            res=front->next;
            return res;
        }
        }
    }
};
