#include <fstream>
#include <iostream>
#include <sstream>
#include <limits>
#include <algorithm>
#include <vector>

struct vec3 {
   int x, y, z;
   static vec3 ZERO;
   
   vec3() : x(0), y(0), z(0) {}
   vec3(int x, int y, int z) : x(x), y(y), z(z) {}
   bool operator>(const vec3& v) const {
      return x > v.x || y > v.y || z > v.z;
   }
   bool operator==(const vec3& v) const {
      return x == v.x && y == v.y && z == v.z;
   }
   bool operator!=(const vec3& v) const {
      return x != v.x || y != v.y || z == v.z;
   }   
   vec3 operator-(const vec3& v) const {
      return vec3(x - v.x, y - v.y, z - v.z);
   }
};
std::istream& operator>>(std::istream& is, vec3& v) {
   int x, y, z;
   is >> x >> y >> z; 
   v.x = x; v.y = y; v.z = z;
   is.ignore(256, '\n');
   return is;
}

vec3 vec3::ZERO(0, 0, 0);

bool isSubsetSum(std::vector<vec3>& set, size_t n, const vec3 sum) {
   // Base Cases
   if (sum == vec3::ZERO) return true;
   if (n == 0 && sum != vec3::ZERO) return false;
 
   // If last element is greater than sum, ignore it
   if (set[n - 1] > sum) {
      return isSubsetSum(set, n - 1, sum);
   }
 
   return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

std::vector<vec3> readFoodList(std::istream& fis) {
   int foodCount;
   fis >> foodCount;
   fis.ignore(256, '\n');

   std::vector<vec3> foods;

   for (int i = 0; i < foodCount; i++) { 
      vec3 food; 
      fis >> food;
      foods.push_back(food);
   }   
   return foods;
}

int P_main(int argc, char* argv[]) {
	std::ifstream fis("new_years_resolution.in");
	std::ofstream fos("new_years_resolution.out");
   std::cout.rdbuf(fos.rdbuf());
	
	int n;
	fis >> n;
	fis.ignore(256, '\n');

	int cases = 1;
	while (n--) { 
      vec3 sum;
      fis >> sum;
      
      std::vector<vec3> food = readFoodList(fis);
      
      bool onDiet = isSubsetSum(food, food.size(), sum);
      
      std::cout << "Case #" << cases << ": " << (onDiet ? "yes" : "no") << std::endl;
      cases++;
	}
	return 0;
}