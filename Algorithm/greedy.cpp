#include "Path.h"
using namespace std;

Path greedy(vector<City>* cities, float** roads, int city_num, City begin, City goal)
{
	//data structure begin with the original city
	Path begin_path=Path(begin, begin.distance_to(goal), roads, goal);
	priority_queue<Path, vector<Path>, Path> paths;
	paths.push(begin_path);
	set<int> visited;
	visited.insert(begin_path.get_end().index);

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
			//renew the g_h to h hat
			new_path.g_h=new_path.get_end().distance_to(goal);

			return new_path;
		}
		
		//find a successor
		for(int i=0;i<city_num;i++)
		{
			set<int>::iterator find=visited.find(i);
			if(find!=visited.end())
				continue;
			float new_distance=roads[last_city.index][i];

			//if new node is unreachable, do nothing
			if(new_distance>0)
			{
				//add the new path to data structure
				Path new_path=Path(now_path);
				new_path.add_city(cities->at(i));
				visited.insert(i);
				//renew the g_h to h hat
				new_path.g_h=new_path.get_end().distance_to(goal);
				paths.push(new_path);
			}
		}
	}
	return Path();
}