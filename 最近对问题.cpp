#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define NUM 20 
struct point {
	double x;
	double y;
};

double distance(point z1, point z2) {
	double t;
	t = (z1.x - z2.x)*(z1.x - z2.x) + (z1.y - z2.y)*(z1.y - z2.y);
	return sqrt(t);
};
double min(double p1, double p2) {
	return p1 < p2 ? p1 : p2;
}
double EfficientClosestPair(point p[], point q[], int n) {
	int i, k, num=0, index;
	double d1, dt, d, m,dminsq;
	point p1[NUM], q1[NUM], pt[NUM], qt[NUM], s[NUM];
	if (n == 2) {
		return distance(p[0], p[1]);
	}
	else if(n==3) {
		return min(distance(p[0], p[1]), distance(p[1], p[2]));
	}
	else {
		for (i = 0; i < n / 2; i++) {
			p1[i]= p[i];
		}
		for (i = 0; i < n / 2; i++) {
			q1[i]= q[i];
		}
		for (i = n/2; i < n; i++) {
			pt[i-n/2] = p[i]; 
		}
		for (i = n/2; i < n; i++) {
			qt[i - n / 2] = q[i];
		}
		d1 = EfficientClosestPair(p1, q1, n / 2);
		dt = EfficientClosestPair(pt, qt, n - n / 2);
		d = min(d1, dt);
		
		index = int(ceil(n / 2.0) - 1);
		m = p[index].x;
		for (i = 0; i < n; i++) {
			if (fabs(q[i].x - m) < d) {
				s[num++] = q[i];
			}
		}
		dminsq = d * d;
		for (i = 0; i < num - 2; i++) {
			k = i + 1;
			while (k <= num - 1 && (s[k].y - s[i].y)*(s[k].y - s[i].y) < dminsq) {
				dminsq = min((s[k].x - s[i].x)*(s[k].x - s[i].x) + (s[k].y - s[i].y)*(s[k].y - s[i].y), dminsq);
				k++;
			}
		}
	}
	return sqrt(dminsq);
}

int main() {
	point p[NUM] = { {1.0,0},{1.0,2.0},{2.0,1.0},{2.5,1.0},{4.0,0},{4.0,1.0},{6.0,0},{6.0,1.0},{6.0,2.0} };
	point q[NUM]= { {1.0,0},{4.0,0},{6.0,0},{2.0,1},{2.5,1.0},{4.0,1.0},{6.0,1.0},{1.0,2.0},{6.0,2.0} };
	printf("×îÐ¡¾àÀë£º%f\n",EfficientClosestPair(p, q, 9));

	return 0;
}


