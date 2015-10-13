//
//  main.cpp
//  Merge_k_Sorted_Lists
//
//  Created by 李佳 on 15/10/12.
//  Copyright © 2015年 LiJia. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*Definition for singly-linked list. */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.size() == 1)
        {
            return lists[0];
        }
        ListNode* first = lists[0];
        ListNode* tmp = NULL;
        for (int i = 1; i < lists.size(); ++i)
        {
            ListNode* last = lists[i];
            tmp = mergeTwoList(first, last);
            first = tmp;
        }
        return tmp;
    }
    
    ListNode* mergeTwoList(ListNode* first, ListNode* last)
    {
        ListNode* result = NULL;
        ListNode* resultHead = NULL;
        if (first->val < last->val)
        {
            result = first;
            first = first->next;
        }
        else if (first->val > last->val)
        {
            result = last;
            last = last->next;
        }
        else
        {
            result = first;
            first = first->next;
            last = last->next;
        }
        resultHead = result;
        
        while (first && last)
        {
            if (first->val < last->val)
            {
                result->next = first;
                first = first->next;
            }
            else if (first->val > last->val)
            {
                result->next = last;
                last = last->next;
            }
            else
            {
                result->next = first;
                first = first->next;
                last = last->next;
            }
            result = result->next;
        }
        
        
        if (first)
        {
            result->next = first;
        }
        if (last)
        {
            result->next = last;
        }
        return resultHead;
    }
};

void printList(ListNode* list)
{
    while (list)
    {
        printf("%d ", list->val);
        list = list->next;
    }
    printf("\n");
}

ListNode* bulidLists(vector<int> nums)
{
    ListNode* head = new ListNode(nums[0]);
    ListNode* result = head;
    for (int i = 1; i < nums.size(); ++i)
    {
        ListNode* node = new ListNode(nums[i]);
        head->next = node;
        head = head->next;
    }
    return result;
}



int main(int argc, const char * argv[])
{
    ListNode* one = bulidLists({1,2,3,6});
    ListNode* two = bulidLists({4,5,7});
    ListNode* three = bulidLists({8,9,10,12});
    ListNode* four = bulidLists({11,13,20,100});
    
    Solution* pSol = new Solution;
    vector<ListNode*>lists = {one, two, three, four};
    ListNode* result = pSol->mergeKLists(lists);
    printList(result);
    delete pSol;
    return 0;
}
