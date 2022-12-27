#include <string>
#include <vector>
#include <fstream>

using namespace std;

class FileInteractor {

private:
    string fileName;
    vector<string> rawContents;

    // from google
    vector<string> split (string s, string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
            token = s.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back (token);
        }

        res.push_back (s.substr (pos_start));
        return res;
}

public:

    static string printVector(vector<string> contents) {
        string rs = "";
        for (auto line: contents) {
            rs += line + "\n";        
        }
        return rs;
    }

    FileInteractor(string fileName) {
        this->fileName = fileName;
    }

    string getFileName() {
        return this->fileName;
    }

    string getContents() {
        string rs = "";
        for (auto line: rawContents) {
            rs += line + "\n";        
        }
        return rs;
    }

    FileInteractor* readLines() {
        rawContents = vector<string>();
        string myText;

        ifstream file(this->fileName);
        string line;

        while (getline(file, line)) {
            rawContents.push_back(line);
        }

        file.close();
        return this;
    }

    vector<string> toWords() {
        vector<string> words;
        for (int i = 0; i < rawContents.size(); i++) {
            vector<string> temp = this->split(rawContents[i], " ");
            for (auto w: temp) {
                words.push_back(w);
            }
        }
        return words;
    }


    void writeLines(vector<string> contents) {
        ofstream file(this->fileName);
        for(int i = 0; i < contents.size(); i++) {
            file << contents[i] << "\n";
        }
        file.close();
        this->rawContents = contents;
    }

};