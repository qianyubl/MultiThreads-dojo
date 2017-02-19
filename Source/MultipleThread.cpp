#include "../Include/MultipleThread.hpp"
#include <fstream> 
#include <mutex> 

int g_syncTds = 0;
static mutex g_mutex;

string MultipleThread::ReadFromFile(string fileName)
{
    ifstream myFile;
    myFile.open(fileName);
    string output;

    if(myFile.is_open()) 
    {
        while(!myFile.eof()) 
        {
            myFile >> output;
        }
        myFile.close();
    }
    return output;

}

void MultipleThread::creatAndWriteFile(string name, string content)
{
    ofstream fout(name, ios::app);
    if (fout)
    {  
        fout << content;
        fout.close();
    }
} 

void MultipleThread::threadStart(string name, string content, int count)
{
    while(count > 0)
    {
        lock_guard<mutex> lck(g_mutex);
        if ("A" == content)
        {
            if (g_syncTds == 0)
            {
                creatAndWriteFile(name, content);  
                g_syncTds = 1;
                count--;
            }
        }
        
        if ("B" == content)
        {
            if (g_syncTds == 1)
            {
                creatAndWriteFile(name, content);  
                g_syncTds = 0;
                count--;
            }
        }
        
    }
}


void MultipleThread::creatThreads(int count)
{
    thread tdA(MultipleThread::threadStart, "test.txt", "A", count);   
    thread tdB(MultipleThread::threadStart, "test.txt", "B", count);
    tdA.join();
    tdB.join();
}

void MultipleThread::creatThreads4DiffFiles( int count)
{
    thread tdA(MultipleThread::threadStart, "A.txt", "A", count);   
    thread tdB(MultipleThread::threadStart, "B.txt", "B", count);
    tdA.join();
    tdB.join();
}

void MultipleThread::creatThreadA(string fileName, int count)
{
    thread td(MultipleThread::threadStart, fileName, "A", count);   
    td.join();
}

void MultipleThread::creatThreadB(string fileName, int count)
{
    thread td(MultipleThread::threadStart, fileName, "B", count);
    td.join();
}

void MultipleThread::creatThreadC(string fileName, int count)
{
    thread td(MultipleThread::threadStart, fileName, "C", count);
    td.join();
}

void MultipleThread::creatThreadD(string fileName, int count)
{
    thread td(MultipleThread::threadStart, fileName, "D", count);
    td.join();
}
void MultipleThread::clearfile(string fileName)
{
    ofstream fout(fileName, ios::trunc);
    fout.close();
}