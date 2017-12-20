#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;

double equation(double x){
    double myEquation = x*x - 4*x - 10;
    return myEquation;
}

int main(){
    //x2 -4x - 10 = 0
    double xmax, n, a[3], firstTerm, xmaxEquation,prev,next;
    int i,intervalCounter = 0,foundIntervalCounter = 0;
    a[0] = 1;
    a[1] = -4;
    a[2] = -10;

    firstTerm = a[1]/ a[0];
    xmaxEquation = firstTerm * firstTerm - 2 * (a[2] / a[0]);
    xmax = sqrt(xmaxEquation);
    double intervals[(int)(xmax * 2)][2];
    double foundIntervals[6][2];

    for(i = xmax*-1;i<=xmax;i++){
        intervals[intervalCounter][0] = i;
        intervals[intervalCounter][1] = equation(i);
        //cout << intervals[intervalCounter][0] << " : " << intervals[intervalCounter][1] << endl;
        intervalCounter++;
    }
    prev = intervals[0][1];
    for(i = 1;i<intervalCounter;i++){
        next = intervals[i][1];
        if(prev*next < 0 ){
            foundIntervals[foundIntervalCounter][0] = intervals[i][0];
            foundIntervals[foundIntervalCounter][1] = intervals[i-1][0];
            foundIntervalCounter++;
            //cout << "You want: " << intervals[i][0] << " , " << intervals[i-1][0]  << endl;
            //we can do that here
        }
        prev = next;
    }

    double interval1 , interval2 , average,avgValue;
    interval1 = foundIntervals[0][0];
    interval2 = foundIntervals[0][1];
    average = (interval1 + interval2) /2;
    avgValue = equation(average);

    //cout << "Interval1: " << interval1 << " Interval2: " << interval2 << endl;
    //cout << "Average: " << average << " AverageValue: " << avgValue << endl;



    while( abs(avgValue) > .01){
        if(avgValue * equation(interval1) < 0 ){
            interval2 = average;
        }else if(avgValue * equation(interval2) < 0 ){
            interval1 = average;
        }
        average = (interval1 + interval2) /2;
        avgValue = equation(average);
        //cout << "Interval1: " << interval1 << " Interval2: " << interval2 << endl;

    }


    cout << "Result: " << average << " : " << avgValue << endl;



	return 0;
}
