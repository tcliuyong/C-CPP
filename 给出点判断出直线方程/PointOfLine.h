
using namespace std;

struct point
{
	double x;
	double y;
	
};
struct Line
{
	double a,b,c;
	
};
class PoiontOfLine
{	
public:
	Line GetLine(point , point);
	PoiontOfLine(point , point);
private:	
	point p1;
	point p2;
};
PoiontOfLine::PoiontOfLine(point px,point py)
{
	px = p1;
	py = p2;

}
Line PoiontOfLine::GetLine(point p1, point p2)
{
	Line l;
	l.a = p2.y - p1.y;
	l.b = p1.x - p2.x;
	l.c = p2.x*p1.y - p1.x*p2.y;
	return l;	
}