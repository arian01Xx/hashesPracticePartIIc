#ifndef SOLUTION_TWO_HPP
#define SOLUTION_TWO_HPP

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0]>b[0];
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k){
        vector<vector<int>> v; //cada elemento es un par de valores
        for(int i=0; i<nums2.size(); i++){
            v.push_back({nums2[i], nums1[i]}); //otra forma de agregar a vector de vectores
        }
        sort(v.begin(), v.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> pq;
        //greater el mas grande, el menor valor siempre estará en la cima
        long long int ans=0, sum=0;

        for(int i=0; i<nums1.size(); i++){
            if(i<k-1){
                pq.push(v[i][1]);  //se agrega v[i][1] a la cola de prioridad y...
                sum += v[i][1];    //se suma a 'sum'
            }else{
                pq.push(v[i][1]);   //se agrega a v[i][1] a la cola de prioridad y
                sum += v[i][1];     //se suma a 'sum'
                ans = max(ans, sum*v[i][0]);
                sum -= pq.top();
            }
        }
        return ans;
    }
};

#endif // SOLUTION_TWO_HPP