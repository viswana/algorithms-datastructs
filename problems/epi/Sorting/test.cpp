#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

struct Person {
  string name;
  int age;
};

void GroupByAge(vector<Person>& people) {
  unordered_map<int, int> age_to_count;
  for (auto i : people) {
    age_to_count[i.age]++;
  }
  unordered_map<int, int> age_to_offset;
  int offset = 0;
  for (auto [age, count] : age_to_count) {
    age_to_offset[age] = offset;
    offset += count;
  }
  while (!age_to_offset.empty()) {
    auto from = age_to_offset.begin();
    auto to = age_to_offset.find(people[from->second].age);
    swap(people[from->second], people[to->second]);
    --age_to_count[to->first];
    if (age_to_count[to->first] > 0) {
      ++to->second;
    }
    else {
      age_to_offset.erase(to);
    }
  }
}

int main() {
  vector<Person> people = {
    {"Greg", 14},
    {"John", 12},
    {"Andy", 11},
    {"Jim", 13},
    {"Phil", 12},
    {"Bob", 13},
    {"Chip", 13},
    {"Tim", 14}
  };
  GroupByAge(people);
  for (auto i : people) {
    cout << i.name << " " << i.age << " ";
  }
  cout << endl;
  return 0;
}

  
