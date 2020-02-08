#include <iostream>
using namespace std;

int main()
{
	double coord1x, coord1y, coord2x, coord2y, slope, midpointx, midpointy;
	//coord1x,coord1y is (x,y)
	//coord2x, coord2y is (x1,y1)
	//slope is a variable that gets calculated
	//midpointx and midpointy helps caluclate the midpoint of the program

	cout << "Please enter the x coordinate of the first point on a line:";
	cin >> coord1x;
	cout << "Please enter the y coordinate of the first point on a line:";
	cin >> coord1y;
	cout << "Please enter the x coordinate of the second point on the line:";
	cin >> coord2x;
	cout << "Please enter the y coordinate of the second point on the line:";
	cin >> coord2y;

	midpointx = coord2x + coord1x / 2;
	midpointy = coord2y + coord1y / 2;
	slope = coord2y - coord1y / coord2x - coord1x;

	cout << "The first point's coordinate is:(" <<coord1x<<","<<coord1y<<")\n";
	cout << "The second point's coordinate is:(" << coord2x << "," << coord2y << ")\n";
	cout << "The slope of the line is:" << slope<<"\n";
	cout << "The midpoint is:("<< midpointx<<","<<midpointy<<")";


	return 0;
}


