#include <iostream>
#include <queue>
#include <stack>
#include <cctype>

using namespace std;

bool isPalindrome(const string& input){
    stack<char> s;
    queue<char> q;

    for(char ch : input){
        s.push(ch);
        q.push(ch);
    }

    while(!s.empty()){
        if(s.top() != q.front()){
            return false;
        }
        s.pop();
        q.pop();
    }
    return true;
}

int main(){
    cout <<boolalpha;
    cout <<"Is 'racecar' a palindrome?"
         <<isPalindrome("racecar") << endl;

    cout <<"Is 'hello' a palindrome?"
         <<isPalindrome("hello") << endl;

    return 0; 
}