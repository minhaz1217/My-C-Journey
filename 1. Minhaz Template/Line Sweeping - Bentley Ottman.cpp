#include<bits/stdc++.h>
using namespace std;


//Line Sweeping
#define x second
#define y first
#define MAX 100000
typedef pair<int,int >point;
struct event
{
    point p1,p2;
    int type;
    event() {};
    event(point p1,point p2, int type) : p1(p1), p2(p2),type(type) {};  //initialization of event
};
int n,e;
event events[MAX];
bool compare(event a, event b)
{
    return a.p1.x<b.p1.x;
}
set<point >s;
void hv_intersection()
{
    for (int i=0; i<e; ++i)
    {
        cout << "I " << i << endl;
        event c = events[i];
        if (c.type==0)
            s.insert(c.p1);//insert starting point of line segment into set
        else if(c.type==1){
            s.erase(c.p2);//remove starting point of line segment from set, equivalent to removing line segment
        }
        else
        {
            for (auto it=s.lower_bound(make_pair(c.p1.y,-1)); it!=s.end() && it->y<=c.p2.y; it++) // Range search
                printf("%d, %d\n", events[i].p1.x, it->y);//intersections
        }
    }
}
int main ()
{
    scanf("%d", &n);
    int p1x,p1y,p2x,p2y;
    for (int i=0; i<n; ++i)
    {
        scanf("%d %d %d %d", &p1x, &p1y,&p2x, &p2y);
        if(p1x==p2x)                //if vertical line, one event with type=2
        {
            events[e++]=event(make_pair(p1y,p1x),make_pair(p2y,p2x),2);
        }
        else                    //if horizontal line, two events one for starting point and one for ending point
        {
            //store both starting points and ending points
            events[e++]=event(make_pair(p1y,p1x),make_pair(p2y,p2x),0);
            //store both ending and starting points, note the order in the second, this is because we sort on p1, so ending points first, then we remove a line when we hit its ending point , so we need its starting point for removal of line
            events[e++]=event(make_pair(p2y,p2x),make_pair(p1y,p1x),1);
        }
    }
    cout << "HELLO" << endl;
    sort(events, events+e,compare);//on x coordinate
    hv_intersection();
    return 0;
}
