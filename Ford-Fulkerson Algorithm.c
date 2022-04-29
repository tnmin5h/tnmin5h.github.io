#include <stdio.h>
#define MAX 999999999

int main(void)
{
    int V, E, u, v, c;

    int cap[V_Max][V_Max], flow[V_Max][V_Max];
    //간선의 용량과 유량을 저장할 배열을 생성

    int ford(int src, int sink) {

        int res;
        //반환할 최대 유량값 설정

        while (true) {
            //도착 지점에 유량을 보내는 일이 없을 때까지, 즉, 증가 경로가 없을 때까지 계속해서 반복하는 구조

            vector<int>parent(V_Max, -1);
            //어느 노드에서 유량이 흘러왔는지 저장할 벡터를 생성해준다.

            queue <int> q;
            //유량을 흘려보낼 노드를 보관할 큐를 생성해준다.

            q.push(src); parent[src] = src;
            //소스를 큐에 넣습니다. 

            while (!q.empty() && parent[sink] == -1) {
                //방문할 노드가 존재하고 아직 도착지점에 도달하지 않았다면 반복해준다.

                int here = q.front(); q.pop();
                //큐에서 방문할 노드를 하나 뽑아준다.

                for (int there = 0; there < V; there++) {
                    //모든 정점에 대하여

                    if (cap[here][there] - flow[here][there] > 0 && parent[there] == -1)
                        q.push(there); parent[there] = here;
                    //잔여 용량이 남아있고 아직 방문하지 않았다면, 큐에 넣고 방문처리를 해준다.
                }
            }

            if (parent[sink] == -1)break;
            //만약, 도착지점에 도착하지 않았다면 반복을 멈춘다.

            int amount = MAX;
            //흘려보낼 유량의 값을 저장한다.

            for (int vertex = sink; vertex != src; vertex = parent[vertex])
                amount = min(cap[parent[vertex]][vertex] - flow[parent[vertex]][vertex], amount);
            //증가 경로의 간선 중에서 잔여 용량이 가장 작은 것을 유량으로 고려합니다.

            for (int vertex = sink; vertex != src; vertex = parent[vertex]) {
                flow[parent[vertex]][vertex] += amount;
                flow[vertex][parent[vertex]] -= amount;
            }
            //흘러오는 유량과 보내는 유량을 각 간선마다 새롭게 바꿔준다.

            res += amount;
            //증가 경로를 통해 들어온 유량을 전체 유량 값에 추가해준다.

        }
        return res;
        //계산된 최대 유량값을 반환해준다.
 
}

