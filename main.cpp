#include <iostream>
#include <set>

using namespace std;

bool isConsistent(const set<string>&);
set<string> getPhoneList();

int main() {
    
    int testcases;
    cin >> testcases;
    
    if (!cin || testcases < 1 || testcases > 40)
        return -1;
    
    for (int i=1; i<=testcases; ++i)
    {
        set<string> phone_list = getPhoneList();
        if (phone_list.size() == 0)
            return -1;

        if (isConsistent(phone_list))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}

set<string> getPhoneList()
{
    int num_phone_numbers;
    set<string> phone_list;
    
    cin >> num_phone_numbers;
    
    if (!cin || num_phone_numbers < 1 || num_phone_numbers > 10000)
        return set<string>();
    
    for (int i=1; i<=num_phone_numbers; ++i)
    {
        string phone_number;
        cin >> phone_number;
        
        if (!cin || phone_number.length() < 1 || phone_number.length() > 10)
            return set<string>();
        
        phone_list.insert(phone_number);
    }
    
    return phone_list;
}

bool isConsistent(const set<string>& phone_list)
{
    for (set<string>::const_iterator it = phone_list.cbegin(); it != phone_list.cend();)
    {
        const string& current = *it;
        set<string>::const_iterator it_next = ++it;
        if (it_next == phone_list.end())
            return true;
        const string& next = *it_next;
        
        if (current.compare(0,current.length(),next,0,current.length()) == 0)
        {
            return false;
        }
    }
    
    return true;
}