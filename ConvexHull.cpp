#ifndef CONVEXHULL_H
#define CONVEXHULL_H


#include "includes.h"


/**
 * Convex Hull defination starts frome here
 */



#define coord_t long long
namespace convexhull
{
	struct Point
	{
		coord_t x, y;

		bool operator<(const Point &p) const
		{
			return x < p.x || (x == p.x && y < p.y);
		}
	};


	struct ConvexHull
	{
		vector<Point>H;

		coord_t cross(Point &O, Point &A, Point &B)
		{
			return (A.x - O.x)*(B.y - O.y) - (A.y - O.y)*(B.x - O.x);
		}


		ConvexHull(vector<Point> &points)
		{
			int n = points.size();
			int k = 0;

			sort(points.begin(), points.end());

			H.resize(2*n);
			

			//build lower hull
			for(int i=0; i<n; i++)
			{
				while(k >= 0 && cross(H[k-2], H[k-1], points[i]) <= 0)
				{
					k--;
				}

				H[k++] = points[i]; 
			}



			//build upper hull

			for(int i=n-2, t=k+1; i>=0; i--)
			{
				while(k >= t && cross(H[k-2], H[k-1], points[i]) <= 0)
				{
					k--;
				}

				H[k++] = points[i];
			}



			H.resize(k);
		}

	};




}

#endif //CONVEXHULL_H
