#include<map>
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T, list<pair<T,int> > > m;

public:

    void addEdge(T u,T v,int dist,bool bidir=true){
        m[u].push_back(make_pair(v,dist));

    }
    void printAdj(){
        //printing the adjacency list
        for(auto j:m){

            cout<<j.first<<"->";

            //Iterater over the list of cities
            for(auto l: j.second){
                    cout<<"("<<l.first<<","<<l.second<<")";

            }
            cout<<endl;
        }

    }//adj list made
    void dijkstra(T src){

        map<T,int> dist;

        //initially setting all the dist to infinity
        for(auto j:m){
            dist[j.first] = INT_MAX;
        }

        //Make a set to find out node with the minimum distance and the place it reach
        set<pair<int, T> > s;
        //setting source dist as 0
        dist[src] = 0;
        s.insert(make_pair(0,src));

        while(!s.empty()){

            //search for the pair
            auto p =   *(s.begin());
            T node = p.second;

            int nodeDist = p.first;
            s.erase(s.begin());


            //Iterate over adj node of the current node
            for(auto childPair: m[node]){

                if(nodeDist + childPair.second < dist[childPair.first]){

                    T dest = childPair.first;
                    auto f = s.find( make_pair(dist[dest],dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    //Insert the new pair
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest],dest));

                }

            }
        }
        //print the not reachable case
        if(s.empty()){
            cout<<"Not Reachable"<<endl;
        }

        //Lets print distance to all other node from src
        for(auto d:dist){

            cout<<d.first<<" "<<d.second<<endl;
        }


    }


};

int main(){

    Graph<string> place;
    station.addEdge("Delhi","Pune",160);
    station.addEdge("Delhi","Hyderabad",100);
    station.addEdge("Pune","Nagpur",90);
    station.addEdge("Nagpur","Chennai",80);
    station.addEdge("Vizag","Chennai",2);
    station.addEdge("Mumbai","Bhopal",3);
    station.printAdj();
    station.dijkstra("Delhi");


 return 0;
}
