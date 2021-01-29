#include <bits/stdc++.h>
using namespace std;
# define N 1000
vector<int> gr[N];
// Function to add edge
void Add_edge(int x, int y)
{
	gr[x].push_back(y);
    gr[y].push_back(x);
}


int DFS(int source,int visited[],int connected)
{
visited[source]=1;
for(auto x: gr[source])
{
    if(visited[x]==0)
    {
        connected++;
        connected=DFS(x,visited,connected);
    }
}
return connected;
}

int main()
{
int n;
cout<<"\nEnter the number of nodes: ";
cin>>n;
int pairs;
cout<<"\nEnter the number of pairs: ";
cin>>pairs;
cout<<"\nEnter the pairs:\n";
for(int i=0;i<pairs;i++)
{
    int x,y;
    cin>>x>>y;
    Add_edge(x,y);
}

int visited[n]={0};
int connected_components=1;
int connected[n]={0};
int count=0;
for(int i=0;i<pairs;i++)
{
    if(visited[i]==0)
    {
        int x=DFS(i,visited,connected_components);
        connected[count]=x;
        count++;
    }
}
cout<<"\nNumber of connected components are: "<<count;
cout<<"\nNodes in each connected component is: \n";
for(int i=0;i<count;i++)
cout<<connected[i]<<"\n";

}