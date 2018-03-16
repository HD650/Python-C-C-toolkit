#include "Path.h"
using namespace std;

Path uniform_cost(vector<City>* cities, float** roads, int city_num, City begin, City goal)
{
	//begin with the original city
	Path begin_path=Path(begin, 0., roads, goal);
	priority_queue<Path> paths;
	paths.push(begin_path);
	//path extension
	while(paths.size()>0)
	{
		Path now_path=paths.top();
		paths.pop();
		City last_city=now_path.get_end();
		City begin_city=now_path.get_begin();
		
		//found the goal
		if(last_city.index==goal.index)
		{
			Path new_path=Path(now_path);
			new_path.add_city(goal);
			new_path.g_h=new_path.length;
			return new_path;
		}

		//if this path is longer than we know, this path should not exist.
		//I don't delete the longer path explicitly but just ignore it
		if(roads[begin_city.index][last_city.index]<now_path.length)
		{
			continue;
		}
		
		//find a successor
		for(int i=0;i<city_num;i++)
		{
			float new_distance=roads[last_city.index][i];
			
			//if new node is unreachable, do nothing
			if(new_distance>0)
			{
				//add the new path to data structure
				Path new_path=Path(now_path);
				new_path.add_city(cities->at(i));
				new_path.g_h=new_path.length;
				paths.push(new_path);
			}
		}
	}
	//found no path
	return Path();
}