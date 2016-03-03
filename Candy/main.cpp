//
//  main.cpp
//  Candy
//
//  Created by Trinity on 16/3/3.
//  Copyright © 2016年 Trinity. All rights reserved.
//


/*
 问题：幼儿园的老师给学生们分糖果，现假设小朋友们排成一横排，每个小朋友有一个以整数表示的成绩，所分糖果必须满足以下的要求：
    ［1］：如果分数高于旁边的小朋友的话，所分得的糖果也必须更多，分数想等的不做要求。
    ［2］：每个人至少分得一个糖果。
 输入：第一行一个整数n表示小朋友总数，第二行n个整数表示每个小朋友的成绩
 输出：最少需要的糖果数量
 示例输入：
 3
 1 2 1
 以上输入得到的输出:
 4
 
 */
#include <iostream>
#define MAX 1024*1024
#undef DEBUG
#define DEBUG
using namespace std;
int a[MAX];
int w[MAX];

int n;

int cnt;

int dfs (int i) {
    cnt++;
    if(a[i] > 0 || i == 0 || i == n + 1) return a[i];
    a[i] = 1;
    
    if(w[i] > w[i + 1]) {
        int right = dfs(i + 1);
        a[i] = a[i] > right ? a[i] : (right + 1);
        
    }
    if(w[i] > w[i - 1]){
        int left = dfs(i - 1);
        a[i] = a[i] > left ? a[i] : (left + 1);
    }
    
    return a[i];
}

int msum () {
    int result = 0;
#ifdef DEBUG
    cout<<"sum : ";
#endif
    for (int i = 1; i <= n; i++) {
        result += a[i];
#ifdef DEBUG
        cout<<a[i]<<" ";
#endif
    }
#ifdef DEBUG
    cout<<endl;
#endif
    return result;
}

void dfs() {
    for(int i = 1; i <= n; i++) a[i] = 0; /* Clear a[MAX] */
    for(int i = 1; i <= n; i++) dfs(i);
}

int main(int argc, const char * argv[]) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i + 1];
    }
    dfs();
    cout<<msum()<<endl;
    cout<<"count : "<<cnt<<endl;
    
    return 0;
}




