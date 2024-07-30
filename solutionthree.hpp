#ifndef SOLUTION_THREE_HPP
#define SOLUTION_THREE_HPP

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

class SolutionTwo {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        //candidatos es la cantidad a seleccionar del vector
        long long ans=0;
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        int cnt=0;
        int i=0;
        int j=costs.size()-1;
        while(cnt < k){   //por ejemplos 3 rondas de contratacion
            while(pq1.size()<candidates && i<=j){
                pq1.push(costs[i++]); //empieza desde adelante con el limite de candidatos (4)
            }
            while(pq2.size()<candidates && j>=i){
                pq2.push(costs[j--]);  //empieza desde atrás
            }
            int cost1=pq1.size()>0 ? pq1.top(): INT_MAX; //si pq1 no está vacia, entonces se evalua para el de adelante, sino, que se mantenga en INT_MAX
            int cost2=pq2.size()>0 ? pq2.top(): INT_MAX;  //igual aqui
            if(cost1 <= cost2){
                ans += cost1; //de esta forma acumula el costo
                pq1.pop();  //va quitando los candidatos ya seleccionados
            }else{
                ans+=cost2;
                pq2.pop();
            }
            cnt++;
        }
        return ans;
    }
/*
Input: costs = [17,12,10,2,7,2,11,20,8], k = 3, candidates = 4
Output: 11
*/
};

#endif // SOLUTION_THREE_HPP