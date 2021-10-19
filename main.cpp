#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <list>

using std::cout;
using std::endl;
using std::cin;
using std::map;
using std::pair;
using std::multimap;
using std::unordered_map;
using std::unordered_multimap;
using std::string;
using std::set;
using std::vector;
using std::for_each;
using std::list;
using std::replace_if;

//?
bool BSort(int first, int second){      //argument for reverce output
    return first > second;
}

bool Checker1(pair<int, string> a){
    return a.first >= 0 and a.first <= 5;
}

bool Checker2 (int x){
    return x < 0;
}

void Out(pair<int, string> a){
    cout << '{' << a.first << ", " << a.second << "}; ";
}

void Outer(unordered_multimap<int, string> a){
    for_each(a.begin(), a.end(), Out);
    cout << endl;
}

int Counter(pair<int, string> a, int counter){
    if(a.first >= 0 && a.first <= 5){
        counter++;
    }
    return counter;
}

int VecF(pair<int, string> a){
    return a.first;
}

int ListF(int x){
    return x;
}

void VecOut(int x){
    cout << x << ' ';
}

void ListOut(int x){
    cout << x << ' ';
}

void SetOut(int x){
    cout << x << ' ';
}

int main() {
    
    unordered_multimap<int, string> asar1;
    asar1.insert(unordered_multimap<int, string>::value_type(5, "opener"));     //value_type - автоматически определенный тип
    asar1.insert(unordered_multimap<int, string>::value_type(5, "middler"));
    asar1.insert(unordered_multimap<int, string>::value_type(5, "closer"));
    asar1.insert(unordered_multimap<int, string>::value_type(-6, "negative"));
    asar1.insert(unordered_multimap<int, string>::value_type(3, "first_three"));
    asar1.insert(unordered_multimap<int, string>::value_type(3, "second_three"));
    //----------------------OPTIONAL_VALUES---------------------------
    asar1.insert(unordered_multimap<int, string>::value_type(4, "phone"));
    asar1.insert(unordered_multimap<int, string>::value_type(9, "pumkin"));
    asar1.insert(unordered_multimap<int, string>::value_type(-1, "chair"));
    asar1.insert(unordered_multimap<int, string>::value_type(-3, "house"));
    
    cout << "Start array:" << endl;
    Outer(asar1);
    
    for (auto it = asar1.begin(); it != asar1.end(); ++it){
        if (it -> first == 3){
            asar1.erase(it);
            break;
        }
    }
    cout << "Edited array:" << endl;
    Outer(asar1);
    
    map<int, string> copied;
    for (unordered_multimap<int, string>::const_iterator it = asar1.begin(); it != asar1.end(); ++it){
        copied.insert(map<int, string>::value_type(it->first, it->second));
    }
    cout << "Copied in map array:" << endl;
    for_each(copied.begin(), copied.end(), Out);
    cout << endl;
    cout << count_if(copied.begin(), copied.end(), Checker1) << endl;
    vector<int> vect(copied.size());
    transform(copied.begin(), copied.end(), vect.begin(), VecF);
    cout << "Keys:" << endl;
    for (int i = 0; i < vect.size(); ++i){
        cout << vect[i] << ' ';
    }
    cout << endl;
    
    auto pos = find(vect.begin(), vect.end(), 5);   //?
    cout << "Posicion of element, wich is equal '5': "<< *pos + 1 << endl;
    vector<int> vecr(vect.size());
    for(int i = 0; i < vect.size(); ++i){
        vecr[i] = vect[i];
    }
    cout << "Sorted vector: ";
    for_each(vecr.begin(), vecr.end(), VecOut);
    cout << endl;
    
    list<int> lis(vecr.size());
    transform(vecr.begin(), vecr.end(), lis.begin(), ListF);
    cout << "New list:" << endl;
    for_each(lis.begin(), lis.end(), ListOut);
    cout << endl;
    replace_if(lis.begin(), lis.end(), Checker2, 0);
    cout << "Edited list:" << endl;
    for_each(lis.begin(), lis.end(), ListOut);
    cout << endl;
    lis.sort(BSort);
    cout << "Sorted:" << endl;
    for_each(lis.begin(), lis.end(), ListOut);
    cout << endl;
    
    set<int> st(lis.begin(), lis.end());
    cout << "New set:" << endl;
    for_each(lis.begin(), lis.end(), SetOut);
    cout << endl;
    
    
    auto res_search = st.find(5);
    if (res_search != st.end()){
        cout << "There is element, that is equal 5";
    }
    else{
        cout << "There is no element, that is equal 5";
    }
    cout<< endl;
    return 0;
}
