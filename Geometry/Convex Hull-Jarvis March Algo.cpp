#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x,y;
    Point(int _x,int _y){
        x = _x;
        y = _y;
    }
    bool operator < (const Point &p)const{
        if(x == p.x)
            return y<p.y;
        else
            return x<p.x;
    }
};

int crossProduct(Point a , Point b , Point c)   ///result>0 means c is on left of ab ; result=0 means a,b and c are collinear ; result<0 means c is on right of ab
{
    int x1 = a.x - b.x;
    int x2 = a.x - c.x;
    int y1 = a.y - b.y;
    int y2 = a.y - c.y;
    return y2*x1 - y1*x2;
}

int Distance(Point a , Point b , Point c)   ///result<0 means b is closer to a; result=0 means b and c are same distance from a; result>0 means c is closer to a
{
    int x1 = a.x - b.x;
    int x2 = a.x - c.x;
    int y1 = a.y - b.y;
    int y2 = a.y - c.y;
    int x = x1*x1 + y1*y1;
    int y = x2*x2 + y2*y2;
    if(x == y)
        return 0;
    else if(x < y)
        return -1;
    else
        return 1;
}

set<Point> findConvexHull(vector<Point> &points)
{
    Point start = points[0];    ///Find leftmost point to start
    for(int i=1 ; i<(int)points.size() ; i++){
        if(points[i].x < start.x)
            start = points[i];
    }
    Point current = start;
    set<Point>result;   ///use set because this algorithm might try to insert duplicate point.
    result.insert(start);
    vector<Point>collinear;

    while(1){
        Point nxtTarget = points[0];
        for(int i=1 ; i<(int)points.size() ; i++){
            if(points[i].x == current.x && points[i].y == current.y)
                continue;
            int val = crossProduct(current , nxtTarget , points[i]);

            if(val > 0){    ///points[i] is on left of current->nextTarget line.
                nxtTarget = points[i];
                collinear.clear();  ///Reset collinear because we've a new nextTarget
            }
            else if(val == 0){  ///current,nextTarget and points[i] are collinear. IF its collinear point then pick the further one but add closer one to list of collinear point.
                if(Distance(current , nxtTarget , points[i]) < 0){
                    collinear.push_back(nxtTarget);
                    nxtTarget = points[i];
                }
                else{   ///
                    collinear.push_back(points[i]);
                }
            }
        }

        for(auto p : collinear)
            result.insert(p);
        if(nxtTarget.x == start.x && nxtTarget.y == start.y)
            break;
        result.insert(nxtTarget);
        current = nxtTarget;
    }
    return result;
}

int main()
{
    vector<Point>inp;
    int i,j,k,n,x,y;
    cin>>n;
    for(int i=1 ; i<=n ; i++){
        cin>>x>>y;
        inp.push_back(Point(x , y));
    }
    set<Point>out = findConvexHull(inp);
    for(auto pp : out)
        cout<<pp.x<<' '<<pp.y<<endl;
    return 0;
}
