//Given N points, how many triples of these points are the vertices of an isosceles triangle?
//Input data
//The first line contains an integer n(3 ? n ? 1500).Each of the following lines contains two integers xi and yi, which determine the coordinates of the i - th point.All the coordinates of points do not exceed 109 in absolute value.Among the given points there are no coinciding points.
//
//Output
//Output the answer to the above problem



#include <iostream>
#include <cmath>
using namespace std;


struct _pair
{
	double first;
	int second;
};

double len(double x1, double y1, double x2, double y2)
{
	return pow(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2), 0.5);
}

int cmp(const void *x, const void *y)
{
	if ((*(_pair*)x).first < (*(_pair*)y).first)
		return -1;
	else if ((*(_pair*)x).first > (*(_pair*)y).first)
		return 1;
	else return 0;
}

bool are_collinear(double x1, double y1, double x2, double y2)
{
	if ((x1 == 0 && x2 == 0) || (y1 == 0 && y2 == 0))
		return 1;
	if (abs(x2 / x1 - y2 / y1) < numeric_limits<double>::epsilon())
		return 1;
	else return 0;
}

int main()
{
	int n, triangles = 0;
	cin >> n;
	_pair *points = new _pair[n];
	_pair *dist;
	for (int i = 0; i < n; i++)
	{
		cin >> points[i].first >> points[i].second;
	}
	int sz = n - 1;
	dist = new _pair[n];

	int counter;
	double x1, x2, y1, y2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dist[j].first = len(points[i].first, points[i].second, points[j].first, points[j].second);
			dist[j].second = j;
		}
		qsort(dist, n, sizeof(_pair), cmp);
		for (int l = 0; l < n; l++)
			cout << dist[l].first << " ";
		cout << endl;
		int k = 0;
		while( k < n)
		{
			counter = 1;
			while (k + counter < n && abs(dist[k].first - dist[k + counter].first) < numeric_limits<double>::epsilon())
				counter++;
			for (int l = k; l < k + counter - 1; l++)
			{
				for (int m = l + 1; m < k + counter; m++)
				{
					x1 = points[dist[l].second].first - points[i].first;
					y1 = points[dist[l].second].second - points[i].second;
					x2 = points[dist[m].second].first - points[i].first;
					y2 = points[dist[m].second].second - points[i].second;
					if (!are_collinear(x1, y1, x2, y2))
						triangles++;
				}
			}
			k += counter;
		}
	}



	cout << triangles;
	delete[] dist;
	delete[] points;
	system("pause");
	return 0;
}