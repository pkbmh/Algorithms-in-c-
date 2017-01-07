#include <bits/stdc++.h>

using namespace std;

struct Point {
    float x, y;
};
Point cp1, cp2, cps1, cps2;

int compareX(const void* a, const void* b) { Point *p1 = (Point *)a,  *p2 = (Point *)b; return (p1->x - p2->x); }

int compareY(const void* a, const void* b) { Point *p1 = (Point *)a,   *p2 = (Point *)b; return (p1->y - p2->y); }

float dist(Point p1, Point p2) { return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)); }

float min(float x, float y) { return (x < y)? x : y; }

float bruteForce(Point P[], int n) {
	float min = FLT_MAX;
	Point temp1 = cp1, temp2 = cp2;
    	for (int i = 0; i < n; ++i) {
        	for (int j = i+1; j < n; ++j) {
        	    	if (dist(P[i], P[j]) < min) {
               	 		min = dist(P[i], P[j]);
              			temp1 = P[i];
              			temp2 = P[j];
            		}
        	}
	}
	if (dist(cp1, cp2) > dist(temp1, temp2)) {
		cp1 = temp1;
		cp2 = temp2;
	}
		
    return min;
}

float stripClosest(Point strip[], int size, float d) {
	float min = d;
	Point temp1 = cps1, temp2 = cps2;
	
	for (int i = 0; i < size; ++i) {
        	for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) {
            		if (dist(strip[i],strip[j]) < min) {
                		min = dist(strip[i], strip[j]);
                		temp1 = strip[i];
                		temp2 = strip[j];
            		}
        	}
    	}
    	if (dist(cps1, cps2) > dist(temp1, temp2)) {
		cps1 = temp1;
		cps2 = temp2;
	}
 	return min;
}

float closestUtil(Point Px[], Point Py[], int n) {
	if(n <= 3)
		return bruteForce(Px, n);

	int mid = n/2;
	Point midPoint = Px[mid];
	Point Pyl[mid+1];
    	Point Pyr[n-mid-1];
    	int li = 0, ri = 0;
    	for (int i = 0; i < n; i++) {
      		if (Py[i].x <= midPoint.x)
         		Pyl[li++] = Py[i];
      		else
         		Pyr[ri++] = Py[i];
    	}
 	float dl = closestUtil(Px, Pyl, mid);
    	float dr = closestUtil(Px + mid, Pyr, n-mid);
 	float d = min(dl, dr);
    	Point strip[n];
    	int j = 0;
    	for (int i = 0; i < n; i++)
        	if (abs(Py[i].x - midPoint.x) < d)
            		strip[j] = Py[i], j++;

 	float xxx = stripClosest(strip, j, d);
 	float re =  min(d,  xxx);
    	return re;
}

float closest(Point P[], int n) {
	Point Px[n];
	Point Py[n];
	for (int i = 0; i < n; i++) {
		Px[i] = P[i];
		Py[i] = P[i];
	}

	qsort(Px, n, sizeof(Point), compareX);
	qsort(Py, n, sizeof(Point), compareY);
	
	return closestUtil(Px, Py, n);
}

int main()
{
	//Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	//int n = sizeof(P) / sizeof(P[0]);
	int n;
	cin >> n;
	Point P[n];
	for (int i = 0; i < n; i++) 
		cin >> P[i].x >> P[i].y; 

	cp1 = cps1 = P[0];
	cp2 = cps2 = P[1];

	cout << "The smallest distance is " << closest(P, n);

	if(dist(cp1, cp2) < dist(cps1, cps2))
		cout << endl << cp1.x << " " << cp1.y << " :: " << cp2.x << " " << cp2.y << endl;
	else 
		cout << endl << cps1.x << " " << cps1.y << " :: " << cps2.x << " " << cps2.y << endl;
    
	return 0;
}
