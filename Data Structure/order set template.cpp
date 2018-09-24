#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(1)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5

int main()
{
    orderset<int>x;
    orderset<int>::iterator it;
    x.insert(1);
    x.insert(2);
    x.insert(4);
    x.insert(8);
    x.insert(16);
    x.erase(16);
    cout<<*x.find_by_order(1)<<endl; /** Access value of index 1**/
    cout<<*x.find_by_order(3)<<endl; /** Access value of index 3**/
    cout<<*x.find_by_order(4)<<endl; /** Access value of index 4 which is already erased. so,print 0 by default**/
    cout<<*x.find_by_order(5)<<endl; /** Access value of index 5 which is empty. so,print 0 by default*/
    cout<<x.order_of_key(8)<<endl;   /** Print the index of value 8 **/
    cout<<x.order_of_key(5)<<endl;   /** If not found,then ans the suitable index for this value **/
    return 0;
}
