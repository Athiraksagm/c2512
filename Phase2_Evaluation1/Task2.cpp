#include<iostream>
#include<vector>
#include<string>
#include<thread>

class LabTest{

     private:
          std::string testId;
          double resultValue;
     public:
          LabTest(std::string id, double result) : testId(id), resultValue(result) {}
          double getResult() const{
              return resultValue;
          }
};


//findSum of ResultValues
void findSum(const std::vector<LabTest> &tests,double& sum)
{
    
    for(auto &e : tests)
{
   sum += e.getResult();
}
    // return sum;
}

//findmin in 1st half ,find max in 2nd half

void findMinOfFirstHalf(const std::vector<LabTest> &tests,double& min)
{
    // int min = tests[0].getResult();
    int half =( (tests.size()-1)/2);
    for (int i = 1; i < half; i++)
    {
        if (tests[i].getResult() < min)
        {
            min = tests[i].getResult();
        }
    }


}


void findMaxOfSecondHalf(const std::vector<LabTest> &tests,double& max)
{
    //  int max = tests[0].getResult();
    
    for (int i = ( (tests.size()-1)/2); i < (tests.size())-1; i++)
    {
        if (tests[i].getResult() > max)
        {
            max = tests[i].getResult();
        }
    }

}

int main()
{
//create vector add 5 objects

std::vector<LabTest> tests;
 tests.emplace_back("T001",10.15);
 tests.emplace_back("T002",20.25);
 tests.emplace_back("T003",30.35);
 tests.emplace_back("T004",40.45);
 tests.emplace_back("T005",50.55);

 double sum = 0;
 double min = tests[0].getResult();
 double max = tests[0].getResult();

std::thread threadSum(findSum, std::ref(tests),std::ref(sum));
std::thread threadMin(findMinOfFirstHalf, std::ref(tests),std::ref(min));
std::thread threadMax(findMaxOfSecondHalf, std::ref(tests),std::ref(max));
threadSum.join();
threadMin.join();
threadMax.join();

//sum = findSum(tests);
std::cout << "sum is " << sum << std::endl;
//int min=findMinOfFirstHalf(tests);
std::cout << "The minimum value is: " << min << std::endl;
//int max=findMaxOfSecondHalf(tests);
std::cout << "The maximum value is: " << max << std::endl;
return 0;
}

