#include <iostream>
#include <string>
#include <stdexcept>
#include "qm/crypt.h"
#include "nm/ncmcrypt.h"
using namespace std;

bool convertFile(const string &filename);


int main(int argc, char **argv) {
    if (argc < 2) {
        cerr << "A tools to decrypt ncm,qmc0,qmc3,qmcflac file" << endl;
        cerr << "Usage: \n nqdump <input_file1> <input_file2> <input_file3> <...>" << endl;
        return 1;
    }
    int yt = argc - 2;
    while (yt > 0) {
        string in = argv[yt];
        bool result = convertFile(in);
        yt--;
    }
}


bool convertFile(const string &filename) {
    auto pos = filename.rfind('.');
    if (pos == string::npos) {
        cerr << "Warning: no extname." << endl;
        return false;
    } else {
        auto base = filename.substr(0, pos);
        auto ext = filename.substr(pos + 1);
        if (ext == "qmcflac") {
            ext = ".flac";
            try {
                cout << "Dumping to flac: " << base + ext << endl;
                return convert(filename, base + ext);
            } catch (invalid_argument e) {
                cout << "exception: " << e.what() << endl;
            } catch (...) {
                cout << "unexcept exception!" << endl;
            }
            return false;
         } else if (ext == "qmc0" || ext == "qmc3") {
            ext = ".mp3";
            try {
                cout << "Dumping to mp3: " << base + ext << endl;
                return convert(filename, base + ext);
            } catch (invalid_argument e) {
                cout << "exception: " << e.what() << endl;
            } catch (...) {
                cout << "unexcept exception!" << endl;
            }
            return false;
         } else if (ext == "ncm") {
             try {
                NeteaseCrypt crypt(filename);
                crypt.Dump();
                crypt.FixMetadata();
                cout << "Dumped NCM: " << crypt.dumpFilepath() << endl;
            } catch (invalid_argument e) {
                cout << "exception: " << e.what() << endl;
            } catch (...) {
                cout << "unexcept exception!" << endl;
            }
            return true;
        } else {
            cerr << "Warning: unknown extname (support: ncm,qmcflac, qmc0, qmc3)."
                 << endl;
            return false;
        }
        return false;
    }
}
