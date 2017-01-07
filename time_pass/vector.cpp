#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>  // for vector
#include <stack>   // for stack operation
#include <queue>   //for queue operation
#include <utility>  //for pair operation
#include <set>      //for set operation
#include <algorithm> //for some algo's
#include <map>       //for map operation
#include <numeric> //for accumulate() sum of vector
#include <functional> //for minus,divide etc;
using namespace std;
#define all(c) (c).begin(),(c).end()  //from begin to end useful in sort and so many time;
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
//#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) //travel any data type
// SOME USEFUL #DEFINE TO REDUCE TYPING AND SAVE TIME
/*
 typedef vector<int> vi; //now we can declare a vector int use vi 
 typedef vector<vi> vvi;  //vector of vector int (graph) vvi
 typedef pair<int,int> ii;  //pair of integer 
 #define sz(a) int((a).size())  //size of a
 #define pb push_back             //pushback a item
 #define all(c) (c).begin(),(c).end()  //from begin to end useful in sort and so many time;
 #define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) //travel any data type
 #define present(c,x) ((c).find(x) != (c).end())  //element present in set or not;
 #define cpresent(c,x) (find(all(c),x) != (c).end()) 
using namespace std;
*/
vector<vector<int> > graph;
vector<bool> state(10 , false); //create vector for check state of vertex either visited or not in dfs
//vector<bool> state_bfs(10 , false); //create vector for check state of vertex either visited or not in bfs

void fillvector(vector<int>& newmyvector){
 int i;
for(i = 0; i < newmyvector.size();i++)
cout<<newmyvector[i];

cout<<endl;
}
void dfs(int s) { //Depth First Search for graph
stack<int> gs; //create stack
//vector<int> state(10 , false); //create vector for check state of vertex either visited or not
gs.push(s); //insert in stack
int v;
while(!(gs.empty())) { 
v = gs.top();  //pop one element from top of the stack
gs.pop(); //decrease top
printf("%d ",v); //visite the vertex
state[v] = true; //declare state as visited
tr(graph[v] , it){ //visit all vertex connected to current vertex
//printf("%d ", *it);
if(!state[*it]){  //check next vertex already visited or not
//printf("%d ", *it);
gs.push(*it);           //insert in stack if vertex not visited
state[*it] = true;  //assign vertex as visited because loop repeat until empty then definitely will visit;
}
}
//cout<<"\n";
}
}
void bfs(int s) //Breadth First Search
{
queue<int> gq;   //create queue for BFS
gq.push(s); //insert start vertex in queue
int v;
while(!(gq.empty())){ // unitl queue is not empty
v = gq.front(); //dequeue one item
printf("%d ", v); //visit vertex
state[v] = true; //assign visited
gq.pop(); 
tr(graph[v] , it) { //travel vertex v
//printf("%d ",*it);
if(!state[*it]) {  //check vertex visited or not
gq.push(*it); ////push if already not visited
//printf("%d ",*it);
state[*it] = true; //assign visited;
}
}
//cout<<"\n";
}
}

void dijkstra(int s) {
priority_queue<int> dpq;
dpq.push(s);
while(!(dpq.empty())) {
int v = dpq.top();
dpq.pop();
printf("%d ", v);
state[v] = true;
tr(graph[v] , it) {
if(!state[*it]){
state[*it] = true;
dpq.push(*it);
}
}
}
}
void print(){
for(int i = 0; i < 5; i++){
for(int j = 0; j < 5; j++)
cout<<graph[i][j]<<" ";

cout<<endl;
}
}

