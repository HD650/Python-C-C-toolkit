using namespace std;
vector<string>* BFS(map<string, set<string> >roads, string begin, string goal)
{
	//data structure of paths
	queue<vector<string> > path;
	vector<string> begin_path;
	//initial path in data structure
	begin_path.push_back(begin);
	path.push(begin_path);
	//visited nodes
	set<string> visit;
	visit.insert(begin);

	//expand the paths
	while(!path.empty())
	{
		//pop top path
		vector<string> last=path.front();
		path.pop();
		
		//use a queue so we don't need to reverse the push order
		for(set<string>::iterator i=roads[last.back().c_str()].begin();i!=roads[last.back().c_str()].end();i++)
		{
			//goal match
			if((*i)==goal)
			{
				last.push_back((*i));
				vector<string>* res=new vector<string>(last);
				return res;
			}
			else
			{	
				//generate new path
				set<string>::iterator is_visited=visit.find((*i));
				if(is_visited==visit.end())
				{
					visit.insert((*i));
					vector<string> new_path=vector<string>(last);
					new_path.push_back((*i));
					//printf("push: %s\n", new_path.back().c_str());
					path.push(new_path);
				}
				else
				{
					//do not visit visited path again
				}
			}
		}
	}
	//no path found
	return NULL;
}