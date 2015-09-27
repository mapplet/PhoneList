#include <iostream>
#include <set>

using namespace std;

pair<set<string>, bool> getPhoneList();
bool addPhoneNumber(set<string>&, const string&, const bool&);
bool is_subset_of(const string&, const string&);

int main() {
    
    int testcases;
    cin >> testcases;
    
    if (!cin || testcases < 1 || testcases > 40)
        return -1;
    
    for (int i=1; i<=testcases; ++i)
    {
        pair<set<string>, bool> phone_list = getPhoneList();
        if (phone_list.first.size() == 0)
            return -1;

        if (phone_list.second)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}

bool addPhoneNumber(set<string>& phone_list, const string& phone_number, const bool& is_consistent)
{
    auto ret_val = phone_list.insert(phone_number);
    if (is_consistent)
    {
        if (ret_val.second)
        {
            if (ret_val.first != phone_list.begin())
            {
                auto prev_it = prev(ret_val.first);
                if ( is_subset_of(*prev_it, phone_number) )
                    return false;
            }
            auto next_it = next(ret_val.first);
            if ( next_it != phone_list.end() && is_subset_of(phone_number, *next_it) )
                return false;
        }
    }

    return true;
}

pair<set<string>, bool> getPhoneList()
{
    set<string> phone_list;
    bool is_consistent = true;
    int num_phone_numbers;
    
    cin >> num_phone_numbers;
    
    if (!cin || num_phone_numbers < 1 || num_phone_numbers > 10000)
        return make_pair(set<string>(), false);
    
    for (int i=1; i<=num_phone_numbers; ++i)
    {
        string phone_number;
        cin >> phone_number;
        
        if (!cin || phone_number.length() < 1 || phone_number.length() > 10)
            return make_pair(set<string>(), false);
        if (!addPhoneNumber(phone_list, phone_number, is_consistent))
            is_consistent = false;
    }
    
    return make_pair(phone_list, is_consistent);
}

bool is_subset_of(const string& lhs, const string& rhs)
{
    if (lhs.compare(0,lhs.length(), rhs, 0, lhs.length()) != 0)
        return false;
    return true;
}