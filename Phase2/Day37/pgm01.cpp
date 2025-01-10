#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<climits>

template <class MyStream>
void t(long first, long second, long sum, MyStream& output){
    output << "process: " << first << " + " << second << " = " << sum << "done." << std::endl;
    output << "\tresponse sent to client " << std::endl;
    
}
int main(){
    long first = 1L;
    long second = 2L;
    long sum = first + second;
    
    std::stringstream output;
    t(first,second,sum,output);
    
    std::string logmsg = output.str();
    std::ofstream foutput("log.txt",std::ios::app);
    foutput<<logmsg;
    foutput.close();
    return 0;
}
