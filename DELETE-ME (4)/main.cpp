#include <iostream>
#include <fstream>
#include <sstream>  
#include <vector>
#include <cmath>

using namespace std;

class gorod {
  public:
  string city;
  double x, y;
};

double dis(pair<gorod, gorod> a) {
  return sqrt( pow(a.first.x - a.second.x, 2) + pow(a.first.y - a.second.y, 2) );
}

int main() {
  vector<gorod> v; // создаем вектор 
  ifstream NSC("NSCities.csv"); // указываем, что можем читать данный файл (несортированные города)
  ofstream SC("SCities.csv"); // указываем, что можем изменять это файл (сортированные города)
  string line;
  gorod g;
  int t, n;
  cin >> n;
  t = 0;
  while (getline(NSC, line)) {
    ++t;
    if (t > n){
      break;
    }
    stringstream stream(line);
    string elem;
    int k = 1;
    string out;
    while (getline(stream, elem, ',')) {
      if (k == 1 || k == 2 || k == 3) {
        if (k == 1)
          g.city = elem;
        if (k == 2)
          g.x = stod(elem);
        if (k == 3)
          g.y = stod(elem);
        out += elem + ",";
      }
      ++k;
    }
    v.push_back(g);
    out.pop_back();
    out += '\n';
    SC << out;
    k = 1;
  }

  ofstream f("tab.csv");
  f << '\t' << ';';
  for (auto i : v)
    f << i.city << ';';
  f << '\n';
  for (int i = 0; i < v.size(); ++i) {
    f << v[i].city << ';';
    for (int j = 0; j < v.size(); ++j) {
      f << dis({v[i], v[j]});
      if (j == v.size()-1)
        f << '\n';
      else
        f << ';';
    }
  }

  ofstream ff("connect.csv");
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v.size(); ++j) {
      if (i != j)
        ff << v[i].x << ',' << v[i].y << ',' << v[j].x << ',' << v[j].y << ',' << dis({v[i], v[j]}) << '\n';
    }
  }
}