using namespace std;
//all the available data
const char* data="oradea     zerind      71\
arad       timisoara  118\
lugoj      mehadia     70\
oradea     sibiu      151\
dobreta    craiova    120\
sibiu      fagaras     99\
pitesti    craiova    138\
bucharest  pitesti    101\
bucharest  giurgiu     90\
vaslui     urziceni   142\
hirsova    eforie      86\
neamt      iasi        87\
zerind          arad            75\
timisoara       lugoj          111\
dobreta         mehadia         75\
arad            sibiu          140\
sibiu           rimnicu_vilcea  80\
rimnicu_vilcea  craiova        146\
rimnicu_vilcea  pitesti         97\
bucharest       fagaras        211\
bucharest       urziceni        85\
hirsova         urziceni        98\
vaslui          iasi            92";

void read_from_file()
{
    ifstream infile("./road.txt");
    string one_line;
    string cityA, cityB;
    int distance;
    while(getline(infile, one_line))
    {
        istringstream ss(one_line);
        //use istringstream to format read the file
        ss>>cityA>>cityB>>distance;
        printf("reading: %s, %s, %d\n",cityA.c_str(), cityB.c_str(), distance);
    }

}

void read_from_char()
{
    string sdata(data);
    istringstream ss(sdata);
    string cityA, cityB;
    int distance;
    //use istringstream to format read the data
    while ((ss>>cityA>>cityB>>distance))
    {
        printf("reading: %s, %s, %d\n",cityA.c_str(), cityB.c_str(), distance);
    }
}


