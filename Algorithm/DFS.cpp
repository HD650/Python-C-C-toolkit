using namespace std;

vector<string>* DFS(map<string, set<string> >roads, string begin, string goal)
{
	//data structure of path
	stack<vector<string> > path;
	//insert the initial path
	vector<string> begin_path;
	begin_path.push_back(begin);
	path.push(begin_path);
	//record the visited location
	set<string> visit;
	visit.insert(begin);

	//expand the path
	while(!path.empty())
	{
		//pop the top path
		vector<string> last=path.top();
		path.pop();
		
		//use a stack so we should reverse the push order
		for(set<string>::reverse_iterator i=roads[last.back().c_str()].rbegin();i!=roads[last.back().c_str()].rend();i++)
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
