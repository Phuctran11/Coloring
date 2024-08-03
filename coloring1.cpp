#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n, m;
vector<int> A[N], C;
int B[N],a[N],b[N];

void input(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> a[i] >> b[i];
        A[a[i]].push_back(b[i]);
        A[b[i]].push_back(a[i]);
    }
}

void colorGraph(){
    int k = 1;
    for(int i=1; i<=n; i++){
        if(B[i] == 0){
            B[i] = k;
            C.insert(C.end(), A[i].begin(), A[i].end());
            for(int j=2; j<=n; j++){
                if(find(C.begin(), C.end(), j) == C.end() && B[j] == 0){
                    bool can_color = true;
                    for(auto v : A[j]){
                        if(B[v] == k){
                            can_color = false;
                            break;
                        }
                    }
                    if(can_color){
                        B[j] = k;
                        C.insert(C.end(), A[j].begin(), A[j].end());
                    }
                }
            }
            C.clear();
            k++;
        }
    }
}

int main(){
    input();
    colorGraph();
    
    
    ofstream out("graph.dot");
    if (!out) {
        cerr << "Không th? t?o file";
        return 1;
    }
    
    
    
    
    
    out << "graph dothi\n{\n";
  
    for(int i=1; i<=n; i++) {
    if(B[i] == 1) out << i << " [fillcolor=red, style=filled];\n";
    else if(B[i] == 2) out << i << " [fillcolor=green, style=filled];\n";
    else if(B[i] == 3) out << i << " [fillcolor=blue, style=filled];\n";
    else if(B[i] == 4) out << i << " [fillcolor=violet, style=filled];\n";
    else if(B[i] == 5) out << i << " [fillcolor=yellow, style=filled];\n";
    else if(B[i] == 6) out << i << " [fillcolor=white, style=filled];\n";
    else if(B[i] == 7) out << i << " [fillcolor=black, style=filled];\n";
    else if(B[i] == 8) out << i << " [fillcolor=indigo, style=filled];\n";
    else if(B[i] == 9) out << i << " [fillcolor=Orange, style=filled];\n";
    }
    for (int i = 1; i <= m; i++) {
        out << a[i] << " -- " << b[i] << ";" << endl;
    }

    out << "}";
    out.close();
    return 0;
}
