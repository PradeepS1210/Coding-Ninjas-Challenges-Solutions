// Companies asking this question: HSBC, Wipro

/****************************************************************
Problem statement
You are given two sorted linked lists of length ‘N1’ and ‘N2’ respectively. Your task is to create a linked list with common elements such that all common odd elements are before common even elements.

Note: The relative order inside both the even and odd groups should remain as it was in the input.

You just need to return the head of the new linked list formed, don't print the elements.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 5
0 <= N <= 5 * 10 ^ 6
1 <= nodeVal[i] <= 10 ^ 9

Time Limit: 1 sec.
Sample Input 1:
2
1 2 3 4 5 7 8 -1
2 4 4 7 8 10 -1
1 2 7 10 20 23 -1
2 7 23 -1
Sample Output 1:
7 2 4 8
7 23 2
Explanation of Sample Input 1:
In the first test case, the common elements are {2, 4, 7, 8 }. So the elements of the new linked list is 7 -> 2 -> 4 -> 8 -> NULL as odd will come before even maintaining the relative order.

In the second test case, the common elements are {2, 7, 23 }. So the elements of the new linked list is 7 -> 23 -> 2 -> NULL as odd will come before even maintaining the relative order..
Sample Input 2:
2
10 11 12 -1
1 2 8 9 10 12 12 -1
1 2 3 3 4 -1
1 2 3 4 -1
Sample Output 2:
10 12
1 3 2  4
*****************************************************************/

#include <bits/stdc++.h> 
/****************************************************************
Following is the Linked list node structure already written

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode(T data)
    { 
        this->data = data;
        next = NULL;
    }
};
*****************************************************************/

LinkedListNode<int>* commonOddEven(LinkedListNode<int> *head1, LinkedListNode<int> *head2)
{
    if(head1 == NULL || head2 == NULL)
    {
        return NULL;
    }

    LinkedListNode<int> * oddHead = NULL, * oddTail = NULL;

    LinkedListNode<int> * evenHead = NULL, * evenTail = NULL;

    while(head1 && head2)
    {
        if((head1 -> data) < (head2 -> data))
        {
            head1 = head1 -> next;
        }
        else if((head1 -> data) > (head2 -> data))
        {
            head2 = head2 ->next;
        }
        else
        {
            if((head1 -> data) % 2 == 0)
            {
                if(evenTail == NULL)
                {
                    evenHead = new LinkedListNode<int>(head1 -> data);

                    evenTail = evenHead;
                }
                else
                {
                    evenTail -> next = new LinkedListNode<int>(head1 -> data);

                    evenTail = evenTail ->next;
                }
            }
            else
            {
                if(oddTail == NULL)
                {
                    oddHead = new LinkedListNode<int>(head1 -> data);

                    oddTail = oddHead;
                }
                else
                {
                    oddTail -> next = new LinkedListNode<int>(head1 -> data);
                    
                    oddTail = oddTail ->next;
                }
            }

            head1 = head1 ->next;
            head2 = head2 -> next;
        }
    }

    if(oddHead == NULL)
    {
        return evenHead;
    }

    oddTail -> next = evenHead;

    return oddHead;

}
