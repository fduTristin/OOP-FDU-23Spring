#include"shape.h"
#include"handle.h"
#include<fstream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>


using std::cout;
using std::endl;
using std::vector;
using std::setprecision;
using std::streamsize;

int main() {
    vector<Handle> shapes;
    std::ifstream infile("shapes");
    readinfo(infile, shapes);
    sort(shapes.begin(), shapes.end(), compare);
    cal_output(shapes);
    return 0;
}