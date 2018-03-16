class Path
{
public:
    float g_h;
    float length;
    vector<City> path;
    float** roads;
    City goal;
    set<int> visited;
    //for priority queue only, do nothing
    Path()
    {

    }
    Path(City _begin, float _g_h, float** _roads, City _goal):g_h(_g_h),roads(_roads),goal(_goal),length(0.0)
    {
        this->path.push_back(_begin);
        this->visited.insert(_begin.index);
    }
    //used to create a identical path
    Path(const Path& old_path)
    {
        this->g_h=old_path.g_h;
        this->length=old_path.length;
        this->path=vector<City>(old_path.path);
        this->roads=old_path.roads;
        this->goal=old_path.goal;
        this->visited=old_path.visited;
    }
    //add a city to a path, also update the shortest path
    void add_city(City new_node)
    {
        City begin=this->get_begin();
        City now=this->get_end();
        this->length=this->roads[now.index][new_node.index]+this->length;
        if((this->length<roads[begin.index][new_node.index])||(roads[begin.index][new_node.index]==-1))
        {
            roads[begin.index][new_node.index]=this->length;
            roads[new_node.index][begin.index]=this->length;
            this->g_h=this->length+new_node.distance_to(this->goal);
            this->path.push_back(new_node);
            this->visited.insert(new_node.index);
        }
        else
        {
            this->g_h=this->length+new_node.distance_to(this->goal);
            this->path.push_back(new_node);
            this->visited.insert(new_node.index);
        }
    }
    City get_begin()
    {
        return this->path.front();
    }
    City get_end()
    {
        return this->path.back();
    }
    bool operator()(const Path &a, const Path &b);
};

//help priority to sort all paths
bool operator<(const Path &a, const Path &b)
{
    if(a.g_h==b.g_h)
        return strcmp(a.get_end().name.c_str(),b.get_end().name.c_str());
    else
        return a.g_h>b.g_h;
}

