#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>Set;
Set rbt;

rbt.erase(x);
rbt.insert(x);
int x=*rbt.find_by_order(k-1);//第k小 

int x=rbt.order_of_key(k);//比k小的数的个数 
