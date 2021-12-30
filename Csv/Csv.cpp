
#include "Csv.h"
#include "../Engine/Utility.h"
void Csv::load() {
    ifstream inFile( path , ios::in);
    if (!inFile) {
        cout << "打开文件失败！" << path << endl;
        return;
    }
    string line;
    char separated = ',';
    char domin = '"';
    if (getline(inFile, line)) {
        auto cell = split(line, separated, domin);
        if (csv_header->size()) 
            return;
        int i = 0;
        for (auto it = cell->begin(); it != cell->end(); it++ , i++) {
            csv_header->insert(pair<string, int>(*it , i));
        }
    }
    while (getline(inFile, line))//getline(inFile, line)表示按行读取CSV文件中的数据
    {
        CellVector_p row = split(line, separated, domin);
        csv_data->insert(pair<int, CellVector_p>(safeStoi( (*row)[0] ), row));
    }
    inFile.close();
}

int Csv::getIndex(string str)
{
    auto it = csv_header->find(str);
    if (it != csv_header->end()) {
        return it->second;
    }
    return -1;
}

string Csv::getCell(int id, int index)
{
    auto it = csv_data->find(id);
    if (it != csv_data->end()) {
        return (*(it->second))[index];
    }
    return string();
}

string Csv::getCell(int id, string str)
{
    int index = getIndex(str);
    return getCell(id, index);
}

int Csv::convIntCell(string name, CellVector_p cells)
{
    int idx = getIndex(name);
    if (idx != -1) {
        return safeStoi((*cells)[idx]);
    }
    return 0;
}

string Csv::convStrCell(string name, CellVector_p cells)
{
    int idx = getIndex(name);
    if (idx != -1) {
        return (*cells)[idx];
    }
    return "";
}