int main(){
int i;
vector<int> myvector;
for(i =0;i <5;i++)
myvector.push_back(i);

for(i =0; i < myvector.size();i++)
cout<<myvector[i];

cout<<endl;
//insert element at position
myvector.insert(myvector.begin()+3,5);
for(i =0; i < myvector.size();i++)
cout<<myvector[i];

cout<<endl;
//delete element at position
myvector.erase(myvector.begin()+4);
for(i =0; i < myvector.size();i++)
cout<<myvector[i];

cout<<endl;
//check myvector is empty or not
if(!myvector.empty())
cout<<"myvector is not empty;"<<endl;
//make empty my vector:
myvector.clear();
if(myvector.empty())
cout<<"myvector is empty"<<endl;

//vector in function:
for(i =0;i <5;i++)
myvector.push_back(i*i);

fillvector(myvector);

cout<<"creating a stack"<<endl;
//stack initialization 
stack <int> newstack;
for(i = 1; i<= 5; i++)
newstack.push(i); // insert a element into newstack[i]
//for(i = 0; i < newstack.size();i++) {
while(!newstack.empty()) {
cout<<newstack.top(); // printing thae top of stack;
newstack.pop(); //delete element from stack top--;
}
cout<<endl<<"creating a queue"<<endl;
queue <int> newqueue; // initialization;
for(i = 1; i <= 5; i++)
newqueue.push(i); // insert a element in newqueue;

/*swap queue;
queue <int> swapqueue;
newqueue.swap(swapqueue);
cout<<endl<<"size "<<swapqueue.size()<<endl;
*/

//for(i = 0; i<newqueue.size(); i++) {
while(!newqueue.empty()) {
cout<<newqueue.front();//printing front of queue;
newqueue.pop();//deleting element from queue;
}

cout<<"\ncreating pair in vector\n"<<endl;
pair <string , int> pair1 (" pankaj ",300);
pair <string , int> pair2 (pair1);
pair <string , int> pair3;
pair3.first = "birat";
pair3.second = 10;
cout<<pair1.first<<pair3.first<<" have "<<pair2.second<<" friend "<<" and "<<pair3.second<<" girlfriend"<<endl;

cout<<"\n travel a vector using iterators\n";
vector<int> v;
for(i = 1; i <= 10; i++)
v.push_back(i);

for(vector<int>::iterator it = v.begin(); it != v.end(); it++) //initialization a iterator
cout<<v[*it];

cout<<"\nsome string operation :P\n";
string s = "hello";
string 
  s2 = s.substr(1, 3), // "ell" 
      s3 = s.substr(0, s.length()-1), //"hell" 
      s4 = s.substr(1); // "ello" 
	cout<<s2<<endl<<s3<<endl<<s4<<endl;
cout<<"##### SET IN STL #####\n";
set<int> sset; //initialization set;
for(i = 1; i<= 100; i++)
sset.insert(i);

sset.insert(42); // 42 already present in set;
int size = sset.size(); // compute the size of set;
cout<<"size of set = "<<size<<endl;
for(i =2; i <= 100; i+=2)
sset.erase(i); // erase even value from set;																																											

size = sset.size(); // now size of set is decrease because even value deleted from set

// compute the sum of all element in set; 
long int r = 0; 
for(set<int>::iterator its = sset.begin(); its != sset.end(); its++) 
      r += *its; 
cout<<"sum of all element in set = "<<r<<endl;

if(sset.find(42) != sset.end()) 
cout<<"42 present in set"<<endl;
else cout<<"42 is not present in set"<<endl;
cout<<"sum = "<<r<<endl;

//Set has an interval constructor: 
/* int data[5] = { 5, 1, 4, 2, 3 }; 
 set<int> S(data, data+5);
The erase() function also has the interval form: 
set<int> s; 
 // .. 

 set<int>::iterator it1, it2; 
 it1 = s.find(10); 
 it2 = s.find(100); 
 // Will work if it1 and it2 are valid iterators, i.e. values 10 and 100 present in set. 
 s.erase(it1, it2); // Note that 10 will be deleted, but 100 will remain in the container 
 */

cout<<"\t\t ##### MAP IN STL :P #####\n";
map<string , int> newmap; // initialization of map;
newmap["pankaj"] = 1;
newmap["birat"] = 2;
newmap["map"] = 3;
int x = newmap["pankaj"] + newmap["birat"];
cout<<"x "<<x<<endl;

if(newmap.find("pankaj") != newmap.end()) //
newmap.erase("pankaj");

cout<<newmap["pankaj"]<<endl;
//insert in map
newmap.insert(pair<string , int>("sumit" , 12));
//cout<<newmap["sumit"]<<endl;
tr(newmap , it) //print whole map;
cout<<"["<<it->first<<"]"<<" = "<<it->second<<endl;
cout<<"\n\t\tcreate a vector using map\n";
map<string , int> mapv; // map with string and integer
mapv["hello"] = 1;
vector < pair<string , int> > vector_map(all(mapv)); // all(c) c.begin() , c.end();
//cout<<vector_map.pair.second<<endl;
//for(vector<pair <string , int> >::iterator i = vector_map.begin(); i != vector_map.end(); i++)
//cout<<vector_map[*i];
cout<<"\n\n\n";
// COPY DATA BETWEEN CONTAINERS
cout<<"\t\tCOPY DATA BETWEEN CONTAINERS\n\n";
vector<int> vc1;
vector<int> vc2;
vc2.resize(10);
for(int j = 0; j < 10; j++){
vc1.push_back(j);
vc2[j] = j * j;
}
cout<<"\nvc1 = ";
tr(vc1 , it) //travel vector by mecro;
cout<<" "<<*it; //printing value store at it location;
cout<<"\nvc2 = ";
tr(vc2 , it) //travel by mecro;
cout<<" "<<*it; //printing value store at it location;

vc2.resize(vc1.size()+vc2.size());  //resizing vc2 for copy data;
copy(all(vc1) , vc2.end() - vc1.size()); // copy all element of vc1 into end of vc2;
cout<<"\ncopied vc1 in end of vc2\n";
cout<<"vc2 = ";
for(vector<int>::iterator it = vc2.begin(); it != vc2.end(); it++) //travel vector;
cout<<" "<<*it; // printing value it pointing at

cout<<"\n\t\t### SOME CALCULATING OPERATION :p #### \n";
//calculate the sum of all element in vector;
vector<int> vector_for_sum;
for(i = 1; i <= 100; i++)
vector_for_sum.push_back(i);

cout<<"\t calculating the sum of all element(1 to 100) in vector \n";              

long int sum = accumulate(all(vector_for_sum) , (long int) 0);
cout<<"sum of vector(contain 1 to 100) = "<<sum<<endl;

//calculate the inner product of two vector
cout<<"\n\t\tcalculating the inner product of two vector\n"<<endl;
vector<int> v1_for_innerproduct;
vector<int> v2_for_innerproduct;
for(i = 1; i <= 10; i++){
v1_for_innerproduct.push_back(i);
v2_for_innerproduct.push_back(i);
}
cout<<"\nv1 for innerproduct = ";
tr(v2_for_innerproduct , it)
cout<<" "<<*it;
cout<<"\nv2 for innerproduct = ";
tr(v2_for_innerproduct , it)
cout<<" "<<*it;
			
long int innerproduct = inner_product(all(v1_for_innerproduct) , v2_for_innerproduct.begin(), (long int) 0);
cout<<"\ninner product is = "<<innerproduct;

//end of inner product;
//sort a vector;
cout<<"\n\t\tsorting a vector\n";
vector<int> for_sort;
for(i = 1; i <= 10; i++)
for_sort.push_back(rand()%100);
cout<<"vector for sort = ";
tr(for_sort , it) //vector before sort
cout<<" "<<*it;

sort(all(for_sort)); // sorting the vector;
cout<<"\nNow vector = ";
tr(for_sort , it) //vector after sort
cout<<" "<<*it;

//Implementing real algorithms with STL;
cout<<"\n\t\tImplementing real algorithms with STL\n\n";
cout<<"\t\t\t#####---GRAPH---H#####\n";
// globle declared vector<vector<int> > graph;
graph.resize(5); //initialization of graph with 5 vertex;

graph[0].push_back(1); //insert edge between 0 1 vertex
graph[0].push_back(2); //insert edge between 0 2 vertex
graph[0].push_back(3); //insert edge between 0 3 vertex
graph[1].push_back(2); //insert edge between 1 2 vertex
graph[1].push_back(4); //insert edge between 1 4 vertex
graph[4].push_back(3); //insert edge between 4 3 vertex
graph[3].push_back(2); //insert edge between 3 2 vertex
graph[1].push_back(0); //insert edge between 1 0 vertex
graph[2].push_back(0); //insert edge between 2 0 vertex
graph[3].push_back(0); //insert edge between 3 0 vertex
graph[2].push_back(1); //insert edge between 2 1 vertex
graph[4].push_back(1); //insert edge between 4 1 vertex
graph[3].push_back(4); //insert edge between 3 4 vertex
graph[2].push_back(3); //insert edge between 2 3 vertex
//print();
cout<<"\t \ntravel graph using DFS\n";
dfs(0); //dfs start from vertex 0;
for(i = 0; i < 5; i++) { //if graph is not connected then some vertex still remain to visit
if(!state[i]) //check which vertex not visit yet (state is globle bool variable which contain state of all vertex which are visited
dfs(i); //visit this vertex;
}
for(i = 0; i < 10; i++)
state[i] = false; // make all state false bcz we need state array in bfs;

cout<<"\t\n travel graph using BFS\n";

bfs(0); //bfs start from 0
for(i = 0; i < 5; i++) { //if graph is not connected then some vertex still remain to visit
if(!state[i]) //check which vertex not visit yet (state is globle bool variable which contain state of all vertex which are visited
bfs(i); //visit this vertex;
}
cout<<endl;

cout<<"\t\nSHORTEST PATH IN GRAPH\n";
cout<<"DIJKSTRA’S ALGORITHM \n";
for(i = 0; i < 10; i++)
state[i] = false; // make all state false bcz we need state array in dijkstra;

dijkstra(0);
cout<<endl;
return 0;
}
