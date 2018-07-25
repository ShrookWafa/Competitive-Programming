#include <bits/stdc++.h>

using namespace std;

struct Point{
    double x, y;
    Point(double x, double y):x(x), y(y){}
    Point():x(0), y(0){}
    Point& operator=(const Point& o){
        x = o.x;
        y = o.y;
        return *this;
    }
    Point& operator+=(const Point& o){
        x += o.x;
        y += o.y;
        return *this;
    }
    Point& operator-=(const Point& o){
        x -= o.x;
        y -= o.y;
        return *this;
    }
    Point& operator*=(double fact){
        x -= fact;
        y -= fact;
        return *this;
    }
    Point& operator/=(double fact){
        x /= fact;
        y /= fact;
        return *this;
    }
};
Point any;
Point operator-(const Point &a){
    return Point(-a.x, -a.y);
}
Point operator+(const Point &a, const Point &b){
    return Point(a.x+b.x, a.y+b.y);
}
Point operator-(const Point &a, const Point &b){
    return Point(a.x-b.x, a.y-b.y);
}
double operator*(const Point &a, const Point &b){
    return a.x*b.x + a.y*b.y;
}
double operator^(const Point &a, const Point &b){
    return a.x*b.y - a.y*b.x;
}
Point operator*(const double factor, const Point & p){
    return Point(factor * p.x, factor * p.y);
}
Point operator*(const Point & p, const double factor){
    return Point(factor * p.x, factor * p.y);
}
double abs(const Point &p){
    return p*p;
}
double norm(const Point &p){
    return sqrt(p*p);
}

struct Segment{
    Point a, ab;
    Segment(const Point &a, const Point &b):a(a), ab(b-a){}
    Segment():a(), ab(){}
    Point b () const {
        return a + ab;
    }
};
double dist(const Segment& r, const Point& p){
        if((p - r.a) * (r.ab) <= 0)return norm(p - r.a);
        if((p - r.b()) * (-r.ab) <= 0)return norm(p - r.b());
        return abs(((p-r.a)^r.ab)/norm(r.ab));
}
bool inter(const Segment& s1, const Segment &s2, Point& res = any){
    if((s1.ab ^ s2.ab) == 0)return 0; // parallel
    double t1 = ((s2.a - s1.a) ^ s2.ab) / (s1.ab ^ s2.ab);
    double t2 = ((s1.a - s2.a) ^ s1.ab) / (s2.ab ^ s1.ab);
    if(t1 < 0 || t1 > 1 || t2 < 0 || t2 > 1)return 0;// does not intersect
    res = s1.a + s1.ab * t1;
    return 1;
}

bool PointInPolygon(Point point, vector<Point>points) {
  int i, j, nvert = points.size();
  bool c = false;
  for(i = 0, j = nvert - 1; i < nvert; j = i++) {
    if( ( (points[i].y >= point.y ) != (points[j].y >= point.y) ) &&
        (point.x <= (points[j].x - points[i].x) * (point.y - points[i].y) / (points[j].y - points[i].y) + points[i].x)
      )
      c = !c;
  }
  return c;
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector <Point> p,q;
    vector <Segment> ps,qs;
    for(int i=0; i<n; i++){
        double x,y;
        cin >> x >> y;
        Point a;
        a = Point(x,y);
        p.push_back(a);
    }
    for(int i=0; i<m; i++){
        double x,y;
        cin >> x >> y;
        Point a;
        a = Point(x,y);
        q.push_back(a);
    }
    Segment s;
    s = Segment(p[0],p[n-1]);
    ps.push_back(s);
    s = Segment(q[0],q[m-1]);
    qs.push_back(s);
    for(int i=1; i<n; i++){
        s = Segment(p[i],p[i-1]);
        ps.push_back(s);
    }
    for(int i=1; i<m; i++){
        s = Segment(q[i],q[i-1]);
        qs.push_back(s);
    }

    for(int i=0; i<n; i++){
        if(PointInPolygon(p[i],q)){
            cout << 0 << endl;
            return 0;
        }
    }
     for(int i=0; i<m; i++){
        if(PointInPolygon(q[i],p)){
            cout << 0 << endl;
            return 0;
        }
    }

     for(int i=0; i<ps.size(); i++){
        for(int j=0; j<qs.size(); j++){
            if(inter(ps[i],qs[j],any)){
                cout << 0 << endl;
                return 0;
            }
        }
    }

    double ans = 1e9;
    for(int i=0; i<n; i++){
        for(int j=0; j<qs.size(); j++){
            ans = min(ans, dist(qs[j],p[i]));
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<ps.size(); j++){
            ans = min(ans, dist(ps[j],q[i]));
        }
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
