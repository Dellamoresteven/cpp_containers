#include <stdlib.h>
#include <string>
#include <vector>
#include <assert.h>
#include <stack>
#include <queue>

using namespace std;
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
int romanToInt(string s){
    int ret = 0;
    for(int i = 0; i < s.length(); ++i) {
        if(s.at(i) == 'I') {
            if(i+1 <= s.length()-1 && (s.at(i+1) == 'V' || s.at(i+1) == 'X')) {
                ret--;
            } else {
                ret++;
            }
        } else if(s.at(i) == 'V') {
            ret += 5;
        } else if(s.at(i) == 'X') {
            if(i+1 <= s.length()-1 && (s.at(i+1) == 'L' || s.at(i+1) == 'C')) {
                ret-=10;
            } else {
                ret+=10;
            }
        } else if(s.at(i) == 'L') {
            ret += 50;
        } else if(s.at(i) == 'C') {
            if(i+1 <= s.length()-1 && (s.at(i+1) == 'D' || s.at(i+1) == 'M')) {
                ret-=100;
            } else {
                ret+=100;
            }
        } else if(s.at(i) == 'D') {
            ret += 500;
        } else if(s.at(i) == 'M') {
            ret += 1000;
        }
    }

    printf("ret: %d\n", ret);
    return ret;
}


struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode * root = new ListNode();
    ListNode * ans = root;
    int carry = 0;
    while(l1 != NULL || l2 != NULL) {
        int l1_val = (l1 != NULL) ? l1->val : 0;
        int l2_val = (l2 != NULL) ? l2->val : 0;
        ans->next = new ListNode((l1_val+l2_val+carry)%10);
        printf("l1 %d   l2 %d == %d\n", l1_val, l2_val, ans->next->val);
        ans = ans->next;
        carry = (l1_val+l2_val+carry)/10;
        l1 = (l1 != NULL) ? l1->next : l1;
        l2 = (l2 != NULL) ? l2->next : l2;
    }
    if(carry == 1) {
        ans->next = new ListNode(1);
    }
    return root->next;
}

int main() {

    ListNode * first = new ListNode(2);
    first->next = new ListNode(4);
    first->next->next = new ListNode(9);
    //first->next->next->next = new ListNode(9);
    //first->next->next->next->next = new ListNode(9);
    //first->next->next->next->next->next = new ListNode(9);
    //first->next->next->next->next->next->next = new ListNode(9);

    ListNode * second = new ListNode(5);
    second->next = new ListNode(6);
    second->next->next = new ListNode(4);
    second->next->next->next = new ListNode(9);
    ListNode * ans = addTwoNumbers(first, second);
    //ListNode * ans = addTwoNumbers(second, first);
    while(ans != nullptr) {
        printf("%d ->", ans->val);
        ans = ans->next;
    }
    printf("\n");
    //2 4 9
    //5 6 4 9
    //-------

    //[7,0,4,0,1]
    assert(romanToInt("I") == 1);
    assert(romanToInt("III") == 3);
    assert(romanToInt("IV") == 4);
    assert(romanToInt("V") == 5);
    assert(romanToInt("IX") == 9);
    assert(romanToInt("X") == 10);
    assert(romanToInt("CD") == 400);
    assert(romanToInt("CM") == 900);
    assert(romanToInt("XL") == 40);
    assert(romanToInt("XC") == 90);
    assert(romanToInt("XCII") == 92);
}
