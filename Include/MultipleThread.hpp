#include <string>
#include <thread>
using namespace std;

extern int g_syncTds;

class MultipleThread
{
public:
      static void threadStart(string name, string content, int count);
      void creatThreadA(string fileName, int count);
      void creatThreadB(string fileName, int count);
      void creatThreadC(string fileName, int count);
      void creatThreadD(string fileName, int count);
      void creatThreads(int count);
      void creatThreads4DiffFiles(int count);
      string ReadFromFile(string fileName);
      static void creatAndWriteFile(string name,string content);
      void clearfile(string fileName);    

};